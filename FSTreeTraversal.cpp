#include <iostream>
#include <string>
#include "FSTree.h"
using namespace std;

void print_dir(DirNode *, string);
int main(int argc, char *argv[]) 
{
	if(argc != 2) 
	{
		cerr << "Usage: ./search [string]\n";
		return 1;
	}
	
	string path = argv[1];
	FSTree file_tree(path);
	DirNode * directory = file_tree.get_root();
	print_dir(directory, path);

	return 0;
}

void print_dir(DirNode *directory, string path) 
{
	int count = directory->num_subdirs(), 
			files = directory->num_files();
	if(count > 0)
		for (int i = 0; i < count; ++i)
		{
			DirNode *curr = directory->get_subdir(i);
			string name = curr->get_name();
			print_dir(curr, (path + "/" + name) );
		}

	for(int i = 0; i < files; i++)
		cout << path << "/" << directory->get_file(i) << endl;
	cout << path << endl;
}