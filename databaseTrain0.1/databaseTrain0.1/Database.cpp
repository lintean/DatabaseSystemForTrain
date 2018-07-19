#include "Database.h"

Database::Database(string databaseName)
{
	name = databaseName;
}

bool Database::addTable(Table * newTable)
{
	tables.push_back(*newTable);
	return false;
}

bool Database::deleteTable(string tableName)
{
	for (vector<Table>::iterator i = tables.begin(); i != tables.end(); i++)
	{
		if (i->getTableName() == tableName)
		{
			tables.erase(i);
			return true;
		}
	}
	return false;
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
