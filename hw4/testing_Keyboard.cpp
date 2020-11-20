/* **************************************************************************************
 * Filename: testing_Keyboard.cpp.
 * Author: Lodewyk Jansen van Rensburg.
 * Date: November 22, 2020.
 * Description: 
 * Input: -
 * Output: -
 * **************************************************************************************/

#include "Player.h"
#include "Keyboard.h"
#include "Vec2d.h"


#include <cassert> 
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <string>

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Actions the player can peform:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// ========
// 1. Move:
// ========
/*
	 This will be implemented using the move() member function.
	 The keyboard class will take in the user input and validate it. Then it
	 will return the Vec2d object to where the player will move.
	 The function will accept a Vec2d as argument. This will be the new position
	 to where the player will move. It will take in the direction
	 to where the player moves and return the current position
	 of the player.  This function will update the player's
	 current position on the grid as well as return the current position
	 of the player so that the grid gets the information as well.

 */
// =========
// 2. Shoot:
// =========
/*
	 The keyboard class will take in the user input and validate it. Then it
	 will return the Vec2d object to where the player will shoot an arrows.
	 The shoot() member function will return the direction where the arrow was
	 shot and it will decrement the number of arrows available for the user to 
	 use.
 */

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// How to think about direction on the grid:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/*
 	Because the 2d grid has its origin in the top left hand corner
	and not the bottom left hand corner like the cartesian plane, we need
	to user the "vector" incorrectly in order to move to the desired point
	in the grid.

 	To move:
		North: Add the Vec2d <-1,0>
		South: Add the Vec2d <1,0>
		East: Add the Vec2d <0,1>
		West: Add the Vec2d <0,-1>

*/
 
int main(){
	Vec2d init(0,0), current(0,0);
	unsigned int grid_size = 10;
	// This is how to intitalize a player.
	Player p(init, current, 3);
	// =============================
	// Creating the Keyboard class.
	// =============================
	// This is how to initialize a Keyboard used for the game.
	// 1. The keyboard must be created with the player's initial position.
	Keyboard k(init, grid_size);
	// ** This is a very helpful function ** //
	// It will give you all the current information regarding the Player's members.
	p.print_all_info();
	// ** This is a very helpful function ** //
	// It will give you all the current information regarding the Keyboard's members.
	k.print_all_info();
	prompt_move();	

	init * 10;

	// =========================
	// Using the get() function.
	// =========================
	std::cout << std::endl;
	std::cout << k.get() << std::endl;	
	k.print_all_info();
	
	// =========================
	// Using the dir() function.
	// =========================
	while(1){
		//std::cin >> current; 
		std::cout << "get(): " << k.get() << std::endl;
		Vec2d dir = k.dir(); // NB!! dir() should only run once per round.
		std::cout << "dir(): "<< dir << std::endl;	
		// This will move the player to the space that he/she needs to be. 
		p.move(dir);	
		// Seeing all the members of the classes.
		k.print_all_info();
		p.print_all_info();
	}
	return 0;
}
