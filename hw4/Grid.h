/* ***************************************************************************************
 * Filename: Grid.h
 * Author: Lodewyk Jansen van Rensburg
 * Date: November 22, 2020.
 * Assignment: Homework 4.
 * Description: This it the Grid class. It will contain multiple rooms. See Grid.h
 * 		for more information and explanation.
 * Input: -
 * Output: -
 * ***************************************************************************************/

#ifndef GRID_H
#define GRID_H

#include "_2d_Array.hpp" // The Grid inherents from the _2d_Array
#include "Room.h"
#include "Vec2d.h"

// The parent on top followed by all its children.
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


class Grid: public _2d_Array<Room> // Room is a custom data type that has the Event* member
{
public:
	// ==================
	// Working functions:
	// ==================
	// 1. Inserts events into the room. Only use if you know all rooms are empty.
	// ** This is meant to be used just after empty_rooms() inside the Start_game() 
	// function.
	//
	// ** This function decides of the game is going to be in 
	// 	debug mode or in normal mode.
	void init(bool debug_mode = true); // Only true for development purposes.
	
	// 2. Empty's all the Rooms from the Event. If empty = false, then no cleaning occurs.
	void empty_rooms(bool empty = true);
	// 3. This function will be used after init() to shuffle the rooms randomly.
	void random_shuffle();
	// 4. This function must be used after the random_shuffle to insert the player into 
	// 	the grid. It sets the player's init and current pos.
	void insert_player(Event* );
	// 5. Returns the position of the symbol as a vector.
	Vec2d find_pos(char);
	// =================
	// Display:
	// =================
	void search_around(const Vec2d&);
	// =================
	// Constructor:
	// =================
	// 1. This creates a grid with n x n size and stores empty dynamic Rooms int the array.
	Grid(int);
	
	// =================
	// Destructor:
	// =================
	~Grid();
	
	// Rest of the Big Three.
	Grid(const Grid&) = delete;
	Grid& operator=(const Grid&) = delete;


};

#endif
