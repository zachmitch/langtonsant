/************************************************************************
Name - Zach Mitchell
Date - 4/13/17
This file contains the execution for Langton's Ant, as well as the generic
menu and input validation functions described in the spec
**************************************************************************/

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "Board.hpp"
#include "Ant.hpp"


//menu function prototype
void menu();

//input validation prototype
void integerInputValid(int &variable, int lowerBound, int upperBound);

int main()
{
	menu();	

	return 0;
}

/******************************************
//Menu function from assignment spec
******************************************/

void menu()
{
	//User will later decide if they want to play again, initialized to true so program will run on first go
	bool playAgain = true;
	
	while(playAgain){

	//Welcome screen
	std::cout << "\nWelcome to one of the most historical mathematical automatons, Langton's Ant!" << std::endl;

	//List options
	std::cout << "\nWould you like to see this wonderous simulation? Please enter either 1 or 2: " << std::endl;
	

	std::cout << "1.  YES [START LANGTON'S ANT] " << std::endl;
	std::cout << "2.  NO [END PROGRAM] " << std::endl;

	int optionChoice;
	integerInputValid(optionChoice, 1, 2);


	//Decision tree based on user input
	switch(optionChoice)
	{
		case 1:	
		{		//inquire size
				int boardSize;
				std::cout << "\nWhat size is our board today? (Between 20-50): " << std::endl;
				integerInputValid(boardSize,20,50);

				//inquire steps
				int steps;
				std::cout << "\nHow many steps should the Ant take? (Between 1-10,000) " << std::endl;
				integerInputValid(steps,1,10000);

				//inquire chosen location or RANDOM LOCATION 
				std::cout << "\nWould you like to choose where the Ant starts or would you like us to place it randomly?" << std::endl;
				int randomStart;
				int xCoord, yCoord;

				//More options listing
				std::cout << "1. I'LL CHOOSE MY OWN, PLEASE [NON-RANDOM] " << std::endl;
				std::cout << "2. YOU CHOOSE FOR ME [RANDOM] " << std::endl;
				integerInputValid(randomStart,1,2);				

				switch(randomStart)
				{			//User chosen start points
					case 1:		std::cout << "Imagine you're looking at a 2-D coordinate plane, your 'run-of-the-mill' positive X & Y...\n" << std::endl;
							std::cout << "Starting at 1, and less than " << boardSize << " what is your horizontal X-Coordinate? " << std::endl;
							integerInputValid(xCoord,1,boardSize);
							std::cout << "Starting at 1, and less than " << boardSize << " what is your vertical Y-Coordinate? " << std::endl;
							integerInputValid(yCoord,1,boardSize);

							//Conversion to 'traditional x-y coordinate plane look
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
					std::cout << "\nSTEP: " << i+1 << std::endl; //Print game
					newGame.step();  // Step through an iteration
				}

				//ask if they want to play again
				std::cout << "\nWant to play again? " << std::endl;
				std::cout << "1.  YES [PLAY AGAIN]" << std::endl;
				std::cout << "2.  NO [DON'T PLAY AGAIN]" << std::endl;
				int again;
				integerInputValid(again,1,2);

				switch(again)
				{
					case 1:  break;
					
					//quit
					case 2:  playAgain = false;
						 break;	

				}

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

/********************************************
//Input validation function from text
//Takes in the reference variable, the lower bound and the upper bound
************************************************************/

void integerInputValid(int &variable, int lowerBound, int upperBound)
{
	while((variable<lowerBound)||(variable>upperBound))
	{
		std::cin >> variable;

		if((variable<lowerBound)||(variable>upperBound))
			std::cout << "Please enter a valid choice between " << lowerBound << " and " << upperBound << std::endl;
	}
}
