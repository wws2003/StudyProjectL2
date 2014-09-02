package com.techburg.autospring.bo.abstr;

import com.techburg.autospring.model.business.BuildScript;
import com.techburg.autospring.model.entity.BuildScriptEntity;

public interface IBuildScriptBo {
	public BuildScriptEntity getEntityFromBusinessObject(BuildScript buildScript);
	public BuildScript getBusinessObjectFromEntity(BuildScriptEntity entity);
}
