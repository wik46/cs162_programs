/* **************************************************************************************
 * Filename: Deck.h.
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Lab: Lab3.
 * Date: October 13, 2020.
 * Description: This is the header file for my Deck class. The main program 
 * 		will use a Deck of cards. The class Deck can will make use of a dynamic
 * 		array on the heap consisting of 52 const Card instances. An instance
 * 		of a Deck class will have the functionality to shuffle itself. 
 * 
 * Input: -
 * Output: -
 * **************************************************************************************/


#ifndef DECK_H
#define DECK_H

#include "Card.h"

#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>


// A deck of cards will consist out of 52 cards. It will be stored in a dynamic array
// of 52 elements.
class Deck{
	// Member variables.
	Card* m_deck; // The deck will consist out of 52 Card instances.
	unsigned int m_size;		
	

	// This card will represent the Card that is liying face up on the deck.
	Card m_faceup_card;
	// This will be the index of the top of the pile of unused cards.
	int m_toppile_card;
public:
	// The Constructor.
	Deck();	
	// Desctrucor.
	~Deck();	
	// Copy	 Constructor.

	// Accessor functions (getters).
	Card* get_deck();
	// 
	Card& get_faceup_card();
	// More getters.
	int& get_toppile_card();
	
	// Overloaded assignment operator.
	Deck& operator=(const Deck&);
	// Shuffle deck. 
	void shuffle_deck();
	// Print the deck to the screen.
	void print_deck() const;
	// The overloaded subscript operator.
	Card& operator[](int);
private:	
	// This function will only be used by the constructor and is a private member.
	void create_deck();
	// I do not want to provide people access to the defaul copy constructor.
	Deck(const Deck&);
};

#endif
