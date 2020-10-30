/* **************************************************************************************
 * Filename: Player.cpp.
 * Author: Lodewyk Jansen van Rensburg.
 * Date: October 25, 2020.
 * Description: This is the implementation file for the class Player. An instance of 
 * 		Player will have two children: Human and Computer. The only differences 
 * 		between these inhereted classes is the get_card() function. Because 
 * 		the Human will be prompted to enter a valid card where as the computer 
 * 		will choose a random card from its hand.
 * Input: -
 * Output: -
 * **************************************************************************************/

#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "Player.h"


#include <cassert> 
#include <unistd.h>
#include <iostream>

Player::Player(){

}
/* **************************************************************************************
 * Function name: get_hand().
 * Description: This function will return a const ref to a Hand intance. It is used to 
 * 		access to the hand of cards held by the user.
 * Parameters: -
 * Pre-conditions: Assumes that the hand contains cards.
 * Post-conditions: Returns a const reference to of a Hand instance.
 * **************************************************************************************/
Hand& Player::get_hand(){
	return m_hand;
}

/* **************************************************************************************
 * Function name: get_name().
 * Description: This function is used to get access to the private member m_hand.
 * Parameters: -
 * Pre-conditions: Assumes the player has a hand.
 * Post-conditions: Returns the name of the player.
 * **************************************************************************************/
std::string& Player::get_name(){
	return m_name;
}
/* ***************************************************************************************
 * Function name: put_card_down()
 * Description: This function will accept an address to the Deck of cards.
 * 		If the user played a card that is allowed (rank/suite matches or rank = 8)
 * 		, then the program will call this function. This function will remove the 
 * 		card from the user's hand, decrease the hand size by one, and store change 
 * 		the m_faceup_card to the new one played by the user.
 * Paramters: Deck*
 * Pre-conditions: The function makes use of the overloaded decrement operator defined 
 * 			for the Hand class. The operator will remove the last element
 * 			in the Hand and return a array with length - 1;
 * Post-conditions: The user played a card and the user's hand as well as the Deck is
 * 		    updated accordingly.
 * **************************************************************************************/
// This function is defined in Deck.cpp
void swap(Card*, Card*);

void Player::put_card_down(Deck* deck, Card* user_card_played){
	// Searching for the card played in the user's hand to put it at the last element
	// in the Hand.
	for(int i = 0; i < this->get_hand().get_size(); i++){
		if(this->get_hand()[i] == *user_card_played){
		// Setting the card played to the last element of the user hand.
		// Afterwards the decrement operator will remove the last element in hand.
			swap(&get_hand()[i], &get_hand()[get_hand().get_size() - 1]);
		//		Card* tmp = &get_hand()[i];
		//	&(get_hand()[i]) = &(get_hand()[get_hand().get_size() - 1]);
		//	&(get_hand()[get_hand().get_size() - 1]) = tmp;
			break;
		}
	}
	// This removes the last element in the hand.
	--m_hand;
	// This is the card that the user placed on the deck as his/her move.
	deck->get_faceup_card() = *user_card_played;
}

/* **************************************************************************************
 * Function name: pick_card_up()
 * Description: The purpose of this function is to simulate the action of a player
 * 		picking up a card from the deck if he/she cannot make a move. The function
 * 		will add the new card to the player's hand and the toppile card will be 
 * 		changed to the next unplayed card in the deck. If the deck is empty, the 
 * 		player will not be able to pick up a card. Note that there 
 * 		is a function that gets called after each round to determine if the 
 * 		deck is empty. If this function is passed an empty deck then there 
 * 		is a bug in the program.
 * Parameters: Deck*.
 * Pre-conditions: Assumes that the Deck of card is non-empty. But will assert that
 * 		   that this is in fact the case.
 * Post-conditions: The card at the top of the unplayed pile is added to the user's
 * 		    hand and a new toppile card is set.
 * **************************************************************************************/
