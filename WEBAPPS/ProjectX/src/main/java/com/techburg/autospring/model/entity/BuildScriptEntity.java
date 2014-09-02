package com.techburg.autospring.model.entity;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name="build_script")
public class BuildScriptEntity {
	@Id
	@GeneratedValue
	private long id;
	
	@Column(name="script_file_path")
	private String mScriptFilePath;

	public long getId() {
		return id;
	}
	public void setId(long id) {
		this.id = id;
	}

	public String getScriptFilePath() {
		return mScriptFilePath;
	}
	public void setScriptFilePath(String mScriptFilePath) {
		this.mScriptFilePath = mScriptFilePath;
	}
}
