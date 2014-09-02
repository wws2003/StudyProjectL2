package com.techburg.autospring.service.impl;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.PersistenceException;
import javax.persistence.Query;

import org.springframework.beans.factory.annotation.Autowired;

import com.techburg.autospring.bo.abstr.IBuildScriptBo;
import com.techburg.autospring.model.BasePersistenceQuery.DataRange;
import com.techburg.autospring.model.BuildScriptPersistenceQuery;
import com.techburg.autospring.model.business.BuildScript;
import com.techburg.autospring.model.entity.BuildScriptEntity;
import com.techburg.autospring.service.abstr.IBuildScriptPersistenceService;
import com.techburg.autospring.service.abstr.PersistenceResult;

public class BuildScriptPersistenceServiceJPAImpl implements IBuildScriptPersistenceService {

	private EntityManagerFactory mEntityManagerFactory = null;
	private IBuildScriptBo mBuildScriptBo = null;

	@Autowired
	public BuildScriptPersistenceServiceJPAImpl(EntityManagerFactory entityManagerFactory) {
		mEntityManagerFactory = entityManagerFactory;	
	}

	@Autowired
	public void setBuildInfoBo(IBuildScriptBo buildScriptBo) {
		mBuildScriptBo = buildScriptBo;
	}

	@Override
	public int persistBuildScript(BuildScript buildScript) {
		BuildScriptEntity entity = mBuildScriptBo.getEntityFromBusinessObject(buildScript);
		EntityManager entityManager = mEntityManagerFactory.createEntityManager();
		try {
			EntityTransaction ts = entityManager.getTransaction();
			ts.begin();
			entityManager.persist(entity);
			entityManager.detach(entity); //Do not need to manage this object longer !
			ts.commit();
		}
		catch (PersistenceException pe) {
			return PersistenceResult.PERSISTENCE_FAILED;
		}
		finally {
			entityManager.close();
		}
		return PersistenceResult.PERSISTENCE_SUCCESSFUL;
	}

	@Override
	public int updateBuildScript(BuildScript buildScript) {
		EntityManager entityManager = mEntityManagerFactory.createEntityManager();
		BuildScriptEntity entity = entityManager.find(BuildScriptEntity.class, buildScript.getId());
		if(entity == null) {
			return PersistenceResult.UPDATE_FAILED;
		}
		EntityTransaction tx = entityManager.getTransaction();
		tx.begin();
		entity.setScriptFilePath(buildScript.getScriptFilePath());
		tx.commit();
		entityManager.close();
		return PersistenceResult.UPDATE_SUCCESSFUL;
	}

	@Override
	public int loadBuildScript(List<BuildScript> buildInfoList,
			BuildScriptPersistenceQuery query) {
		Query loadQuery = null;
		buildInfoList.clear();
		EntityManager entityManager = mEntityManagerFactory.createEntityManager();
	
		switch (query.mDataRange) {
		case DataRange.ALL:
			loadQuery = entityManager.createNativeQuery("select * from build_script;", BuildScriptEntity.class);
			try {
				@SuppressWarnings("unchecked")
				List<BuildScriptEntity> entities = loadQuery.getResultList();
				for(BuildScriptEntity entity : entities) {
					entityManager.detach(entity);
					buildInfoList.add(mBuildScriptBo.getBusinessObjectFromEntity(entity));
				}
				return PersistenceResult.LOAD_SUCCESSFUL;
			}
			catch (Exception e) {
				e.printStackTrace();
				return PersistenceResult.INVALID_QUERY;
			}
		case DataRange.ID_MATCH:
			long id = query.id;
			BuildScriptEntity entity = entityManager.find(BuildScriptEntity.class, id);
			if(entity != null) {
				entityManager.detach(entity);
				buildInfoList.add(mBuildScriptBo.getBusinessObjectFromEntity(entity));
			}
			return PersistenceResult.LOAD_SUCCESSFUL;
		default:
			return PersistenceResult.INVALID_QUERY;
		}
	}

	@Override
	public int removeBuildScriptByID(long id) {
		// TODO Auto-generated method stub
		return 0;
	}

}
