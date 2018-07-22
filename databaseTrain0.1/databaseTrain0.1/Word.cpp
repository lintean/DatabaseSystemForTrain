#include"Word.h"

// 下面的赋值放在头文件里会出错！
const Word Word::select("select", Tag::SELECT);
const Word Word::Delete("delete", Tag::DELETE);
const Word Word::insert("insert", Tag::INSERT);
const Word Word::update("update", Tag::UPDATE);
const Word Word::Not("not", Tag::NOT);
const Word Word::null("null", Tag::Null);
const Word Word::into("into", Tag::INTO);
const Word Word::value("value", Tag::VALUE);
const Word Word::values("values", Tag::VALUES);
const Word Word::from("from", Tag::FROM);
const Word Word::create("create", Tag::CREATE);
const Word Word::drop("drop", Tag::DROP);
const Word Word::table("table", Tag::TABLE);
const Word Word::database("database", Tag::DATABASE);
const Word Word::set("set", Tag::SET);
const Word Word::equal("=", Tag::EQUAL);
const Word Word::mt(">", Tag::MT);
const Word Word::lt("<", Tag::LT);
const Word Word::le("<=", Tag::LE);
const Word Word::ge(">=", Tag::GE);
const Word Word::nq("<>", Tag::NQ);
const Word Word::lpa("(", Tag::LPA);
const Word Word::rpa(")", Tag::RPA);
const Word Word::smc(";", Tag::SMC);
const Word Word::cma(",", Tag::CMA);
const Word Word::dot(".", Tag::DOT);
const Word Word::udl("_", Tag::UDL);
const Word Word::Int("int", Tag::INT);
const Word Word::Float("float", Tag::FLOAT);
const Word Word::Char("char", Tag::CHAR);
const Word Word::varchar("varchar", Tag::VARCHAR);