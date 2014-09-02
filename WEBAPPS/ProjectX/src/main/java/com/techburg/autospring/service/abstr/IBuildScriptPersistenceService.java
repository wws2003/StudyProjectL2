package com.techburg.autospring.service.abstr;

import java.util.List;

import com.techburg.autospring.model.BuildScriptPersistenceQuery;
import com.techburg.autospring.model.business.BuildScript;

public interface IBuildScriptPersistenceService {
	public int persistBuildScript(BuildScript buildScript);
	public int updateBuildScript(BuildScript buildScript);
	public int loadBuildScript(List<BuildScript> buildInfoList, BuildScriptPersistenceQuery query);
	public int removeBuildScriptByID(long id);
}
