/* ***************************************************************************************
 * Filename: testing_Room.cpp
 * Author: Lodewyk Jansen van Rensburg
 * Date: November 22, 2020.
 * Assignment: Homework 4.
 * Description: This it the implementation file for my Event class.
 * 		An Event will be an abstract class with the following children.
 * 			1. Wumpus,
 * 			2. Gold, 
 * 			3. Bats, and
 * 			4. Pit.
 *		The events will each have a member function that is a boolean value.
 *			- True (debug/print mode) and false (normal/non-print mode).
 *		Event will have member functions that displays the information of
 *		of based on the m_debug member.
 *		
 *		Events will be stored inside a room. The game will have a 2d matrix of rooms
 *		that is stored in a grid. The grid class will be a wrapper around a 2d 
 *		std::vector.
 * 		An event will be constructed with the debug mode on true of false.
 * 		The default will be false. That is by default the game will be played
 * 		without printing the events inside the room.
 * Input: -
 * Output: -
 * ***************************************************************************************/

// ========================================================================================
// This is used to test the Room class.
// ========================================================================================


#include "Event.h"
#include "Room.h"
#include <iostream>
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

	return 0;
}
