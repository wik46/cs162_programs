/* **************************************************************************************
 * Filename:
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: October 11, 2020.
 * Assignment: Program 1 - Wizard Spellbook Catalog.
 * Description:
 * Input:
 * Ouput:
 * **************************************************************************************/

#include "wizard.h"
#include <iostream>

/* **************************************************************************************
 * Function name: print_info()
 * Description: Outputs all the data of one wizard to the screen.
 * Parameters: Wizard*
 * Pre-conditions: The instance of a wizard must contain data and not garbage.
 * Post-conditions: The data that the Wizard pointer is pointing to is printed to 
 * 			the screen.
 * **************************************************************************************/
void print_info(Wizard* wiz){
	std::cout << "Name: " << wiz->name << std::endl;
	std::cout << "Id: " << wiz->id << std::endl;
	std::cout << "Password: " << wiz->password << std::endl;
	std::cout << "Class standing: " << wiz->position_title << std::endl;
	std::cout << "Beard length: " << wiz->beard_length << "m."<< std::endl;

}
/* **************************************************************************************
 * Function name: print_info()
 * Description: Outputs all the data contained by the school. That is, it will print out
 * 		all the information of all the wizards in the school.
 * Parameters: School*
 * Pre-conditions: The instance of a school must contain data and not garbage.
 * Post-conditions: The data that the School pointer is pointing to is printed to 
 * 			the screen.
 * **************************************************************************************/

// ## Not tested yet
void print_info(School* schl){
	std::cout << "Number of wizards: " << schl->num_wiz_in_school << std::endl;
	for(int i = 0; i < schl->num_wiz_in_school; i++){
		std::cout << "Wizard: " << i << "." << std::endl;
		print_info(&(schl->wiz_ar[i]));
	}

}

