#ifndef _QUERY_H_
#define _QUERY_H_

#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>


//Query接口
class Query_base {
    friend class Query;
protected:
    using line_no=TextQuery::line_no;
    virtual ~Query_base()=default;
private:
    //接受TextQuery对象并返回QueryResult，使用给定的TextQuery来查找与之匹配的行
    virtual QueryResult eval(const TextQuery&) const =0;
    //返回基础查询的string表示形式
    virtual std::string rep() const =0;
};

//工具类，保存Query_base的指针
class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &,const Query &);
    friend Query operator&(const Query &,const Query &);
public:
    Query(const std::string &);
    QueryResult eval(const TextQuery &t) const
    {
        return q->eval(t);
    }
    std::string rep() const
    {
        return q->rep();
    }
private:
    Query(std::shared_ptr<Query_base> query) :q(query){}
    std::shared_ptr<Query_base> q;
};


inline std::ostream & operator<<(std::ostream &os,const Query &query)
{
    return os<<query.rep();
}

#endif
