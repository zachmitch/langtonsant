
all: test
	
test:  main.o Ant.o Board.o
	g++ main.o Ant.o Board.o -o test

main.o: main.cpp
	g++ -c main.cpp

Ant.o: Ant.cpp
	g++ -c Ant.cpp

Board.o: Board.cpp
	g++ -c Board.cpp
