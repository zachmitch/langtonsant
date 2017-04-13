#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "Board.hpp"
#include "Ant.hpp"


//menu function prototype
void menu();

int main()
{
	menu();	

	return 0;
}



void menu()
{
	bool playAgain = true;
	
	while(playAgain){

	//Welcome screen
	std::cout << "\nWelcome to one of the most historical mathematical automatons, Langton's Ant!" << std::endl;

	//List options
	std::cout << "\nWould you like to see this wonderous simulation? Please enter either 1 or 2: " << std::endl;
	

	std::cout << "1.  YES [START LANGTON'S ANT] " << std::endl;
	std::cout << "2.  NO [END PROGRAM] " << std::endl;

	int optionChoice;
	std::cin >> optionChoice;

	switch(optionChoice)
	{
		case 1:	
		{		//inquire size
				int boardSize;
				std::cout << "\nWhat size is our board today? (recommended between 20-50): " << std::endl;
				std::cin >> boardSize;

				//inquire steps
				int steps;
				std::cout << "\nHow many steps should the Ant take? (Lets keep it < 32,000ish plz) " << std::endl;
				std::cin >> steps;

				//inquire start location or random location
				std::cout << "\nWould you like to choose where the Ant starts or would you like us to place it randomly?" << std::endl;
				int randomStart;
				int xCoord, yCoord;

				std::cout << "1. I'LL CHOOSE MY OWN, PLZ [NON-RANDOM] " << std::endl;
				std::cout << "2. YOU CHOOSE FOR ME [RANDOM] " << std::endl;
				std::cin >> randomStart;				

				switch(randomStart)
				{
					case 1:		std::cout << "Imagine you're looking at a coordinate plane, your run of the mill X & Y 2-D plane...\n" << std::endl;
							std::cout << "Starting at 1, what is your horizontal X-Coordinate? " << std::endl;
							std::cin >> xCoord;
							std::cout << "Starting at 1, what is your vertical Y-Coordinate? " << std::endl;
							std::cin >> yCoord;

							xCoord -= 1;
							yCoord = boardSize - yCoord;
							break;
						
					case 2:		//make random choice
							//Sourced from cplusplus reference
							// www.cplusplus.com/reference/cstdlib/srand/

							srand (time(NULL));
							xCoord = rand() % boardSize;
							yCoord = rand() % boardSize;
							break;
				}						

				//run simulation
				Ant newGame(boardSize, xCoord, yCoord);
				for (int i = 0; i < steps; i++)
				{	
					std::cout << "\nSTEP: " << i+1 << std::endl;
					newGame.step();
				}

				//ask if they want to play again
				std::cout << "\nWant to play again? " << std::endl;
				std::cout << "1.  YES [PLAY AGAIN]" << std::endl;
				std::cout << "2.  NO [DON'T PLAY AGAIN]" << std::endl;
				int again;
				std::cin >> again;

				switch(again)
				{
					case 1:  break;

					case 2:  playAgain = false;
						 break;	

				}

				//break
				break;
		}			
		case 2:
		{		//quit
				playAgain = false;
				break;
		}
	}
				
	}




}

