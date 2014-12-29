load("scripts/base.js")
load("scripts/insertSampleData.js")

function generateSampleXYData() {
 	var point = {};
	point["x"] = Math.random() * 100;
	point["y"] = point["x"] * (3 + Math.random() / 10) + 4 + Math.random(); 
	return point;
}

var dbName = "mydb1";
var db = connectToDB(dbName);
var collectionName = "points_collection";
var numberOfSample = 25;
insertSampleDataSet(db, collectionName, numberOfSample, generateSampleXYData);


