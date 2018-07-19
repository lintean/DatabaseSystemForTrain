#pragma once
#include<vector>
#include"Table.h"
using namespace std;
class Database
{
private:
	string name;
	int tableCount;
	vector<Table> tables;
public:
	Database(string databaseName);
	bool addTable(Table* newTable);
	bool deleteTable(string tableName);

	bool setDatabaseName(string databaseName);
	string getDatabaseName();

	int getTableCount();
};