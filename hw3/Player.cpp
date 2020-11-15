/* **************************************************************************************
 * Filename: Player.cpp.
 * Author: Lodewyk Jansen van Rensburg.
 * Date: November 8, 2020.
 * Description: This is the implementation file for the class Player. An instance of 
 * 		Player will have two children: Human and Computer. The only differences 
 * 		between these inhereted classes is the get_card() function. Because 
 * 		the Human will be prompted to enter a valid card where as the computer 
 * 		will choose a random card from its hand.
 * Input: -
 * Output: -
 * **************************************************************************************/

#include "Player.h"

#include <cassert> 
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <string>

/* **************************************************************************************
 * Function name: is_buy().
 * Description: This will be a boolean function. It will prompt the user to decide if 
 * 		they want to buy an animal or not. 
 * Parameters: -
 * Pre-conditions: This function will be used in an if condition of my main program.
 * Post-conditions: Return true if the user want to buy at least one animal and returns
 * 		    false if the user does not want to buy an animal. 
 * **************************************************************************************/
bool Player::is_buy() const {
	// This is only for user to know what to do.
	std::cout << std::setprecision(2);
	std::cout << std::endl;
	std::cout << "Do you want to purchase more animals for your Zoo this round."
	<< std::endl
	<< "*************************************************************************\n"
	<< "Current available funds before expenses:  $" << m_banktotal << ".\n"
	<< "*************************************************************************\n"
	<< std::endl << "Yes - 1, No - 0. " << std::endl;
	std::string tmp = "";
	std::cin >> tmp;
	// Only logic implemented for the function.
	if(tmp == "0"){
		// The case when the user does not want to buy animals.
		return 0;
	}else if(tmp == "1"){
		// The case when the user wants to buy animals.
		return 1;
	}else{
		std::cout << "The input you provided was invalid: " << tmp << std::endl;		
		return this->is_buy();
	}
}

/* ***************************************************************************************
 * Function name: get_name().
 * Description: This function will be used to get access to the name of the player.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Return the name of the player.
 * **************************************************************************************/
std::string Player::get_name() const{ 
	return m_name;
}
/* ***************************************************************************************
 * Function name: get_bankname().
 * Description: This function will be used to get access to the bankname of the player.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Return the name of the player's bankname.
 * **************************************************************************************/
std::string Player::get_bankname() const {
	return m_bankname;
}
/* ***************************************************************************************
 * Function name: get_bank().
 * Description: This function will be used to get access to the bank total of the player.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Return the name of the player's bank total.
 * **************************************************************************************/
float& Player::get_bank(){
	return m_banktotal;
} 
/* **************************************************************************************
 * Function name: set_info().
 * Description: This function will be used to prompt the user to enter hiw/her player 
 * 		details. It will be used inside the constructor of the class. It will be
 * 		a private function because the user of the class should not use it 
 * 		outside of the constructo.
 * Parameters: - 
 * Pre-conditions: -
 * Post-condtions: The player information is saved in an instance of a Player class.
 * **************************************************************************************/
void Player::set_info(){
	std::cout << std::fixed;
	std::cout << std::endl 
	<< "======================================================================="
	<< "====================\n"
	<< "Enter your name here: ";
	std::cin >> this->m_name;
	std::cout << "Enter the name of your bank where I should deposit the $100 000"
	<< " to get you started: " << std::endl;
	std::cin.ignore(256 ,'\n');
	std::getline(std::cin, this->m_bankname);
	std::cout 
	<< "======================================================================="
	<< "====================" << std::endl;
	// This lets the user think that the money is being deposited.
	std::cout << std::endl;
	std::cout << "Give me a moment to deposit the money in your account.\n";
	sleep(3);
	std::cout << std::endl
	<< "***************************************************************************\n"
	<< "$ 100 000 deposited in " << this->m_name << "'s account at " 
	<< this->m_bankname << "." << std::endl
	<< "****************************************************"
	<< "***********************\n" << std::endl;
	return;
}

/* **************************************************************************************
 * Function name: Player()
 * Description: This is the constructor for the player class. I will only define the 
 * 		default constructor as it is the only one needed at the moment for
 * 		the class. The class will not contains dynamic memory and therefore
 * 		not need one of the big three.
 * Parameters: float.
 * Pre-conditions: The function makes use of the set_info() member function.
 * Post-conditions: The player instance is initialized with all its members variables
 * 			set to the correct values.
 * **************************************************************************************/
Player::Player(float ib_total)
: m_banktotal{ib_total}
{
	set_info();
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
			std::cout << "Please enter an integer value." << std::endl;
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
int get_int(std::string prompt ,std::string error_msg){
	// This will be the output message to the user.
		std::cout << std::endl << prompt << std::endl;
	// The string is initialized to an invalid value so that the while-loop will iterate.
	std::string tmp = " ";
	// The id-number is invalid if the string contains any non-numeric characters.
	while(!is_valid(&tmp)){
		// this will prompt the user to enter a new string and save the value into tmp.
		tmp = ask_for_input();
		// This is used to display helpful input to the user.
		if(!is_valid(&tmp)){
			std::cout << error_msg << std::endl;
		}
	}
	return stoi(tmp);
}
