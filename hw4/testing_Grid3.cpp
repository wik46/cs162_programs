/* ***************************************************************************************
 * Filename: testing_Grid.cpp
 * Author: Lodewyk Jansen van Rensburg
 * Date: November 22, 2020.
 * Assignment: Homework 4.
 * Description: This it the implementation file for my Event class.
 * ***************************************************************************************/

// ========================================================================================
// This is used to test the Room class.
// ========================================================================================


#include "Event.h"
#include "Room.h"

#include "Vec2d.h"
#include "Grid.h"

#include "Bat.h"
#include "Gold.h"
#include "Pit.h"
#include "Wumpus.h"

#include <iostream>
#include <iomanip>
#include <cassert>




int main(){
	int in_size = 0;
	std::cin >> in_size;

	std::cout << "Creating a Grid of the given size:" << std::endl;
	std::cout << "---------------" << std::endl;
	Grid grid( in_size);
	//Event* e29 = new Event('@',"111",1); 
	// NB! Never try to insert an event in the grid without the insert function.
	std::cout << "===="<< std::endl;
	
	//grid.get_v()[0][0].insert(e29);
//	grid.get_v()[0][0].display();
	std::cout << std::endl;
	//grid.get_v()[0][1].display();
	// This is how to remove an event from a room.
	//Room room_cleaner2(grid.get_v()[0][0].remove());	

	// 1. INSERTING EVENTS:
	// ===================
	// grid.dim() returns m_array.size()
	// The first two for loops is used so that I get access to all the elements 
	// constainer.
	// First trying to find the Wumpus adn Gold in the bord.
	// These will search for the events in the grid.
	// Because the grid is initially empty, it will not find anything.
	// 
	

	//grid.empty_rooms();

	grid.init(true);
// You need a way to find a wumpus or gold. If it is not in the array, then you insert it.
// 	If the user selected a old game just insert the missing events.
// 	If the user selected a new game, just shuffle the grid after inserting the events.
	//bool old_game = false;
//	if(){
	// If any of these iterators return the end, then
	//	auto wumpus_it = std::find();
	//	auto gold_it = std::find();
	//	auto pit_it = std::find();
	//	auto bat_it = std::find()
//	}else{

	//}
	// Outputting the grid.
	grid.print_with_grid();	
	std::cout << std::endl;
	//grid.empty_rooms();
	grid.print_with_grid();	
	std::cout << std::endl;
	//grid.init(true);
	grid.print_with_grid();	
	std::cout << std::endl;
		
	// 2. SHUFFLEING GRID:
	// ===================

	// 2. This code is finding the element.
	// find returns the last iterator in the container if no match is found.
	// NB!! you need to overload the operator == and != for a Room as well as event 
	// 	so that you only check for the symbol of the event.
	// Steps 1: Overload == and != so that the condition
	// Steps 2: Create a function to pass alongside the std::find() that determines
	// 		equality based on the symbol of the event, not all the members of the event.
	
	// 3. Next door(). 
	// ====================
	// ** You need to define search_around such that it prints out the sound and not the symbol.
	// ** In progress.
	Vec2d v1(1,1);
//	grid.search_around(v1);
	std::cout << std::endl;
	std::cout << "Last" << std::endl;
	
	return 0;
}
