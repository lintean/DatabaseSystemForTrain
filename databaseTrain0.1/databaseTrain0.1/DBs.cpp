#include "DBs.h"

bool DBs::createTable(string databaseName,Table *newTable)
{
	for (auto it = databasees.begin(); it != databasees.end(); it++)
	{
		if (it->getDatabaseName() == databaseName)
		{
			it->addTable(newTable);
		}
	}
	return false;
}

bool DBs::dropTable(string databaseName, string tableName)
{
	for (auto it = databasees.begin(); it != databasees.end(); it++)
	{
		if (it->getDatabaseName() == databaseName)
		{
			it->deleteTable(databaseName);
		}
	}
	return false;
}

bool DBs::createDatabase(Database databaseName)
{
	databasees.push_back(databaseName);
	return false;
}

bool DBs::dropDatabase(string databaseName)
{
	for (auto it = databasees.begin(); it != databasees.end(); it++)
	{
		if (it->getDatabaseName() == databaseName)
		{
			databasees.erase(it);
		}
	}
	return false;
}

DBs::DBs()
{
}

bool DBs::Delete(string databaseName, string tableName, Where)
{
	
	return false;
}
