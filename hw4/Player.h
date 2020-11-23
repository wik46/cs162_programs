/* **************************************************************************************
 * Filename: Player.h.
 * Author: Lodewyk Jansen van Rensburg.
 * Date: November 2, 2020.
 * Description: This is the implementation file for the class Player. 
 * 		Please see Player.cpp for more information.
 * **************************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H
#include "Vec2d.h" // Mathematical vector not the std::vector.
#include "Event.h"

#include <cassert> 
#include <unistd.h>
#include <iostream>

class Player: public Event{
	// The player's name.
	std::string m_name;
	// This is used to determine if the game has ended with a win or a los.
	// Player win: The player is standing on the initial 
	// 		position with m_has_gold = true
	// Player loses: If the game has ended and m_has_gold = false.
	bool m_has_gold;
	// Initial position.
	Vec2d m_init_pos;
	// Current position.
	Vec2d m_current_pos;
	// The direction of the shot fired by the user.
	Vec2d m_shot_dir;
	// The player's number of arrows.
	unsigned int m_num_arrows;
public:
	// ========================
	// Player actions.
	// ========================
	// 1. This will move the player to the position given as a vector.
	const Vec2d& move(const Vec2d&);
	// 2. This will decrement the number of arrows of the player.
	void make_shot();
	// 3. This will set the m_has_gold to true.
	void pick_up_gold();
	// 4. This will be used inside the reset() function in the Game class
	//    to reset the game for a new one. This function set m_has_gold = false.
	void reset_gold();
	

	// ========================
	// Accessors and Mutators.
	// ========================
	// 1. This function will gives me access to my member variables.
	std::string get_name() const ;
	// 2. True -> player has picked up the gold	
	bool get_has_gold();
	// 3. Initial position.
	Vec2d& get_init_pos()override;
	// 4. Current position.
	Vec2d& get_current_pos()override;
	// 5. Returns the shot direction of the player.
	Vec2d& get_shot_dir(){return m_shot_dir;}
	
	// 6. Returns the number of arrows.
	// 	Will return 0 if no arrows left.
	unsigned int get_num_arrows(); 
	
	// ========================
	// Development helpers.
	// ========================
	// This function will print the current state of all the player's members.
	void print_all_info();
	
	// ========================
	// Constructor.
	// ========================
	// This will create a player with the default of three arrows.
	// 1. Initial position, current position, number of arrows.
	Player(const Vec2d&, const Vec2d&, bool debug_mode = true ,unsigned int total = 3);
private:
	// This function will be used inside the constructor to ask the user for 
	// there name and print out a nice message. 
	void set_info();

};


/* **************************************************************************************
 * Function name: ask_for_input()
 * **************************************************************************************/
std::string ask_for_input();
/* **************************************************************************************
 * Function name: is_valid()
 * **************************************************************************************/
bool is_valid(std::string* str1);
/* **************************************************************************************
 * Function name: get_int()
 * **************************************************************************************/
// This is used for the first part of getting use input.
int get_int(std::string prompt = "default_prompt" 
	,std::string error_msg = "Your input is invalid");

#endif
