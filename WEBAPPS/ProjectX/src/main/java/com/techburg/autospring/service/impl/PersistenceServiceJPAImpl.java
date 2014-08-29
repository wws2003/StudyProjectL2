package com.techburg.autospring.service.impl;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.PersistenceException;
import javax.persistence.Query;

import org.springframework.beans.factory.annotation.Autowired;

import com.techburg.autospring.model.BasePersistenceQuery.DataRange;
import com.techburg.autospring.model.BuildInfoPersistenceQuery;
import com.techburg.autospring.model.business.BuildInfo;
import com.techburg.autospring.model.entity.BuildInfoEntity;
import com.techburg.autospring.service.abstr.IPersistenceService;

public class PersistenceServiceJPAImpl implements IPersistenceService {

	//TODO Auto wiring the single entity manager
	private EntityManager mEntityManager = null;
	
	@Autowired
	public PersistenceServiceJPAImpl(EntityManagerFactory entityManagerFactory) {
		mEntityManager = entityManagerFactory.createEntityManager();
	}
	
	@Override
	public int persistBuildInfo(BuildInfo buildInfo) {
		BuildInfoEntity entity = getEntityFromBusinessObject(buildInfo);
		try {
			EntityTransaction ts = mEntityManager.getTransaction();
			ts.begin();
			mEntityManager.persist(entity);
			mEntityManager.detach(entity); //Do not need to manage this object longer !
			ts.commit();
		}
		catch (PersistenceException pe) {
			return PersistenceResult.PERSISTENCE_FAILED;
		}
		return PersistenceResult.PERSISTENCE_SUCCESSFUL;
	}

	@Override
	public int loadBuildInfo(List<BuildInfo> buildInfoList,	BuildInfoPersistenceQuery query) {
		//Temporally only load all data for investigate purpose
		Query loadQuery = null;
		buildInfoList.clear();
		switch (query.mDataRange) {
		case DataRange.ALL:
			loadQuery = mEntityManager.createNativeQuery("select * from build_info;", BuildInfoEntity.class);
			try {
				@SuppressWarnings("unchecked")
				List<BuildInfoEntity> entities = loadQuery.getResultList();
				for(BuildInfoEntity entity : entities) {
					System.out.println("Entity begin build timestamp " + entity.getBeginTimeStamp().getTime());
					buildInfoList.add(getBusinessObjectFromEntity(entity));
				}
				return PersistenceResult.LOAD_SUCCESSFUL;
			}
			catch (Exception e) {
				e.printStackTrace();
				return PersistenceResult.INVALID_QUERY;
			}
		default:
			return PersistenceResult.INVALID_QUERY;
		}
	}

	@Override
	public int removeBuildInfoByID(long id) {
		EntityTransaction transition = mEntityManager.getTransaction();
		int ret = PersistenceResult.REMOVE_FAILED;
		transition.begin();
		BuildInfoEntity entityToDelete = mEntityManager.find(BuildInfoEntity.class, id);
		if(entityToDelete != null) {
			mEntityManager.remove(entityToDelete);
			ret = PersistenceResult.REMOVE_SUCCESSFUL;
		}
		transition.commit();
		return ret;
	}
	
	private BuildInfoEntity getEntityFromBusinessObject(BuildInfo buildInfo) {
		BuildInfoEntity entity = new BuildInfoEntity();
		entity.setBeginTimeStamp(buildInfo.getBeginTimeStamp());
		entity.setEndTimeStamp(buildInfo.getEndTimeStamp());
		entity.setId(buildInfo.getId());
		entity.setStatus(buildInfo.getStatus());
		entity.setLogFilePath(buildInfo.getLogFilePath());
		return entity;
	}

	private BuildInfo getBusinessObjectFromEntity(BuildInfoEntity entity) {
		BuildInfo buildInfo = new BuildInfo();
		buildInfo.setBeginTimeStamp(entity.getBeginTimeStamp());
		buildInfo.setEndTimeStamp(entity.getEndTimeStamp());
		buildInfo.setId(entity.getId());
		buildInfo.setStatus(entity.getStatus());
		buildInfo.setLogFilePath(entity.getLogFilePath());
		return buildInfo;
	}
}
