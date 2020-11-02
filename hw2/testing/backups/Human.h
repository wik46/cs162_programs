/* **************************************************************************************
 * Filename: Human.h.
 * Author: Lodewyk Jansen van Rensburg.
 * Date: October 25, 2020.
 * Description: This is the headerfile for the class Human. This class inherents 
 * 		form the base class Player. The purpose for the relationship is to define 
 * 		a function to acquire card input from a user differently for a human 
 * 		player than a computer player. 
 * Input: -
 * Output: -
 * **************************************************************************************/

#ifndef HUMAN_H
#define HUMAN_H
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"

#include <cassert>
#include <iostream>


class Human: public Player{

public:
	// The constructor.
	Human();
	// This function prompt the user to input an integer that will represent
	// the index in the Hand of the player.
	// This function is overwritten.
	/*const*/ Card get_input(std::string*);

};
#endif
