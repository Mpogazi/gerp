#include "Index.h"
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
void process(string &word);

int main(int argc, char *argv[]) 
{
	if(argc != 2) 
	{
		cerr << "USAGE: ./the_index filename\n";
		return -1;
	}

	auto start = chrono::system_clock::now();
	Index the_gerp(argv[1]);
	auto end = chrono::system_clock::now();
	chrono::duration<double> elapsed = end - start;
    cout << "elapsed time: " << elapsed.count() << endl;
    
    string query;
    while(!cin.eof()) 
    {
    	cout << "Query?";
    	cin >> query;
    	process(query);
    	the_gerp.find(query);
    }

	return 0;
}

void process(string &word) 
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
}
