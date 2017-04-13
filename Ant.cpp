#include <iostream>
#include <string>
#include "Ant.hpp"


Ant::Ant(int boardSize, int xCoord, int yCoord)
{
	board = new Board(boardSize);
	this->xCoord = xCoord;
	this->yCoord = yCoord;
	dir = left;
	
}

void Ant::printAnt()
{
	board->setAnt(yCoord, xCoord);
	board->printBoard();
}

void Ant::moveUp()
{
	if((yCoord-1) >= 0)
	{
		yCoord -= 1;
	}
	else
	{
		yCoord = (board->getDimension() - 1);
	}
		
}

void Ant::moveRight()
{
	if( (xCoord+1) < board->getDimension())
	{
	xCoord += 1;
	}
	else
	{
		xCoord = 0;
	}
}

void Ant::moveLeft()
{
	if( (xCoord-1) >= 0)
	{	
		xCoord -= 1;
	}
	else
	{
		xCoord = (board->getDimension() - 1);
	}
}

void Ant::moveDown()
{
	if( (yCoord + 1) < board->getDimension())
	{
		yCoord += 1;
	}
	else
	{
		yCoord = 0;
	}
}

void Ant::step()
{
	


	int currentXcoord = xCoord;
	int currentYcoord = yCoord;

	switch(dir)
	{
		case up:
			if(board->_isBlack)
			{
				dir = left;
				board->changeColor(currentYcoord,currentXcoord);
				board->_isBlack = board->isBlack(yCoord, xCoord-1);
				moveLeft();
				
			}
			else
			{
				dir = right;
				board->changeColor(currentYcoord,currentXcoord);
				board->_isBlack = board->isBlack(yCoord, xCoord+1);
				moveRight();
			}
			
			break;

		case right:
			if(board->_isBlack)
			{
				dir = up;
				board->changeColor(currentYcoord, currentXcoord);
				board->_isBlack = board->isBlack(yCoord-1, xCoord);
				moveUp();
			}
			else
			{
				dir = down;
				board->changeColor(currentYcoord, currentXcoord);
				board->_isBlack = board->isBlack(yCoord+1, xCoord);
				moveDown();
			}

			break;

		case down:
			if(board->_isBlack)
			{
				dir = right;
				board->changeColor(currentYcoord, currentXcoord);
				board->_isBlack = board->isBlack(yCoord, xCoord+1);
				moveRight();
			}
			else
			{
				dir = left;
				board->changeColor(currentYcoord, currentXcoord);
				board->_isBlack = board->isBlack(yCoord, xCoord-1);
				moveLeft();
			}

			break;

		case left:
			if(board->_isBlack)
			{
				dir = down;
				board->changeColor(currentYcoord, currentXcoord);
				board->_isBlack = board->isBlack(yCoord+1, xCoord);
				moveDown();
			}
			else
			{
				dir = up;
				board->changeColor(currentYcoord, currentXcoord);
				board->_isBlack = board->isBlack(yCoord-1, xCoord);
				moveUp();
			}					
			
			break;
	}

	std::cout << "Ant Position" << std::endl;
	std::cout << "X: " << xCoord+1 << " Y: " << board->getDimension()-yCoord << std::endl;
	printAnt();


}

