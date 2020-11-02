/* **************************************************************************************
 * Filename: Deck.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Lab: Lab3.
 * Date: October 13, 2020.
 * Description: This is the implementation file for my Deck class. The main program 
 * 		will use a Deck of cards. The class Deck can will make use of a dynamic
 * 		array on the heap consisting of 52 const Card instances. An instance
 * 		of a Deck class will have the functionality to shuffle itself. 
 * 
 * Input: -
 * Output: -
 * **************************************************************************************/

#include "Card.h"
#include "Deck.h"

#include <cassert>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <unistd.h>

/* **************************************************************************************
 * Function name: Deck()
 * Description: A deck of cards will consist out of 52 cards. It will be stored in a 
 * 		dynamic array of 52 elements.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: The Deck of cards is created with the unface card the card at index 0,
 * 		    and the top of the pile at index 1.
 * **************************************************************************************/

Deck::Deck(): m_deck(NULL), m_size(52) // The size of the deck of cards will always be 52
{	
	create_deck();
	// This is to seed the random number generator.
	// I only seed the random number generator once.
	
	srand(time(NULL));
}

/* ***************************************************************************************
 * Function name: ~Deck()
 * Description: This function is used to clean up all the dynamic memory used
 * 		by an instance of a Deck class.
 * Paramters: - 
 * Pre-condtions: The function will only free memory if it was allocated.
 * Post-condtions: The function free's any dynamic memory.
 * **************************************************************************************/
Deck::~Deck(){
	if(m_deck != NULL){
		delete[] m_deck;
	}
}	
/* **************************************************************************************
 * Function name: Deck()
 * Description: The copy constructor. (The copy constructor is a private member 
 * 		and will not be used.)
 * Parameters: const Deck&
 * Pre-condtions: Assumes that the user wants to copy data from another
 * 		  instance during initialization.
 * Post-conditions: Data is copied from one instance of Deck to another
 * 	            via a deep copy.
 * **************************************************************************************/
Deck::Deck(const Deck& old_deck){
	// Assumes that the Card* contains no data.
	if(old_deck.m_deck != NULL){
		this->m_size = old_deck.m_size;
		this->m_deck = new Card[m_size];
		for(int i = 0; i < this->m_size; i++){
			this->m_deck[i] = old_deck.m_deck[i];
		}
	}
}

/* **************************************************************************************
 * Function name: get_deck().
 * Description: This function returns the array of Card instances.
 * Parameters: -
 * Pre-conditions: Assumes that the Deck of cards is non-empty.
 * Post-conditions: Returns the array of Card instances.
 * **************************************************************************************/
Card* Deck::get_deck(){
	return m_deck;
}

/* **************************************************************************************
 * Function name: get_faceup_card().
 * Description: This function is used to get access to the m_faceup_card member.
 * 		Note it returns a reference to the member so that is can be changed.
 * Parameters: -
 * Pre-conditions: Assumes that the member being return contains data.
 * Post-conditions: Returns a refernce to the member m_faceup_card.
 * **************************************************************************************/
Card& Deck::get_faceup_card(){
	return m_faceup_card;
}
	
/* **************************************************************************************
 * Function name: get_toppile_card().
 * Description: This function acts as a accessor and mutator function. It allows
 * 		access to the index of the toppile_card in the deck of cards.
 * 		This card is the first card that will be picked up by the user
 * 		if he/she cannot play a card.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: This function returns the index (int) of the card that is
 * 		    at the top of the unused pile of cards.
 * **************************************************************************************/
int& Deck::get_toppile_card(){
	return m_toppile_card;
}

/* **************************************************************************************
 * Function name: operator=()
 * Description: This is the overloaded assignment operator. It will be used to copy
 * 		data from one instance a Deck object to another.
 * Paramters: const Deck&
 * Pre-conditions: The instnance of the Deck where the data is copied from should be 
 * 		   initialized.
 * Post-conditions: Data is deep copied from one class instance to another.
 * **************************************************************************************/
