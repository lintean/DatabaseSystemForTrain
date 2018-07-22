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
	int line;                            // ��������
	char peek = ' ';                   // ����һ���ַ�
	bool handleNumber = false;   //  ��ǰ�����ܴ����� ���������š����ںš�С�ںŵȷ��ŵĺ���Ž��ܴ����֣�
									     //  ��ȻԲ���ź��滹�������������������Ѿ����Ա�֤�������Ǵ�������
	int ith = 0;                       // ���ڼ�¼��ǰ������sql����λ��
	string sql="";                     // �洢���ı�������������Ҫִ�е�sql���
	hash_map<string, Word> Identifiers;       // �洢��ʶ��
	hash_map<string, Word> words;

	string getATerm();             // ɨ����һ������ؼ��֡���ʶ���������֣�
	bool IsANumber(string term);
	bool IsAIdentifier(string term);            // �ж��Ƿ��Ǻ���ı�ʶ��
public:
	Lexer(string filepath);        // �����ļ�·�������ļ�
	~Lexer();
	int getLine() { return line; }
	string getSQLStatement() { return sql; }
	void readch();
	bool readch(char c);
	Word scan();
};

