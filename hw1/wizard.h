/* **************************************************************************************
 * Filename: Wizard.h
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: October 11, 2020.
 * Assignment: Program 1 - Wizard Spellbook Catalog.
 * Description: This file has the definitions of the Wizard and School struct as well
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

struct Wizard{
	std::string name{"default name"};
	int id{0};
	std::string password{"default password"};
	std::string position_title{"default title"};
	float beard_length{0};
};

struct School{
	// Will contains all the wizards in the school.
	Wizard* wiz_ar{NULL};
	unsigned int num_wiz_in_school{0}; 
};

// This functions uses the number of wizards to create an array
// 	of that size on the heap.
void set_info(School*);

// This function prints information of a single Wizard.
void print_info(Wizard*);

// This prints the information of the entire School.
void print_info(School);
#endif

