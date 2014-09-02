package com.techburg.autospring.service.impl;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.PersistenceException;
import javax.persistence.Query;

import org.springframework.beans.factory.annotation.Autowired;

import com.techburg.autospring.bo.abstr.IBuildInfoBo;
import com.techburg.autospring.model.BasePersistenceQuery.DataRange;
import com.techburg.autospring.model.BuildInfoPersistenceQuery;
import com.techburg.autospring.model.business.BuildInfo;
import com.techburg.autospring.model.entity.BuildInfoEntity;
import com.techburg.autospring.service.abstr.IBuildInfoPersistenceService;
import com.techburg.autospring.service.abstr.PersistenceResult;

public class BuildInfoPersistenceServiceJPAImpl implements IBuildInfoPersistenceService {

	private EntityManagerFactory mEntityManagerFactory;
	private IBuildInfoBo mBuildInfoBo = null;
	
	@Autowired
	public BuildInfoPersistenceServiceJPAImpl(EntityManagerFactory entityManagerFactory) {
		mEntityManagerFactory = entityManagerFactory;
	}
	
	@Autowired
	public void setBuildInfoBo(IBuildInfoBo buildInfoBo) {
		mBuildInfoBo = buildInfoBo;
	}
	
	@Override
	public int persistBuildInfo(BuildInfo buildInfo) {
		BuildInfoEntity entity = mBuildInfoBo.getEntityFromBusinessObject(buildInfo);
		EntityManager entityManager = mEntityManagerFactory.createEntityManager();
		try {
			EntityTransaction tx = entityManager.getTransaction();
			tx.begin();
			entityManager.persist(entity);
			entityManager.detach(entity); //Do not need to manage this object longer !
			tx.commit();
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
	public int loadBuildInfo(List<BuildInfo> buildInfoList,	BuildInfoPersistenceQuery query) {
		Query loadQuery = null;
		buildInfoList.clear();
		EntityManager entityManager = mEntityManagerFactory.createEntityManager();
		switch (query.mDataRange) {
		case DataRange.ALL:
			loadQuery = entityManager.createNativeQuery("select * from build_info;", BuildInfoEntity.class);
			try {
				@SuppressWarnings("unchecked")
				List<BuildInfoEntity> entities = loadQuery.getResultList();
				for(BuildInfoEntity entity : entities) {
					entityManager.detach(entity);
					buildInfoList.add(mBuildInfoBo.getBusinessObjectFromEntity(entity));
				}
				return PersistenceResult.LOAD_SUCCESSFUL;
			}
			catch (Exception e) {
				e.printStackTrace();
				return PersistenceResult.INVALID_QUERY;
			}
		case DataRange.ID_MATCH:
			long id = query.id;
			BuildInfoEntity entity = entityManager.find(BuildInfoEntity.class, id);
			if(entity != null) {
				entityManager.detach(entity);
				buildInfoList.add(mBuildInfoBo.getBusinessObjectFromEntity(entity));
			}
			return PersistenceResult.LOAD_SUCCESSFUL;
		default:
			return PersistenceResult.INVALID_QUERY;
		}
	}

	@Override
	public int removeBuildInfoByID(long id) {
		EntityManager entityManager = mEntityManagerFactory.createEntityManager();
		EntityTransaction transition = entityManager.getTransaction();
		int ret = PersistenceResult.REMOVE_FAILED;
		transition.begin();
		BuildInfoEntity entityToDelete = entityManager.find(BuildInfoEntity.class, id);
		if(entityToDelete != null) {
			entityManager.remove(entityToDelete);
			ret = PersistenceResult.REMOVE_SUCCESSFUL;
		}
		transition.commit();
		entityManager.close();
		return ret;
	}
}
