#pragma once
#include<string>
#include"Column.h"
#include"Row.h"
#include"ArrayPlus.h"
using namespace std;
class Table
{
private:
	string tableName;  //����
	int columnCount;  //�еĸ���
	int rowCount;  //�ñ�ǰ�еĸ���
	Column* column;  //������
	ArrayPlus<Row> row; //������
public:
	Table();  //Ĭ�Ϲ��캯��
	Table(string name);
	Table(string name,int colCount, Column* col);

	bool setTableName(string);
	string getTableName();

	bool setColumnCount(int c);  //����֮ǰ���rowCount�Ƿ�Ϊ��
	int getColumnCount();

	int getRowCount();

	bool addRow(Row*);
	bool deleteRow(int rowIndex);

	void showTable();

};