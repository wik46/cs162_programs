/* ***************************************************************************************
 * Filename: Grid.cpp
 * Author: Lodewyk Jansen van Rensburg
 * Date: November 22, 2020.
 * Assignment: Homework 4.
 * Description: This it the Grid class. It will contain multiple rooms. Each room can
 * 		be empty, contain a player, or an Event*.
 * 		The purpose of the grid is to:
 * 			1. Give me access to see who is in the adjacent rooms from the
 * 			   player's current position via the Next_door() function.
 * 			2. It will empty a Room using the Room.remove() member funcion.
 * 			3. It will inherent from the custom _2d_Array class.
 * 			4. It acts as an interface to the Rooms.
 * 			5. At its core, it is an 2d vector.
 * Input: -
 * Output: -
 * ***************************************************************************************/

#include "Grid.h"
#include "Room.h"
#include "_2d_Array.hpp" // The Grid inherents from the _2d_Array
#include "Vec2d.h"

#include <cassert>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <iomanip>

// =======================================================================================
// Hard working functions.
// =======================================================================================
/* ***************************************************************************************
 * Function name: init()
 * Description: The constructor of Grid will insert all the Room instance in the grid.
 * 		This function will be used to insert the Event* inside the rooms. It will
 * 		only insert them in order and then the random_shuffle() will
 * 		shuffle the grid. It will first determine if their is not already
 * 		an Event* in the Room. If there is one it will delete it.
 * Parameters: -
 * Pre-conditions: Assumes that the Grid already has Rooms in it after construction.
 * Post-conditions: This function sets all the 
 * ***************************************************************************************/

/* ***************************************************************************************
 * Function name: random_shuffle()
 * Description: This function will make used of the random_shuffle() defined in the 
 * 		std::vector container. It will be used after init() that is used to 
 * 		set give all the Rooms alreay in the grid the events that they need.
 * 		This function will shuffle all the Rooms in the grid and must be used 
 * 		directly after init().
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * ***************************************************************************************/


/* ***************************************************************************************
 * ***************************************************************************************/

/* ***************************************************************************************
 * ***************************************************************************************/

// =======================================================================================
// Overloaded operators.
// =======================================================================================

/* ***************************************************************************************
 * ***************************************************************************************/
// =======================================================================================
// Constructors.
// =======================================================================================
/* ***************************************************************************************
 * Function: Grid()
 * Description: THis is the only construtor that will be defined for the Room class.
 * 		It will greate a Square grid with the uniform Room passed into it.
 * 		This constructor create a square Grid of size n x n.
 * 		It then Rooms into the grid. The Rooms are stored on the Stack.
 *		It sets all the Event* in the Room to NULL.
 * Parameters: int, Room.
 * Pre-conditions: NB!! If you store an event inside a Room it must be a dynamic
 * 			Event.
 * Post-condition: -
 * ***************************************************************************************/
Grid::Grid(int n)
:_2d_Array<Room>(n)
{
	std::cout << "Grid constructor" << std::endl;
	// Making sure that the array has at least one element.
	assert(n > 0 && "[Unable to construct array]: Must have size of at leaste one");	
/*	// setting size of the vector for to store the vectors inside.
	//m_array.reserve(n);
	// Now each vector will also contain a vector of size n.
	for(int i = 0; i < n; i++){
		// First I resize the vector so that there is room to insert variables.
		//m_array[i].reserve(n);
		for(int j = 0; j < n; j++){
			std::cout << i << j<< std::endl;
			//Room* tmp = Room(NULL);
			//Room& tmp_ref = *tmp;
			//_2d_Array<Room>::get_v()[i][j] = Room(NULL);	//j++;
		}
	}
*/
}



// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Destructor:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// =======================================================================================
// The big three.
// =======================================================================================
// 1. Destructor.
/* ***************************************************************************************
 * Function name: Grid()
 * Description: You do not need to destructor because you are storing all your Room on 
 * 		the stack.
 *
 * ***************************************************************************************/
Grid::~Grid(){}

