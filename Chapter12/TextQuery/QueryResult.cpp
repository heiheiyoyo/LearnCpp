#include "QueryResult.h"



std::ostream& operator<<(std::ostream& os,const QueryResult& qr)
{
    std::string time("time");
    if(qr.lines->size()>1)
    {
        time+="s";
    }
    os<<qr.sought<<" occurs "<<qr.lines->size()<<" "
    <<time<<std::endl;
    for(auto num: *(qr.lines))
    {
        os<<"\t(line "<<num+1<<") "<<*(qr.file->begin()+num)<<std::endl;
    }
    return os;
}