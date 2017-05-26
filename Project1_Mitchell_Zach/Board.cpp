/*******************************************************************
Name - Zach Mitchell
Date - 4/13/17
Description - This file contains the function definitions for a game board that helps
track the progression of Langton's ant
**************************************************************************/

#include <iostream>
#include "Board.hpp"
#include "Ant.hpp"

/*********************************
//Constructor
//Dynamically initializes a 2D gameboard
**********************************/

Board::Board(int size)
{

	this->dimension = size;

	this->gameBoard = new char*[size];

	for (int i = 0; i < size; i++)
		gameBoard[i] = new char[size];
	
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			gameBoard[i][j] = ' ';
	
	_isBlack = false;	

}

/************************************
//Deconstructor, prevents memory leaks
*************************************/

Board::~Board()
{
	for (int i = 0; i < dimension; i++)
		delete [] gameBoard[i];

	delete [] gameBoard;
}

/****************************************
//Gets dimension of board (private member)
**************************************/

int Board::getDimension()
{
	return this->dimension;
}

/********************************************
//Determines if a cell is black or white
//Had to do some input validation specifically here, bc my ant kept looking
//off-board and that would cause segfaults.
************************************************/

bool Board::isBlack(int i, int j)
{	
	//Error handling, made certain that ant is looking
	//at wrapped position instead of off-board

	if (i < 0)
	{
		i = (dimension - 1);
	}
	if (i >= dimension)
	{
		i = 0;
	}
	if (j < 0)
	{
		j = (dimension - 1);
	}
	if (j >= dimension)
	{
		j = 0;
	}

	//Checks if contents are black/white

	if (this->gameBoard[i][j]=='#')
		return true;
	else
		return false;
}

/**********************************************
Outputs the current status of the board with number of steps &
position of the ant visually and at x & y of trad coordinate plane
**************************************************/

void Board::printBoard()
{
	for (int i = 0; i < dimension; i++)
	{	
		//for visual purposes added y coords
		std::cout << dimension-i;
		
		if(dimension-i <= 9)
			std::cout << " ";

		for (int j = 0; j < dimension; j++)
		{	
			std::cout << gameBoard[i][j] << " ";
		}
		std::cout << "\n";
	}
	
	//for visual purposes added x coords	
	for (int i = 0; i <= dimension; i++)
	{	if (i < 10)
		{
			std::cout << i << " ";
		}	
		else
		{
			std::cout << i;
		}
	}

	std::cout << "\n";
}

/*************************************************
Sets the ant visual idenetifier on the board
*************************************************/

void Board::setAnt(int i, int j)
{
	gameBoard[i][j] = '@';
}

/**********************************************
Function that changes cells from black to white and
white to black
*************************************************/

void Board::changeColor(int i, int j)
{
	//error checking if statement
	if((i>=0) && (j>=0) && (j<=dimension) && (i<=dimension))
	{
	if(_isBlack)
		gameBoard[i][j] = ' ';
	else
		gameBoard[i][j] = '#';
	}
}		
