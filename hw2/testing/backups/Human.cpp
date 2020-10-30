/* **************************************************************************************
 * Filename: Human.cpp.
 * Author: Lodewyk Jansen van Rensburg.
 * Date: October 25, 2020.
 * Description: This is the implementation file for the class Human. This class inherents 
 * 		form the base class Player. The purpose for the relationship is to define 
 * 		a function to acquire card input from a user differently for a human 
 * 		player than a computer player. 
 * Input: -
 * Output: -
 * **************************************************************************************/

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Human.h"
#include "Player.h"

#include <iostream>
#include <cassert>
#include <string>

// The contructor.
Human::Human(): Player(){
	std::cout<< "Human created."  << std::endl;
}

/* ***************************************************************************************
 * Function name: get_card().
 * Description: This function is used to get user input. It will prompt the user to 
 * 		select a card to play for the round. If the user can play a valid card and
 * 		does so, the function will return the card. If the user enters a card that
 * 		is not in his/her hand, then the function will reprompt the user to enter
 * 		valid input. The user will be informed to press enter if they can't make 
 * 		a move.
 * Parameters: -.
 * Pre-conditions: Accepts the card that is unfaced on the table.
 * Post-condtions: Returns a valid card in the user's hand or the default card if the
 * 		   user can not make a move.
 * **************************************************************************************/
///#####################
/*const*/ Card Human::get_input(std::string* user_in){
	assert(user_in != NULL);
	std::cout << "\nYour turn to make a move." << std::endl <<
	"If you cannot make a move, then type '0'." 
	<< std::endl;
	//std::cin.getline(user_in,256);
	std::cout << "Look: " << *user_in << std::endl;
	std::cin >> *user_in;
	char tmp = (*user_in)[0];
	// This checks if the user entered an enter key.
	if(tmp - 48 == 0){
		// It is accpetable to return a local variable becuase I am returnin by
		// value.
		return Card();
	// The user will enter a numeric char to select the card that he/she want to play.
	}else if (tmp - 48 > 0 && tmp - 48 <= get_hand().get_size()
		&& (*user_in).length() == 1){	
		std::cout << tmp - 48 << std::endl;
		std::cout << "\nThat card is in deed inside your hand.\n" << std::endl;	
		// If the user enters 1, then the function will return the card at index
		// 0 to the user. If 2, then return 1 and so on...
		return get_hand()[tmp - 48 - 1];
	}else{
		return this->get_input(user_in);
	}
}

	// Displays the current use hand.

