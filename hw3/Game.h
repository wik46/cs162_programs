/* **************************************************************************************
 * Filename: Game.h
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: November 8, 2020.
 * Description: This is the implementation file for the Game class. This
 * 		class will contain all the member needed to play the game
 * 		Zoo Tycoon. It will have a player, a Zoo that starts of with no Animals
 * 		, and various member functions that run the game for the user. An 
 * 		examples is start_game() which is used by start game.
 * Input: -
 * Output: -
 * **************************************************************************************/

#ifndef GAME_H
#define GAME_H

#include "Animal.h"
#include "Bear.h"
#include "Sea_lion.h"
#include "Tiger.h"
#include "Date.h"
#include "Player.h"
#include "Probability.h"


#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>


class Game{
	// This will represent the player of the game.
	// This is only a one player game.
	Player m_player;
	// This class will be used to increase/decrease the probability of animals 
	// sick.
	Probability m_prob;
	// This will be all inside the game class	
	Zoo m_zoo;

	// This function will store the game_state.
	// The game_state can be: 'not_started', 'in_progress', 'finished', or 
	// 'terminated.'
	std::string m_game_state;

public:
	Game();
	// The destrutcor.
	~Game();
	// Accesors and mutators.
	Player& get_player();
	Probability& get_prob();
	Zoo& get_zoo();
	const std::string& get_game_state();

	// This function is used inside Start_game().
	void Start_game();
	void print_game_rules();	
	void print_round(int round) const;
	// This function will be used to implement all the needed work
	// for the end of a round
	void Play_next_round();
	// This is used inside Play_next_round() to help modularize my code.
	void probability_decider(std::string);
};

// Non-member functions.
// =====================
void press_enter();		

#endif







