#include "Column.h"

Column::Column()
{
}

Column::Column(string colName, type colType, int colLength, bool colPrimaryKey, bool colAllowNull)
{
	columnName = colName;
	columnType = colType;
	length = colLength;
	primaryKey = colPrimaryKey;
	allowNull = colAllowNull;
}

bool Column::setColumnName(string colName)
{
	columnName = colName;
	return true;
}

string Column::getColumnName()
{
	return columnName;
}

bool Column::getPrimaryKey()
{
	return primaryKey;
}

bool Column::setPrimaryKey(bool colPrimaryKey)
{
	primaryKey = colPrimaryKey;
	return true;
}

bool Column::getAllowNull()
{
	return allowNull;
}

bool Column::setAllowNull(bool colAllowNull)
{
	allowNull = colAllowNull;
	return true;
}

type Column::getColumnType()
{
	return columnType;
}

bool Column::setColumnType(type colType)
{
	columnType = colType;
	return true;
}

int Column::getLength()
{
	return length;
}

bool Column::setLength(int colLength)
{
	length = colLength;
	return true;
}
