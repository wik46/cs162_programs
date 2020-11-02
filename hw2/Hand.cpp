/* ***************************************************************************************
 * Filename: Hand.h
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717
 * Date: October 25, 2020.
 * Description: This is the implementation file of my Hand class.
 * Input: -
 * Output: -
 * **************************************************************************************/

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <cassert>
#include <iomanip>
#include <iostream>


/* ***************************************************************************************
 * Function name: Hand(int)
 * Description: This constructor will construct a hand class that can
 * 		store the n number of cards passed in as the argument of the
 * 		constructor.
 * Parameters: int.
 * Pre-condtions: This class makes use of dynamic memory that is cleaned up by the
 * 		  destructor. 
 * Post-conditions: A instance of a Hand is constructed that can store the number
 * 		    of cards passed in as argument of the constructor.
 * **************************************************************************************/

Hand::Hand(int size): m_card_ar{NULL}, m_hand_size{size}
{
	assert(m_hand_size > 0 && "[Error in Hand constructor]:"); 
	// This array of Card instance will represent a hand of cards
	// held by the user during the game.
	m_card_ar = new Card[m_hand_size];
//	std::cout << "Hand constructed size:" << m_hand_size << std::endl;
}

/* ***************************************************************************************
 * Function name: Card(const Card&).
 * Description: The copy constructor. This funcion is used whan an instance of
 * 		a Hand object needs to be copied at intialization.
 * Parameters: const Card&.
 * Pre-conditions: Assumes that the m_card_ar is null.
 * Post-conditions: A deep copy is performed when a new instance of a Hand is
 * 		    created and the value of an old instance of Hand is copied.
 * **************************************************************************************/
Hand::Hand(const Hand& old_Hand){
	assert(old_Hand.m_card_ar != NULL);
	// Shallow copy is allowed between primitive types.
	this->m_hand_size = old_Hand.get_size();
	// Assumes that the new hand contains garbage.
	this->m_card_ar = new Card[this->m_hand_size];
	// Retrieving data from the old Hand.
	for(int i = 0; i < this->m_hand_size; i++){
		// Shallow copy between to Card instances is allowed.
		(*this)[i] = old_Hand[i];
	}
}


/* ***************************************************************************************
 * Function name: operator[]()
 * Version: Const.
 * Description: This function is used to get the ith card in the array of Card instances.
 * Parameters: int.
 * Pre-conditions: There must exist a card at the index passed to the function.
 * Post-conditions: The function returns a reference to an Card at index i.
 * **************************************************************************************/
const Card& Hand::operator[](int index) const {
	assert(index > -1 && index < m_hand_size && 
	"[Error]: Invalid index in Hand class.");
	return m_card_ar[index];
} 
/* ***************************************************************************************
 * Function name: operator[]()
 * Version: Non-const.
 * Description: This function is used to get the ith card in the array of Card instances.
 * Parameters: int.
 * Pre-conditions: There must exist a card at the index passed to the function.
 * Post-conditions: The function returns a reference to an Card at index i.
 * **************************************************************************************/
Card& Hand::operator[](int index){
	assert(index > -1 && index < m_hand_size && 
	"[Error]: Invalid index in Hand class.");
	return m_card_ar[index];
} 


/* **************************************************************************************
 * Function name: operator<<()
 * Description: This is the overloaded leftwize bitshift operator. It will print out an
 * 		instance of a Hand of cards acompanied with their index + 1. That is for 
 * 		example the card at index 2 will be selected to the user as 3.
 * Parameters: const ostream&, const Hand&
 * Pre-conditions: The function assumes that the instance of a Hand contains data.
 * Post-condtions: The entire hand of cards is printed to the screen.
 * **************************************************************************************/

std::ostream& operator<<(std::ostream& stream, const Hand& hand){
	stream << std::fixed << std::setprecision(2);
	stream << std::left << std::setw(3) << std::setfill(' ');
	stream << std::endl;
	std::cout << "---------------------------"<< std::endl;
	std::cout << "Current player's hand: " << std::endl;
	std::cout << "---------------------------"<< std::endl;
	for(int i = 0; i < hand.get_size(); i++){
		// Remember that the subscript operator is overloaded.
		stream << i + 1 << ".) " << hand[i] << std::endl;
		std::cout << "---------------------------"<< std::endl;
	}
	stream << std::endl;
	return stream;	
}

