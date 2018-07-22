#include"DBs.h"
#include"Table.h"
#include"Column.h"
#include"Row.h"
#include"Database.h"
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
		if (databasees[i].getDatabaseName() == databaseName)
		{
			vector<Table> currentTables;
			currentTables = databasees[i].getTables();
			for (int j = 0; j < currentTables.size(); j++)
			{
				if (currentTables[j].getTableName() == tableName)
				{
					string* newRow = new string[currentTables[j].getColumnCount()];
					vector<Column> currentColumnArray = currentTables[j].getColumnArray();
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
		if (databasees[i].getDatabaseName() == databaseName)
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


bool DBs::Delete(string databaseName, string tableName, Where whe)  //ɾ�����е�һ��
{
	for (auto it = databasees.begin(); it != databasees.end(); it++)
	{
		if (it->getDatabaseName() == databaseName)
		{
			return it->deleteTableRow(tableName, whe);
		}
	}
	return false;
}


Table DBs::select(string databaseName, string tableName, string * columnName, int columnCount, Where selectCondition)
{
	for (int i = 0; i < databasees.size(); i++)
	{
		if (databasees[i].getDatabaseName() == databaseName)
		{
			vector<Table> currentTables;  //��¼��ǰ���ݿ�ı��������
			currentTables = databasees[i].getTables();
			for (int j = 0; j < currentTables.size(); j++)
			{
				if (currentTables[j].getTableName() == tableName)
				{
					
					
					vector<Column> currentColumnArray = currentTables[j].getColumnArray();  //��¼��ǰ����ж�������
					vector<Row> currentRowArray = currentTables[j].getRowArray();  //��¼��ǰ����ж�������
					Table newTable = Table("selectStatementReturnTable",columnCount);  //select �����ķ���ֵ
					for (int n = 0; n < columnCount; n++)
						(newTable.getColumnArray())[n].setColumnName(columnName[n]);

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
		if (databasees[i].getDatabaseName() == databaseName)
		{
			vector<Table> currentTables;  //���浱ǰ���ݿ�ı��������
			currentTables = databasees[i].getTables();
			for (int j = 0; j < currentTables.size(); j++)
			{
				if (currentTables[j].getTableName() == tableName)
				{
					Table currentTable = currentTables[j];  //������Ҫ���µı�
					vector<Column> currentColumnArray = currentTable.getColumnArray();  //������Ҫ���µı���ж�������
					vector<Row> currentRowArray = currentTable.getRowArray();  //������Ҫ���µı����

					//�ҵ� where ����е� column �ڸñ�� column ���������е��±꣬�������� columnIndex ������
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
								currentRowArray[n].setCell(rowIndex[m], updateData[ (currentColumnArray[rowIndex[m]]).getColumnName() ]);
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

bool DBs::createTable(string databaseName, Table * newTable)
{
	for (auto it = databasees.begin(); it != databasees.end(); it++)
	{
		if (it->getDatabaseName() == databaseName)
		{
			return it->addTable(newTable);
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
			return it->dropTable(tableName);
		}
	}
	return false;
}

bool DBs::createDatabase(Database* database)
{
	bool databaseExisted = false;
	for (auto it = databasees.begin(); it != databasees.end(); it++)
	{
		if (it->getDatabaseName() == database->getDatabaseName())
		{
			databaseExisted = true;
			break;
		}
	}
	if (databaseExisted)
	{
		cout << "DataBase existed!\n";
		return false;
	}
	else
	{
		databasees.push_back(*database);
		return true;
	}
}

bool DBs::dropDatabase(string databaseName)
{
	for (auto it = databasees.begin(); it != databasees.end(); it++)
	{
		if (it->getDatabaseName() == databaseName)
		{
			databasees.erase(it);
			return true;
		}
	}
	cout << "Do not exist this database!\n";
	return false;
}

int DBs::getTableColumnCount(string databaseName, string tableName)
{
	for (int i = 0; i < databasees.size(); i++)
	{
		if (databasees[i].getDatabaseName() == databaseName)
		{
			for (int j = 0; j < databasees[i].getTables().size(); j++)
			{
				if ((databasees[i].getTables())[j].getTableName() == tableName)
				{
					return (databasees[i].getTables())[j].getColumnCount();
				}
			}
			cout << "No such table!\n";
			return -1;
		}
	}
	cout << "No such database!\n";
	return -1;
}
