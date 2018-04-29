#include <iostream>
#include <list>
#include <fstream>
#include "HashWord.h"

#ifndef HASH_H_
#define HASH_H_

const int MAX_ITEMS = 100000;

class Hash
{
public:
    Hash();

    bool is_full() const;
    bool is_empty() const;

    void find(HashWord, bool &);
    void insert(HashWord);
    string return_line(string, int);
    
private:
    int length;
    std::list<HashWord> info[MAX_ITEMS];
};

#endif
