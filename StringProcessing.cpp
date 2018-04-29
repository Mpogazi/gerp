#include "StringProcessing.h"

using namespace std;

StringProcessing::StringProcessing() 
{

}

StringProcessing::~StringProcessing() 
{


}

string StringProcessing::process(string &word) 
{
	bool done = false;
	while(!done) 
	{
		// Checking for purely non alnum string
		if(word.length() == 0)
			break;

		char end = word[word.length() - 1], 
							begining = word[0];
		// Checking for end
		if(isalnum(begining)&&isalnum(end))
			done = true;
		else if(!isalnum(begining)) 
			word.erase(0, 1);
		else if(!isalnum(end)) 
			word.erase(word.length() - 1, 1);
	}
	return word;
}