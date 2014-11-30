package com.techburg.autospring.service.impl;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.Query;

import org.springframework.beans.factory.annotation.Autowired;

import com.techburg.autospring.bo.abstr.IWorkspaceBo;
import com.techburg.autospring.db.task.abstr.AbstractDBTask;
import com.techburg.autospring.db.task.abstr.IDBTaskExecutor;
import com.techburg.autospring.db.task.impl.WorkspaceDBTaskImpl;
import com.techburg.autospring.model.BasePersistenceQuery.DataRange;
import com.techburg.autospring.model.WorkspacePersistenceQuery;
import com.techburg.autospring.model.business.Workspace;
import com.techburg.autospring.model.entity.WorkspaceEntity;
import com.techburg.autospring.service.abstr.IWorkspacePersistenceService;
import com.techburg.autospring.service.abstr.PersistenceResult;

public class WorkspacePersistenceServiceJPAImpl implements IWorkspacePersistenceService {

	private EntityManagerFactory mEntityManagerFactory = null;
	private IWorkspaceBo mWorkspaceBo = null;
	private IDBTaskExecutor mDBTaskExecutor = null;
	
	@Autowired
	public WorkspacePersistenceServiceJPAImpl(EntityManagerFactory entityManagerFactory) {
		mEntityManagerFactory = entityManagerFactory;	
	}

	@Autowired
	public void setWorkspaceBo(IWorkspaceBo workspaceBo) {
		mWorkspaceBo = workspaceBo;
	}
	
	@Autowired
	public void setDBTaskExecutor(IDBTaskExecutor dbTaskExecutor) {
		mDBTaskExecutor = dbTaskExecutor;
	}

	@Override
	public int persistWorkspace(Workspace workspace) {
		WorkspaceDBTaskImpl workspacePersistTask = new WorkspaceDBTaskImpl(mWorkspaceBo, mEntityManagerFactory);
		try {
			workspacePersistTask.setPersistParams(workspace);
			workspacePersistTask.setScheduleMode(AbstractDBTask.SCHEDULE_ASYNC_MODE);
			mDBTaskExecutor.executeDBTask(workspacePersistTask);
		}
		catch (Exception e) {
			return PersistenceResult.PERSISTENCE_FAILED;
		}
		return PersistenceResult.REQUEST_QUEUED;
	}

	@Override
	public int updateWorkspace(Workspace workspace) {
		EntityManager entityManager = mEntityManagerFactory.createEntityManager();
		WorkspaceEntity entity = entityManager.find(WorkspaceEntity.class, workspace.getId());
		if(entity == null) {
			return PersistenceResult.UPDATE_FAILED;
		}
		EntityTransaction tx = entityManager.getTransaction();
		tx.begin();
		entity.setScriptFilePath(workspace.getScriptFilePath());
		tx.commit();
		entityManager.close();
		return PersistenceResult.UPDATE_SUCCESSFUL;
	}

	@Override
	public int loadWorkspace(List<Workspace> buildInfoList, WorkspacePersistenceQuery query) {
		Query loadQuery = null;
		buildInfoList.clear();
		EntityManager entityManager = mEntityManagerFactory.createEntityManager();

		switch (query.dataRange) {
		case DataRange.ALL:
			loadQuery = entityManager.createNativeQuery("select * from workspace;", WorkspaceEntity.class);
			try {
				@SuppressWarnings("unchecked")
				List<WorkspaceEntity> entities = loadQuery.getResultList();
				for(WorkspaceEntity entity : entities) {
					entityManager.detach(entity);
					buildInfoList.add(mWorkspaceBo.getBusinessObjectFromEntity(entity));
				}
				return PersistenceResult.LOAD_SUCCESSFUL;
			}
			catch (Exception e) {
				e.printStackTrace();
				return PersistenceResult.INVALID_QUERY;
			}
		case DataRange.ID_MATCH:
			long id = query.id;
			
			/**
			 * TODO Try to force the predicted error of database locked
			 * by executing a time-consuming select rather than executing
			 * select query many times
			 */
			WorkspaceEntity entity = entityManager.find(WorkspaceEntity.class, id);
			if(entity != null) {
				entityManager.detach(entity);
				buildInfoList.add(mWorkspaceBo.getBusinessObjectFromEntity(entity));
			}
			return PersistenceResult.LOAD_SUCCESSFUL;
		default:
			return PersistenceResult.INVALID_QUERY;
		}
	}

	@Override
	public int removeWorkspaceByID(long id) {
		// TODO Auto-generated method stub
		return 0;
	}

}
