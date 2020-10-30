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
 * Input: -
 * Ouput: -
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
// This struct will keep the data of an individual spellbook.
struct spellbook{
	std::string title{"default title"};
	std::string author{"default author"};
	int num_pages{0};
	int edition{0};
	int num_spells{0};
	float avg_success_rate{0};
	// This will be an array of spells.
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

/* **************************************************************************************
 * Function name: delete_library()
 * **************************************************************************************/
// ### Caution: Allocates dynamic memory. ###
// This function will create a dynamic array of spellbooks.
spellbook* create_spellbooks(int num_books);

/* **************************************************************************************
 * Function name: create_spells()
 * **************************************************************************************/
// ### Caution: Allocates dynamic memory. ###
// This function will create a dynamic array of spells.
spell* create_spells(int num_spells);

/* **************************************************************************************
 * Function name: delete_spellbook_array()
 * **************************************************************************************/
// This function frees the memory allocated by create_spellbooks().
void delete_spellbook_array(spellbook* spell_bk_ar);

/* **************************************************************************************
 * Function name: delete_spell_array()
 * **************************************************************************************/
// This function is used to free the memory allocated by create_spells().
void delete_spell_array(spell* spell_ari);

/* **************************************************************************************
 * Function name: delete_library()
 * **************************************************************************************/
// This frees all the memory allocated by the spell arrays and the book array.
void delete_library(library* lib);

/* **************************************************************************************
 * Function name: get_spell_data()
 * **************************************************************************************/
// This function will retrieve the data for all the spells contained inside one book.
// This function assumes that memory of the correct size is already allocated for the spell_ar.
void get_spell_data(spell* spell_ar, int num_spells, std::ifstream& fin);

/* **************************************************************************************
 * Function name: get_spellbook_data()
 * **************************************************************************************/
// ### Caution: This function creates dynamic memory.###
// This function will retrieve all the data needed for 1 spellbook. 
// It creates an dynamic array of spells.
// This function assumes that memory of the correct size is already allocated for the spellbook_ar.
void get_spellbook_data(spellbook* spellbook_ar, int num_books, std::ifstream& fin);

/* **************************************************************************************
 * Function name: get_data()
 * **************************************************************************************/
// This function is created to help modularize my program.
void get_data(library* lib, std::ifstream* fin);

#endif

