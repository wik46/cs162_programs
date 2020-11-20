/* ***************************************************************************************
 * Filename: Keyboard.cpp
 * Author: Lodewyk Jansen van Rensburg
 * Date: November 22, 2020.
 * Assignment: Homework 4.
 * Description: This it the implementation file for my Keyboard class.
 * 		PURPOSE: Accept and validate user input and return user input.
 *		Member variables.
 *			1. m_input: The newly received and already validated input.
 *
 * 		Member functions:
 * 			1. get() - This function will obtain the user input.
 * 				 - It will return the Position as parameters to use
 * 				   for validate that the user made a move on the game
 * 				   grid. Another parameter will be the size of the square
 * 				   grid. The function will set the m_input member to the
 * 				   validated input received.
 * 			2. give() - This function will return the current input received
 * 				    from the user.
 * 			3. dir() -  This function wil be used in the .move() member
 * 				    function of player. It will return a vector
 * 				    that you can add to the current position
 * 				    to obtain the new position.
 * 			4. is_move() - will return true if the player moved on the grid.
 * 			5. is_shot() - will return true if the player shot and arrow.
 * 		
 * 		Exceptions that get() can throw:
 * 			1. Invalid direction: The user tried to move of the board.
 * 			2. Empty arrow: The user tried to fire a shot without an arrow.
 * Input: -
 * Output: -
 * ***************************************************************************************/

#include "Vec2d.h"
#include "Player.h"
#include "Keyboard.h"
#include <iostream>
#include <iomanip>



// =======================================================================================
// Hard working functions.
// =======================================================================================
/* ***************************************************************************************
 * Function name: get()
 * Description: This function will be used to prompt the user to enter his/her move.
 * 		It will validate the move and then calculate the direction that the move.
 * 		The dir() member function will return the direction that the player
 * 		should move and it will be used inside the .move() member function of
 * 		player.
 * Parameters: -
 * Pre-condtions: -
 * Post-conditions: Validates the user input and returns it i.t.o. a vector.
 * ***************************************************************************************/
const Vec2d& Keyboard::get(){
	prompt_move();
	std::string input = "A";
	std::getline(std::cin,input);
	// If the player wants to make a shot.
	if(input[0] == ' '){
		std::cout << "[temporary]: User wants to fire an arrow." << std::endl;

	// N,E,S,W is const Vec2d instances defined as private member of the class.
	// Move north.
	}else if(input == "w"){	
		m_input = N;
	// Move east.
	}else if(input == "d"){
		m_input = E;
	// Move south.
	}else if(input == "s"){
		m_input = S;
	// Move west.
	}else if(input == "a"){
		m_input = W;
	}else{
		std::cout << std::endl << std::endl << std::endl;
		std::cout << std::setfill('-') << std::setw(20) << ' ' << std::endl;
		std::cout << "Invalid input please enter the directions specified." 
		<< std::endl;
		std::cout << std::setfill('-') << std::setw(20) << ' ' << std::endl;
		// This will reprompt the user to enter another move.
		get();
	}
	return m_input;
	
}
/* ***************************************************************************************
 * Function name: dir()
 * Decription: This function will used the m_input Vec2d from the class which represent
 * 		the current direction that the player wants to move in. It will return
 * 		the vector that should be passed in the player.move() function to
 * 		update the player's position. It will also update the player's position.
 * Parameters: -
 * Pre-condtions: Assumes that get() update the player's current move.
 * Post-conditions: Returns the Vec2d needed for player.move().
 * ***************************************************************************************/
const Vec2d& Keyboard::dir(){
	// If the position of the player is on the boundry of the grid.
	if( is_boundry(m_player_pos) ){
		std::cout << "[On boundry:]" << std::endl;
		// Case 1: On the boundry.
		return calc_boundry_move(m_player_pos, m_input, m_grid_size);	
	}else{
		std::cout << "[Not boundry:]" << std::endl;
		// Case 2: Not on the boundry.
		m_player_pos = m_player_pos + m_input;
		return m_input;
	}

}
/* ***************************************************************************************
 * Function name: prompt_move()
 * Description
 * ***************************************************************************************/
void prompt_move(){
	std::cout << std::endl;
	std::cout << std::setfill('*') << std::setw(20);
	std::cout << ' ' << std::endl;
	
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << 'w' << std::endl;
	
	std::cout << std::setfill(' ') << std::setw(5);
	std::cout << 'a';
	
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << 'd' << std::endl;
	
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << 's' << std::endl;
	
	std::cout << std::setfill('*') << std::setw(20);
	std::cout << ' ' << std::endl;
	std::cout << std::endl;

}

/* ***************************************************************************************
 * Function name: action()
 * ***************************************************************************************/

