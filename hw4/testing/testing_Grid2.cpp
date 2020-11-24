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
	// These symbols will represent the Events in the grid.
	char symbol1 = 'w';
	char symbol2 = 'g';	
	char symbol3 = 'k';	
	
	// Creating Event instances.
	// *** Note *** that Event will be an abstract class because action will be a pure
	// virtual function. Therefore if you want to test this class comment out
	// the action() function.
	Event* e1 = new Bat(true);
	
	Event* e2 = new Gold(false);
	Event* e3 = new Wumpus(1);
	// ====================================================
	// Method 1: Create room objects from created rooms.
	// ====================================================
	// Creating three rooms.
	Room r1(e1);
	Room r2(e2);
	Room r3; // This has a NULL pointer therefore the room is empty.
	// ============================================================
	// Method 2: Create new rooms and new event inside the room.
	// ============================================================
	// ## In progress ## 
	
	std::cout << "(((((()))))))))" << std::endl;
	std::cout << r1 << std::endl;	
	std::cout << r2 << std::endl;	
	std::cout << r3 << std::endl;	
	std::cout << "(((((()))))))))" << std::endl;

	// Using display()
	// ================
	std::cout << std::endl;	
	std::cout << "---------------" << std::endl;
	// This demonstrates the Room's display() function.
	// It will used the display() function of the event in the room.
	r1.display();
	r2.display();
	r3.display(); // This will display nothing becuase there is no Event in r3.
	
	std::cout << "---------------" << std::endl;
	std::cout << std::endl;	
	// This will cause a memory leak because remove() returns the dynamic memory
	// and r2 is not resposible for deleting it anymore.
	std::cout << std::endl;	

	// Using insert().
	// ==============
	std::cout << "---------------" << std::endl;
	Room r4(NULL);
	r4.insert( new Event('3', "MOOOOO" , 1)); 
	r3.insert( e3 );	
	std::cout << r4 << std::endl;
	std::cout << r3 << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << std::endl;	
	
	// Using remove()
	// ================
	// r2.remove();
	// Therefore the caller needs to clean the memory.
	// ---------
	// Method 1.
	// ---------
	Event* r_cleaner = r2.remove();
	delete r_cleaner;
	// ----------
	// Method 2.
	// ----------
	Room r_cleaner2( r1.remove() );

	// Creating a new instance of a Grid.
	// ==================================
	int in_size = 0;
	std::cin >> in_size;

	std::cout << "Creating a Grid of the given size:" << std::endl;
	std::cout << "---------------" << std::endl;
	Grid grid( in_size);
	Event* e29 = new Event('@',"111",1); 
	// NB! Never try to insert an event in the grid without the insert function.
	std::cout << "===="<< std::endl;
	

	grid.get_v()[0][0].insert(e29);
	grid.get_v()[0][0].display();
	std::cout << std::endl;
	grid.get_v()[0][1].display();
	// This is how to remove an event from a room.
	Room room_cleaner2(grid.get_v()[0][0].remove());	
	
	// 1. INSERTING EVENTS:
	// ===================
	// grid.dim() returns m_array.size()
	// The first two for loops is used so that I get access to all the elements 
	// constainer.
	// First trying to find the Wumpus adn Gold in the bord.
	// These will search for the events in the grid.
	// Because the grid is initially empty, it will not find anything.
	// 
	

	grid.empty_rooms();
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
	//grid.random_shuffle();
	grid.print_with_grid();	
	std::cout << std::endl;
	grid.empty_rooms();
	grid.print_with_grid();	
	std::cout << std::endl;
	grid.init(true);
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
	grid.search_around(v1);
	std::cout << std::endl;
	std::cout << "Last" << std::endl;
	
	return 0;
}
