#pragma once
#include<string>
using namespace std;

enum type{ varchar };

class Column
{
private:
	bool primaryKey;  //�����ʶ
	string columnName;  //����
	type columnType; //�е�����
	bool allowNull;  //�Ƿ�����Ϊ��
	int length;  //��ֵ�ĳ���
public:
	Column(string colName, type colType, int colLength, bool colPrimaryKey, bool colAllowNull);

	bool setColumnName(string colName);
	string getColumnName();

	bool getPrimaryKey();
	bool setPrimaryKey(bool colPrimaryKey);

	bool getAllowNull();
	bool setAllowNull(bool colAlloeNull);

	type getColumnType();
	bool setColumnType(type colType);

	int getLength();
	bool setLength(int colLength);
};