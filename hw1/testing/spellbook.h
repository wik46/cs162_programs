/* **************************************************************************************
 * Filename: spellbook.h
 * Author: Lodewyk Jansen van Rensburg.
 * student ID: 934 309 717.
 * Date: October 11, 2020.
 * Assignment: Program 1 - Wizard Spellbook Catalog.
 * Description: This is the header file for the spellbook struct. It contains the 
 * 		definition of the spell and spellbook struct. This file also contains 	
 * 		all the function prototypes of the functions defined in spellbook.cpp 
 * 		It also contains the definiton of the library struct.
 * Input:
 * Ouput:
 * **************************************************************************************/

#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <fstream>
#include <iostream>

// There will be multiple spells inside one spell book.
struct spell{
	std::string name{"default spell name"};
	float success_rate{0};
	std::string effect{"default spell effect"};
};

struct spellbook{
	std::string title{"default title"};
	std::string author{"default author"};
	int num_pages{0};
	int edition{0};
	int num_spells{0};
	float avg_success_rate{0};
	spell* s{NULL};
};

// This is a data structure that will contain all the spellbooks used by the program.
struct library{
	// This array will contains all the spellbooks of the program.
	spellbook* book_ar{NULL};
	// This array will keep the data of all the spells from all the spellbooks.
	spell* all_spells{NULL};
	// The number of spellbooks.
	int num_books{0};
	// The total number of spells used by the program.
	int num_spells{0};
	
};


// Functions used to manipulate the data stored inside the structs.

// ### Caution: Allocates dynamic memory. ###
// This function will dynamically allocate an array of spells of a requisted size.
spellbook* create_spellbooks(int);

// This function will store the data of one spellbook that is contained in the 
// fstream object inside a spellbook.
void get_spellbook_data(spellbook*, int, std::ifstream&);

// ### Caution: Allocates dynamic memory. ###
// This function will dynamically create an array of spells of a requisted size.
spell* create_spells(int);

// This function will fill a spellstruct with the information it need from the ifstream
// object.
void get_spell_data(spell*, int, std::ifstream&);
// Functions that clean up memory is defined in the clean_up.cpp file.

// 1. Clean up the array of spells in each spell book.
// 2. Clean up the array of spellbooks in the library.
#endif

