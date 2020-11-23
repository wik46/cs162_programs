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

// The parent at the top followed by all its children.
#include "Event.h"
#include "Bat.h"
#include "Gold.h"
#include "Pit.h"
#include "Wumpus.h"
#include "Player.h"

#include <algorithm>
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
 * Description: The constructor of Grid will insert all the Room instance empty in the grid.
 * 		This function will be used to insert the Event* inside the rooms. It will
 * 		only insert them in order and then the random_shuffle() will
 * 		shuffle the grid. It will first determine if their is not already
 * 		an Event* in the Room. If there is one it will delete it.
 * Parameters: -
 * Pre-conditions: Assumes that the Grid already has Rooms in it after construction.
 * Post-conditions: This function sets all the 
 * ***************************************************************************************/
// This will remove any event that is stored in the place where a new one will be inserted.
void Grid::init(bool debug_mode){
	//bool debug_mode = true;
	for(int i = 0; i < get_dim(); i++){
		for(int j = 0; j < get_dim(); j++){			
			// This part inserts the 2 Bats events and the 2 Pit events.
			// ==========================================================
			if((j % 2 == 0) && (i == 0) && (j < 4)){
				// ===== This will delete the event from the room if it does have an Event*
				if(!get_v()[i][j].is_empty()){
					delete get_v()[i][j].remove();
				}
				// ====
				get_v()[i][j].insert(new Bat(debug_mode));
			}else if(i == 0 && j < 4){
				// ===== This will delete the event from the room if it does have an Event*
				if(!get_v()[i][j].is_empty()){
					delete get_v()[i][j].remove();
				}
				// ====
				get_v()[i][j].insert(new Pit(debug_mode));
			}
			// 2. Inserting the Wumpus and the Gold 
			// ==========================================================
			if( i == 1 && j == 0){
				// ===== This will delete the event from the room if it does have an Event*
				if(!get_v()[i][j].is_empty()){
					delete get_v()[i][j].remove();
				}
				// ====
				get_v()[i][j].insert(new Gold(debug_mode));
			}else if(i == 1 && j == 1){
				// ===== This will delete the event from the room if it does have an Event*
				if(!get_v()[i][j].is_empty()){
					delete get_v()[i][j].remove();
				}
				// ====
				get_v()[i][j].insert(new Wumpus(debug_mode));		
			}
		}
	}	
}	

// This function will be used to insert the player randomly after the 
// 	gameboard was shuffled.
/*
 * Function name: insert_player()
 * Description: This function inserts a player randomly into a game board, as well
 * 		as saves the player's init and current position.
 * Parameters: The Player is a child of Event*
 * Pre-condtitions: -
 * Post-conditions: -
 * */
void Grid::insert_player(Event* $){ // The dollar is the player symbol
	
	int i_e = 0, j_e = 0;
	do{
		// Calculate a random space to insert the player.
		i_e = rand() % (get_v().size());
		j_e = rand() % (get_v().size());
		// Seeing if I can remove a grid from full room to an empy room.
		// If the room is empty, the the function will insert the player, else
		// 	it will search for another one.
	// Continue searching if the Room is not empty.
	}while( !get_v()[i_e][j_e].is_empty() );// If this room is not empty.	
	
	// Inserting the Player instance into the empty room.
	get_v()[i_e][j_e].insert( $ ); 
	// Setting the initial and current position for my player.
	$->get_init_pos() = Vec2d(i_e, j_e);
	$->get_current_pos() = Vec2d(i_e, j_e);
			
	return;
}

/// THIS FUNCTION MAKES MY INIT AND EMPTY FUNCTINOS PRODUCES A SEG FAULT.
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
void Grid::random_shuffle(){

	for(int i = 0; i < get_v().size(); i++){
		for(int j = 0; j < get_v()[i].size(); j++){
			// Assuming a square grid.
			int i_e = rand() % (get_v().size());
			int j_e = rand() % (get_v().size());
			// Seeing if I can remove a grid from full room to an empy room.
			if(get_v()[i_e][j_e].is_empty()   // If this room is empty.
			&& !(get_v()[i][j].is_empty() )){ // If this room is not empty.	
				get_v()[i_e][j_e].insert(  get_v()[i][j].remove() ); 
			}
		}
	}
	return;
}
/* ***************************************************************************************
 * Function name: empty_rooms()
 * Description: This function will iterate through the entire Grid of rooms
 * 		and empty the room if it contains any event inside.
 * 		It will be used before init() inside the reset function if the user 
 * 		selected to start a new game.
 * Parameters: bool to depend if the function should empty. Set to true by default.
 * Pre-conditions: -
 * Post-conditions: If the parameter was set to true, all the rooms in the grid are empty.
 * **************************************************************************************/
