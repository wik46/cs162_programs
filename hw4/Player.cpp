/* **************************************************************************************
 * Filename: Player.cpp.
 * Author: Lodewyk Jansen van Rensburg.
 * Date: November 22, 2020.
 * Description: This is the implementation file for the Player class.
 * 		1. It is important to note that the Player's position will be represented
 * 			by a Vec2d class. Note that the direction of the vectors will not
 * 			be correct becuase the (0,0) is top left and not bottom right.
 * 		2. A Player will win the game if during Evaluate_round() the player
 * 			"has the gold"  ie m_has_gold = true.
 * 		   A Player will lose the game if m_game_state = "finished" and 
 * 		   m_has_gold = false.  
 *
 * Input: -
 * Output: -
 * **************************************************************************************/

#include "Player.h"
#include "Vec2d.h"
#include "Event.h"
#include <cassert> 
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <string>

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Actions the player can peform:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ========
// 1. Move:
// ========
/*
	 This will be implemented using the move() member function.
	 The keyboard class will take in the user input and validate it. Then it
	 will return the Vec2d object to where the player will move.
	 The function will accept a Vec2d as argument. This will be the new position
	 to where the player will move. It will take in the direction
	 to where the player moves and return the current position
	 of the player.  This function will update the player's
	 current position on the grid as well as return the current position
	 of the player so that the grid gets the information as well.

 */
// =========
// 2. Shoot:
// =========
/*
	 The keyboard class will take in the user input and validate it. Then it
	 will return the Vec2d object to where the player will shoot an arrows.
	 The shoot() member function will return the direction where the arrow was
	 shot and it will decrement the number of arrows available for the user to 
	 use.
 */

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// How to think about direction on the grid:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/*
 	Because the 2d grid has its origin in the top left hand corner
	and not the bottom left hand corner like the cartesian plane, we need
	to user the "vector" incorrectly in order to move to the desired point
	in the grid.

 	To move:
		North: Add the Vec2d <-1,0>
		South: Add the Vec2d <1,0>
		East: Add the Vec2d <0,1>
		West: Add the Vec2d <0,-1>

*/
 

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// I) Player Actions: 
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


/* **************************************************************************************
 * Function name: move()
 * Description: This function takes in the direction to where the player should move 
 * 		obtained from the Keyboard class and returns the player's current 
 * 		position.
 * Parameters: const Vec2d&
 * Pre-conditions: Assumes that the player can validly move to the positions.
 * Post-conditions: The player moved to the new position.
 * **************************************************************************************/
// 1. This will move the player to the position given as a vector.
const Vec2d& Player::move(const Vec2d& dir){
	this->m_current_pos.get_x() += dir.get_x();
	this->m_current_pos.get_y() += dir.get_y();
	// This is of type Vec2d.
	return m_current_pos;
}
/* **************************************************************************************
 * Function name: .
 * **************************************************************************************/
// 2. This function will decrement the player's number of arrows and return
// 	the direction of the shot made. The Keyboard class will validate the input.
const Vec2d& shoot(const Vec2d& dir);
/* **************************************************************************************
 * Function name: pick_up_gold().
 * Description: This function will be used when the Player enter the Room where there
 * 		is gold inside. The gold will be removed from the Room and by picking
 * 		up the gold, the m_has_gold member is set to true. If the user now
 * 		goes to their initial position, the Evaluate_round() function 
 * 		will end the game by setting m_game_state = "finished".
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
// 2. This will set the m_has_gold to true.
void Player::pick_up_gold(){
	std::cout << std::endl;
	m_has_gold = true;
	std::cout << "$$$$$$$$ You found the hidden treasure $$$$$$$$$" << std::endl;
	std::cout << std::endl;
	return;
}
/* **************************************************************************************
 * Function name: reset_gold().
 * Description: This is the opposite of pick_up_gold(). It will be used when the player
 * 		wants to playe another round. The gold will be returned to the game
 * 		after the game ended to start a new round. 
 * **************************************************************************************/
// 4. This will set the m_has_gold to false.
void Player::reset_gold(){
	m_has_gold = false;
	return;
}




// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// II) Getters and Setters: 
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* ***************************************************************************************
 * Function name: get_name().
 * Description: This function will be used to get access to the name of the player.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Return the name of the player.
 * **************************************************************************************/
std::string Player::get_name() const{ 
	return m_name;
}
/* ***************************************************************************************
 * Function name: get_current_pos().
 * Description: This function will be used to get access 
 * 		to the current position of the player.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Return the current position of the player.
 * **************************************************************************************/
Vec2d& Player::get_current_pos(){
	return m_current_pos;
}
/* ***************************************************************************************
 * Function name: get_initial_pos().
 * Description: This function will be used to get access to the initial 
 * 		position of the player.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Return the initial position of the player.
 * **************************************************************************************/
Vec2d& Player::get_init_pos() {
	return m_init_pos;
}

/* ***************************************************************************************
 * Function name: get_num_arrows().
 * Description: This function will be used to return the number of arrows left for the
 * 		user to use. It will return 0 if the user does not have any arrows left.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Return the name of the player's number of arrows.
 * **************************************************************************************/