void Player::pick_card_up(Deck* deck){
	// Remember to set a getter for the size of the deck.
	assert(deck->get_toppile_card() <= 51
	&& "You tried to collect a card from an empty deck.");
	// This will return the same hand for space at the end
	// for one more Card instance.
	++m_hand;
	// The user picks up the card at the top of the unused pile.
	// Shallow copying between Card instances is allowed.
	m_hand[m_hand.get_size() - 1] = deck->get_deck()[deck->get_toppile_card()];
	// Sets the new toppile card.
	deck->get_toppile_card()++;
}
/* **************************************************************************************
 * Function: explain_card_selection().
 * Description: This function will describe to the user how to select a card.
 * Paramters: -
 * Pre-conditions: -
 * Post-conditions: Output rules to the screen.
 * **************************************************************************************/
void explain_card_selection(){
	std::cout << std::endl <<
	"Please enter the integer corresponding to the card that you wish to select."
	<< " If you cannot play a card, press 0 to pickup one up." 
	<< std::endl 
	<< "*Note: If you select a card that is in your hand but is not a valid move, "
	<< "you will be punished by picking up a card."
	<< std::endl;
}
/* **************************************************************************************
 * Function name: ask_for_input()
 * Description: This function only collects a string as a input from the user.
 * Parameters: -
 * Pre-conditions: -
 * Post-condtions: Returns the string entered as a input by the user.
 * **************************************************************************************/
std::string ask_for_input(){
	std::string temp;
	std::cin >> temp;
	return temp;
}

/* **************************************************************************************
 * Function name: is_valid()
 * Description: This function validates that the string only contains numeric charaters.
 * Parameters: - 
 * Pre-condtions: A string declared in an outer scope.
 * Post-condtions: Returns true if the pointer is pointing to an only-numeric charater
 * 		   string, else returns false.
 * **************************************************************************************/
bool is_valid(std::string* str1){
	for(int i = 0; i < (*str1).length(); i++){
		// This condition will be met if the charater is not a numeric value.
		if((*str1)[i] < 48 || (*str1)[i] > 57){
			// This returns false.
			return 0;
		}
		// The empty string cannot be passed to stoi() later in the program.
	}
	return 1;
}
/* **************************************************************************************
 * Function name: get_int()
 * Description: This function promts the user for his/her input. It will only return
 * 		a valid input. That is a string that contains only numeric.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: The function returns the first valid integer entered by the user.
 * **************************************************************************************/
// This is used for the first part of getting use input.
int get_int(){
	// The string is initialized to an invalid value so that the while-loop will iterate.
	std::string tmp = " ";
	// The id-number is invalid if the string contains any non-numeric characters.
	while(!is_valid(&tmp)){
		// this will prompt the user to enter a new string and save the value into tmp.
		tmp = ask_for_input();
		// This is used to display helpful input to the user.
		if(!is_valid(&tmp)){
			std::cout << "Your input is invalid." << std::endl;
		}
	}
	return stoi(tmp);
}

/* ***************************************************************************************
 * Function name: get_input().
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
Card Player::get_input(){
	int tmp = get_int();
	if(tmp == 0){
		// It is accpetable to return a local variable becuase I am returnin by
		// value.
		return Card();
	// The user will enter a numeric char to select the card that he/she want to play.
	}else if (tmp > 0 && tmp <= get_hand().get_size()){		
		std::cout << "\nThat card is in deed inside your hand.\n" << std::endl;	
		// If the user enters 1, then the function will return the card at index
		// 0 to the user. If 2, then return 1 and so on...
		return get_hand()[tmp - 1];
	}else{
		std::cout << "\nPlease enter a card inside you hand." << std::endl;
		return this->get_input();
	}
}

/* **************************************************************************************
 * Function name: get_input()
 * Description: This function will be called on the computer's turn. It will play the 
 * 		first possible card in the computer's hand. If none is possilbe,
 * 		it will return the default card that will enable the computer
 * 		to pick up a card.
 * Parameters: Deck*, char.
 * Pre-conditions: -
 * Post-conditions: Simulates a round played by the computer.
 * **************************************************************************************/
Card Player::get_input(Deck* deck, const char* dummy){
	// This function will return a valid move if possible by the computer.
	std::cout << "\nThe computer is thinking...\n" << std::endl;
	sleep(3);
	for(int i = 0; i < m_hand.get_size(); i++){
		if (m_hand[i].get_rank() == deck->get_faceup_card().get_rank()
		|| m_hand[i].get_suite() == deck->get_faceup_card().get_suite()){
			return m_hand[i];
		}
	}	
	return Card();
}
/* ***************************************************************************************
 * Function name: print_options()
 * Description: This function prints the options available for the user to 
 * 		enter his/her custom suite after the wild card 8 has been played.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Outputs user options to the screen to select the suite for
 * 		    the game.
 * **************************************************************************************/
