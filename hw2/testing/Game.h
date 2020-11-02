/* **************************************************************************************
 * Filename: Game.h
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date:October 25, 2020.
 * Description: This is the implementation file for the Game class. This
 * 		class will contain all the member needed to play the game
 * 		Crazy eights. It will have two players, a Deck of cards, and
 * 		various member functions that run the game for the user. Examples
 * 		are start_game(), hand_out() which is used by start game.
 * Input: -
 * Output: -
 * **************************************************************************************/

#ifndef GAME_H
#define GAME_H

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"

#include <cassert>
#include <iostream>
#include <ctime>

class Game{
// ##### ONLY TEMPORARY #####.
public:
	// This will be initialized with 52 cards that each contain the correct suite.
	Deck m_deck;
	// This function will store the game_state.
	// The game_state can be: 'not_started', 'in_progress', 'finished', or 
	// 'terminated.'
	std::string m_game_state;
	// This will be an array of Players.
	// The size wil be deterined by m_num_players.
	Player* m_player_ar;
	// This variable store the number of players in the game.
	int m_num_players;

public:
	// This function starts the game.
	void Start_game(int*);
	void print_round(int) const;
	// This function will hand out the default hand_size
	// of cards to each player.
	void hand_out(int hand_size = 7);
	// This will empty the player's hand so 
	// that 7 new cards can be inserted.
	void reset_hand();
	void Evaluate_round_end();
	// Used inside Evaluate_result().
	void who_is_winner();
	void Evaluate_result();
	// Accessor.
	Deck& get_deck();
	// The constructor.
	Game(int num_player = 2);
	// The destrutcor.
	~Game();
	// This function is used inside Start_game().
	void print_game_rules();	
};

#endif