void Grid::empty_rooms(bool exec){
	// This function will not clean the Rooms in the grid if the parameter is false.
	if(exec){
		for(int i = 0; i < get_dim(); i++){
			for(int j = 0; j < get_dim(); j++){			
				// ===== This will delete the event from the room if it does have an Event*
				if(!(get_v()[i][j]).is_empty()){
					delete get_v()[i][j].remove();
				}		// ====
			}	
		}	
	}
}
/* ***************************************************************************************
 * ***************************************************************************************/
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Display:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/* **************************************************************************************
 * Function name: search_around()
 * Description: This function will accept a head of a vector and search around the 
 * 		position given. This function will only print the N/E/S/W blocks
 * 		on the 2d-array. Note that becuase this is a 2d array with rows
 * 		and tables and not a cartesian plane, the vectors are not used correctly
 * 		to determine direction. Exampl <1,0> wich means one unit upwards
 * 		will go one unit downards if you add it to a point in the 2d_array.
 * Parameters: const Vec2d&
 * Pre-conditions: Takes in the head of a vector.
 * Post-conditions: Searches around the point given. Note that here it only prints the
 * 		    point. It can be used to do other tasks.
 * **************************************************************************************/

void Grid::search_around(const Vec2d& v) {
	// If the point inserted is not in the 2d_array then the function will inform the 
	// designer of the program.
	if(is_inside(v)){
		// Note that you are working with a table like array where (0,0) is
		// top left and not a cartesian plane. 
		Vec2d N(-1,0), E(0,1), S(1,0), W(0,-1);
		// This is so that I have the position of the adjacent blocks.
		Vec2d vN = v + N;
		Vec2d vE = v + E;
		Vec2d vS = v + S;
		Vec2d vW = v + W;
		// If the adjacent block is in the grid I want to perform an action on it.
		// ** Note that the objects stored in the array needs to be able to 
		// be printed to the console.
		// This only prints the elements but you can do anything with them.
		// ** The second condition determines of the room is empty.
		if(is_inside(vN) && !get_v()[vN.get_x()][vN.get_y()].is_empty()){
			// Going up and down rows is is moving parallel to the y axis
			get_v()[vN.get_x()][vN.get_y()].get_event()->make_sound();
		}
		if(is_inside(vE) && !get_v()[vE.get_x()][vE.get_y()].is_empty()){
			// Going up and down rows is is moving parallel to the y axis
			get_v()[vE.get_x()][vE.get_y()].get_event()->make_sound();
		}
		if(is_inside(vS) && !get_v()[vS.get_x()][vS.get_y()].is_empty()){
			// Going up and down rows is is moving parallel to the y axis
			get_v()[vS.get_x()][vS.get_y()].get_event()->make_sound();
		}
		if(is_inside(vW) && !get_v()[vW.get_x()][vW.get_y()].is_empty()){
			// Going up and down rows is is moving parallel to the y axis
			get_v()[vW.get_x()][vW.get_y()].get_event()->make_sound();
		}
	}else{
		// This is when the point inserted is not in the 2d array.
		std::cerr << "[_2d_Array.search_around() was passed a vector outside "
		<< " the array]" << std::endl;
	}
	return;
}

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
	// Setting all the event = null so that they do not contain garbage.
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

/* ***************************************************************************************
 * Function name: find_pos()
 * Description: THIS FUNCION RETURNS THE VECTORS OF THE SYMBOL
 * ***************************************************************************************/
Vec2d Grid::find_pos(char symbol){
	
	bool end = false;
	
	int i = 1, j = 1;
	for(i = 0; i < get_v().size(); i++){
		for(j = 0; j < get_v().size(); j++){
			if(!get_v()[i][j].is_empty()){
				if(get_v()[i][j].get_event()->get_symbol() == symbol){
				std::cout << get_v()[i][j].get_event()->get_symbol() << std::endl;
					
					end = true;
					break;
				}
			}
		}
		if(end){
			break;
		}
		
	}
	// This will return based on the bool = end.
	if(end){
		return Vec2d(i,j);
	}else{
		// This is the value that will return of no symbol was found.
		return Vec2d(-1,-1);
	}
}
/* ***************************************************************************************
 * Function name: is_boundry()
 * Description: This function returns true if the vector is on the boundry.
 * ***************************************************************************************/
bool Grid::is_boundry(Vec2d v,Vec2d dir){
	if(dir == Vec2d(-1,0)){
		if(v.get_x() == 0){
			return true;
		}
	}else if(dir == Vec2d(1,0)){
		if(v.get_x() == get_v().size() - 1){
			return true;
		}
	}else if(dir == Vec2d(0,1)){
		if(v.get_y() == get_v().size() - 1){
			return true;
		}
	}else if(dir == Vec2d(0,-1)){
		if(v.get_y() == 0){
			return true;
		}
	}
	return false;
}


