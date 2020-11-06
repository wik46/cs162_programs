/* **************************************************************************************
 * Filename: Player.h.
 * Author: Lodewyk Jansen van Rensburg.
 * Date: November 8, 2020.
 * Description: This is the implementation file for the class Player. 
 * 		The player will have a name, bank name and bank total. 
 * **************************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <cassert> 
#include <unistd.h>
#include <iostream>

class Player{
	float m_banktotal;
	std::string m_name;
	std::string m_bankname;
public:
	// This function will prompt the user to decide if they want to buy an animal.
	// Yes - 1, No - 0.
	bool is_buy() const;
	// Accessors and Mutators.
	// This function will gives me access to my member variables.
	std::string get_name() const ;
	std::string get_bankname() const ;
	float& get_bank(); 
	
	// The default initial bank total is $ 100 000.00 .
	Player(float bank_total = 100000.0);
private:
	void set_info();

};


/* **************************************************************************************
 * Function name: ask_for_input()
 * **************************************************************************************/
std::string ask_for_input();
/* **************************************************************************************
 * Function name: is_valid()
 * **************************************************************************************/
bool is_valid(std::string* str1);
/* **************************************************************************************
 * Function name: get_int()
 * **************************************************************************************/
// This is used for the first part of getting use input.
int get_int(std::string prompt = "default_prompt" 
	,std::string error_msg = "Your input is invalid");

#endif
