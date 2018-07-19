#pragma once
<<<<<<< HEAD
#include <string>
=======
#include<string>
>>>>>>> 8ce9253263a2efb29f36e8b87572c6848656020a
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