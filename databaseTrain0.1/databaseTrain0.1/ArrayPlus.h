#pragma once
#include<string>
using namespace std;
template <typename T>
class ArrayPlus
{
private:
	T * array;
	int currentLength;
	int maxLength;
public:
	ArrayPlus();
	ArrayPlus(T* currentArray);
	T getContent(int index);
	bool addContent(T* content);
	bool deleteContent(int index);
};