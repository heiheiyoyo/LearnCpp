#include "Querys.h"
#include "TextQuery.h"
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

void printStr(const string &s) {
	cout << s << " ";
}

void print(const vector<string> &words)
{
	for_each(words.begin(), words.end(), printStr);
	cout << endl;
}

bool get_word(string &s1)
{
    cout << "enter a word to search for, or q to quit: ";
    cin >> s1;
    if (!cin || s1 == "q") return false;
    else return true;
}

bool get_words(string &s1, string &s2)
{

    // iterate with the user: prompt for a word to find and print results
    cout << "enter two words to search for, or q to quit: ";
    cin  >> s1;

    // stop if hit eof on input or a "q" is entered
    if (!cin || s1 == "q") return false;
    cin >> s2;
    return true;
}


int main(int argc, char **argv)
{
    ifstream ifile("test.txt");
    TextQuery file(ifile);
    while (true) {
        string sought1, sought2, sought3;
        if (!get_words(sought1, sought2)) break;
        cout << "\nenter third word: " ;
        cin  >> sought3;
        // find all the occurrences of the requested string
        Query q = Query(sought1) & Query(sought2) 
                             | Query(sought3);
        cout << "\nExecuting Query for: " << q << endl;
        const QueryResult results = q.eval(file);
        // report matches
		print(cout, results);
     } 
     return 0;
}