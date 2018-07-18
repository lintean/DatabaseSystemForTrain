#pragma once
#include<string>
#include<iostream>
#include<map>
#include"Table.h"
#include"Database.h"
#include"Where.h"
#include"Row.h"

using namespace std;

class Logic
{
public:
	static bool insert(string databaseName, string tableName, map<string, string>);
	static bool insert(string databaseName, string tableName, string*);
	static bool Delete(string databaseName, string tableName, Where);  //Where 结构体的作用是确定Row对象及其下标
	static Table select(string databaseName, string tableName, string* columnName,int columnCount, Where);
	static bool update(string databaseName, string tableName, map<string, string>, Where);
	static bool createTable(Table*); //调用 Database.addTable(Table*)
	static bool dropTable(string databaseName, string tableName);  //调用 Database.deleteTable(String tableName)
	static bool createDatabase(Database databaseName);
	static bool dropDatabase(string databaseName);
};