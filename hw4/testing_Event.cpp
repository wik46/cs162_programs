/* ***************************************************************************************
 * Filename: testing_Event.cpp
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
//
// ========================================================================================


#include "Event.h"
#include <iostream>
int main(){
	// These symbols will represent the Events in the grid.
	char symbol1 = 'w';
	char symbol2 = 'g';	
	
	// Creating Event instances.
	// *** Note *** that Event will be an abstract class because action will be a pure
	// virtual function. Therefore if you want to test this class comment out
	// the action() function.
	Event e1(symbol1, "I am e1", true);
	Event e2(symbol2, "I am e2", false);
	// 1. Showing that display() only prints the symbol of the Event if m_debug = true.
	std::cout << "1. display()"  << std::endl;
	std::cout << e1 << std::endl;
	std::cout << e2 << std::endl;
	std::cout << "+++" << std::endl;
	e1.display();
	e2.display();
	std::cout << "+++" << std::endl;
	
	// 2. Showing that the Events make a unique sound.
	std::cout << "2. make_sound()"  << std::endl;
	std::cout << "----" << std::endl;
	e1.make_sound();
	e2.make_sound();
	std::cout << "----" << std::endl;
	return 0;
}
