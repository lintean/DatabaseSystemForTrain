#pragma once

class Tag
{
public:
	static const int SELECT = 1, DELETE = 2, INSERT = 3, UPDATE = 4, NOT = 5, Null = 6,
		INTO = 7, VALUE = 8, VALUES = 9, FROM = 10, CREATE = 11, DROP = 12,
		TABLE = 13, DATABASE = 14, SET = 15, EQUAL = 16, MT = 17, LT = 18, LE = 19, GE = 20, NQ = 21,/* MT ����  LT С��  LE С�ڵ���  GE ���ڵ���  NQ ������*/
		LPA = 22, RPA = 23, SMC = 24, CMA = 25, DOT = 26, UDL =27,  /* LPA������    RPA������    SMC�ֺ�   CMA����   DOTС����   UDL�»��� */
		INT = 28, FLOAT = 29, VARCHAR = 30, CHAR = 31;
	static const int IDENTIFIER = 100;  // ��ʶ�������������ݿ���������������  
	static const int NUMBER = 101;     // ����
	static const int EXIT = 0;              // �����˳�
	static const int ERROR = -1;         // ���ִ���Ż��õ� 
};