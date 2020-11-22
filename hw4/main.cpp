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
		
	// 2. This will create the Game class with a specified board size and 
	// 	in debug mode/ normal mode.
	Game g(temp, argv);

	g.get_player().print_all_info();
	
	do{
			// Testing: Makins sure that the player get updated correctly.
			std::cout << "\n\nStart of test:" << std::endl;
			g.get_player().print_all_info();
			g.get_keyboard().print_all_info();
			std::cout << "===================" << std::endl << std::endl;
			std::cin.get();
			//=========================================================================
			

			// 3. This will get called at the start of the game. It will be executed if
			// 	m_game_state == "not_started".
			g.Start_game();	
			// 4. This will only output the grid.
			//  	** The grid will be created in debug/normal mode an that will
			//Event* e1 = g.get_grid().get_v()[0][0].remove();
			//  		ensure if the characters get printed or not.
			//g.get_grid().random_shuffle();	
			//g.get_grid().get_v()[3][3].insert(e1);
			g.get_grid().print_with_grid();	

			
			//Event* e1 = &g.get_player();
			//e1->make_sound();
			// 5. This will print out all the message that events from adjacent caves
			// 	 print.
			//    ** It will not print a message if the cave (room) is empty.
			std::cout << " --- " << std::endl;
			//g.get_grid().get_v()[2][1].get_event()->make_sound();
			
			g.get_grid().search_around( g.get_player().get_current_pos());	
			// 6. This is the largest part of the program.
			// 	** It takes in the user input and updates the board according 
			// 		to the user's moves.
			
			// 7. This evaluates the game after each round and depends if the round 
			// 	should be finished or continued.
			// ** It will set m_game_state = "finished". Or it will leave
			// 	it at "in_progress".
	
			std::cin >> g.m_game_state;	
		
	}while(g.get_game_state() != "terminated");
	
	return 0;
}
