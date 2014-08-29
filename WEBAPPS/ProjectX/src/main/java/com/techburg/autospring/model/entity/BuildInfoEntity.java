package com.techburg.autospring.model.entity;

import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "build_info")
public class BuildInfoEntity {
	@Id
	@GeneratedValue
	private long id;
	
	@Column(name = "status")
	private int status;
	
	@Column(name = "begin_build_time")
	private Date beginBuildTime;
	
	@Column(name = "end_build_time")
	private Date endBuildTime;
	
	@Column(name = "log_file_path")
	private String logFilePath;
	
	public BuildInfoEntity() {
		
	}
	
	public long getId() {
		return id;
	}

	public void setId(long id) {
		this.id = id;
	}

	public int getStatus() {
		return status;
	}

	public void setStatus(int status) {
		this.status = status;
	}

	public Date getBeginTimeStamp() {
		return beginBuildTime;
	}

	public void setBeginTimeStamp(Date beginTimeStamp) {
		this.beginBuildTime = beginTimeStamp;
	}

	public Date getEndTimeStamp() {
		return endBuildTime;
	}

	public void setEndTimeStamp(Date endTimeStamp) {
		this.endBuildTime = endTimeStamp;
	}

	public String getLogFilePath() {
		return logFilePath;
	}

	public void setLogFilePath(String logFilePath) {
		this.logFilePath = logFilePath;
	}
}
