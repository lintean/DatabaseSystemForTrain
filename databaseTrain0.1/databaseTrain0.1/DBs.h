#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include"Table.h"
#include"Database.h"
#include"Where.h"
#include"Row.h"
#include"ArrayPlus.h"

using namespace std;

class DBs
{
private:
	vector<Database> databasees;
public:
	DBs();
	bool insert(string databaseName, string tableName, map<string, string>);
	bool insert(string databaseName, string tableName, string*);
	bool Delete(string databaseName, string tableName, Where);  //Where �ṹ���������ȷ��Row�������±�
	Table select(string databaseName, string tableName, string* columnName,int columnCount, Where);
	bool update(string databaseName, string tableName, map<string, string>, Where);
	bool createTable(string databaseName,Table* newTable); //���� Database.addTable(Table*)
	bool dropTable(string databaseName, string tableName);  //���� Database.deleteTable(String tableName)
	bool createDatabase(Database databaseName);
	bool dropDatabase(string databaseName);
};