/* ***************************************************************************************
 * Function name: operator++()
 * Description: This postfix operator is used to add one element to my array of Cards.
 * 		Hand++ will mean that the new Hand has exactly the same cards as the 
 * 		initial hand, but is has space for an additional card.
 * Paramters: -
 * Pre-conditions: Assumes that the hand is already created and does not have an
 * 		   array pointing to null.
 * Post-condtions: Returns an identical array with original length+1
 * **************************************************************************************/

Hand& Hand::operator++(){
	assert(m_card_ar != NULL && 
	"[Error]:You tried to use the postfix operator on an empty Card array");
	// This will save the memory in a temporary array of cards.
	Card* new_hand = new Card[m_hand_size + 1];
	for(int i = 0; i < m_hand_size; i++){
		// This is doing a shallow copy between Card instances.
		// It is okay because a Card instance does not contain dynamic memory.
		new_hand[i] = m_card_ar[i];
	}
	// Now we can delete the old array.
	delete[] m_card_ar;
	// and set it to the new array with space for an extra card.
	m_card_ar = new_hand;
	// And the integer keeping track of the size needs to be incremented.
	m_hand_size++;
	return *this;
}

/* ***************************************************************************************
 * Function name: operator--().
 * Description: This is an overloaded decrement operator for an instance
 * 		of Hand class. The operator will remove the last element in the
 * 		array and return an array of lenth - 1.
 * Parameters: -
 * Pre-condtions: Assumes that the array of Card instances contains Card instances.
 * Post-conditions: The Hand instance storing the cards of the player is returned without
 * 			the last element. 
 * **************************************************************************************/
Hand& Hand::operator--(){
	assert(m_card_ar != NULL &&
	"[Error]: You cannot use the decrement operator on an empty Card*.");
	if(m_hand_size > 0){
		Card* new_hand = new Card[m_hand_size - 1];
		for(int i = 0; i < m_hand_size - 1; i++){
			// Shallow copying between Card instances is allowd.
			new_hand[i] = m_card_ar[i];	
		}
		delete[] m_card_ar;
		// Storing the new array data in the member of the current class.
		m_card_ar = new_hand;
		m_hand_size--;
		return *this;
	}else{
		// Unsuccessful decrement.
		return *this; 
	}
}

/* ***************************************************************************************
 * Function name: ~Hand().
 * Description: The destructor will be used to clean up all memory used by an instance of
 * 		a Hand class.
 * Parameters: -.
 * Pre-conditions: The card_ar is an array stored on the heap and must be cleaned up
 * 		   by the programmer.
 * Post-conditions: All memory used by an instance of a Hand is freed.
 * **************************************************************************************/
 
Hand::~Hand(){
	if(m_card_ar != NULL){
		delete[] m_card_ar;
	}
	//std::cout << "The Hand is destructed." << std::endl;
}
/* ***************************************************************************************
 * Function name: operator=()
 * Desciption: This is the overloaded assignment operator that does a deep copy
 * 		for the Hand class.
 * Parameters: const Hand&
 * Pre-condtions: Assumes that the user want to copy the value of a Hand instance
 * 		  from one to another after initialization.
 * Post-condtions: Deep copy.
 * **************************************************************************************/

Hand& Hand::operator=(const Hand& old_object){
	// Testing for self assignment.
	if(this == &old_object){
		return *this;
	}
	if(this->m_card_ar != NULL){
		// First free the data stored inside the array before new allocation.
		delete[] m_card_ar;
	}
	// Deep copy.
	if(old_object.m_card_ar != NULL &&
	old_object.m_hand_size > 0){
		this->m_hand_size = old_object.m_hand_size;
		this->m_card_ar = new Card[this->m_hand_size];
	}
	return *this;
}
/* ***************************************************************************************
 * Function: get_size()
 * Descritption: This function will return the size of the current hand.
 * Parameters: -
 * Pre-conditions: -
 * Post-condtions: The function returns the size of the instance of a Hand. 
 * **************************************************************************************/

const int Hand::get_size() const {
	return m_hand_size;
}
