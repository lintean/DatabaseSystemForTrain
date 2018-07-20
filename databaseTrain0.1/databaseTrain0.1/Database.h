#pragma once
#include<vector>
#include"Table.h"
#include"Where.h"
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
	bool deleteTableRow(string tableName, Where);
	bool dropTable(string tableName);

	vector<Table> getTables();
	bool setDatabaseName(string databaseName);
	string getDatabaseName();

	int getTableCount();
};