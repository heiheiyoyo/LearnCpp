#include "TextQuery.h"
#include "QueryResult.h"
#include <sstream>

TextQuery::TextQuery(std::ifstream& ifs)
:file(new std::vector<std::string>)
{
    std::string text;
    while(std::getline(ifs,text))
    {
        file->push_back(text);
        
        int n=file->size()-1; //行号

        //文本分解为单词
        std::istringstream line(text);
        std::string word;
        while(line>>word)
        {
            auto &lines=wm[word];

            //不存在则新建
            if(!lines)
                lines.reset(new std::set<line_no>);
            
            //插入行号
            lines->insert(n);
        }

    }
}

QueryResult TextQuery::query(const std::string& sought) const
{
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto loc=wm.find(sought);
    if(loc==wm.end())
        return QueryResult(sought,nodata,file);
    else
    {
        return QueryResult(sought,loc->second,file);
    }
    
}