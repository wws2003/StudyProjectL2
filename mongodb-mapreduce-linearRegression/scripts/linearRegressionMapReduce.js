load("scripts/base.js")

const X_ITM_KEY = "X";
const Y_ITM_KEY = "Y";
const XY_ITM_KEY = "XY";
const XX_ITM_KEY = "XX";
const COUNT_ITM_KEY = "COUNT";

var KEYS = {X_ITM_KEY:X_ITM_KEY,
	 Y_ITM_KEY:Y_ITM_KEY,
	 XY_ITM_KEY:XY_ITM_KEY, 
	 XX_ITM_KEY:XX_ITM_KEY, 
	 COUNT_ITM_KEY: COUNT_ITM_KEY};

var lrMap = function() {
	var x = this.x;
	var y = this.y;

	emit(keyds.X_ITM_KEY, x);
	emit(keyds.Y_ITM_KEY, y);
	emit(keyds.XY_ITM_KEY, x * y);
	emit(keyds.XX_ITM_KEY, x * x);
	emit(keyds.COUNT_ITM_KEY, 1);
}

var lrReduce = function(key, values) {
	var sum = 0;
	values.forEach(function acc(entry) {
		sum += entry;
	});
	return sum;
}

function myMapReduce(db, collectionName, func_map, func_reduce, scope, outCollection) {
	db[collectionName].mapReduce(
	func_map,
	func_reduce,
	{	
		scope: scope,
		out: {replace: outCollectionName}
	}
	);
}

function calculateAndShowFinalResult(db, outCollectionName) {
	var sumxy = db[outCollectionName].findOne({"_id" : XY_ITM_KEY}).value;
	var sumxx = db[outCollectionName].findOne({"_id" : XX_ITM_KEY}).value;
	var count = db[outCollectionName].findOne({"_id" : COUNT_ITM_KEY}).value;
	var sumX = db[outCollectionName].findOne({"_id" : X_ITM_KEY}).value;
	var sumY = db[outCollectionName].findOne({"_id" : Y_ITM_KEY}).value;
	
	var meanX = sumX / count;
	var meanY = sumY / count;
	var sxx = (sumxx - count * meanX * meanX);
	var sxy = (sumxy - count * meanX * meanY);
	
	if(sxx != 0) {
		var lambda = sxy / sxx;
		var theta = meanY - lambda * meanX;
		print("y = " + lambda + "*x + " + theta)
	}
}

var dbName = "mydb1";
var db = connectToDB(dbName);
var collectionName = "points_collection";
var outCollectionName = "lr_out_collection1";
var scope = {keyds: KEYS};
myMapReduce(db, collectionName, lrMap, lrReduce, scope, outCollectionName);
calculateAndShowFinalResult(db, outCollectionName);
