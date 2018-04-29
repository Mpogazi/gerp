#include "Index.h"
#include <sstream>
#include <fstream>

using namespace std;

Index::Index(string file) 
{
	path = file;
	directory = FSTree(file);
	root = directory.get_root();
	read_dir(root, path);
}

// Function: index()
// Params: DirNode *
// Deos: Reads all files in a directory
void Index::read_dir(DirNode *directory, string path) 
{
	int count = directory->num_subdirs(),
				files = directory->num_files();
	if(count > 0)
		for(int i = 0; i < count; i++) 
		{
			DirNode *curr = directory->get_subdir(i);
			string name = curr->get_name();
			read_dir(curr, (path + "/" + name));
		}
	for(int i = 0; i < files; i++) 
	{
		string file_path = path + "/"+ directory->get_file(i);
		read_file(file_path);
	}
}

// Function: read_file
// Params: path
// Does: Reads a file and store each word in hashTable
void Index::read_file(string path) 
{
	ifstream infile;
	int line_number = 1;
	infile.open(path);
	if(!infile.is_open()) 
	{
		cout << "path: " << path << endl;
		cerr << "Cannot open file\n";
		exit(-1);
	}

	while(!infile.eof()) 
	{
		string line;
		getline(infile, line);
		stringstream ss(line);
		string temp_word;
		while(ss >> temp_word) 
		{
			HashWord temp_hash(temp_word);
			temp_hash.insert(path, line_number);
			indices.insert(temp_hash);
		}
		line_number++;
	}	
	infile.close();
}

void Index::find(string word) 
{
	bool found = false;
	indices.find(word, found);
}


