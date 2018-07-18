#pragma once
#include"Table.h"
#include"ArrayPlus.h"
using namespace std;
class Database
{
private:
	string name;
	int tableCount;
	ArrayPlus<Table> tables;
public:
	Database(string databaseName);
	bool addTable(Table*);
	bool deleteTable(string tableName);

	bool setDatabaseName(string databaseName);
	string getDatabaseName();

	int getTableCount();
};