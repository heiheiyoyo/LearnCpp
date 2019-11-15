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

std::ostream &print(std::ostream & os, const QueryResult &qr)
{
    using namespace std;
    // if the word was found, print the count and all occurrences
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;

    // print each line in which the word appeared
	// for every element in the set 
    typedef std::set<TextQuery::line_no>::const_iterator lineIter;
	for (lineIter num = qr.lines->begin();
				num != qr.lines->end(); ++num) 
		// don't confound the user with text lines starting at 0
        os << "\t(line " << *num + 1 << ") " 
		   << *(qr.file->begin() + *num) << endl;
	return os;
}
