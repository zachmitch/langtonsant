#ifndef ANT_HPP
#define ANT_HPP
#include "Board.hpp"


class Ant{
	private:
	int xCoord;
	int yCoord;	
	
	public:
	Ant(int boardSize, int xCoord, int yCoord);
	enum Direction {up, right, down, left};
	Direction dir;
	Board *board;
	void printAnt();	
	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();	
	void step();
	

};
#endif
