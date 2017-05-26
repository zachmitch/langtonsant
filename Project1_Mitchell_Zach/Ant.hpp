/*******************************************************************
Name - Zach Mitchell
Date - 4/13/17
Desc - This file contains the function prototypes for the ant class
**************************************************************************/


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
