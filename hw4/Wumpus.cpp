/* ***************************************************************************************
 * Filename: Wumpus.cpp
 * Author: Lodewyk Jansen van Rensburg
 * Date: November 22, 2020.
 * Assignment: Homework 4.
 * Symbol: 'w'
 * Description: This is the implementation file for the Wumpus class.
 * 		This class is a child with parent Event class.
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

#include "Event.h"
#include "Wumpus.h"
#include "Grid.h"
//#include "Player.h"
//#include "Keyboard.h"
#include <iostream>

// =======================================================================================
// Hard working functions.
// =======================================================================================
/* ***************************************************************************************
 * Function name: display()
 * Description: This function will only print out the symbol of the event if the
 * 		m_debug_mode variable is TRUE. Else the function will not print.
 * 		Prints bases on m_debug_mode
 * Parameters: -
 * Pre-conditions: Prints based on the truth value of m_debug_mode.
 * Post-conditions: Only prints if m_debug_mode == TRUE.
 * ***************************************************************************************/
// =====================
// Defined in Event.cpp
// =====================

/* ***************************************************************************************
 * Function name: make_sound()
 * Description: This function will print out the sound that the event makes when the
 * 		user is close by.
 * Parameters: -
 * Pre-conditions: Prints the m_sound variable.
 * Post-conditions: It will be used to let the player know that the event is in an 
 * 			adjacent room.
 * ***************************************************************************************/
// =====================
// Defined in Event.cpp
// =====================

/* ***************************************************************************************
 * Function name: action()
 * Description: This function will perform the action on the user.
 * 		1. The wumpus kills the user. That is the games end and an end_game
 * 		   exception is thrown.
 * 		2. The user receives gold. The gold gets picked up but the user still
 * 		   needs to go back to his/her initial block to exit the game.
 * 		3. The user enters a cave with bats and the user gets moved to a new
 * 		   cage that may or may not contains the Wumpus.
 * 		4. The user falls into a pit and dies. Therefore an endgame exception
 * 		   is thrown.
 * Parameters: -
 * Pre-conditions: This is a pure virtual function and each Event child will implement
 * 		   it differently.
 * Post-conditions: -
 * ***************************************************************************************/
void Wumpus::action(Player& p, Keyboard& k, Grid& grid){
	std::cout << "I am the wumpus actions" << std::endl;
	// Resetting the arrows.
	if(p.get_num_arrows() < 3){
		p.get_num_arrows() = 3;	
	}
	// Resetting the gold.
	p.reset_gold();
	// Inserting gold into the grid.
	if(grid.find_pos('g') == Vec2d(-1,-1)){
		for(int i = 0; i < grid.get_v().size(); i++){
			for(int j = 0; j < grid.get_v().size(); j++){
				if(grid.get_v()[i][j].is_empty()){
					grid.get_v()[i][j].insert(new Gold(p.get_debug_mode()));
					// So that the loop stops.
					j = grid.get_v().size() + 10;
					i = j;
				}
			}
		}
	}
	// Resetting previous position of the player.
	p.get_current_pos() = k.get_prev_pos();
	k.get_player_pos() = p.get_current_pos();
	throw "Wumpus: 'I caugth you !!!!' ";
	return; 
}
/* ***************************************************************************************
 * ***************************************************************************************/

// =======================================================================================
// Overloaded operators.
// =======================================================================================

/* ***************************************************************************************
 * Function name: operator<<()
 * Description: This function will ouput the symol the event is to the screen
 * 		and it does not take the debug state of the class into account.
 * 		ALWAYS PRINT.
 * Parameters: std::ostream& const Event&.
 * Pre-conditions: Assumes that the Event is constructed with a m_symbol member.
 * Post-conditions: Prints the m_symbol of the event to the screen.
 * ***************************************************************************************/
// This displays the symbol of the Event.
// =====================
// Defined in Event.cpp
// =====================

// =======================================================================================
// Constructors.
// =======================================================================================
/* ***************************************************************************************
 * Function name: Wumpus()
 * Description: This is the default constructor. The used must create the instance as 
 * 		follows:
 * 			1. m_sound = The sound that the event makes when the user
 * 			   	     is in an adjacent room.
 * 			2. m_debug_moded = If true - the event will be printed by make_sound()
 * 					   if false - make_sound() prints nothing.
 * 			3. m_symbol = The symbol that represents the character on the 
 * 					screen/grid.
 * ***************************************************************************************/
// The default consrtuctor.
Wumpus::Wumpus(bool debug_mode)
:Event('w', "You smell a terrible stench...", debug_mode)
{}
// =======================================================================================
// The big three.
// =======================================================================================
// 1. Destructor.
/* ***************************************************************************************
 * ***************************************************************************************/
