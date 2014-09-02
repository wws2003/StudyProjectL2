package com.techburg.autospring.controller;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;

import com.techburg.autospring.model.BuildScriptPersistenceQuery;
import com.techburg.autospring.model.BasePersistenceQuery.DataRange;
import com.techburg.autospring.model.business.BuildScript;
import com.techburg.autospring.service.abstr.IBuildScriptPersistenceService;
import com.techburg.autospring.util.FileUtil;

@Controller
public class ScriptController {
	private static final String gScriptFileAvailable = "scriptFileAvailable";
	private static final String gScriptFileContent = "scriptFileContent";
	
	private IBuildScriptPersistenceService mBuildScriptPersistenceService;
	
	@Autowired
	public void setBuildScriptPersistenceService(IBuildScriptPersistenceService buildScriptPersistenceService) {
		mBuildScriptPersistenceService = buildScriptPersistenceService;
	}
	
	@RequestMapping(value="/script/edit", method=RequestMethod.GET)
	public String editScriptContent(Model model) {
		long id = 1; //TODO In the future, id will be read from proper parameters
		BuildScript buildScript = getBuildScriptbyId(id);
		if(buildScript != null) {
			String scriptFilePath = buildScript.getScriptFilePath();
			FileUtil fileUtil = new FileUtil();
			try {
				String scriptFileContent = fileUtil.getStringFromFile(scriptFilePath);
				System.out.println("File content " + scriptFileContent);
				model.addAttribute(gScriptFileContent, scriptFileContent);
				model.addAttribute(gScriptFileAvailable, true);
			}
			catch (Exception e) {
				model.addAttribute(gScriptFileAvailable, false);
			}
		}
		else  {
			model.addAttribute(gScriptFileAvailable, false);
		}
		return "script";
	}
	
	@RequestMapping(value="/script/submit", method=RequestMethod.POST)
	public String submitScriptContent(
			@RequestParam(value = "content", required = true) String content,
			Model model) {
		//TODO Add task to processor to avoid concurrency
		long id = 1; //TODO In the future, id will be read from proper parameters
		BuildScript buildScript = getBuildScriptbyId(id);
		if(buildScript != null) {
			String scriptFilePath = buildScript.getScriptFilePath();
			FileUtil fileUtil = new FileUtil();
			try {
				fileUtil.storeContentToFile(content, scriptFilePath);
			}
			catch (Exception e) {
				return "home";
			}
		}
		return "redirect:/script/edit";
	}
	
	private BuildScript getBuildScriptbyId(long id) {
		List<BuildScript> buildScripts = new ArrayList<BuildScript>();
		if(mBuildScriptPersistenceService != null) {
			BuildScriptPersistenceQuery query = new BuildScriptPersistenceQuery();
			query.mDataRange = DataRange.ID_MATCH;
			query.id = id;
			mBuildScriptPersistenceService.loadBuildScript(buildScripts, query);
			return buildScripts.isEmpty() ? null : buildScripts.get(0);
		}
		return null;
	}
}
