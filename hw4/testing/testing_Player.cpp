/* **************************************************************************************
 * Filename: testing_Player.cpp.
 * Author: Lodewyk Jansen van Rensburg.
 * Date: November 22, 2020.
 * Description: This is the implementation file for the Player class.
 * 		1. It is important to note that the Player's position will be represented
 * 			by a Vec2d class. Note that the direction of the vectors will not
 * 			be correct becuase the (0,0) is top left and not bottom right.
 * 		2. A Player will win the game if during Evaluate_round() the player
 * 			"has the gold"  ie m_has_gold = true.
 * 		   A Player will lose the game if m_game_state = "finished" and 
 * 		   m_has_gold = false.  
 *
 * Input: -
 * Output: -
 * **************************************************************************************/

#include "Player.h"
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
	Vec2d init(1,0), current(4,2);
	// This is how to intitalize a player.
	Player p(init, current, 3);
	// ** This is a very helpful function ** //
	// It will give you all the current information regarding the Player's members.
	p.print_all_info();

	init * 10;
	// Using move()
	// Enter the direction that the player should move:
	// ** The Keyboard class will validate the input.
	std::cout << std::endl;
	Vec2d North(-1,0), South(1,0), East(0,1), West(0,-1);	
	std::cout << "Current position retrieved from move(): "<< p.move(West) << std::endl;
	// Using pick_up_gold().
	// This set the m_has_gold member to true.
	p.pick_up_gold();
	p.print_all_info();
	// Using reset_gold().
	p.reset_gold();
	p.print_all_info();

	return 0;
}
