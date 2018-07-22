#include "Lexer.h"

Lexer::Lexer(string filepath)  //  filepath 可以是文本文件路径也可以是sql语句
{
	line = 0; // 行数

	fstream read(filepath, ios::in);
	if (read.fail())
	{
		sql = filepath;  // 如果输入的不是文件路径，直接当做一条sql语句处理
	}
	else  //  成功打开文件，读取文件
	{
		while (read.get(peek))
		{
			sql += peek;
		}
	}
	peek = ' ';   //  记得还原peek ！！！
	read.close();
	
	// 将关键字加入哈希表
	words["select"] = Word::select;
	words["delete"] = Word::Delete;
	words["insert"] = Word::insert;
	words["update"] = Word::update;
	words["not"] = Word::Not;
	words["null"] = Word::null;
	words["into"] = Word::into;
	words["value"] = Word::value;
	words["values"] = Word::values;
	words["from"] = Word::from;
	words["create"] = Word::create;
	words["drop"] = Word::drop;
	words["table"] = Word::table;
	words["database"] = Word::database;
	words["set"] = Word::set;
	words["="] = Word::equal;
	words[">"] = Word::mt;
	words["<"] = Word::lt;
	words["<="] = Word::le;
	words[">="] = Word::ge;
	words["<>"] = Word::nq;
	words["("] = Word::lpa;
	words[")"] = Word::rpa;
	words[";"] = Word::smc;
	words[","] = Word::cma;
	words["."] = Word::dot;
	words["_"] = Word::udl;
	words["int"] = Word::Int;
	words["float"] = Word::Float;
	words["char"] = Word::Char;
	words["varchar"] = Word::varchar;
}

Lexer::~Lexer()
{
}

void Lexer::readch()
{
	if (ith == sql.length())   //   扫描完毕，置peek为 !
	{
		peek = '!';
		return;
	}
	peek = sql.at(ith);
	ith++;
}

bool Lexer::readch(char c)
{
	readch();
	if (peek == c) { peek = ' '; return true; }
	return false;
}

// 扫描获得一个词语（关键字、标识符、纯数字）
string Lexer::getATerm()
{
	if (peek == '!')
		return "";  // 扫描完毕，返回空值
	string term = "";
	while ((peek>='0'&&peek<='9')||(peek>='a'&&peek<='z')||(peek>='A'&&peek<='Z')||peek=='_')
	{
		term += peek;
		readch();
	}
	return term;
}

// 判断扫描得到的一个词语term 是不是纯数字
bool Lexer::IsANumber(string term)
{
	for (int i = 0; i < term.length(); i++)
	{
		if (term.at(i) > '9' || term.at(i) < '0')
			return false;
	}
	return true;
}

// 判断是不是合理的标识符
bool Lexer::IsAIdentifier(string term)
{
	// 标识符不能是个纯数字
	if (IsANumber(term))
		return false;

	// 不能全部是下划线
	bool ALLisUnderline = true;
	for (int i = 0; i < term.length(); i++)
	{
		if (term.at(i) != '_') { ALLisUnderline = false; break; }
	}
	if (ALLisUnderline) return false;

	return true;
}

Word Lexer::scan()
{
	// 忽略开始的空格等看不见的符号
	for (;; readch()) 
	{
		if (peek == ' ' || peek == '\t' || peek == '\r') continue;
		else if (peek == '\n') line = line + 1;
		else break;
	}

	// 处理符号
	switch (peek) {
		case '=':
			peek = ' ';
			handleNumber = true;  // 在左括号后面接受纯数字
			 return Word::equal;
		case '<':
			handleNumber = true;  // 在左括号后面接受纯数字
			if (readch('>')) return  Word::nq;
			else if (peek=='=') return  Word::le;
			else {	return  Word::lt;	}
		case'>':
			handleNumber = true;  // 在左括号后面接受纯数字
			if (readch('=')) return  Word::ge;
			else {  return  Word::mt; }
		case'(':
			peek = ' ';
			handleNumber = true;  // 在左括号后面接受纯数字
			return  Word::lpa;
		case')':
			peek = ' ';
			handleNumber = false; //  在右括号后面不再立刻接受纯数字
			return  Word::rpa;
		case'.':
			peek = ' ';
			return  Word::dot;
		case',':
			peek = ' ';
			handleNumber = false; //  在右括号后面不再立刻接受纯数字
			return  Word::cma;
		case';':
			peek = ' ';
			handleNumber = false; //  在右括号后面不再立刻接受纯数字
			return  Word::smc;
	}

	string term = getATerm(); // 读一个词

	// 扫描到一个数并且当前接受一个纯数字
	if (IsANumber(term)&&handleNumber)
	{
		return Word(term, Tag::NUMBER);
	}

	hash_map<string, Word>::iterator tempKeyword = words.find(term);  //  在 关键字哈希表 里查找 term 这个词
	if (tempKeyword != words.end()) // 在 关键字哈希表 里找到了term，说明term是关键字
	{
		return words[term];
	}
	else if (IsAIdentifier(term))  // 是合理的标识符
	{
		hash_map<string, Word>::iterator tempIdentifier = Identifiers.find(term);  //  在 标识符哈希表 里查找 term 这个词
		if (tempIdentifier == Identifiers.end())  //  在 标识符哈希表 里没找到term，当前不存在这个标识符，把term当做标识符处理
			Identifiers[term] = Word(term, Tag::IDENTIFIER);   //  新建一个标识符
		return Identifiers[term];
	}
	else if (term == "")           //  读取完毕，正常退出
		return Word("", Tag::EXIT);
	else
	{
		cout << "非法输入，我无法识别第"<<line<<"行的: "<<term<<endl;
		return Word(term, Tag::ERROR);
	}
}
