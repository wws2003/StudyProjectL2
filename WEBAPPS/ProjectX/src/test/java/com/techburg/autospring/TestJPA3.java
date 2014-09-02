package com.techburg.autospring;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.techburg.autospring.model.BuildInfoPersistenceQuery;
import com.techburg.autospring.model.BasePersistenceQuery.DataRange;
import com.techburg.autospring.model.BuildScriptPersistenceQuery;
import com.techburg.autospring.model.business.BuildInfo;
import com.techburg.autospring.model.business.BuildScript;
import com.techburg.autospring.model.business.BuildInfo.Status;
import com.techburg.autospring.service.abstr.IBuildInfoPersistenceService;
import com.techburg.autospring.service.abstr.IBuildScriptPersistenceService;
import com.techburg.autospring.service.abstr.PersistenceResult;

public class TestJPA3 {

	private IBuildInfoPersistenceService mBuildInfoPersistenceService;
	private IBuildScriptPersistenceService mBuildScriptPersistenceService;

	@Before
	public void setUp() throws Exception {
		//Retrieve mPersistenceService by factory method
		String xmlPath = "file:src/main/webapp/WEB-INF/spring-conf/springmvc-conf.xml";
		try {
			ApplicationContext applicationContext = new ClassPathXmlApplicationContext(xmlPath);
			//applicationContext is also a bean factory...
			mBuildInfoPersistenceService = applicationContext.getBean("buildInfoPersistenceService", IBuildInfoPersistenceService.class);
			mBuildScriptPersistenceService = applicationContext.getBean("buildScriptPersistenceService", IBuildScriptPersistenceService.class);
		}
		catch (Exception e) {
			e.printStackTrace();
			throw e;
		}
	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void testPersist() {
		assertNotNull(mBuildInfoPersistenceService);
		assertNotNull(mBuildScriptPersistenceService);
		
		BuildScript buildScript = new BuildScript();
		buildScript.setScriptFilePath("gafin.vn");
		assertEquals(mBuildScriptPersistenceService.persistBuildScript(buildScript), PersistenceResult.PERSISTENCE_SUCCESSFUL);

		
		List<BuildScript> buildScripts = new ArrayList<BuildScript>();
		BuildScriptPersistenceQuery query2 = new BuildScriptPersistenceQuery();
		query2.mDataRange = DataRange.ID_MATCH;
		query2.id = 1;
		mBuildScriptPersistenceService.loadBuildScript(buildScripts, query2);
		
		assertEquals(buildScripts.size(), 1);
		
		BuildInfo buildInfo = new BuildInfo();
		buildInfo.setLogFilePath("LogFilePath");
		buildInfo.setStatus(Status.BUILD_SUCCESSFUL);
		buildInfo.setBeginTimeStamp(new Date());
		buildInfo.setEndTimeStamp(new Date());
		buildInfo.setBuildScript(buildScripts.get(0));
		
		assertEquals(mBuildInfoPersistenceService.persistBuildInfo(buildInfo), PersistenceResult.PERSISTENCE_SUCCESSFUL);
	
		List<BuildInfo> buildInfoList = new ArrayList<BuildInfo>();
		BuildInfoPersistenceQuery query = new BuildInfoPersistenceQuery();
		query.mDataRange = DataRange.ALL;
		mBuildInfoPersistenceService.loadBuildInfo(buildInfoList, query);
		
		assertEquals(1, buildInfoList.size());
		BuildScript targetBuildScript = buildInfoList.get(0).getBuildScript();
		assertNotNull(targetBuildScript);
		assertEquals("gafin.vn", targetBuildScript.getScriptFilePath());
	}
	
	@Test
	public void testUpdate() {
		BuildScript buildScript = new BuildScript();
		buildScript.setScriptFilePath("gafin.vn");
		assertEquals(mBuildScriptPersistenceService.persistBuildScript(buildScript), PersistenceResult.PERSISTENCE_SUCCESSFUL);

		List<BuildScript> buildScripts = new ArrayList<BuildScript>();
		BuildScriptPersistenceQuery query2 = new BuildScriptPersistenceQuery();
		query2.mDataRange = DataRange.ALL;
		mBuildScriptPersistenceService.loadBuildScript(buildScripts, query2);
		
		assertEquals(1, buildScripts.size());
		BuildScript buildScriptToUpdate = buildScripts.get(0);
		buildScriptToUpdate.setScriptFilePath("cafef.vn");
		
		assertEquals(PersistenceResult.UPDATE_SUCCESSFUL, mBuildScriptPersistenceService.updateBuildScript(buildScriptToUpdate));
	}

}
