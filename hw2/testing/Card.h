/* **************************************************************************************
 * Filename: Card.h
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Lab: Lab3.
 * Date: October 13, 2020.
 * Description: This is the header file for my Card class. Note that the cards will not
 * 		be accessed individually by the main program. The only way to access a 
 * 		single card will be to first work through the Deck class defined in
 * 		Deck.cpp. 
 * Input: -
 * Outpu: -
 * **************************************************************************************/

#ifndef CARD_H
#define CARD_H

#include <iostream>

// The Deck class will constist of an array of 52 const Card elements.
class Card{
	// Member variables.
	// 1-13. (1 - ace, ..., 11 - jack, 12 - queen, 13 - king)
	int m_rank;
	// 'c' - clubs, 'd' - diamonds, 'h' - heart, and 's' - spades.
	std::string m_suite; 
public:
	//Member funtions.	
	// The default constructor.
	Card();
	// The second destructor.
	// This will be used by the Deck class to create a deck of 52 cards.
	Card(int);
	// Note that there are no dynamic memory allocation done by a Card class.
	// Therefore it uses the default descrutctor, copy constructor, and
	// assignment operator to the a shallow copy
	
	// This will allow the user to print the information of a single card.
	void print_card() const;	
	// Accessors.
	int get_rank() const;
	std::string get_suite() const;
	// Mutator.
	std::string& get_suite();
	
	// This is the overloaded bitwize operator.
	friend std::ostream& operator<<(std::ostream&, const Card&);
	// The overloaded equality operator.
	bool operator==(const Card&);
private:
	// Mutators.
	// This will only be used by the constructor when creating a card.
	void set_suite_and_rank(int);
};

#endif

