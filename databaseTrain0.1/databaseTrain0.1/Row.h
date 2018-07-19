#pragma once
#include<string>
using namespace std;
class Row
{

private:
	string* data;  //ĞĞµÄÄÚÈİ

public:
	Row(string* rowData);

	string getCell(int index);
	bool setCell(int index, string cellContent);
};