/* ***************************************************************************************
 * ***************************************************************************************/

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Development helpers: 
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/* ***************************************************************************************
 * Function name: print_all_info()
 * Description: This will print all the information of the player to the console with 
 * 		labels next to the member variables.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
void Keyboard::print_all_info(){
	std::cout << "-------------------------------------------------------"<< std::endl;
	std::cout << "All member variables of the current Keyboard:" << std::endl;
	std::cout << "-------------------------------------------------------"<< std::endl;
	std::cout << "1.) User input as vector [m_input]: " << m_input << std::endl;
	std::cout << "2.) User position as vector [m_player_pos]: " << m_player_pos << std::endl;
	std::cout << "3.) The size of the grid [m_grid_size]: " << m_grid_size << std::endl;
	std::cout << "4.) North [N]: " << N << std::endl;
	std::cout << "5.) East  [E]: " << E << std::endl;
	std::cout << "6.) South [S]: " << S << std::endl;
	std::cout << "7.) West  [W]: " << W << std::endl;
	std::cout << "-------------------------------------------------------"<< std::endl;
	return;
}


// =======================================================================================
// Overloaded operators.
// =======================================================================================

/* ***************************************************************************************
 * Function name: operator<<()
 * ***************************************************************************************/

// =======================================================================================
// Constructors.
// =======================================================================================
/* ***************************************************************************************
 * Function name: Event()
 * Description: This is the default constructor. It will create a keyboard object
 * 		that is used through out the game. It will know the size of
 * 		the grid so that is can validate user input and return the correct
 * 		direction that the user specified to move or make the shot. 
 * Parameters: unsigned int, const Vec2d&
 * Pre-conditions: -
 * Post-conditions: -
 * ***************************************************************************************/
// The default consrtuctor.
Keyboard::Keyboard(const Vec2d& init, unsigned int size)
:m_grid_size{size}, m_input(0,0), m_player_pos{init}, N(-1,0), E(0,1), S(1,0), W(0,-1)
{}
// =======================================================================================
// The big three.
// =======================================================================================
// 1. Destructor.
/* ***************************************************************************************
 * ***************************************************************************************/

// =======================================================================================
// Private Members.
// =======================================================================================
/* ***************************************************************************************
 * Function name: is_boundry()
 * Description: This function is used to determine if the vector passed as argument
 * 		is on the boundry of the grid.
 * Parameters: const Vec2d&
 * Pre-conditions: Uses the grid size member.
 * Post-condtions: Returns true if the player is on the boundry and false otherwise.
 * **************************************************************************************/
bool Keyboard::is_boundry(const Vec2d& pt){
	if((pt.get_x() == 0 || pt.get_x() == m_grid_size - 1) 
	&& (pt.get_y() >= 0 && pt.get_y() < m_grid_size)){
		// Any position for y on the x boundry.
		return 1;
	
	}else if((pt.get_y() == 0 || pt.get_y() == m_grid_size - 1) 
	&& (pt.get_x() >= 0 && pt.get_x() < m_grid_size)){
		// Any positions for x on the y boundry.
		return 1;
	
	}else{
		// The Vec2d instance is not on the boundry.
		return 0;
	}
}




/*
 * Function name: calc_boundry()
 * Description This function will take in the player's position, the direction in which the 
 * 		player wishes to go, and the size of the grid. It will retrun the Vec2d
 * 		needed to be passed to the .move() member function of player.
 * Parameter: conts Vec2d&, const Vec2d&, int
 * Pre-conditions:
 * Post-conditions: Returns the vector need to pass to .move() in the Player class.
 * */
const Vec2d& Keyboard::calc_boundry_move(Vec2d& player_pos, const Vec2d& input_pos, int size){
	// Remember to check return of local memory.
	// Case 1: upper row and up.
	if(player_pos.get_x() == 0 && input_pos == N){
		
		player_pos = player_pos + ((-1 * (size - 1)) * input_pos);
		std::cout << "[calc boundry N]" << ( -1 * (size -1)) * input_pos << std::endl;
		return input_pos * ( -1 * (size -1) );
	
	// Case 2: bottom row and down.
	}else if(player_pos.get_x() == size - 1 && input_pos == S){
		player_pos = player_pos + ((-1 * (size - 1)) * input_pos);
		std::cout << "[calc boundry S]" << ( -1 * (size -1)) * input_pos << std::endl;
		return input_pos * ( -1 * (size -1) );
	
	// Case 3: right column and right.
	}else if(player_pos.get_y() == size - 1 && input_pos == E){
		player_pos = player_pos + ((-1 * (size - 1)) * input_pos);
		std::cout << "[calc boundry E]" << ( -1 * (size -1)) * input_pos << std::endl;
		return input_pos * ( -1 * (size -1) );
	
	// Case 4: left column and left.
	}else if(player_pos.get_y() == 0 && input_pos == W){
		player_pos = player_pos + ((-1 * (size - 1)) * input_pos);
		std::cout << "[calc boundry W]" << ( -1 * (size -1)) * input_pos << std::endl;
		return input_pos * ( -1 * (size -1) );
	}else{
	// Case 5: Normal movement.
		std::cout << "[calc boundry else]" <<  input_pos << std::endl;
		player_pos = player_pos + input_pos;
		return input_pos;
	}

}
