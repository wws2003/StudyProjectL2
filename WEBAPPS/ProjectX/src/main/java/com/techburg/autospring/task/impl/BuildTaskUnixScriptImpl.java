package com.techburg.autospring.task.impl;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;

import com.techburg.autospring.task.abstr.AbstractBuildTask;
import com.techburg.autospring.util.FileUtil;

public class BuildTaskUnixScriptImpl extends AbstractBuildTask {

	private String mScriptFileLocation;
	private String mScriptFileName;

	private static final String gCommand = "/bin/bash";

	public BuildTaskUnixScriptImpl(String logFilePathPrefix, String logFileExtension, String logFileLocation, String scriptFileLocation, String scriptFileName) {
		super(logFilePathPrefix, logFileExtension, logFileLocation);
		this.mScriptFileLocation = scriptFileLocation;
		this.mScriptFileName = scriptFileName;
	}

	@Override
	protected int mainExecute() {
		try {
			System.out.println("--------------------------Build task to be executed---------------------");
			Thread.sleep(6000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

		List<String> commandsAndArguments = new ArrayList<String>();
		commandsAndArguments.add(gCommand);
		commandsAndArguments.add(mScriptFileLocation + File.separator + mScriptFileName);
		ProcessBuilder processBuilder = new ProcessBuilder(commandsAndArguments);

		StringBuilder outputBuilder = new StringBuilder();

		try {
			startProcessAndGetOutputString(processBuilder, outputBuilder);
		} 
		catch (Exception e) {
			e.printStackTrace();
			return BuildTaskResult.FAILED;
		}

		try {
			writeOutputToLogFile(outputBuilder.toString());
			return BuildTaskResult.SUCCESSFUL;
		} 
		catch (Exception e) {
			e.printStackTrace();
			return BuildTaskResult.FAILED;
		}
	}

	private void startProcessAndGetOutputString(ProcessBuilder processBuilder, StringBuilder outputBuilder) throws Exception {
		FileUtil fileUtil = new FileUtil();
		InputStream processBufferedOutputStream = null;
		try {
			processBuilder.redirectErrorStream(true);
			Process process = processBuilder.start();

			processBufferedOutputStream = new BufferedInputStream(process.getInputStream());
			fileUtil.getStringFromInputStream(processBufferedOutputStream, outputBuilder);
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		finally {
			processBufferedOutputStream.close();
		}
	}
	
	private void writeOutputToLogFile(String output) throws Exception {
		FileUtil fileUtil = new FileUtil();
		OutputStream logFileOutputStream = null;
		try {
			logFileOutputStream = new BufferedOutputStream(new FileOutputStream(getLogFileFullPath()));
			fileUtil.writeStringToOutputStream(output, logFileOutputStream);
			logFileOutputStream.close();
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		finally {
			logFileOutputStream.close();
		}
	}

}