unsigned int Player::get_num_arrows(){
	if(this->m_num_arrows > 0){
		// Returns the number of arrows left.
		return m_num_arrows;
	}else{
		// This function will return false if the user does not have any
		// arrows left.
		return 0;
	}
} 
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Development helpers: 
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/* ***************************************************************************************
 * Function name: print_all_info()
 * Description: This will print all the information of the player to the console with 
 * 		labels next to the member variables.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
void Player::print_all_info(){
	std::cout << "-------------------------------------------------------"<< std::endl;
	std::cout << "All member variables of the current Player:" << std::endl;
	std::cout << "-------------------------------------------------------"<< std::endl;
	std::cout << "1.) Name [m_name]: " << m_name << std::endl;
	std::cout << "2.) Has gold [m_has_gold]: " << m_has_gold << std::endl;
	std::cout << "3.) Initial position [m_init_pos]: " << m_init_pos << std::endl;
	std::cout << "4.) Current position [m_current_pos]: " << m_current_pos << std::endl;
	std::cout << "5.) Number of arrows [m_num_arrows]: " << m_num_arrows<< std::endl;
	std::cout << "-------------------------------------------------------"<< std::endl;
	return;
}
/* **************************************************************************************
 * Function name: set_info().
 * Description: This function will be used to prompt the user to enter hiw/her player 
 * 		details. It will be used inside the constructor of the class. It will be
 * 		a private function because the user of the class should not use it 
 * 		outside of the constructo.
 * Parameters: - 
 * Pre-conditions: -
 * Post-condtions: The player information is saved in an instance of a Player class.
 * **************************************************************************************/
void Player::set_info(){
	std::cout << std::fixed;
	std::cout << std::endl 
	<< "======================================================================="
	<< "====================\n"
	<< "Enter your name here: ";
	std::cin >> this->m_name;
	std::cout 
	<< "======================================================================="
	<< "====================" << std::endl;
	// This lets the user think that the money is being deposited.
	std::cout << std::endl;
	std::cout << "**** You are entering the cave of the famous WUMPUS ************ \n"; 
	std::cout << "**** Be careful not to wake him before you've even started.***** \n"; 
	sleep(4);
	std::cout << std::endl
	<< "*************************************************************************************\n"
	<< "You are inside the WUMPUS cave " << this->m_name  
	<< " do your best to find the gold before he finds you." << std::endl
	<< "**************************************************************"
	<< "***********************\n" << std::endl;
	return;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Constructors: 
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* **************************************************************************************
 * Function name: Player()
 * Description: This is the constructor for the player class. I will only define the 
 * 		default constructor as it is the only one needed at the moment for
 * 		the class. The class will not contains dynamic memory and therefore
 * 		not need one of the big three.
 * Parameters: float.
 * Pre-conditions: The function makes use of the set_info() member function.
 * Post-conditions: The player instance is initialized with all its members variables
 * 			set to the correct values.
 * **************************************************************************************/
Player::Player(const Vec2d& init, const Vec2d& current, bool debug_mode, unsigned int total)
:Event('$', " ", debug_mode)
, m_has_gold{false}, m_init_pos{init}, m_current_pos{current}, m_num_arrows{total}
{
	set_info();
}
/* **************************************************************************************
 * Function name: ask_for_input()
 * Description: This function only collects a string as a input from the user.
 * Parameters: -
 * Pre-conditions: -
 * Post-condtions: Returns the string entered as a input by the user.
 * **************************************************************************************/
std::string ask_for_input(){
	std::string temp;
	std::cin >> temp;
	return temp;
}

/* **************************************************************************************
 * Function name: is_valid()
 * Description: This function validates that the string only contains numeric charaters.
 * Parameters: - 
 * Pre-condtions: A string declared in an outer scope.
 * Post-condtions: Returns true if the pointer is pointing to an only-numeric charater
 * 		   string, else returns false.
 * **************************************************************************************/
bool is_valid(std::string* str1){
	for(int i = 0; i < (*str1).length(); i++){
		// This condition will be met if the charater is not a numeric value.
		if((*str1)[i] < 48 || (*str1)[i] > 57){
			std::cout << "Please enter an integer value." << std::endl;
			return 0;
		}
		// The empty string cannot be passed to stoi() later in the program.
	}
	return 1;
}
/* **************************************************************************************
 * Function name: get_int()
 * Description: This function promts the user for his/her input. It will only return
 * 		a valid input. That is a string that contains only numeric.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: The function returns the first valid integer entered by the user.
 * **************************************************************************************/
// This is used for the first part of getting use input.
int get_int(std::string prompt ,std::string error_msg){
	// This will be the output message to the user.
		std::cout << std::endl << prompt << std::endl;
	// The string is initialized to an invalid value so that the while-loop will iterate.
	std::string tmp = " ";
	// The id-number is invalid if the string contains any non-numeric characters.
	while(!is_valid(&tmp)){
		// this will prompt the user to enter a new string and save the value into tmp.
		tmp = ask_for_input();
		// This is used to display helpful input to the user.
		if(!is_valid(&tmp)){
			std::cout << error_msg << std::endl;
		}
	}
	return stoi(tmp);
}
