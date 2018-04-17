#include <iostream>
#include <string>
#include <cctype>
#include "DirNode.h"
#include "FSTree.h"

using namespace std;

int main() 
{
	string input;
	while(true) 
	{
		cout << ">>";
		cin >> input;
		bool done = false;
		while(!done) 
		{
			char end = input[input.length() - 1], begining = input[0];
			if(isalnum(begining)&&isalnum(end)) 
			{
				done = true;
			} else if(!isalnum(begining)) 
			{
				input.erase(0, 1);
			} else if(!isalnum(end)) 
			{
				input.erase(input.length() - 1, 1);
			}
		}
		cout << input << "\n\n";
	}
	return 0;
}