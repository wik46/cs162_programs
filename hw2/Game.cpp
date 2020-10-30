/* **************************************************************************************
 * Filename: Game.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date:October 25, 2020.
 * Description: This is the implementation file for the Game class. This
 * 		class will contain all the member needed to play the game
 * 		Crazy eights. It will have two players, a Deck of cards, and
 * 		various member functions that run the game for the user. Examples
 * 		are start_game(), hand_out() which is used by start game.
 * Input: -
 * Output: -
 * **************************************************************************************/

#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include "Hand.h"
#include "Player.h"

#include <cassert>
#include <iostream>

/* **************************************************************************************
 * Function name: print_game_rules()
 * Description: This function will out put the game rule to the user.
 * 		It is used inside Start_game() and will only be called at the 
 * 		begining of the game. The function also gets the player's name.
 * Paramters: - 
 * Pre-conditions: Assumes a new game has started.
 * Post-conditions: Outputs a welcome message to the screen.
 * **************************************************************************************/
void Game::print_game_rules(){
	std::cout << std::endl;
	std::cout << "===================================================" << std::endl;	
	std::cout << "Welcome to the Crazy 8's Card game." << std::endl;
	std::cout << "===================================================" << std::endl;	
	std::cout << std::endl;
	std::cout << "Please enter your name: ";
	std::cin >> m_player_ar[0].get_name();
	std::cout << "\n***************************************************" << std::endl;	
	std::cout << "Game Rules:" << std::endl;
	std::cout << "***************************************************\n" << std::endl;	
	std::cout << "1.) Select the integer corresponding to the card in\n    your hand.\n\n"
	<< "2.) If you cannot play a valid card, press 0 to\n    pick up one from the deck.\n\n"
	<< "3.) You can pickup a maximum of 3 cards before \n    your move is finished.\n\n"
	<< "4.) If you select a card that is in your hand, but\n    is not a valid move you "
	<< "will be punished\n    by picking up a card.\n\n";
	std::cout << "***************************************************\n" << std::endl;	
	std::cout << std::endl;
	//std::cout << "Press any key to start the Game."<< std::endl;	
	//std::cin.get(dummy);
}
/* **************************************************************************************
 * Function name: hand_out().
 * Description: This function is used at the start of the game to hand out 
 * 		cards to the players. The default value will be seven but the
 * 		integer argument passed to the function will decide the size of
 * 		a single hand of a player.
 * Parameters: int - The size of a hand of cards.
 * Pre-condtions: The instance of a Deck class must be created to have cards to 
 * 		  hand out.
 * Post-conditions: The top 14 cards of the deck is handed to the two players
 * 		    of the game.
 * **************************************************************************************/
void Game::hand_out(int hand_size){
	//std::cout << m_player_ar[0].get_hand() << std::endl;

	// This function will onyl be called by start_game().
	// Therefore the size of the hands will be equal.
	assert(hand_size > 0 
	&& "[Error]: hand_out()");	
	// These integer will be use so that my the card is inserted in the correct
	// hand index for each player.
	int i = 0, j = 0, k = 0;
	for(i = 0; i < hand_size*2; i++){
		// This conditions will oscillate between 1 and true.
		// That is it will oscillate between true and fales.
		// It will hand out the cards between the two players.
		if(i % 2){
			// I want to access for example the 10th element in the	
			// deck but I do not want to access the 10th element in
			// a players hand because id does not exist.
			m_player_ar[0].get_hand()[j] = m_deck[i]; 
			j++;
		}else{
			m_player_ar[1].get_hand()[k] = m_deck[i];
			k++;
		}
		// This moves the top of the pile card.
		m_deck.get_toppile_card()++;
	}
	m_deck.get_faceup_card() = m_deck[i];
}

/* **************************************************************************************
 * Function name: Game(int)
 * Description: This is the Game class constructor.
 * Parameters: int.
 * Pre-conditions: There will be only one instance of a game class in the progra. 
 * Post-condtions: An instance of a Game classes is constructed.
 * **************************************************************************************/

Game::Game(int num_players):m_game_state{"not_started"} ,m_player_ar{NULL},m_num_players{num_players}{
	// This will create a dynamic array of Players.
	assert(m_num_players > 0 
	&& "[Error]: Cannot construct a game because the number of players is less than 1.");
	m_player_ar = new Player[m_num_players];
	// Creating a human player.
	
}
/* **************************************************************************************
 * Function name: get_deck().
 * Description: This function returns the array of Card instances.
 * Parameters: -
 * Pre-conditions: Assumes that the Deck of cards is non-empty.
 * Post-conditions: Returns the array of Card instances.
 * **************************************************************************************/
Deck& Game::get_deck(){
	return m_deck;
}



/* **************************************************************************************
 * Function name: ~Game().
 * Description: This is the destructor of the Game class. It will free the dynamic 
 * 		memory used by the program to store the array of Player instances.
 * Paramters: -
 * Pre-conditions: Given that a Game instance was created, the players in the game
 * 		   will be store as a member in the Game class. This will be stored 
 * 		   the heap.
 * Post-conditions: The memory allocated for storage of the Player array is freed.
 * **************************************************************************************/
