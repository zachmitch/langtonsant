
all: test
	
test:  main.o ant.o board.o
	g++ main.o ant.o board.o -o test

main.o: main.cpp
	g++ -c main.cpp

ant.o: ant.cpp
	g++ -c ant.cpp

board.o: board.cpp
	g++ -c board.cpp
