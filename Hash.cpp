/*
 * HashTable.cpp
 * 
 * Implementation for Hash Table class
 *
 * COMP15
 * Spring 2018
 *
 * What hash you done??
 *
 */

#include <string>
#include "Hash.h"
using namespace std;

// Default constructor
Hash::Hash()
{
    length = 0;
}

// Function is_full(), const
// Parameters: none
// Returns: bool
// Does: Checks if array (static) is full
bool Hash::is_full() const
{
    return (length == MAX_ITEMS);
}

// Function is_empty(), const
// Parameters: none
// Returns: bool
// Does: Checks if array is emtpy
bool Hash::is_empty() const 
{
    return (length == 0);
}

// Function: find
// Parameters: Hashword, bool
// Returns: nothing
// Does: 
void Hash::find(HashWord item, bool &found)
{
    size_t location = item.hash_value() % MAX_ITEMS;
    list<HashWord>::iterator i;
    found = false;
    HashWord temp = item;
    string filename;
    int line_number;
    string line;
    if(info[location].size() != 0) 
    {
        for(i = info[location].begin(); i != info[location].end(); i++) 
        {
            if(*i == temp) 
            {
                filename = i->get_filename();
                line_number = i->get_line();
                line = return_line(filename, line_number);
                i->print();
                cout << line << endl;
                found = true;
            }
        }
    }
    if(!found) 
    {
        cout << "Word not found \n";
    }
}

// Function: insert
// Parameters: HashWord
// Returns: nothing
// Does: Gets the hash value of the given item.
//       If that position is available, insert the item.
//       If not, insert the item at the next open slot,
//       using linear probing. Counts and returns the number
//       of spaces we check before we can insert.
void Hash::insert(HashWord item)
{
    size_t location = item.hash_value() % MAX_ITEMS;
    info[location].push_back(item);
    length++;
}

// Function: return_line
// Params: filename, line
// Returns: string
// Does: Opens a file and returns a line
string Hash::return_line(string filename, int line) 
{
    ifstream infile;
    infile.open(filename.c_str());
    if(infile.fail())
     cerr << "Can't open\n";
    int count = 1;
    string s;
    while(!infile.eof()) 
    {
        getline(infile, s);
        if(count == line)
            break;
        count++;
    }
    infile.close();
    return s;
}
