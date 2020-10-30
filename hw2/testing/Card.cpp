/* **************************************************************************************
 * Filename: Card.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Lab: Lab3.
 * Date: October 13, 2020.
 * Description: This is the implementation file for my Card class. 
 * 		Note that the cards will not
 * 		be accessed individually by the main program. The only way to access a 
 * 		single card will be to first work through the Deck class defined in
 * 		Deck.cpp. 
 * Input: -
 * Output: -
 * **************************************************************************************/

#include "Card.h"

#include <iostream>
#include <iomanip>
// The Deck class will constist of an array of 52 const Card elements.
	
// 0-12. (0 - ace, ..., 10 - jack, 11 - queen, 12 - king)	
// 'c' - clubs, 'd' - diamonds, 'h' - heart, and 's' - spades.

//Member funtions.	
// The default constructor.
/* **************************************************************************************
 * Function name: Card()
 * Description: The defaul constructor is set as a private member 
 * 		because the user of the class needs to instantiate 
 * 		the object with the other provided constructor.
 * Parameters: -
 * Pre-condtions: Constructs a card instance with default values.
 * Post-condtions: -
 * **************************************************************************************/
Card::Card(): m_rank(-1), m_suite("default suite "){
	//std::cout << "Default Card constructor." << std::endl;
}

/* *************************************************************************************** 
 * Function name: Card()
 * Description: This constructor will be used when creating a deck of cardsi. The m_rank
 * 		is set to -1 so that the program will no it does not contain valid rank.
 * Pre-condtions: This constructor is used by the Deck class to create
 * 		   a deck of 52 Card instance.
 * Post-conditions: A Card instance with a rank of i and a suite of Ace - 0, ..., 
 * 		    jack - 11, queen - 12, and king - 13.
 * **************************************************************************************/

Card::Card(int i): m_rank(-1), m_suite("default suite")
{
	//std::cout << "Constructor 2 called." << std::endl;	
	set_suite_and_rank(i);
} 
// Accessors.
/* **************************************************************************************
 * Function name: get_rank()
 * Description: This function returns the m_rank member variable. 
 * 		It is a const function and will not change the value of the member.
 * Paramter: -
 * Pre-conditions: -
 * Post-condtions: Returns the m_rank member variable.
 * ***************************************************************************************/
int Card::get_rank() const{
	return this->m_rank;
}
/* **************************************************************************************
 * Function name: get_suite()
 * Description: This function returns the m_suite member variable. 
 * 		It is a const function and will not change the value of the member.
 * Paramter: -
 * Pre-conditions: -
 * Post-condtions: Returns the m_suite member variable.
 * ***************************************************************************************/
std::string Card::get_suite() const{
	return this->m_suite;
}
/* **************************************************************************************
 * Function name: print_card()
 * Description: This funcion is only used for development purposes
 * 		and will not be used by the the program for other
 * 		purposes.
 * Paramters: -
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/ 
void Card::print_card() const{
	std::cout << "Rank: " << this->m_rank << "." << std::endl;
	std::cout << "Suite: " << this->m_suite << "." << std::endl;
}	

// Mutators.
//
/* **************************************************************************************
 * Function name: get_suite()
 * Description: This function will be used to change the value the suite of a card.
 * Paramters: -
 * Input: Assumes that the card's suite needs to be changed.
 * Output: Changes the Card instance's suite.
 * **************************************************************************************/
std::string& Card::get_suite(){
	// 'c' - clubs, 'd' - diamonds, 'h' - heart, and 's' - spades.
	return m_suite;
};

/* **************************************************************************************
 * Function name: set_suite_and_rank()
 * Description: This function will be used when an instace of a Card is created.
 * 		The function will be used inside a for loop to create an array of 52
 * 		Card instances. The counter in the for loop will be passed as the 
 * 		argument to the function.
 * Parameters: int
 * Pre-consditions: Only use once per Card instance.
 * Post-conditions: Instantiates the member variables of a Card instance.
 * **************************************************************************************/

void Card::set_suite_and_rank(int i){
	// Setting the rank.
	this->m_rank = i % 13 + 1;
	// Setting the suite.
	if(i/13 <  1){
		// Setting the suite to clubs.
		this->m_suite = 'c';
	}else if(i / 13 < 2){
		// Setting the suite to diamonds.
		this->m_suite = 'd';
	}else if(i / 13  <  3){
		// Setting the suite to hearts.
		this->m_suite = 'h';
	}else if(i / 13 <  4){
		// Setting the suite to spades.
		this->m_suite = 's';
	}else{
		std::cout << "[set_suite_and_rank()]: Error suite not set." << std::endl;
	}
}

// Overloaded operators.
/* **************************************************************************************
 * Function name: operator<<()
 * Description: This is a form of operator overloading. It will allo me
 * 		to use an output stream to print my card object.
 * Parameters: &ostream, Card&.
 * Pre-conditions: - 
 * Post-conditions: Enables me to use std::cout with an instance of a Card class.
 * **************************************************************************************/
// Since operator<<() is a friend of Card, we can access its members directly.
std::ostream& operator<<(std::ostream& stream, const Card& card){
	stream << std::fixed << std::setprecision(2);
	stream << std::left << std::setw(3) << std::setfill(' ');
	stream << card.get_rank() << ", " << card.get_suite();
	// NB! Remeber to return the stream object.
	return stream;
}
/* **************************************************************************************
 * Function name: operator==()
 * Description: This will determine if two cards are equal. Two cards are equal iff
 * 		they have the same suite and rank.
 * Parameters: const Card&, const Card&.
 * Pre-conditions: - The instances of the Card objects must have value.
 * Post-conditions: The function returns true if the cards are equal and 
 * 		    false otherwise.
 * **************************************************************************************/

bool Card::operator==(const Card& r_card){
	if(this->m_rank == r_card.m_rank 
	&& this->m_suite == r_card.m_suite){
		// Equal cards.
		return 1;
	}else{
		// Not equal cards.
		return 0;
	}	
}
