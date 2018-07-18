#pragma once
#include<string>
#include<iostream>
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
	ArrayPlus<Database> databasees;
public:
	DBs();
	bool insert(string databaseName, string tableName, map<string, string>);
	bool insert(string databaseName, string tableName, string*);
	bool Delete(string databaseName, string tableName, Where);  //Where �ṹ���������ȷ��Row�������±�
	Table select(string databaseName, string tableName, string* columnName,int columnCount, Where);
	bool update(string databaseName, string tableName, map<string, string>, Where);
	bool createTable(Table*); //���� Database.addTable(Table*)
	bool dropTable(string databaseName, string tableName);  //���� Database.deleteTable(String tableName)
	bool createDatabase(Database databaseName);
	bool dropDatabase(string databaseName);
};