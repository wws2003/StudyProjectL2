function connectToDB(dbName) {
	conn = new Mongo();
	db = conn.getDB(dbName);
	return db;
}
