#include "TextQuery.h"
#include "QueryResult.h"
#include <sstream>

//通过ifstream构造TextQuery
TextQuery::TextQuery(std::ifstream& ifs)
:file(new std::vector<std::string>)
{
    std::string text;
    while(std::getline(ifs,text))
    {
	//压入一行的内容
        file->push_back(text);
        
        int n=file->size()-1; //行号

        //文本分解为单词
        std::istringstream line(text);
        std::string word;
        while(line>>word)
        {
            auto &lines=wm[word];//lines是一个shared_ptr

            //不存在则将lines指向一个新建的set
            if(!lines)
                lines.reset(new std::set<line_no>);
            
            //插入行号
            lines->insert(n);
        }

    }
}

QueryResult TextQuery::query(const std::string& sought) const
{
    //如果未找到sought，则h返回一个指向该set的指针
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    //使用find而不是下标，以免添加元素
    auto loc=wm.find(sought);
    if(loc==wm.end())
        return QueryResult(sought,nodata,file);
    else
    {
        return QueryResult(sought,loc->second,file);
    }
    
}
