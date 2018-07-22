#include "Lexer.h"

Lexer::Lexer(string filepath)  //  filepath �������ı��ļ�·��Ҳ������sql���
{
	line = 0; // ����

	fstream read(filepath, ios::in);
	if (read.fail())
	{
		sql = filepath;  // �������Ĳ����ļ�·����ֱ�ӵ���һ��sql��䴦��
	}
	else  //  �ɹ����ļ�����ȡ�ļ�
	{
		while (read.get(peek))
		{
			sql += peek;
		}
	}
	peek = ' ';   //  �ǵû�ԭpeek ������
	read.close();
	
	// ���ؼ��ּ����ϣ��
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
	if (ith == sql.length())   //   ɨ����ϣ���peekΪ !
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

// ɨ����һ������ؼ��֡���ʶ���������֣�
string Lexer::getATerm()
{
	if (peek == '!')
		return "";  // ɨ����ϣ����ؿ�ֵ
	string term = "";
	while ((peek>='0'&&peek<='9')||(peek>='a'&&peek<='z')||(peek>='A'&&peek<='Z')||peek=='_')
	{
		term += peek;
		readch();
	}
	return term;
}

// �ж�ɨ��õ���һ������term �ǲ��Ǵ�����
bool Lexer::IsANumber(string term)
{
	for (int i = 0; i < term.length(); i++)
	{
		if (term.at(i) > '9' || term.at(i) < '0')
			return false;
	}
	return true;
}

// �ж��ǲ��Ǻ���ı�ʶ��
bool Lexer::IsAIdentifier(string term)
{
	// ��ʶ�������Ǹ�������
	if (IsANumber(term))
		return false;

	// ����ȫ�����»���
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
	// ���Կ�ʼ�Ŀո�ȿ������ķ���
	for (;; readch()) 
	{
		if (peek == ' ' || peek == '\t' || peek == '\r') continue;
		else if (peek == '\n') line = line + 1;
		else break;
	}

	// �������
	switch (peek) {
		case '=':
			peek = ' ';
			handleNumber = true;  // �������ź�����ܴ�����
			 return Word::equal;
		case '<':
			handleNumber = true;  // �������ź�����ܴ�����
			if (readch('>')) return  Word::nq;
			else if (peek=='=') return  Word::le;
			else {	return  Word::lt;	}
		case'>':
			handleNumber = true;  // �������ź�����ܴ�����
			if (readch('=')) return  Word::ge;
			else {  return  Word::mt; }
		case'(':
			peek = ' ';
			handleNumber = true;  // �������ź�����ܴ�����
			return  Word::lpa;
		case')':
			peek = ' ';
			handleNumber = false; //  �������ź��治�����̽��ܴ�����
			return  Word::rpa;
		case'.':
			peek = ' ';
			return  Word::dot;
		case',':
			peek = ' ';
			handleNumber = false; //  �������ź��治�����̽��ܴ�����
			return  Word::cma;
		case';':
			peek = ' ';
			handleNumber = false; //  �������ź��治�����̽��ܴ�����
			return  Word::smc;
	}

	string term = getATerm(); // ��һ����

	// ɨ�赽һ�������ҵ�ǰ����һ��������
	if (IsANumber(term)&&handleNumber)
	{
		return Word(term, Tag::NUMBER);
	}

	hash_map<string, Word>::iterator tempKeyword = words.find(term);  //  �� �ؼ��ֹ�ϣ�� ����� term �����
	if (tempKeyword != words.end()) // �� �ؼ��ֹ�ϣ�� ���ҵ���term��˵��term�ǹؼ���
	{
		return words[term];
	}
	else if (IsAIdentifier(term))  // �Ǻ���ı�ʶ��
	{
		hash_map<string, Word>::iterator tempIdentifier = Identifiers.find(term);  //  �� ��ʶ����ϣ�� ����� term �����
		if (tempIdentifier == Identifiers.end())  //  �� ��ʶ����ϣ�� ��û�ҵ�term����ǰ�����������ʶ������term������ʶ������
			Identifiers[term] = Word(term, Tag::IDENTIFIER);   //  �½�һ����ʶ��
		return Identifiers[term];
	}
	else if (term == "")           //  ��ȡ��ϣ������˳�
		return Word("", Tag::EXIT);
	else
	{
		cout << "�Ƿ����룬���޷�ʶ���"<<line<<"�е�: "<<term<<endl;
		return Word(term, Tag::ERROR);
	}
}
