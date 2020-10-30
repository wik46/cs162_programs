/*
 * Filename: Player.h.
 * Author: Lodewyk Jansen van Rensburg.
 * Date: October 25, 2020.
 * Description: This is the headerfile for the class Player. An instance of 
 * 		Player will have two children: Human and Computer. The only differences between 
 * 		these inhereted classes is the get_card() function. Because the Human will be 
 * 		prompted to enter a valid card where as the computer will choose a random card from
 * 		its hand.
 * Input:
 * Output:
 * */

#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Hand.h"
#include "Deck.h"

#include <cassert> 
#include <iostream>

class Player{
protected:
	// This will represent a hand of cards. The initial number of cards is 7.
	Hand m_hand;
	// The player's name.
	std::string m_name{"default name"};

public:
	// Constructor.
	Player();	
	// Destructor.
	// Accessors (getters) and mutators (setters).
	Hand& get_hand();
	std::string& get_name();
	// The take turn functions.
	//Card get_card(Card*);
	// This function is used in the driver file.
	void Take_turn(Deck*, int);
private:
	// Human input version.
	virtual Card get_input();
	// Computer input version.
	Card get_input(Deck* ,const char*);
	
protected:	
	// Take_turn() functions.
	void put_card_down(Deck*, Card*);
	void pick_card_up(Deck*);
};

#endif
