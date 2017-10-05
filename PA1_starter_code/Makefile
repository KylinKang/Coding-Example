# A simple makefile for CSE 100 P1

#use g++ for everything
CC= g++  	

# include debugging symbols in object files,
# and enable all warnings
FLAGS= -g -Wall -std=c++11

BSTHPP= BST.hpp BSTNode.hpp BSTIterator.hpp

all: main

bst: testBST.o $(BSTHPP)
	$(CC) $(FLAGS) -o bst testBST.o $(BSTHPP)

main: main.o $(BSTHPP)
	$(CC) $(FLAGS) -o main main.o $(BSTHPP)

main.o: $(BSTHPP)
	$(CC) $(FLAGS) -c main.cpp

testBST.o: testBST.cpp
	$(CC) $(FLAGS) -c testBST.cpp

clean:
	$(RM) main bst *.o
