#include "Table.h"

Table::Table(string name, int colCount)
{
	tableName = name;
	columnCount = colCount;
	rowCount = 0;
	column = new Column[colCount];
}

Table::Table()
{
}
