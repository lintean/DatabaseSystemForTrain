#include "Database.h"
#include"Where.h"
#include"Table.h"
#include<iostream>
using namespace std;
Database::Database(string databaseName)
{
	name = databaseName;
}

bool Database::addTable(Table * newTable)
{
	bool tableExisted = false;
	for (int i = 0; i < tableCount; i++)
	{
		if (tables[i].getTableName() == newTable->getTableName())
		{
			tableExisted = true;
			break;
		}
	}
	if (tableExisted)
	{
		cout << "Table existed!\n";
		return false;
	}
	else
	{
		tables.push_back(*newTable);
		tableCount++;
		return true;
	}
	
}

bool Database::dropTable(string tableName)
{
	for (vector<Table>::iterator i = tables.begin(); i != tables.end(); i++)
	{
		if (i->getTableName() == tableName)
		{
			tables.erase(i);
			tableCount--;  //数据库中表的个数减一
			return true;
		}
	}
	return false;
}

bool Database::deleteTableRow(string tableName, Where whe)
{
	for (auto it = tables.begin(); it != tables.end(); it++)
	{
		if (it->getTableName() == tableName)
		{
			it->deleteRow(whe);
		}
	}
}


vector<Table> Database::getTables()
{
	return tables;
}

bool Database::setDatabaseName(string databaseName)
{
	name = databaseName;
	return true;
}

string Database::getDatabaseName()
{
	return name;
}

int Database::getTableCount()
{
	return tableCount;
}
