#pragma once

#include"Token.h"
#include"Tag.h"

using namespace std;

class Word :public Token {
public:
	 string lexeme;    //  把lexeme声明为private会报很多错误，不知为什么
	 string getLexeme() { return lexeme; }
	 Word(){}
	 Word(string s, int tag):Token(tag) {  lexeme = s; }

	 static const Word select, Delete, insert, update, Not, null, into, value, values, from, create, drop, table, database, set, equal, mt, lt, le, ge, nq, lpa, rpa, smc, cma, dot, udl, Int, Float, Char, varchar;

	/*    之前的设计  运行时有内存管理错误 
	~Word()
	 {
		delete select, Delete, insert, update, Not, null, into, value, values,from ,create ,drop ,table ,database ,set ,equal ,mt ,lt ,le ,ge ,nq ,lpa ,rpa ,smc ,cma ,dot , udl,Int,Float,Char,varchar ;
	 }
	 const Word* select = new Word("select", Tag::SELECT);
	 const Word* Delete = new Word("delete", Tag::DELETE);
	 const Word* insert = new Word("insert", Tag::INSERT);
	 const Word* update = new Word("update", Tag::UPDATE);
	 const Word * Not= new Word("not", Tag::NOT);
	 const Word* null = new Word("null", Tag::Null );
	 const Word* into = new Word("into", Tag::INTO );
	 const Word* value = new Word("value", Tag::VALUE );
	 const Word* values = new Word("values", Tag::VALUES );
	 const Word* from = new Word("from", Tag::FROM);
	 const Word* create = new Word("create", Tag::CREATE );
	 const Word* drop = new Word("drop", Tag::DROP);
	 const Word* table = new Word("table", Tag::TABLE );
	 const Word* database = new Word("database", Tag::DATABASE );
	 const Word* set = new Word("set", Tag::SET );
	 const Word* equal = new Word("=", Tag::EQUAL );
     const Word* mt = new Word(">", Tag::MT);
	 const Word*lt = new Word("<", Tag::LT);
     const Word*le = new Word("<=", Tag::LE);
	 const Word*ge = new Word(">=",Tag::GE );
	 const Word*nq = new Word("<>",Tag::NQ);
	 const Word*lpa = new Word("(", Tag::LPA);
	 const Word*rpa = new Word(")", Tag::RPA);
	 const Word*smc = new Word(";", Tag::SMC);
	 const Word*cma = new Word(",", Tag::CMA);
	 const Word*dot = new Word(".", Tag::DOT);
	 const Word*udl = new Word("_", Tag::UDL);
	 const Word*Int = new Word("int", Tag::INT);
	 const Word*Float = new Word("float", Tag::FLOAT);
	 const Word*Char = new Word("char", Tag::CHAR);
	 const Word*varchar = new Word("varchar", Tag::VARCHAR);   */
};

//   static const Word* select;    //  这句写在类里面
//   const Word* Word::select = new Word("select", Tag::SELECT);   // 声明成static， 运行不通过

