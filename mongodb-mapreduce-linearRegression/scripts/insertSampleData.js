
function insertSampleDataSet(db, collectionName, numberOfSample, func_generateSampleData) {
	for(var i = 0; i < numberOfSample; i++) {
		insertSampleData(db, collectionName, func_generateSampleData)
	}
}

function insertSampleData(db, collectionName, func_generateSampleData) {
	db[collectionName].insert(func_generateSampleData());
}
