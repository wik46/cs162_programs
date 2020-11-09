/* **************************************************************************************
 * Filename: Game.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: November 8, 2020.
 * Description: This is the implementation file for the Game class. This
 * 		class will contain all the member needed to play the game
 * 		Zoo Tycoon.
 * Input: -
 * Output: -
 * **************************************************************************************/

#include "Animal.h"
#include "Bear.h"
#include "Sea_lion.h"
#include "Tiger.h"
#include "Zoo.h"

#include "Date.h"
#include "Game.h"
#include "Player.h"
#include "Probability.h"

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>

void press_enter();		
/* **************************************************************************************
 * Function name: get_player()
 * Description: This function is an accessor for the m_player member variable.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns m_player.
 * **************************************************************************************/
Player& Game::get_player(){
	return m_player;
}

/* **************************************************************************************
 * Function name: get_prob()
 * Description: This function is an accessor for the m_prob member variable.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns m_prob.
 * **************************************************************************************/
Probability& Game::get_prob(){
	return m_prob;
}
/* **************************************************************************************
 * Function name: get_zoo()
 * Description: This function is an accessor for the m_zoo member variable.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns m_zoo.
 * **************************************************************************************/
Zoo& Game::get_zoo(){
	return m_zoo;
}
/* **************************************************************************************
 * Function name: get_game_state()
 * Description: This function is an accessor for the m_game_state member variable.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns m_game_state. 
 * **************************************************************************************/
const std::string& Game::get_game_state(){
	return m_game_state;
}

/* **************************************************************************************
 * Function name: print_game_rules()
 * Description: This function will out put the game rule to the user.
 * 		It is used inside Start_game() and will only be called at the 
 * 		begining of the game. The function also gets the player's name.
 * Paramters: - 
 * Pre-conditions: Assumes a new game has started.
 * Post-conditions: Outputs a welcome message to the screen.
 * **************************************************************************************/
void Game::print_game_rules(){
	std::cout << std::endl;
	std::cout << "=======================================================" << std::endl;	
	std::cout << "Welcome " << m_player.get_name() << " to Zoo Tycoon: 2." << std::endl;
	std::cout << "=======================================================" << std::endl;	
	std::cout << std::endl;
	std::cout << "\n******************************************************" << std::endl;	
	std::cout << "Game Rules:" << std::endl;
	std::cout << "******************************************************\n" << std::endl;	
	std::cout << "1.) You start of with $ 100 000 in your bank\n    and with an empty zoo.\n\n"
	<< "2.) You can buy up to two animals per round of the\n     same type.\n\n"
	<< "3.) Each round baby animals will be born, boom in\n    attendace will occur, one "
	<< " of you animals will\n    turn ill, or nothing will happen.\n\n"
	<< "4.) You get to select the food quaility for you \n    animals. Cheap food will be bad for"
	<< " their health \n    and will increase the probability of geting sick.\n"
	<< "    Premium food will decrease their chances of \n    turning ill.\n\n"	
	<< "5.) Lastly enjoy the game!!!\n\n";
	std::cout << "******************************************************\n" << std::endl;	
	std::cout << std::endl;
	press_enter();
}

/* **************************************************************************************
 * Function name: Game(int)
 * Description: This is the Game class constructor.
 * Parameters: int.
 * Pre-conditions: There will be only one instance of a game class in the program. 
 * Post-condtions: An instance of a Game classes is constructed.
 * **************************************************************************************/
Game::Game():m_game_state{"not_started"}
{
	

}
/* **************************************************************************************
 * **************************************************************************************/


/* **************************************************************************************
 * Function name: ~Game().
 * Description: This is the destructor of the Game class. It will free the dynamic 
 * 		memory used by the program to store the array of Animal*'.
 * Paramters: -
 * Pre-conditions: Given that a Game instance was created, the players in the game
 * 		   will be store as a member in the Game class. This will be stored 
 * 		   the stack.
 * Post-conditions: The memory allocated for storage of the Animal* array is freed.
 * **************************************************************************************/
Game::~Game(){
}


/* **************************************************************************************
 * Function name: Start_game()
 * Description: This function is used to intialize the game. That is it will
 * Parameters: int*
 * Pre-condtions: This function will only be execute once at the start of the game.
 * Post-conditions: This function hands out the cards to each player and starts
 * 		    the game.
 * **************************************************************************************/
void Game::Start_game(){
	if(m_game_state == "not_started"){
		print_game_rules();
		m_game_state = "in_progress";
		
	}else{
		return;
	}
}
/* **************************************************************************************
 * Function name: probality_decider()
 * Description: This function will use the m_which_food variable to decide 
 * 		if the probability of the animals getting sick needs to change.
 * Parameters: string
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
void Game::probability_decider(std::string food_type){
	if(food_type == "cheap"){
		// When the user buys cheap food the chances of an animal getting sick 
		// increases.
		m_prob.increase();
	}else if(food_type == "premium"){
		// When the user buys premium food the chances of an animal getting
		// sick decreases.
		m_prob.decrease();
	}
}

/* **************************************************************************************
 * Function name: Play_next_round()
 * Description: This function will first determine if the user has sufficient funds
 * 		to continue the game. 
 * 		It will also prompt the user if they want to play another round 
 * 		or end the game. 
 * 		It will add the age of all the animals in the Zoo.
 * Parameters: 
 * Pre-conditions:-
 * Post-conditions: Determines if the player wants to play another round.
 * **************************************************************************************/		
void Game::Play_next_round(){
	std::cout << "\n****************************\n"<< std::endl;
	std::cout << "End of month summary: "<< std::endl;
	std::cout << "\n****************************\n"<< std::endl;
	// This will print the user's bank total.
	//
	std::cout << "\n**************************************\n"<< std::endl;
	std::cout << "Bank total summary: $" << m_player.get_bank() << std::endl;
	std::cout << "\n**************************************\n"<< std::endl;

	// This function will increase the age of all the animals by one.
	m_zoo.x_month_older();
	// This function will display the entire zoo to the user.
	std::cout << m_zoo << std::endl;
	// This will +/- the chances of an animal getting sick.
	probability_decider(m_zoo.get_food_type());
	// =============  This is the case when the player is bankrupt.
	if(m_player.get_bank() < 0){
		std::cout << "*** WARNING ***: "<< m_player.get_bankname()
		<< " called and said that you are bankrupt.\n Your Zoo will be closed."<< std::endl;
		//This terminates the game.
		m_game_state = "terminated";
		return;
	}
	// This will prompt the user of they want to continue with the game.
	std::string tmp = "";
	std::cout << std::endl << std::endl
	<< "To exit the game press '0', any other input will let you play another round "
	<< "another round." << std::endl;
	std::cin >> tmp;
	// ============== Exit game functionality ============
	if(tmp == "0"){
		std::cout << "Are you sure? Press '0' again to confirm." << std::endl;
		std::cin >> tmp;
		if(tmp == "0"){
			// This will cauase the program to exit the main while loop.
			m_game_state = "terminated";
		}else{
			std::cout << "\n\nI knew you actually wanted to play another round." 
			<< std::endl << std::endl;
		} 
	}else{
		std::cout<< "\nGet ready for the next month!!!" << std::endl << std::endl;
	}
	
}

/* **************************************************************************************
 * Function name: press_enter().
 * Description: This function is used by the game to prompt the user to press enter.
 * 		The only purpose of it is to add some pauses into the game.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * *************************************************************************************/
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

	