Deck& Deck::operator=(const Deck& old_deck){
	// The case for self assignment.
	if(this == &old_deck){
		return *this;
	}
	if(this->m_deck){
		// Before assigning new data to this->m_deck we need to make sure it
		// does not already contain/point to other dynamic memory.
		delete[] this->m_deck;
	}
	// This is only intgers so a shallow copy is allowed.
	//std::cout << "+++++++" << std::endl;
	this->m_size = old_deck.m_size;
	this->m_deck = new Card[this->m_size];
	for(int i = 0; i < this->m_size; i++){
		this->m_deck[i] = old_deck.m_deck[i]; 
	}
	// Returnin existing object so that we can chain this operator.
	return *this;	
}

/* **************************************************************************************
 * Function name: swap() 
 * Description: This function is used to swap two card instances in the shuffle_deck()
 * 		function.
 * Parameters: Card*, Card*.
 * Pre-condtions: You need to make sure you overloaded the assignment operator.
 * 		  (But for a Card instance shallow copying is acceptable because
 * 		  the class does not have dynamic member variables)
 * Post-conditions: The Card instance's position in the array will be swapped.
 * **************************************************************************************/
void swap(Card* c1, Card* c2){
	if(c1 != NULL && c2 != NULL){
		Card tmp = *c1;
		*c1 = *c2;
		*c2 = tmp;	
	
	}else{
		std::cout << "[swap(Card*, Card*)]: Error inside shuffle_deck()" 
		<< std::endl;
	}
}


/* **************************************************************************************
 * Function name: shuffle_deck().
 * Description: This funtion will shuffle the entire array of Card instances. This 
 * 		function will set the faceup_card as the card of the newly shuffled
 * 		deck at index 1.
 * Parameters: -
 * Pre-conditions: The function makes use of the random number generator provided in the
 * 		   standard library.
 * Post-conditions: The function shuffles the array of Card instances. (the deck)
 * **************************************************************************************/
void Deck::shuffle_deck(){
	std::cout << "\nShuffling the deck of cards.\n" << std::endl;
	sleep(3);
	// Using the this* only to getting comforable of how I can use it.
	for(int i = 0; i < this->m_size; i++){
		int random = i + rand() % (this->m_size - i);
		// Swapping the card instance at index i with a random index.
		swap(&m_deck[i], &m_deck[random]);	
	}	
	// This is the card that is turned around to lie face up on the table.
	m_faceup_card = m_deck[0];
	// This is the top unplayed Card instance's index.
	m_toppile_card = 1;
}
/* **************************************************************************************
 * Function name: print_deck() 
 * Description: This is a constant function. It will print the entire deck to the screen.
 * 		Other versions of the functions are in progress where you pass in 
 * 		arguments where you specify what to print to the screen.
 * Parameters: -
 * Pre-conditions: -
 * Post-conidtions: The entire array of Card instances are printed to the screen.
 * **************************************************************************************/
void Deck::print_deck() const{
	std::cout << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << "Rank and Suite." << std::endl;
	std::cout << "---------------" << std::endl;
	for(int i = 0; i < this->m_size; i++){
		std::cout << m_deck[i] << std::endl; // The <<operator() is overloaded.
		std::cout << "---------------" << std::endl;
	}
	std::cout << std::endl;
}

/* **************************************************************************************
 * Function name: create_deck()
 * Description: This function will create a dynamic array of cards. It is a private 
 * 		member function of the class Deck and will only be used once by
 * 		the default constructor.
 * Paramters: -
 * Pre-conditions: -
 * Post-conditions: The function create an array to hold 52 Card instances.
 * **************************************************************************************/
void Deck::create_deck(){
	this->m_deck = new Card[m_size];	
	for(int i = 0; i < m_size; i++){
		this->m_deck[i] = Card(i);	
	}
	// The card that lies face up for the players to see the suite and rank.
	m_faceup_card = this->m_deck[0];
	// This is equal to 1 because the 0th element is the faceup_card.
	m_toppile_card = 1;
}

/* **************************************************************************************
 * Function name: operator[]()
 * Description: This is the overloaded subscript operator. It is used that access a 
 * 		single card inside a Deck instance.
 * Version: Non-const.
 * Paraters: index
 * Pre-condtions: The instace of a Deck class needs to contain Card instances.
 * Post-conditions: The Card instance at the index that is passed into the function
 * 			is returned to the called.
 * **************************************************************************************/

Card& Deck::operator[](int index){
	assert(index > -1 && index < m_size 
	&& "[Error]: Trying to access an element outside the deck");
	// Returns a card.
	return m_deck[index];
}