Game::~Game(){
	// This will only free the memory allocated by the player
	// array if it was allocated.
	if(m_player_ar != NULL){
		delete[] m_player_ar;
	}
}

/* **************************************************************************************
 * Function name: reset_hand()
 * Description: This function will be used to reset a user's hand before 
 * 		the start of the game.
 * Paramters: - 
 * Pre-conditions: This function is used in the start of the game.
 * Post-conditions: Deletes the old hands and refreshes them.
 * **************************************************************************************/ 
void Game::reset_hand(){
	for(int i = 0; i < m_num_players; i++){
		// This will reset the hand.
		while(m_player_ar[i].get_hand().get_size() != 7){
			--m_player_ar[i].get_hand();
		}	
	}
}

/* **************************************************************************************
 * Function name: Start_game()
 * Description: This function is used to intialize the game. That is it will
 * 		shuffle the deck of cards, empty the players' hand before
 * 		handing them there 7 cards for the game. This function will be used
 * 		inside the driver.cpp source file.
 * Parameters: int*
 * Pre-condtions: This function will only be execute once at the start of the game.
 * Post-conditions: This function hands out the cards to each player and starts
 * 		    the game.
 * **************************************************************************************/
void Game::Start_game(int* round){
	if(m_game_state == "not_started"){
		print_game_rules();
		reset_hand();
		m_deck.shuffle_deck();
	//	m_deck.print_deck();
		hand_out();
		// This makes sure that the function is only called at the
		// begining of a match.
		m_game_state = "in_progress";
		*round = 0;
	}else{
		return;
	}
}
/* **************************************************************************************
 * Function name: Evaluate_round_end()
 * Description: This function will be used to determine if the game has ended. It will 
 * 		be called after each round and do the following:
 * 		- If the toppile_card is 52 then there are no more cards left in the deck.
 * 		Note: If the deck is empty the person with the least amount of cards wins.
 * 		- If the one of the players does not have any cards left, then he won the
 * 		game.
 * Paramters: Deck*
 * Pre-conditions: This function is declared inside the the Game class and will have access 
 * 			to the Player instances.
 * Post-conditions: The game_state variable is set to "finished."
 * *************************************************************************************/

void Game::Evaluate_round_end(){
	if(m_player_ar[0].get_hand().get_size() == 0
	|| m_player_ar[1].get_hand().get_size() == 0){
		m_game_state = "finished";
		// The last index in the deck is 51, so 52 implies the deck has reached its end.
	}else if(m_deck.get_toppile_card() == 52){
		m_game_state = "finished";
	}
}
/*
 * Function name: who_is_winner()
 * Description: This function will be used in Evaluate result. It will determine who won
 * 		the match. If the deckk of cards is empty and the players have the same 
 * 		number of cards, then it is a draw.
 * Parameters: -
 * Pre-conditions: The game state variable must be set to "finished".
 * Post-conditions: Returns the results of the match.
 * ***************************************************************************************/

void Game::who_is_winner(){
	int human = 0, computer = 1;
	if(m_player_ar[human].get_hand().get_size() 
	< m_player_ar[computer].get_hand().get_size()){
		std::cout << "\nCongratulations: " << m_player_ar[human].get_name()
		 << std::endl;
		std::cout << "YOU WON!!!." << std::endl;
	}else if(m_player_ar[human].get_hand().get_size() 
	!= m_player_ar[computer].get_hand().get_size()){
		std::cout << "\nBad luck: " <<  m_player_ar[human].get_name()
		<< std::endl;
		std::cout << "The computer won!!!.\n" << std::endl;
		
	}else{
		std::cout << "\nOh no it's a TIE.\n"<< std::endl;
	}
}

/* **************************************************************************************
 * Function name: Evaluate_result()
 * Description: This function will be called if the Evaluate_round_end() set the game_state 
 * 		variable to finished. This will prompt the user whether they want 
 * 		to end the game or continue playing. 
 * 		If they want to end the game the game_state variable will be set to 
 * 		"termintated" and the while loop will stop. Else the game will continue.
 * Parameters: -
 * Pre-conditions: will only be called if m_game_state = "finished"
 * Post-condtions: Determines if the user wants to end the game or play another round.
 * ***************************************************************************************/
void Game::Evaluate_result(){
	if(m_game_state == "finished"){
		// This will output the result of the game.
		who_is_winner();
		std::string user_in = "";
		std::cout << "\nPlay again - press 1, else the game will end." 
		<< std::endl;
		std::cin >> user_in;
		if(user_in == "1"){
			m_game_state = "not_started";
			// This function will empty the hands
			// and return them to a size seven.
		}else{
			m_game_state = "terminated";
		}
	}
}
/* **************************************************************************************
 * Function name: print_round()
 * Description: This function is used to print the rounds to the screen.
 * Parameters: int.
 * Pre-conditions:-
 * Post-conditions:-
 * **************************************************************************************/		
void Game::print_round(int round) const{
	std::cout << "\n****************************\n"<< std::endl;
	std::cout << "Round : " << round << std::endl;
	std::cout << "\n****************************\n"<< std::endl;
}
