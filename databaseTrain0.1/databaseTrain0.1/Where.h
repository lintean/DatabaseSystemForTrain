#pragma once
#include<string>
using namespace std;
class Where
{
private:
	string columnName;
	string value;
public:
	Where(string wherColumnName, string whereValue);

	string getWhereColumnName();
	string getWhereValue();

};