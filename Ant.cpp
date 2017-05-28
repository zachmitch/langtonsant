/*******************************************************************
Name - Zach Mitchell
Date - 4/13/17
Desc - This file contains the functiond definitions for the Ant class of
Langton's Ant
**************************************************************************/

#include <iostream>
#include <string>
#include "Ant.hpp"

/*************************************
Constructor, initializes the Ant object
***************************************/

Ant::Ant(int boardSize, int xCoord, int yCoord)
{
	board = new Board(boardSize);
	this->xCoord = xCoord;
	this->yCoord = yCoord;
	dir = left;
	
}

/*************************************
Destructor, manages dynamic memory
***************************************/
Ant::~Ant()
{
	delete board;
}
/*************************************
Utilizes the separate SetAnt and printBoard functions from the Board object to
display the current state of the automaton to the user
******************************************/




void Ant::printAnt()
{
	board->setAnt(yCoord, xCoord);
	board->printBoard();

}

/******************************************
All the following are directional functions that cause the ant to move to the next
desired space. I had to use error handling for edges and decided to wrap the ant around
the board.
***************************************************/

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


/*****************************************************
The meat of the automaton is right here.  We walk through the 6 major steps:
1. Knowing what 'direction' we are in (initially preset to left bc wikipedia one is set to left)
2. Sensing if current cell Black/white (intitially preset to white bc wikipedia one is set to white)
3. Changing direction based on black/white
4. Change color of current cell
5. Sense color of next cell
6. Move to next cell
************************************************************/



void Ant::step()
{
	

	//Wanted to copy the current X/Y coords so I could make changes to X/Y w/o
	//affecting the intial spot of cell
	
	int currentXcoord = xCoord;
	int currentYcoord = yCoord;

	switch(dir)
	{
		//I will describe the up case and the other directions are the same,
		//but different directions
	
		case up:
			if(board->_isBlack) 	//If a cell is black
			{
				dir = left;	//turn left
				board->changeColor(currentYcoord,currentXcoord); //change current cell white
				board->_isBlack = board->isBlack(yCoord, xCoord-1); //check to see if next cell b/w
				moveLeft(); // move left
				
			}
			else	//If cell is white
			{
				dir = right;	//turn right
				board->changeColor(currentYcoord,currentXcoord); //change current cell black
				board->_isBlack = board->isBlack(yCoord, xCoord+1); //check to see if next cell b/w
				moveRight(); //move right
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

	//Prints the current step and x/y location of the ant

	std::cout << "Ant Position" << std::endl;
	std::cout << "X: " << xCoord+1 << " Y: " << board->getDimension()-yCoord << std::endl;
	printAnt();


}

