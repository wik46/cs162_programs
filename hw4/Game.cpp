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

// Is this static so that I can use it before an instance of the GAME class was created.
std::string Game::m_game_state{"not_started"};
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
	std::cout << "******************************************************" <<
	"*******************" << std::endl;	
	std::cout << "1.) The goal of the game is to find the gold and return\n\n"
	<< "    from where you came before the WUMPUS finds you."
	<< "\n\n2.) Be careful, if you fall down a pit, you die.\n\n"
	<< "3.) Be carefule, there are bats in the cave that can carry\n\n"
	<<"     you to anywhere inside it.\n\n"
	<< "4.) You have only three arrows, use them wisely.\n\n"
	<<"   If you shoot an arrow the Wumpus will wake up."
	<< "\n\n5.) Lastly, enjoy the game and listen to the adjacent caves for hints.\n\n";
	std::cout << "********************************************************"
	<<"******************\n" << std::endl;	
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
Game::Game(int size, bool debug_mode):m_player(Vec2d(0,0), Vec2d(0,0), debug_mode,3)
 , m_grid(size), m_keyboard(Vec2d(0,0), size)
{
	// Seeding the  random number generator.
	srand(time(NULL));
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
 * Function name: Get_input()
 * Description: Obtains the input from the user.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
void Game::Get_input(){	
	get_keyboard().get( get_player() );
	Vec2d dir = get_keyboard().dir(); // NB!! dir() should only run once per round.
	// This will save the player's previous position in the keyboard.
	// It is used by the Evalaute_round to remove the player from the
	// previous room to the new one.
	if( !(get_keyboard().get_input() == Vec2d(0,0)) ){
		get_keyboard().get_prev_pos() = get_player().get_current_pos();
	}
	// This will move the player to the space that he/she needs to be. 
	get_player().move(dir);	
	// Seeing all the members of the classes.
	if(m_player.get_debug_mode()){	
		get_keyboard().print_all_info();
		get_player().print_all_info();
	}
	return;
}			
/* **************************************************************************************
 * Function name: move()
 * Description: Obtains the input from the user.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
void Game::move(){
//	std::cout << "**** THE USER MADE A MOVE ****"<< std::endl;
	// This is if the user moved to an empty room.
	int i = get_player().get_current_pos().get_x();
	int j = get_player().get_current_pos().get_y();
	if( get_grid().get_v()[i][j].is_empty() ){
		// Step 1: Remove the player from his/previous room.
		// Calculating the previous loaction.
		int prev_i = get_keyboard().get_prev_pos().get_x();
		int prev_j = get_keyboard().get_prev_pos().get_y();
		// Step 2: Removing the player from the previous room.
		// The player is not dynamic memory therefore .remove()
		// is no accompanyied with delete.
		get_grid().get_v()[prev_i][prev_j].remove();
		// Step 3: Inserting the player into the new empty room.
		get_grid().get_v()[i][j].insert( &get_player() );

	}else{
		try{
			get_grid().get_v()[i][j].get_event()->action(get_player(), get_keyboard(), get_grid());
				
		}catch(const char* msg){
				std::cout << std::endl << msg << std::endl << std::endl; 
				get_game_state() = "finished";
		}catch(...){
			std::cout << "***caught last block***" << std::endl;
			get_game_state() = "finished";
		}
	}	
}	
/* **************************************************************************************
 * Function name: shoot()
 * Description:Simulates the shooting.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
void Game::shoot(){			
		Vec2d current = get_player().get_current_pos();
		Vec2d dir = get_keyboard().get_shot_dir(); 
				
		Vec2d w_pos = find_pos('w');
		int w_alive = 1;
		// Now we search untill the arrows hits the wall.
		do{
			current = current + dir; 
			// If the shot fired was accurate.
			if(current == w_pos){
				delete get_grid().get_v()[w_pos.get_x()][w_pos.get_y()].remove();
				std::cout << "You killed the WUMPUS !!!!" << std::endl;
				w_alive = 0;
				break;
			}
		}while(!get_grid().is_boundry( current , dir));
		// If the wumpus is not killed he will move.
		if(w_alive == 1){
			std::cout << "The Wumpus ran to another cave" << std::endl;	
			// Move the wumpus here.
			// Step 1: Get the Wumpus's sleeping area.
			int i = w_pos.get_x();
			int j = w_pos.get_y();
			// Step 2: Remove the Wumpus from its sleeping area.
			delete get_grid().get_v()[i][j].remove();

			// This function randomly inserts the Wumpus.	
			int i_e = 0, j_e = 0;
			do{
				// Calculate a random space to insert the player.
				i_e = rand() % (get_grid().get_v().size());
				j_e = rand() % (get_grid().get_v().size());
				// Continue searching if the Room is not empty.
			}while( !get_grid().get_v()[i_e][j_e].is_empty() );// If this room is not empty.	
	
			// Inserting the Player instance into the empty room.
			get_grid().get_v()[i_e][j_e].insert( new Wumpus(get_player().get_debug_mode() )); 
		}
}	
/* **************************************************************************************
 * Function name: find_pos()
 * Description: Returns the vector as position.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
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

	
/* **************************************************************************************
 * Function name: validate_input()
 * Description: The function accepts and intger and a const char* and a bool.
 * 		If the integer < 4, program ends. If const char* var = "true" || "True",
 * 		the program is initialized in debug mode.
 * *************************************************************************************/
bool validate_input(int& argc, char** argv){
	// If the invalid number of commandline arguments were intered.
	const int min_size = 4;
	if(argc < 3){
		throw "You should specify two parameters as initial input.";
	}
	// If the convertion from string to int was unsuccessful it throws an exception.
	std::string tmp = argv[1];
	argc =  stoi(tmp);	
	// If the board is on invalid size.
	if(argc < 4 || argc > 12){
		throw "Invalid board size [4 - 12]";
	}
	// This will return the debug mode.
	if(argv[2][0] == 't' || argv[2][0] == 'T'){
		return true;
	}else{
		return false;
	}
}
/* **************************************************************************************
 * Function name: validate_input()
 * Description: The function accepts and intger and a const char* and a bool.
 * 		If the integer < 4, program ends. If const char* var = "true" || "True",
 * 		the program is initialized in debug mode.
 * *************************************************************************************/
void print_options(){
	std::cout << std::endl << std::endl;
	std::cout << "Type: 'new' to play with a new game board."<< std::endl;		
	std::cout << "Type: 'old' to play with a same game board."<< std::endl;		
	std::cout << "Type: 'terminated' to end the game."<< std::endl;		
	return ;
}
