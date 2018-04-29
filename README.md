### PURPOSE OF THE PROGRAM:
* Search a word from files

### ACKNOWLEDGEMENTS:
* A huge amount of support from Suarav Gyawali with the design
* Collaboration with Ebere Justin on debugging and parts of design

### FILES:

*DirNode.cpp && DirNode.h:
        - Finds the files in a director
*FSTree.cpp && FSTree.h:
        - Builds a file structure tree
*Hash.cpp && Hash.h:
        - Builds a HashTable of linkedlists containing HashWords
*HashWord.cpp && HashWord.h:
        - Contains word to hash, filename, line, and lowercase of word
*Index.cpp && Index.h:
        - Iterates to the provided file path and creates an index for the file
*Main.cpp:
        - Calls Index object and allows the user to search the queries

### DATA STRUCTURES && ALGORITHMS:

*Hash table:
        - This program uses a hash table to index every word in the files
*List:
        - This program uses an stl list to solve collisions in a hashtable

*** Algorithms:
        - The program reads a file and store every word in a hash table with the line and filename
        - After storing the program accepts a query from the user hence finding the word in the hashtable

### TEST:
        - Created outer programs to test this program
        - Ran it against the provided gutenBerg files.

### AUTHOR:
        -- FABRICE BIGABIRO MPOGAZI
