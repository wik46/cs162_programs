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
#include "Human.h"
#include "Player.h"

#include <iostream>

int main(){

	Game g;
	g.m_deck.shuffle_deck();
	g.m_deck.print_deck();
	g.hand_out();
	std::cout << g.get_deck()[g.m_deck.get_toppile_card()] << std::endl;
	std::cout << g.get_deck()[g.m_deck.get_toppile_card() + 1] << std::endl;
	std::cout << g.get_deck()[g.m_deck.get_toppile_card() + 2] << std::endl;
	std::cout << g.get_deck()[g.m_deck.get_toppile_card() + 3] << std::endl;
	std::cout << g.m_player_ar[0].get_hand() << std::endl;	
	g.m_player_ar[0].pick_card_up(&g.m_deck);
	g.m_player_ar[0].pick_card_up(&g.m_deck);
	g.m_player_ar[0].pick_card_up(&g.m_deck);
	g.m_player_ar[0].pick_card_up(&g.m_deck);
	std::cout << g.m_player_ar[0].get_hand() << std::endl;	
	std::cout << g.get_deck()[g.get_deck().get_toppile_card() - 1] << std::endl;	
	return 0;
}
