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
						if (insertData.count(currentColumnArray[n].getColumnName()) > 0)  //������������д��������
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
			vector<Table> currentTables;  //��¼��ǰ���ݿ�ı��������
			currentTables = databasees[i].getTables();
			for (int j = 0; j < currentTables.size(); j++)
			{
				if (currentTables[j].getTableName() == tableName)
				{
					
					
					Column* currentColumnArray = currentTables[j].getColumnArray();  //��¼��ǰ����ж�������
					vector<Row> currentRowArray = currentTables[j].getRowArray();  //��¼��ǰ����ж�������
					Table newTable = Table("selectStatementReturnTable",columnCount);  //select �����ķ���ֵ
					for (int n = 0; n < columnCount; n++)
						(newTable.getColumnArray())[n].setColumnName = columnName[n];

					int columnIndex;  //��¼ where ����е� columnName ���������� Table �� column ���������е��±�
					//�ҵ� where ����ж�Ӧ�����ڵ�ǰ����������е��±� 
					for (int n = 0; n < currentTables[j].getColumnCount(); n++)
					{
						if (currentColumnArray[n].getColumnName() == selectCondition.getWhereColumnName())
						{
							columnIndex = n;
							break;
						}
					}
					//�ҵ� select ����ж�Ӧ�����ڵ�ǰ����������е��±�
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
					//������ǰ���е�ÿһ�У�ѡ������ Where ��������
 					for (int m = 0; m < currentTables[j].getRowCount(); m++)
					{
						if (selectCondition.getWhereValue() == currentRowArray[m].getCell(columnIndex))
						{
							string* newRowData = new string[columnCount];
							for (int k = 0; k < columnCount; k++)
							{
								newRowData[k] = currentRowArray[m].getCell(rowIndex[k]);
							}
							newTable.addRow(new Row(newRowData));  //�����������мӵ�Ҫ���صı���
						}	
					}

					return newTable;
				}
			}
			cout << "No such table!\n";
			return Table();
		}
	}
	cout << "No such database!\n";
	return Table();
}

bool DBs::update(string databaseName, string tableName, map<string, string> updateData, Where updateCodition)
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
					Table currentTable = currentTables[j];
					Column* currentColumnArray = currentTable.getColumnArray();
					vector<Row> currentRowArray = currentTable.getRowArray();

					//�ҵ� where ����� column �ڸñ�� column ���������е��±꣬�������� columnIndex ������
					int columnIndex = -1;
					for (int n = 0; n < currentTable.getColumnCount(); n++)
					{
						if (currentColumnArray[n].getColumnName() == updateCodition.getWhereColumnName())
						{
							columnIndex = n;
							break;
						}
					}
					if (columnIndex == -1)
					{
						cout << "Where statement error! No such column!\n";
						return false;
					}

					//�ҵ� set ����е� column �ڸñ�� column ���������е��±꣬�������� rowIndex ������
					int* rowIndex = new int[updateData.size()];
					int m = 0;  //�ڲ� for ѭ����ѭ��������ȷ����ǰ column ��������ֻ������һ��
					for (int n = 0; n < updateData.size(); n++)
					{
						for (; m < currentTable.getColumnCount(); m++)
						{
							if (updateData.count(currentColumnArray[m].getColumnName()) > 0)  //���������д��ڸ� key ֵ
							{
								rowIndex[n] = m;  //���� column ������±괢�浽 rowIndex ������
								break;
							}
						}
					}

					//������ǰ��� Row �������飬�ҵ���Ҫ�޸ĵ� Row �����޸�
					for (int n = 0; n < currentTable.getRowCount(); n++)
					{
						if (currentRowArray[n].getCell(columnIndex) == updateCodition.getWhereValue())
						{
							for (int m = 0; m < updateData.size(); m++)
							{
								currentRowArray[n].setCell(rowIndex[m], updateData[currentColumnArray[rowIndex[m]].getColumnName()]);
							}
						}
					}
					return true;  //���³ɹ�
				}
			}
			cout << "No such table!\n";
			return false;
		}
	}
	cout << "No such database!\n";
	return false;
}


