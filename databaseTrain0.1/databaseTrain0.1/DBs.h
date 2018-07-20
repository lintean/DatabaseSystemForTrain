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
	bool insert(string databaseName, string tableName, string* insertData);
	bool Delete(string databaseName, string tableName, Where deleteCondition);  //Where 结构体的作用是确定Row对象及其下标
	Table select(string databaseName, string tableName, string* columnName,int columnCount, Where selectCondition);
	bool update(string databaseName, string tableName, map<string, string> updataData, Where updateCondition);
	bool createTable(string databaseName, Table* newTable); //调用 Database.addTable(Table*)
	bool dropTable(string databaseName, string tableName);  //调用 Database.deleteTable(String tableName)
	bool createDatabase(Database databaseName);
	bool dropDatabase(string databaseName);
};