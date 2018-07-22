#pragma once
#include<string>

class Token
{
private:
	int tag;  //  相当于一个常量，在创建类时即被赋值
public:
	Token(){}
	Token(int t) { tag = t; }
	//~Token(){}
	int getTag() { return tag; }
   // string toString() { return "" + (char)tag; }	
};

