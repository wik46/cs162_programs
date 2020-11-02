/* **************************************************************************************
 * Filename: driver.cpp.
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Lab: Lab3.
 * Date: October 13, 2020.
 * Description: The purpose of this program is to demonstrate how to use the Deck and 
 * 		Card class for a card game. This program will create a deck of cards,
 * 		shuffle is an print it to the screen. 
 * Input: -
 * Output: A shuffled deck of cards printed to the screen.
 * **************************************************************************************/


#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include "Hand.h"
#include "Player.h"

#include <iostream>

int main(){
	Game g;
	int round = 0;
	do{
		// This function will only be called once when m_game_state = "not_started"	
		g.Start_game(&round);
		g.print_round(round + 1);
		if(round % 2 == 0){
			// This is a move made by the human.
			g.m_player_ar[0].Take_turn(&g.m_deck, round);
		}else{
			// This is a move made by the computer.
			g.m_player_ar[1].Take_turn(&g.m_deck, round);
		}
		// This gets called while m_game_state = "in_progress".
		// This function set m_game_state = "finished" if the deck is empty
		// or if a player has no cards in his/her hand.
		g.Evaluate_round_end();
		// This only gets called when m_game_state = "finished".
		// If user wants to play again it sets m_game_state = "not_started".
		// If user wants to quit it set m_game_state = "terminated".
		g.Evaluate_result();	
		round++;
	
	}while(g.m_game_state != "terminated");
	std::cout << "\nGoodbey." << std::endl;
	return 0;
}
