#include <iostream>
#include <string>
#include <cctype>

using namespace std;

#ifndef STRINGPROCESSING_H
#define STRINGPROCESSING_H

class StringProcessing
{
public:
	StringProcessing();
	~StringProcessing();
	string process(string &);	
};

#endif