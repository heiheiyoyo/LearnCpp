#ifndef _QUERYS_H_
#define _QUERYS_H_

#include "Query.h"

class WordQuery :public Query_base
{
    friend class Query;
    WordQuery(const std::string &s):query_word(s){}
    QueryResult eval(const TextQuery &t) const
    {
        return t.query(query_word);
    }
    std::string rep() const
    {
        return query_word;
    }
    std::string query_word;
};

class NotQuery :public Query_base
{
    friend Query operator~(const Query &);
    NotQuery(const Query &q): query(q) {}
    std::string rep() const override {return "~(" + query.rep()+")";}
    QueryResult eval(const TextQuery&) const override;
    Query query;
};


class BinaryQuery :public Query_base
{
protected:
    BinaryQuery(const Query &l,const Query &r,std::string s)
            :lhs(l),rhs(r),opSym(s) {}
    //抽象类：BinaryQuery不定义eval
    std::string rep() const
    {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs,rhs;//左侧和右侧的运算对象
    std::string opSym; //运算符的名字
};

class AndQuery :public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left,const Query &right):
	BinaryQuery(left,right,"&") {}
    QueryResult eval(const TextQuery&) const;
};

class OrQuery :public BinaryQuery
{
    friend Query operator|(const Query&,const Query&);
    OrQuery(const Query &left,const Query &right):
	BinaryQuery(left,right,"|") {}
    QueryResult eval(const TextQuery&) const;
};

inline
Query::Query(const std::string &s): q(new WordQuery(s)) { }



inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

inline Query operator&(const Query &lhs,const Query &rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}


inline Query operator|(const Query &lhs,const Query &rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}

#endif