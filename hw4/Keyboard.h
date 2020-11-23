/* ***************************************************************************************
 * Filename: Keyboard.h
 * Author: Lodewyk Jansen van Rensburg.
 * Data: November 22, 2020.
 * Description: This is the header/interface file for the Keyboard class. See Keyboard.cpp
 * 		for any further descriptions.
 * Input: -
 * Output: -
 * **************************************************************************************/

#ifndef KEY_BOARD_H
#define KEY_BOARD_H

#include "Player.h"
#include "Vec2d.h"



#include <iostream>
class Keyboard{
	// Member variables.
	// 1. The sound that the event makes when the player is in the adjacent room.
	Vec2d m_input;
	// 2. This will be the new position on the board to which the Player will move.
	// The keyboard must be created with the player's initial position.
	Vec2d m_player_pos;
	// 3. This keeps track of the player's previos position.
	Vec2d m_prev_pos;
	// 3. This vector represents the shot made by the user.
	Vec2d m_shot_dir;

	// 4. This member will know what is the size of the grid.
	unsigned int m_grid_size;
	// 5. These vectors will be added to the Player's position to calculate the new
	//    position towards where the Player should move.
	const Vec2d N,E,S,W;



public:	
	// Member functions.
	// ========================
	// Hard Working functions.	
	// ========================
	const Vec2d& get(Player& p);
	const Vec2d/*&*/ dir();
	void shoot(Player& p, const std::string&);
	
	// ========================
	// Development helpers.	
	// ========================
	void print_all_info();

	// =====================
	// Getters and Setters.
	// =====================
	Vec2d& get_player_pos();
	Vec2d& get_prev_pos();
	const Vec2d& get_input();
	// =====================
	// Overloaded operators.
	// =====================
	// ==============
	// Constructors.
	// ==============
	// The default consrtuctor.
	Keyboard(const Vec2d&, unsigned int size = 4);
	// ==============
	// The big three.
	// ==============
	// 1. Destructor.
	virtual ~Keyboard() = default;
	
	// ==================
	// Private Functions.
	// ==================
//private:
	// 1. This returns true if the vector is on the boundry grid.
	bool is_boundry(const Vec2d&);	
	// 2. Calculates the direction that the player should move when on the boundry.
	const Vec2d/*&*/ calc_boundry_move(Vec2d&, const Vec2d&, int);
};


// Used inside get() to format user instruction.
void prompt_move();
#endif 
