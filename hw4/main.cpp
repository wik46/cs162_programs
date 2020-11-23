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
	std::cout << "Program summary:" << std::endl;
	std::cout << "1. Find a way to make the user take a shot or move:" << std::endl;
	std::cout << "4. Find a way to make the game prompt user old board, new board, or exit.:" << std::endl;
	
	
	// 1. Validating user commandline input.
	
	// This is testing the code.
	int temp = 4;
	try{
		assert(argc > 2 && "Invalid com arguments");
		temp= std::stoi(argv[1]);
		// This will throw an exception if the game is smaller than
		// than 4 by 4.
		if(temp < 4){
			throw;
		}
	}catch(...){
		std::cout << "invalid command line arguments." << std::endl;
		assert(false);
	}	
	//=========================================================================
	// 2. This will create the Game class with a specified board size and 
	// 	in debug mode/ normal mode.
	Game g(temp, argv);
	//=========================================================================

	do{
		do{
			//=========================================================================
			// Testing: Makins sure that the player get updated correctly.
			std::cout << "\n\nStart of test:" << std::endl;
			g.get_player().print_all_info();
			g.get_keyboard().print_all_info();
			std::cout << "===================" << std::endl << std::endl;
			std::cin.get();
			//=========================================================================
			
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
			std::cout << "\n\n\nStart of move_shoot()"<< std::endl;
			
			// 6. This is the largest part of the program.
			// 	** It takes in the user input and updates the board according 
			// 		to the user's moves.
				std::cout << "get(): " << g.get_keyboard().get( g.get_player() ) << std::endl;
				Vec2d dir = g.get_keyboard().dir(); // NB!! dir() should only run once per round.
				std::cout << "dir(): "<< dir << std::endl;	
				// This will save the player's previous position in the keyboard.
				// It is used by the Evalaute_round to remove the player from the
				// previous room to the new one.
				if( !(g.get_keyboard().get_input() == Vec2d(0,0)) ){
					g.get_keyboard().get_prev_pos() = g.get_player().get_current_pos();
				}
				// This will move the player to the space that he/she needs to be. 
				g.get_player().move(dir);	
				// Seeing all the members of the classes.
				g.get_keyboard().print_all_info();
				g.get_player().print_all_info();
			
				std::cout << "End of move_shoot()\n\n\n"<< std::endl;	
			// ==============================================================

			
			// 7. This evaluates the game after each round and depends if the round 
			// 	should be finished or continued.
			// ** It will set m_game_state = "finished". Or it will leave
			// 	it at "in_progress".
			
			// Case 1: The player made a move. --
			Vec2d shot_fired(0,0);
			if( !(g.get_keyboard().get_input() == shot_fired) ){
				std::cout << "**** THE USER MADE A MOVE ****"<< std::endl;
				// This is if the user moved to an empty room.
				int i = g.get_player().get_current_pos().get_x();
				int j = g.get_player().get_current_pos().get_y();
				if( g.get_grid().get_v()[i][j].is_empty() ){
					// Step 1: Remove the player from his/previous room.
					// Calculating the previous loaction.
					int prev_i = g.get_keyboard().get_prev_pos().get_x();
					int prev_j = g.get_keyboard().get_prev_pos().get_y();
					// Step 2: Removing the player from the previous room.
					// The player is not dynamic memory therefore .remove()
					// is no accompanyied with delete.
					g.get_grid().get_v()[prev_i][prev_j].remove();
					// Step 3: Inserting the player into the new empty room.
					g.get_grid().get_v()[i][j].insert( &g.get_player() );
					
					std::cout << "EMPPPTYYYY"<< std::endl;

				}else{
					std::cout << " NOTT  EMPPPTYYYY"<< std::endl;
				}	
	
			// Case 2: The player fired a shot. -- 
			}else{
				std::cout << "**** THE USER FIRED A SHOT. ****" << std::endl;
			}	
	
			std::cin >> g.m_game_state;	
		
		}while(g.get_game_state() != "finished");
			
			std::cin >> g.m_game_state;	
	
	}while(g.get_game_state() != "terminated");
	
	return 0;
}
