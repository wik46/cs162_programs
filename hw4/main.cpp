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
	std::cout << "2. Make sure that the debug mode an normal mode works." << std::endl;
	
	
	// 1. Validating user commandline input.
	
	// This is testing the code.
	bool debug = false;
	try{
		debug = validate_input(argc, argv);
		std::cout << debug << std::endl;	
	/*
		assert(argc > 2 && "Invalid com arguments");
		temp= std::stoi(argv[1]);
		// This will throw an exception if the game is smaller than
		// than 4 by 4.
		if(temp < 4){
			throw;
		}
	*/
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

				}else{
					try{
						g.get_grid().get_v()[i][j].get_event()->action(g.get_player(), g.get_keyboard(), g.get_grid());
						
					}catch(const char* msg){
						std::cout << std::endl << msg << std::endl << std::endl; 
						g.get_game_state() = "finished";
					}catch(...){
						std::cout << "***caught last block***" << std::endl;
						g.get_game_state() = "finished";
					}
				}	
	
			// Case 2: The player fired a shot. -- 
			}else{
				std::cout << "**** THE USER FIRED A SHOT. ****" << std::endl;
				Vec2d current = g.get_player().get_current_pos();
				Vec2d dir = g.get_keyboard().get_shot_dir(); 
				
				Vec2d w_pos = g.find_pos('w');
				int w_alive = 1;
				// Now we search untill the arrows hits the wall.
				do{
					std::cout << "CURRENT: " << current << std::endl;
					std::cout << "W_pos: " << w_pos << std::endl;
					current = current + dir; 
					// If the shot fired was accurate.
					if(current == w_pos){
						delete g.get_grid().get_v()[w_pos.get_x()][w_pos.get_y()].remove();
						std::cout << "You killed the WUMPUS !!!!" << std::endl;
						w_alive = 0;
						break;
					}
					std::cout << "CURRENT: " << current << std::endl;
				}while(!g.get_grid().is_boundry( current , dir));
				// If the wumpus is not killed he will move.
					std::cout << w_alive << std::endl;
				if(w_alive == 1){
					std::cout << "The Wumpus ran to another cave" << std::endl;	
					// Move the wumpus here.
					// Step 1: Get the Wumpus's sleeping area.
					int i = w_pos.get_x();
					int j = w_pos.get_y();
					// Step 2: Remove the Wumpus from its sleeping area.
					delete g.get_grid().get_v()[i][j].remove();

					// This function randomly inserts the Wumpus.	
					int i_e = 0, j_e = 0;
					do{
						// Calculate a random space to insert the player.
						i_e = rand() % (g.get_grid().get_v().size());
						j_e = rand() % (g.get_grid().get_v().size());
						// Continue searching if the Room is not empty.
					}while( !g.get_grid().get_v()[i_e][j_e].is_empty() );// If this room is not empty.	
	
					// Inserting the Player instance into the empty room.
					g.get_grid().get_v()[i_e][j_e].insert( new Wumpus(g.get_player().get_debug_mode() )); 
				}	
			}	
				// This evaluates if the user could have won.
				g.Evaluate_round();
				
			}while(g.get_game_state() != "finished");
				std::cout << std::endl << std::endl;
				std::cout << "Type: 'new' to play with a new game board."<< std::endl;		
				std::cout << "Type: 'old' to play with a same game board."<< std::endl;		
				std::cout << "Type: 'terminated' to end the game."<< std::endl;		
		
				std::cin >> g.m_game_state;	
	
		}while( Game::m_game_state != "new" && Game::m_game_state != "terminated" );
	
	}while(Game::m_game_state != "terminated");

		
	return 0;
}
