#include "HashWord.h"

using namespace std;

HashWord::HashWord() 
{
	word = "";
}

// Parametrized constructor
HashWord::HashWord(string word) 
{
	this->word = word;
}

// Getters
string HashWord::get_filename() 
{
	return filename;
}

int HashWord::get_line() 
{
	return line;
}


// Function: add_location
// params: location
// Does: adds a location to locations vector
void HashWord::insert(string filename, int line) 
{
	this->filename = filename;
	this->line = line;

}

// Overloaded operators
bool operator == (const HashWord &h1, const HashWord &h2) 
{
	return (h1.word == h2.word);
}

bool operator != (const HashWord &h1, const HashWord &h2) 
{
	return (h1.word != h2.word);
}

// Returns the hash_value of the word
size_t HashWord::hash_value() const 
{
	hash<string> str_hash;
	return str_hash(word);
}

// Function: find()
// Params: none
// Returns: nothing
// Does: Print a line and the file_name
void HashWord::print() 
{
    cout << filename << " " << line << ": ";
}









