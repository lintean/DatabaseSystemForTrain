#pragma once
#include"Lexer.h"
#include"Token.h"
#include"Stmt.h"

class Parser
{
private:
	Lexer lex;
	Token look;

public:
	Parser(Lexer l);
	void move();
	void error(string s);
	void match();
	void program();

	Stmt stmts();
	Stmt stmt();
	~Parser();
};

