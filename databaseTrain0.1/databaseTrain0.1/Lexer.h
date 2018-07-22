#pragma once
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1
#include<string>
#include<iostream>
#include<fstream>
#include<hash_map>
#include"Tag.h"
#include"Word.h"

using namespace std;

class Lexer
{
private:
	int line;                            // 代码行数
	char peek = ' ';                   // 读入一个字符
	bool handleNumber = false;   //  当前不接受纯数字 （在左括号、等于号、小于号等符号的后面才接受纯数字）
									     //  当然圆括号后面还可能是列名，但这样已经可以保证表名不是纯数字了
	int ith = 0;                       // 用于记录当前读到的sql语句的位置
	string sql="";                     // 存储从文本读下来的所有要执行的sql语句
	hash_map<string, Word> Identifiers;       // 存储标识符
	hash_map<string, Word> words;

	string getATerm();             // 扫描获得一个词语（关键字、标识符、纯数字）
	bool IsANumber(string term);
	bool IsAIdentifier(string term);            // 判断是否是合理的标识符
public:
	Lexer(string filepath);        // 输入文件路径，打开文件
	~Lexer();
	int getLine() { return line; }
	string getSQLStatement() { return sql; }
	void readch();
	bool readch(char c);
	Word scan();
};

