#pragma once
#include <hash_map>
#include<string>
#include<iostream>
#include"Tag.h"
#include"Token.h"

using namespace std;

class Lexer
{
private:
	static int line;
	char peek = ' '; //¶ÁÈëÒ»¸ö×Ö·û
	hash_map<string, Tag> word;
	istream read;
public:
	Lexer(istream r);
	void readch();
	bool readch(char c);
	Token scan();

	~Lexer();
};