void print_options(){
	std::cout << std::endl 
	<< "You get to choose the suite." << std::endl
	<< std::endl << "Please select the integer corresponding to the suite "
	<< "you wish to choose: " << std::endl;
	std::cout << "Clubs - 1, Diamonds - 2, Hearts - 3, or Spades - 4."
	<< std::endl; 
}

/* **************************************************************************************
 * Function name: get_custom_suite()
 * Description: This function will be called if the user played the 8 wild card.
 * 		It will set the m_toppile_card's suite to the user selected one.
 * Parameters: -
 * Pre-conditions: Assumes that and 8 was played.
 * Post-condtions: Returns the suite that the user selected.
 * **************************************************************************************/
char get_custom_suite(Deck* deck, int r){
	// When the compute made a move.
	if(r % 2 != 0){
		deck->get_faceup_card().get_suite();
	}
	int clubs = 1, diamonds = 2, hearts = 3, spades = 4;
	// Explains to the user how to select a suite.
	print_options();
	// Gets a valid interger from the user.
	int user_in = get_int();
	if(user_in == clubs){
		return 'c';
	}else if(user_in == diamonds){
		return 'd';
	}else if(user_in == hearts){
		return 'h';
	}else if(user_in == spades){
		return 's';
	}else{
		std::cout << "\n*** Please select an integer between 1 and 4 (inclusively). ***\n"
		<< std::endl;
		return get_custom_suite(deck, r);
	}	
}

/* **************************************************************************************
 * Function name: Take_turn().
 * Description: This function will be used in the driver file. It will prompt the user
 * 		to play a card. If the card is not in the user's hand the function will
 * 		print an error message and remprompt the user to enter a valid input.
 * 		The function will then determine based on the card played by the user
 * 		whether they can play it or if they need to pick up a card.
 * 		A maximum number of three cards will be selected each round.
 * Parameters: Deck*.
 * Pre-conditions: The function assumes that all the objects contains valid data.
 * 		   It does no do error checking to determine if the Deck and Hand 
 * 		   instances contain the correct data.
 * Post-conditions: A round of crazy 8's card game is simulated.
 * **************************************************************************************/

void Player::Take_turn(Deck* deck, int r){
	// Displays the current use hand.
	std::cout << m_hand << std::endl;
	// This string is used to help collect data inside get_card_input.
	const short max = 3;
	Card card_played;
	for(int i = 0; i < max; i++){
		std::cout << "\n: ============================== :"<< std::endl;
		std::cout << "    Card on the Table: " << deck->get_faceup_card() << std::endl;
		std::cout << ": ================================ :\n"<< std::endl;
		// 
		if(r % 2 == 0){
			// Human player takes turn.
			explain_card_selection();
			card_played = get_input();
		}else{
			// This function gets computer input.
			card_played = get_input(deck, "computer input");
		}
		// Create functionality to implement the 8 wild card.
		// The computer will select the suite of the 8 played as default.
		if(card_played.get_rank() == 8 && r % 2 == 0){
			std::cout << std::endl << "You played the wild card!!!\n" << std::endl;
			put_card_down(deck, &card_played);
			// This is after a wild card is played and the suite is selected
			// by the user. 	
			deck->get_faceup_card().get_suite() = get_custom_suite(deck, r);
			return;
		}else if (card_played.get_rank() == deck->get_faceup_card().get_rank()
			|| card_played.get_suite() == deck->get_faceup_card().get_suite()){
			put_card_down(deck, &card_played);
			std::cout << m_hand << std::endl << std::endl;
			return;
		}else{
			if(deck->get_toppile_card() == 52){
				return;
			}else{
				std::cout << "\nPicking up a card."
				<< std::endl << std::endl;
				pick_card_up(deck);	
				std::cout << m_hand << std::endl << std::endl;
			}
		}
	//	std::cout << m_hand << std::endl << std::endl;
	}
}
