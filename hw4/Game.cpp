/* **************************************************************************************
 * Filename: Game.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: November 22, 2020.
 * Description: This is the implementation file for the Game class. This
 * 		class will contain all the member needed to play the game
 * 		Hunt the Wumpus.
 * Input: -
 * Output: -
 * **************************************************************************************/
#include "Game.h"

#include "Event.h"
#include "Room.h"
#include "_2d_Array.hpp"

#include "Vec2d.h"
#include "Grid.h"
#include "Keyboard.h"

#include "Bat.h"
#include "Gold.h"
#include "Pit.h"
#include "Wumpus.h"
#include "Player.h"

#include <iostream>
#include <iomanip>
#include <cassert>


#include <algorithm>
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
 * Function name: get_keyboard()
 * Description: This function is an accessor for the m_keyboard member variable.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns m_keyboard.
 * **************************************************************************************/
Keyboard& Game::get_keyboard(){
	return m_keyboard;
}
/* **************************************************************************************
 * Function name: get_grid()
 * Description: This function is an accessor for the m_grid member variable.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns a reference to m_grid.
 * **************************************************************************************/
Grid& Game::get_grid(){
	return m_grid;
}

/* **************************************************************************************
 * Function name: get_game_state()
 * Description: This function is an accessor for the m_game_state member variable.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns m_game_state. 
 * **************************************************************************************/
std::string& Game::get_game_state(){
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
	std::cout << "Welcome " << m_player.get_name() << " to Hunt the Wumpus." << std::endl;
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
 * Function name: Game(int, bool)
 * Description: This is the Game class constructor.
 * Parameters: int.
 * Pre-conditions: There will be only one instance of a game class in the program. 
 * Post-condtions: An instance of a Game classes is constructed.
 * **************************************************************************************/
Game::Game(int size, bool debug_mode): m_game_state{"not_started"}
 ,m_player(Vec2d(0,0), Vec2d(0,0), debug_mode,3)
 , m_grid(size), m_keyboard(Vec2d(0,0), size)
{
	// This inserts all the Events* into the Grid.
	m_grid.init( debug_mode );	
	// You still need to shuffle the grid.
	//m_grid.random_shuffle();	
	// This inserts the Player randomly and sets the player's init and current pos.
	m_grid.get_v()[3][3].insert(&m_player);
	m_grid.random_shuffle();	
	// Setting the keyboard to the player's initial position.
	// Creating a temporary variable because I dont want to set the two references
	// 	equal to each other.
	// YOU NEED TO FIND THE PLAYERS's init pos.
	std::cout << find_pos('$')<< std::endl;
	Vec2d init_pos = find_pos('$');
	// Setting the initial posistions;
	m_player.get_init_pos() = init_pos;
	m_player.get_current_pos() = init_pos;
	m_keyboard.get_player_pos() = init_pos;
	m_keyboard.get_prev_pos() = init_pos;
}
/* **************************************************************************************
 * Function name: Evaluate_round()
 * **************************************************************************************/
void Game::Evaluate_round(){
	// If the gamestate is finished then the user lost.
	if(m_game_state != "finished"){
		try{
			m_player.action( m_player, m_keyboard, m_grid);
		}catch(const char* msg){
			std::cout << std::endl << msg << std::endl << std::endl; 
			get_game_state() = "finished";
		}catch(...){
			std::cout << "***caught last block***" << std::endl;
			get_game_state() = "finished";	
		}
	}
	return;
}

/* **************************************************************************************
 * **************************************************************************************/

/// THIS FUNCTION RETURNS TH POS OF A SYMBOL.

Vec2d Game::find_pos(char symbol){
	
	bool end = false;
	
	int i = 0, j = 0;
	for(i = 0; i < m_grid.get_v().size(); i++){
		for(j = 0; j < m_grid.get_v().size(); j++){
			if(!m_grid.get_v()[i][j].is_empty()){
				if(m_grid.get_v()[i][j].get_event()->get_symbol() == symbol){
				std::cout << m_grid.get_v()[i][j].get_event()->get_symbol() << std::endl;
					
					end = true;
					break;
				}
			}
		}
		if(end){
			break;
		}
		
	}
	return Vec2d(i,j);
}

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

	

