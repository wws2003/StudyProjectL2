package com.techburg.autospring.bo.impl;

import com.techburg.autospring.bo.abstr.IBuildScriptBo;
import com.techburg.autospring.model.business.BuildScript;
import com.techburg.autospring.model.entity.BuildScriptEntity;

public class BuildScriptBoImpl implements IBuildScriptBo {
	@Override
	public BuildScriptEntity getEntityFromBusinessObject(BuildScript buildScript) {
		if (buildScript == null) {
			return null;
		}
		BuildScriptEntity entity = new BuildScriptEntity();
		entity.setId(buildScript.getId());
		entity.setScriptFilePath(buildScript.getScriptFilePath());
		return entity;
	}
	
	@Override
	public BuildScript getBusinessObjectFromEntity(BuildScriptEntity entity) {
		if (entity == null) {
			return null;
		}
		BuildScript buildScript = new BuildScript();
		buildScript.setId(entity.getId());
		buildScript.setScriptFilePath(entity.getScriptFilePath());
		return buildScript;
	}
}
