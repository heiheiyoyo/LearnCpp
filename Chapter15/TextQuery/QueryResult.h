#ifndef _QUERYRESULT_H_
#define _QUERYRESULT_H_

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>
#include "TextQuery.h"

class QueryResult
{
    friend std::ostream& operator<<(std::ostream&,const QueryResult&);
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    typedef std::set<TextQuery::line_no>::iterator line_it;
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::line_no>> p,
                std::shared_ptr<std::vector<std::string>> f)
        : sought(s), lines(p), file(f)
    {}

    line_it begin(){return lines->begin();}
    line_it end(){return lines->end();}
    std::shared_ptr<std::vector<std::string>> get_file(){return file;}


private:
    std::string sought;//查询的单词
    std::shared_ptr<std::set<TextQuery::line_no>> lines; //行号的集合
    std::shared_ptr<std::vector<std::string>> file;
};



inline
std::string make_plural(std::size_t ctr, const std::string &word, 
                               const std::string &ending)
{
	return (ctr > 1) ? word + ending : word;
}


std::ostream &print(std::ostream & os, const QueryResult &qr);

#endif
