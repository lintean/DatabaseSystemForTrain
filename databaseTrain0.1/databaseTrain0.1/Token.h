#pragma once
#include<string>

class Token
{
private:
	int tag;  //  �൱��һ���������ڴ�����ʱ������ֵ
public:
	Token(){}
	Token(int t) { tag = t; }
	//~Token(){}
	int getTag() { return tag; }
   // string toString() { return "" + (char)tag; }	
};

