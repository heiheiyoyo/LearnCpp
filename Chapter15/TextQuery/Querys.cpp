#include <algorithm>
#include "Querys.h"


//返回两个运算对象查询结果的并集
QueryResult OrQuery::eval(const TextQuery &text) const
{
    using namespace std;
    
    //通过Query成员lhs和rhs进行的虚调用
    //调用eval返回每个运算对象的QueryResult
    auto right=rhs.eval(text),left=lhs.eval(text);
    //将左侧运算对象的行号拷贝到结果set中
    auto ret_lines = make_shared<set<line_no>>(left.begin(),right.end());
    //插入右边对象的所得行号
    ret_lines->insert(right.begin(),right.end());
    //返回一个新的QueryResult，表示并集
    return QueryResult(rep(),ret_lines,left.get_file());
}

QueryResult AndQuery::eval(const TextQuery& text) const
{
    using namespace std;
    auto left=lhs.eval(text),right=rhs.eval(text);
    //创建临时对象保存结果
    auto ret_lines = make_shared<set<line_no>>(left.begin(),right.end());
    //标准库算法，求交集
    set_intersection(left.begin(),left.end(),right.begin(),right.end(),inserter(*ret_lines,ret_lines->begin()));
    return QueryResult(rep(),ret_lines,left.get_file());
    
}

QueryResult NotQuery::eval(const TextQuery &text) const
{
    using namespace std;
    
    auto result=query.eval(text);
    auto ret_lines=make_shared<set<line_no>>();
    auto beg=result.begin(),end=result.end();
    //对于输入文件的每一行，如果改行不在result中，则添加到ret_lines
    auto sz=result.get_file()->size();
    for(size_t n=0;n!=sz;++n)
    {
        if(beg==end||*beg!=n)
            ret_lines->insert(n); //不在result中，则添加这一行
        else if(beg!=end)
            ++beg;//先增加n，再增加beg
    }
    return QueryResult(rep(),ret_lines,result.get_file());
}