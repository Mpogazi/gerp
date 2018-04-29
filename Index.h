#include "DirNode.h"
#include "FSTree.h"
#include "HashWord.h"
#include "Hash.h"

using namespace std;

#ifndef INDEX_H
#define INDEX_H

class Index
{
public:
	Index(string);
	void read_dir(DirNode *, string);
	void read_file(string);
	void find(string);
	
private:
	string path;
	DirNode * root;
	Hash indices;
	FSTree directory;

};

#endif