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
	Event* e1 = new Event(symbol1, "I am e1", true);
	
	Event* e2 = new Event(symbol2, "I am e2", false);
	Event* e3 = new Event(symbol3, "I am e2", false);
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

	// 2. This code is finding the element.
	// find returns the last iterator in the container if no match is found.
	// NB!! you need to overload the operator == and != for a Room as well as event 
	// 	so that you only check for the symbol of the event.
	// Steps 1: Overload == and != so that the condition
	// Steps 2: Create a function to pass alongside the std::find() that determines
	// 		equality based on the symbol of the event, not all the members of the event.
	std::cout << std::endl;
	
	return 0;
}
