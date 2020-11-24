/* **************************************************************************************
 * Filename: Game.h
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: November 8, 2020.
 * Description: This is the implementation file for the Game class. This
 * Input: -
 * Output: -
 * **************************************************************************************/

#ifndef GAME_H
#define GAME_H

#include "Event.h"
#include "Room.h"
#include "_2d_Array.hpp"

#include "Vec2d.h"
#include "Grid.h"
#include "Keyboard.h"

#include "Bat.h"
#include "Gold.h"
#include "Pit.h"
#include "Wumpus.h"
#include "Player.h"

#include <iostream>
#include <iomanip>
#include <cassert>


#include <algorithm>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class Game{
	// This will represent the player of the game.
	// This is only a one player game.
	Player m_player;
	// 2. This will be a wrapper around a vector of vector
	// 	from the C++ STL.
	Grid m_grid;
	// 3. This is used to validate used input as well as calculate the user's
	// 	to move after input.
	Keyboard m_keyboard;
public:	// 4. 
	static std::string m_game_state;
public:
	Game(int size = 4, bool debug = true);
	// The destrutcor.
	~Game();
	// Accesors and mutators.
	// 1.
	Grid& get_grid();
	// 2.
	Player& get_player();
	// 3.
	Keyboard& get_keyboard(); 
	// 4.
	std::string& get_game_state();
	// 5. 
	void Get_input();
	// 6.
	void move();
	// 7.
	void shoot();
	// This function is used inside Start_game().
	void Start_game();
	void print_game_rules();	
	void print_round(int round) const;
	void Evaluate_round();
	// This function will be used to implement all the needed work
	// for the end of a round
//	void Play_next_round();

	Vec2d find_pos(char);
	
};

// Non-member functions.
// =====================
void press_enter();		
bool validate_input(int&, char**);
void print_options();
#endif







