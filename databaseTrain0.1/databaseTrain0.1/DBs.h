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
	bool insert(string databaseName, string tableName, string* insertData);  //insert 语句给出了每一个列对应的值
	bool Delete(string databaseName, string tableName, Where deleteCondition);  //Where 结构体的作用是确定Row对象及其下标
	Table select(string databaseName, string tableName, string* columnName,int columnCount, Where selectCondition);
	Table select(string databaseName, string tableName, string* columnName, int columnCount);  //无 where 语句
	bool update(string databaseName, string tableName, map<string, string> updataData, Where updateCondition);
	bool createTable(string databaseName, Table* newTable); //调用 Database.addTable(Table*)
	bool dropTable(string databaseName, string tableName);  //调用 Database.deleteTable(String tableName)
	bool createDatabase(Database* database);
	bool dropDatabase(string databaseName);
	int getTableColumnCount(string databaseName, string tableName);
};