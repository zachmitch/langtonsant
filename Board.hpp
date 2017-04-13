#ifndef BOARD_HPP
#define BOARD_HPP


class Board{
	private:
	int dimension;
	char** gameBoard;	
	
	public:
	Board(int size = 80);
	~Board();
	bool isBlack(int i, int j);
	bool _isBlack;
	void printBoard();
	void setAnt(int i, int j);
	int getDimension();
	void changeColor(int i, int j);
};

#endif
