/* **************************************************************************************
 * Filename: wizard.h
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: October 11, 2020.
 * Assignment: Program 1 - Wizard Spellbook Catalog.
 * Description: This file has the definitions of the wizard and wchool struct as well
 * 		as all the function prototypes that manipulate their data.
 * Input:
 * Ouput:
 * **************************************************************************************/
// This is the interface file (headerfile) for the wizard struct.

// You always need header guards.
#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include <string>

struct wizard{
	std::string name{"default name"};
	int id{0};
	std::string password{"default password"};
	std::string position_title{"default title"};
	float beard_length{0};
};

struct school{
	// Will contains all the wizards in the school.
	wizard* wiz_ar{NULL};
	unsigned int num_wiz_in_school{0}; 
};
// This function prints information of a single wizard.
void print_info(wizard*);

#endif

