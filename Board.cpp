#include <iostream>
#include "Board.hpp"
#include "Ant.hpp"

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

Board::~Board()
{
	for (int i = 0; i < dimension; i++)
		delete [] gameBoard[i];

	delete [] gameBoard;
}



int Board::getDimension()
{
	return this->dimension;
}


bool Board::isBlack(int i, int j)
{	
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


	if (this->gameBoard[i][j]=='#')
		return true;
	else
		return false;
}


void Board::printBoard()
{
	for (int i = 0; i < dimension; i++)
	{
		std::cout << dimension-i;
		
		if(dimension-i <= 9)
			std::cout << " ";

		for (int j = 0; j < dimension; j++)
		{	
			std::cout << gameBoard[i][j] << " ";
		}
		std::cout << "\n";
	}
	
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

void Board::setAnt(int i, int j)
{
	gameBoard[i][j] = '@';
}

void Board::changeColor(int i, int j)
{
	if((i>=0) && (j>=0) && (j<=dimension) && (i<=dimension))
	{
	if(_isBlack)
		gameBoard[i][j] = ' ';
	else
		gameBoard[i][j] = '#';
	}
}		
