#pragma once
#include<string>
using namespace std;
class Row
{

private:
	string* data;  //�е�����

public:
	Row(string* rowData);

	string getCell(int index);
	bool setCell(int index, string cellContent);
};