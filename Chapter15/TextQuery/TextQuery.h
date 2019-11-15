#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>

class QueryResult;

class TextQuery 
{
    
public:
    //行号类型
    using line_no=std::vector<std::string>::size_type;
    //传入需要读取的ifstream
    TextQuery(std::ifstream& ifs);
    //查询指定单词
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> file;

    //每个单词到它所在行号的集合的映射 即string->{行号}
    std::map<std::string,std::shared_ptr<std::set<line_no>>> wm;
};

#endif
