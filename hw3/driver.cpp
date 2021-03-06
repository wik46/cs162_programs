/* **************************************************************************************
 * Filename: driver.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Assignment: Program 3, Zoo Tycoon.
 * Date: November 8, 2020.
 * Description: This is a reinvention of the classic Microsoft game Zoo Tycoon. This is
 * 		a very basic version of the game that allows the owner of the zoo to only
 * 		buy 3 types of animals for his/her zoo. Namely: bears, sea lions, 
 * 		and tigers. The user will start out with no-animals in the zoo and
 * 		a bank account that containing $100 000 inside. 
 * 		One round played will represent one month in real life. Each round the 
 * 		user is allowed to buy at most two animals from a single species, income 
 * 		will be generated based on the number and types of animals currently in
 * 		the zoo, and the user will pay the monthly zoo expenses.. 
 *
 * 		Random events that occurs each round:
 * 			1. An animal gets sick and the user needs to pay medical cost.
 * 			2. An adult(4 years+) will give birth to the specified number of
 * 			   babies of her type.
 * 			3. A boom in attendance will occur where each sea lion generates
 * 			   between $150 - $400 extra revenue.
 * 			4. Nothing happens, unfortunately.
 * Input: Files needed:
 * 		Game.cpp and Game.h,
 * 		Zoo.cpp and Zoo.h,
 * 		Player.cpp and Player.h,
 * 		Animal.cpp and Animal.h,
 * 		Bear.cpp and Bear.h,
 * 		Bear_cage.cpp and Bear_cage.h,
 * 		Sea_lion.cpp and Sea_lion.h,
 * 		Sea_lion_cage.cpp and Sea_lion_cage.h,
 * 		Tiger.cpp and Tiger.h,
 * 		Tiger_cage.cpp and Tiger_cage.h,
 * 		Date.cpp and Date.h,
 * 
 * Output: A friendly user experience while playing Zoo Tycoon in a command
 * 	   line interface
 * **************************************************************************************/



#include "Animal.h"
#include "Bear.h"
#include "Sea_lion.h"
#include "Tiger.h"
#include "Zoo.h"

#include "Date.h"
#include "Game.h"
#include "Probability.h"
#include "Player.h"


#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>

/*
void press_enter(){		
		std::cout << std::endl;
		std::cout << "*******************************************************"
		<< "****************" << std::endl;
		std::cout << "Press enter to start the game." << std::endl;
		std::cout << "*******************************************************"
		<< "****************" << std::endl;
		std::cin.ignore(256, '\n');
		//std::cin.get();
}
*/
int main(){
	// Seeding the random number generator.
	//srand(time(NULL));	
	

	Game g;
	
	do{
		// This function will only be called once at the start of the game.
		// It will set all the m_game_state variable to "in_progress".
		g.Start_game();
		
		// Function tasks.
		// 1. Simulate random events:
		// 	a. An animals gets sick,
		// 	b. A new baby is born,
		// 	c. Increase in the attendence at the zoo, or
		// 	d. Nothing happens.
		g.get_zoo().Random_events(g.get_player(), g.get_prob());		
		
		// Function tasks.
		// 1. Calculate the total income earned excluding the bonus 
		//    from the Sea lions.
		g.get_player().get_bank() += g.get_zoo().Income();

		// This will prompt the user to buy new animals.
		if(g.get_player().is_buy()){
			g.get_player().get_bank() -= g.get_zoo().Auction();
		}
		// Function tasks.
		// 1. Prompt the user to select the quality of food that they
		//    want to feed there animals.

		g.get_zoo().which_food();
		// Function tasks.
		// 1. Calculate all the expenses occured by the player.
		// 2. Subtract the expenses from the player's account.
		g.get_player().get_bank() -= g.get_zoo().Expenses(rand() % 41 + 81);	
	
		// Function tasks.
		// 1. Increase the age of the animals.
		// 2. Increase/decrease the animals probability of gettin sick.
		// 3. Prompt the user to continue/quit the game.
		// 4. Make sure that the user has sufficient funds to continue the game.	
		g.Play_next_round();

	}while(g.get_game_state() != "terminated");
	std::cout << "\nGoodbey." << std::endl;
	return 0;
}
