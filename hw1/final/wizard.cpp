/* **************************************************************************************
 * Filename: wizard.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: October 11, 2020.
 * Assignment: Program 1 - Wizard Spellbook Catalog.
 * Description: This is the implentation file of the wizard struct. It will include all
 * 		the definitions of the functions that manipulate data associated with
 * 		the type wizard or school( which is at base level an array of wizards.) 
 * Input: -
 * Ouput: -
 * **************************************************************************************/

// Note that a large part of the functions that use the wizard struct is defined
// in the implementation file login_user1.cpp. 

#include "wizard.h"
#include <iostream>

/* **************************************************************************************
 * Function name: print_info()
 * Description: Outputs all the data of one wizard to the screen.
 * Parameters: wizard*
 * Pre-conditions: The instance of a wizard must contain data and not garbage.
 * Post-conditions: The data that the wizard pointer is pointing to is printed to 
 * 			the screen.
 * **************************************************************************************/
void print_info(wizard* wiz){
	std::cout << "Name: " << wiz->name << std::endl;
	std::cout << "Id: " << wiz->id << std::endl;
	std::cout << "Password: " << wiz->password << std::endl;
	std::cout << "Class standing: " << wiz->position_title << std::endl;
	std::cout << "Beard length: " << wiz->beard_length << "m."<< std::endl;

}

