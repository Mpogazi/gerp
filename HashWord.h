#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <functional>


using namespace std;

#ifndef HASHWORD_H
#define HASHWORD_H

class HashWord
{
	public:
		HashWord();
		HashWord(string word);

		void insert(string, int);
		size_t hash_value() const;
		void set_word(string);
		void print();
		string get_filename();
		int get_line();

		// Overriding the operators.
		friend bool operator == (const HashWord &, const HashWord &);
    	friend bool operator != (const HashWord &, const HashWord &);
	private:
		string word;
		string filename;
		int line;
};

#endif