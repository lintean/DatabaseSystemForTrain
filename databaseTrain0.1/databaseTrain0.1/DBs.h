#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include"Table.h"
#include"Database.h"
#include"Where.h"
#include"Row.h"

using namespace std;

class DBs
{
private:
	vector<Database> databasees;  //储存数据库对象的数组
public:
	DBs();
	bool insert(string databaseName, string tableName, map<string, string> insertData);
	bool insert(string databaseName, string tableName, string*);
	bool Delete(string databaseName, string tableName, Where);  //Where 结构体的作用是确定Row对象及其下标
	Table select(string databaseName, string tableName, string* columnName,int columnCount, Where);
	bool update(string databaseName, string tableName, map<string, string>, Where);
	bool createTable(string databaseName, Table*); //调用 Database.addTable(Table*)
	bool dropTable(string databaseName, string tableName);  //调用 Database.deleteTable(String tableName)
	bool createDatabase(Database databaseName);
	bool dropDatabase(string databaseName);
};