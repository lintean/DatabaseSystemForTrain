#include "DBs.h"
#include"Table.h"
#include"Column.h"
#include"Row.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
DBs::DBs()
{
}

bool DBs::insert(string databaseName, string tableName, map<string,string> insertData)
{
	for (int i = 0; i < databasees.size(); i++)
	{
		if (databasees[i].getDatabaseName == databaseName)
		{
			vector<Table> currentTables;
			currentTables = databasees[i].getTables();
			for (int j = 0; j < currentTables.size(); j++)
			{
				if (currentTables[j].getTableName() == tableName)
				{
					string* newRow = new string[currentTables[j].getColumnCount()];
					Column* currentColumnArray = currentTables[j].getColumnArray();
					for (int n = 0; n < currentTables[j].getColumnCount(); n++)
					{
						if (insertData.count(currentColumnArray[n].getColumnName()) > 0)  //如果关联数组中存在这个键
							newRow[n] = insertData[currentColumnArray[n].getColumnName()];
						else
						{
							if (currentColumnArray[n].getAllowNull())
								newRow[n] = "null";
							else
							{
								cout << "Column " << currentColumnArray[n].getColumnName() << " do not allow null!\n";
								return false;
							}
						}
					}
					currentTables[j].addRow(new Row(newRow));
					return true;
				}
			}
			cout << "No such table!\n";
			return false;
		}
	}
	cout << "No such database!\n";
	return false;
}

bool DBs::insert(string databaseName, string tableName, string * insertData)
{
	for (int i = 0; i < databasees.size(); i++)
	{
		if (databasees[i].getDatabaseName == databaseName)
		{
			vector<Table> currentTables;
			currentTables = databasees[i].getTables();
			for (int j = 0; j < currentTables.size(); j++)
			{
				if (currentTables[j].getTableName() == tableName)
				{
					currentTables[j].addRow(new Row(insertData));
					return true;
				}
			}
			cout << "No such table!\n";
			return false;
		}
	}
	cout << "No such database!\n";
	return false;
}


Table DBs::select(string databaseName, string tableName, string * columnName, int columnCount, Where selectCondition)
{
	for (int i = 0; i < databasees.size(); i++)
	{
		if (databasees[i].getDatabaseName == databaseName)
		{
			vector<Table> currentTables;  //记录当前数据库的表对象数组
			currentTables = databasees[i].getTables();
			for (int j = 0; j < currentTables.size(); j++)
			{
				if (currentTables[j].getTableName() == tableName)
				{
					
					
					Column* currentColumnArray = currentTables[j].getColumnArray();  //记录当前表的列对象数组
					vector<Row> currentRowArray = currentTables[j].getRowArray();  //记录当前表的行对象数组
					Table newTable = Table("selectStatementReturnTable",columnCount);  //select 函数的返回值
					for (int n = 0; n < columnCount; n++)
						(newTable.getColumnArray())[n].setColumnName = columnName[n];

					int columnIndex;  //记录 where 语句中的 columnName 所属对象在 Table 的 column 对象数组中的下标
					//找到 where 语句中对应的列在当前表的列数组中的下标 
					for (int n = 0; n < currentTables[j].getColumnCount(); n++)
					{
						if (currentColumnArray[n].getColumnName() == selectCondition.getWhereColumnName())
						{
							columnIndex = n;
							break;
						}
					}
					//找到 select 语句中对应的列在当前表的列数组中的下标
					int* rowIndex = new int[columnCount];
					for (int n = 0; n < columnCount; n++)
					{
						for (int m = 0; m < currentTables[j].getColumnCount(); m++)
						{
							if (currentColumnArray[m].getColumnName() == columnName[n])
							{
								rowIndex[n] = m;
								break;
							}
						}
					}
					//遍历当前表中的每一行，选出符合 Where 条件的行
 					for (int m = 0; m < currentTables[j].getRowCount(); m++)
					{
						if (selectCondition.getWhereValue() == currentRowArray[m].getCell(columnIndex))
						{
							string* newRowData = new string[columnCount];
							for (int k = 0; k < columnCount; k++)
							{
								newRowData[k] = currentRowArray[m].getCell(rowIndex[k]);
							}
							newTable.addRow(new Row(newRowData));  //将创建的新行加到要返回的表中
						}
							
					}
				}
			}
			cout << "No such table!\n";
			return Table();
		}
	}
	cout << "No such database!\n";
	return Table();
}


