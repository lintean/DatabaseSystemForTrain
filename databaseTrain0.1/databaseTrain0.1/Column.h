#pragma once
#include<string>
using namespace std;

enum type{ varchar };

class Column
{
private:
	bool primaryKey;  //主码标识
	string columnName;  //列名
	type columnType; //列的类型
	bool allowNull;  //是否允许为空
	int length;  //列值的长度
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