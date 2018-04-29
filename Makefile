CC = clang++
CFLAGS = -Wall -Wextra -std=c++11 -c -O2
DEPS = HashWord.h Hash.h DirNode.h FSTree.h Index.h

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

the_index: main.o HashWord.o Hash.o DirNode.o FSTree.o Index.o
	$(CC) -o the_gerp main.o HashWord.o Hash.o DirNode.o FSTree.o Index.o

clean:
	rm -f *.o core* *~ test
