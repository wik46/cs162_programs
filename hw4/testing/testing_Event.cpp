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

#include "Bat.h"
#include "Gold.h"
#include "Pit.h"
#include "Wumpus.h"


#include <iostream>
int main(){
	// These symbols will represent the Events in the grid.
	char symbol1 = 'w';
	char symbol2 = 'g';	
	
	// Creating Event instances.
	// *** Note *** that Event will be an abstract class because action will be a pure
	// virtual function. Therefore if you want to test this class comment out
	// the action() function.
	
	// 1. Creating a child of Event.
	Bat b1(true);
	Event* e_b1 = &b1;
	// 2. Creating a child of Event.
	Gold g1;
	Event* e_g1 = &g1;
	// 3. Creating a child of Event.
	Pit p1(true);
	Event* e_p1 = &p1;
	// 4. Creating a child of Event.
	Wumpus w1;
	Event* e_w1 = &w1;

	// 1. Showing that display() only prints the symbol of the Event if m_debug = true.
	std::cout << "1. std::cout <<"  << std::endl;
	std::cout << "+++" << std::endl;
	std::cout << "a.1 " << b1 << std::endl;
	std::cout << "a.2 " << *e_b1 << "// as Event* "<< std::endl;
	std::cout << "b.1 " << g1 << std::endl;
	std::cout << "b.2 " << *e_g1 << " // as Event*" << std::endl;
	std::cout << "c.1 " << p1 << std::endl;
	std::cout << "c.2 " << *e_p1 << " // as Event*" << std::endl;
	std::cout << "d.1 " << w1 << std::endl;
	std::cout << "c.2 " << *e_w1 << " // as Event* " << std::endl;
	std::cout << "+++" << std::endl;
	std::cout << std::endl;
	std::cout << "2. display()"  << std::endl;
	// This function should be used to display the symbol in the grid.
	std::cout << "***" << std::endl;
	b1.display();
	std::cout << "***" << std::endl;
	g1.display();
	std::cout << "***" << std::endl;
	p1.display();
	std::cout << "***" << std::endl;
	w1.display();
	std::cout << "***" << std::endl;
	std::cout << std::endl;
	std::cout << "+++" << std::endl;
	
	// 2. Showing that the Events make a unique sound.
	std::cout << "3. make_sound()"  << std::endl;
	std::cout << "----" << std::endl;
	// As an Child of Event.
	b1.make_sound();
	// As an Event*.
	e_b1->make_sound();
	// -----
	g1.make_sound();
	e_g1->make_sound();
	// As an Child of Event.
	p1.make_sound();
	// As an Event*.
	e_p1->make_sound();
	// -----
	w1.make_sound();
	e_w1->make_sound();
	std::cout << "----" << std::endl;
	return 0;
}
