#include "Where.h"
#include "Where.h"
#include <string>
Where::Where(string whereColumnName, string whereValue)
{
	columnName = whereColumnName;
	value = whereValue;
}

string Where::getWhereColumnName()
{
	return columnName;
}

string Where::getWhereValue()
{
	return value;
}
