/*
 * Filename: Hand.h
 * Author: Lodewyk Jansen van Rensburg.
 * Date: October 25, 2020.
 * Description: This is the headerfile for my Hand class. The main purpose
 * 		of a hand is to act as an array of cards that is dynamically allocated
 * 		so that the size of the array can change as the number of cards
 * 		in the players hand varies.
 * Input: - 
 * Output: -
 **/

#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <cassert>
#include <iomanip>
#include <iostream>

class Hand{
	// This will be a dynamic array of Card instances.
	Card* m_card_ar;
	int m_hand_size;
public:
	// The default constructor.
	//Hand();
	// Creates a array of cards of size 7 as default.
	Hand(int size = 7);	
	// The destructor.
	~Hand();
	// The copy constructor.
	Hand(const Hand&);
	// The overloaded assignment operator.
	Hand& operator=(const Hand&);	
	// The overloaded subscript operator.	
	// Const.
	const Card& operator[](int) const;
	// The overloaded subscript operator.
	// Non-const.	
	Card& operator[](int);
	// Overloaded bitshift operator.
	friend std::ostream& operator<<(std::ostream&, const Hand&);
	// Overloaded prefix plus operator.
	// This will return the array of Card instances with length + 1.
	Hand& operator++();
	// Overloaded decrement operator.
	// This will return the Hand without the last card in the hand.
	Hand& operator--();
	// Getters.
	const int get_size() const;
};

#endif
