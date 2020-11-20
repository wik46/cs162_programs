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


#include <cassert>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <iomanip>


class Grid: public _2d_Array<Room> // Room is a custom data type that has the Event* member
{
public:
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
