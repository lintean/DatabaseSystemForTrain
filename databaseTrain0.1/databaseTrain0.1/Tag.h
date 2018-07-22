#pragma once

class Tag
{
public:
	static const int SELECT = 1, DELETE = 2, INSERT = 3, UPDATE = 4, NOT = 5, Null = 6,
		INTO = 7, VALUE = 8, VALUES = 9, FROM = 10, CREATE = 11, DROP = 12,
		TABLE = 13, DATABASE = 14, SET = 15, EQUAL = 16, MT = 17, LT = 18, LE = 19, GE = 20, NQ = 21,/* MT 大于  LT 小于  LE 小于等于  GE 大于等于  NQ 不等于*/
		LPA = 22, RPA = 23, SMC = 24, CMA = 25, DOT = 26, UDL =27,  /* LPA左括号    RPA右括号    SMC分号   CMA逗号   DOT小数点   UDL下划线 */
		INT = 28, FLOAT = 29, VARCHAR = 30, CHAR = 31;
	static const int IDENTIFIER = 100;  // 标识符，可能是数据库名，表名，列名  
	static const int NUMBER = 101;     // 数字
	static const int EXIT = 0;              // 正常退出
	static const int ERROR = -1;         // 出现错误才会用到 
};