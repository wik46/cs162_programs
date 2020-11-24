/* ***************************************************************************************
 * Filename: main.cpp
 * Author: Lodewyk Jansen van Rensburg
 * Date: November 22, 2020.
 * Assignment: Homework 4.
 * Description: This is the main function for the 'Hunt the Wumpus' game.
 * ***************************************************************************************/

// ========================================================================================
// ========================================================================================


#include "Event.h"
#include "Room.h"

#include "Vec2d.h"
#include "_2d_Array.hpp"
#include "Grid.h"
#include "Game.h"


#include "Bat.h"
#include "Gold.h"
#include "Pit.h"
#include "Wumpus.h"
#include "Player.h"

#include <iostream>
#include <iomanip>
#include <cassert>




int main(int argc, char** argv){
	// 1. Validating user commandline input.
	
	// This is testing the code.
	bool debug = false;
	try{
		debug = validate_input(argc, argv);
	}catch(const char* a){
		std::cout << std::endl << std::endl << a << std::endl;
		return -1;
	}catch(...){
		std::cout << "Invalid board size specified. Size: 4 - 12" << std::endl;
		return -1;
	}	
	
	do{
		//=========================================================================
		// 2. This will create the Game class with a specified board size and 
		// 	in debug mode/ normal mode.
		Game g(argc, debug);
		//=========================================================================
		
		do{
			do{
				// ==============================================================
				// 3. This will get called at the start of the game. 
				// 	It will be executed if m_game_state == "not_started".
				g.Start_game();	
				// ==============================================================
			
				// ==============================================================
				// 4. This will only output the grid.
				//  ** The grid will be created in debug/normal mode an that will
				//  		ensure if the characters get printed or not.
				g.get_grid().print_with_grid();	
				// ==============================================================

				// ==============================================================
				// 5. This will print out all the message that events from 
				// 	adjacent caves print.
				//    ** It will not print a message if the cave (room) is empty.
				g.get_grid().search_around( g.get_player().get_current_pos());	
				// ==============================================================
				
				// ==============================================================
				// 6. This is the largest part of the program.
				// 	** It takes in the user input and updates the board 
				// 		according to the user's moves.
				g.Get_input();
				// ==============================================================

			
				// ==============================================================
				// 7. This evaluates the game after each round and depends if the round 
				// 	should be finished or continued.
				// ** It will set m_game_state = "finished". Or it will leave
				// 	it at "in_progress".
			
				// Case 1: The player made a move. --
				Vec2d shot_fired(0,0);
				if( !(g.get_keyboard().get_input() == shot_fired) ){
					g.move();
				// Case 2: The player fired a shot. -- 
				}else{
					g.shoot();	
				}	
				// ==============================================================
				// This evaluates if the user could have won.
				g.Evaluate_round();
				
			}while(g.get_game_state() != "finished");
				print_options();	
				std::cin >> g.m_game_state;	
	
		}while( Game::m_game_state != "new" && Game::m_game_state != "terminated" );
	
	}while(Game::m_game_state != "terminated");
		
		
	return 0;
}
