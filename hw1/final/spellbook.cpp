/* **************************************************************************************
 * Filename: spellbook.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: October 11, 2020.
 * Assignment: Program 1 - Wizard Spellbook Catalog.
 * Description: This is all the function associated with the creation and deletion
 * 		of the library, spellbooks, and spells struct. 
 * Input: - 
 * Ouput: - 
 * **************************************************************************************/


#include "wizard.h"
#include "spellbook.h"

#include <fstream>
#include <iostream>

/* **************************************************************************************
 * Function name: create_spellbooks()
 * Description: ### Caution: Allocates dynamic memory. ###
 *              This function will create a dynamic array of spellbooks.
 * Paramters: int.
 * Pre-conditions: Size of the array to create.
 * Post-conditions: An array os spellbooks of specified size.
 * **************************************************************************************/
// ### Caution: Allocates dynamic memory. ###
// This function will create a dynamic array of spellbooks.
spellbook* create_spellbooks(int num_books){
	if(num_books > 0){
		return new spellbook[num_books];	
	}else{
		std::cout << "[create_spellbooks()]: Error, cannot create and array" <<
		" of spellbooks of size: " << num_books << "." << std::endl;
		std::cout << "The function will return a NULL pointer." << std::endl
		<< std::endl;
		return NULL;
	}
}
/* **************************************************************************************
 * Function name: create_spells()
 * Description: ### Caution: Allocates dynamic memory. ###
 *              This function will create a dynamic array of spells.
 * Paramters: int.
 * Pre-conditions: Size of the array to create.
 * Post-conditions: An array os spells of specified size.
 * **************************************************************************************/

// ### Caution: Allocates dynamic memory. ###
// This function will create a dynamic array of spells.
spell* create_spells(int num_spells){
	if(num_spells > 0){
		return new spell[num_spells];
	}else{
		std::cout << "[create_spells()]: Error, cannot create and array" <<
		" of spells of size: " << num_spells << "." << std::endl;
		std::cout << "The function will return a NULL pointer." << std::endl
		<< std::endl;
		return NULL;
	}
}	
/* **************************************************************************************
 * Function name: delete_spellbook_array()
 * Description: This function is used to free the memory allocated by create_spellbooks().
 * Paramters: spellbook*
 * Pre-condtions: -
 * Post-condtions: The memory that the pointer arguments is pointing to will only
 * 		   be freed if it is allocated.
 * **************************************************************************************/
// This function frees the memory allocated by create_spellbooks().
void delete_spellbook_array(spellbook* spell_bk_ar){
	if(spell_bk_ar != NULL){	
		delete[] spell_bk_ar;
	}else{
		std::cout << "[delete_spellbook_array()]:" 
		<< "Error, unable to free memory allocated by the spellbook array."
		<< std::endl;
	}
}
/* **************************************************************************************
 * Function name: delete_spell_array()
 * Description: This function is used to free the memory allocated by create_spells().
 * Paramters: spell*
 * Pre-condtions: -
 * Post-condtions: The memory that the pointer arguments is pointing to will only
 * 		   be freed if it is allocated.
 * **************************************************************************************/

void delete_spell_array(spell* spell_ar){
	if(spell_ar != NULL){
		delete[] spell_ar;
	}else{
		std::cout << "[delete_spell_array()]: You passed in a null pointer." 
		<< std::endl;
	}
}
/* **************************************************************************************
 * Function name: delete_library()
 * Description: This frees all the memory allocated by the spell arrays and the book array.
 * Paramters: library*
 * Pre-condtions: -
 * Post-condtions: The memory that the pointer arguments is pointing to will only
 * 		   be freed if it is allocated.
 * **************************************************************************************/
// This frees all the memory allocated by the spell arrays and the book array.
void delete_library(library* lib){
	// Cleaning up memory.
	// This deletes the array of spells in the library.
	delete_spell_array(lib->all_spells);
	// NB! You must first free the memory used by the array of spells before
	// 	freeing the memory used by the spellbook array.
	for(int i = 0; i < lib->num_books;i++){
		delete_spell_array(lib->book_ar[i].s);	
	}
	delete_spellbook_array(lib->book_ar);		
}
/* ***************************************************************************************
 * Function name: get_spell_data()
 * Description: This function will retrieve the data for all the spells contained inside 
 * 		one book. This function assumes that memory of the correct size is 
 * 		already allocated for the spell_ar.
 * Parameters: spellbook*, int , fstream.
 * Pre-condtions: This function assumes that memory of the correct size is 
 * 		   already allocated for the spell_ar.
 * Post-condtions: The spell data from the file associated with the
 * 		   ifstream object is stored in the spell array.
 * **************************************************************************************/
void get_spell_data(spell* spell_ar, int num_spells, std::ifstream& fin){
	for(int i = 0; i < num_spells; i++){
		fin >> spell_ar[i].name >> spell_ar[i].success_rate
		>> spell_ar[i].effect;
	}
}
/* ***************************************************************************************
 * Function name: get_spellbook_data()
 * Description: ### Caution: This function creates dynamic memory.###
 * 		This function will retrieve all the data needed for 1 spellbook.  
 * 		It creates an dynamic array of spells.
 * Parameters: spellbook*, int , fstream.
 * Pre-condtions: This function assumes that memory of the correct size is 
 * 		   already allocated for the spellbook_ar.
 * Post-condtions: The spellbooks data from the file associated with the
 * 		   ifstream object is stored in the spellbook array.
 * **************************************************************************************/
void get_spellbook_data(spellbook* spellbook_ar, int num_books, std::ifstream& fin){
	for(int i = 0; i < num_books; i++){
		fin >> spellbook_ar[i].title >> 
		 spellbook_ar[i].author >> spellbook_ar[i].num_pages 
		>> spellbook_ar[i].edition >> spellbook_ar[i].num_spells;
		// Collecting all the data of the spells.
		// ### allocation of dynamic memory.###.
		spellbook_ar[i].s = create_spells(spellbook_ar[i].num_spells);
		get_spell_data(spellbook_ar[i].s, spellbook_ar[i].num_spells, fin);
	}

}
/* **************************************************************************************
 * Function name: get_data()
 * Description: This function is created to help modularize my program.
 * Paramters: library*, fstream*.
 * Pre-condtions: This function makes use of create_spellbooks() and get_spellbooks-data()
 * Post-conditions: The data from the file associated with the fstream object is stored
 * 		   at the address that the library* is pointing to.
 * ***************************************************************************************/		

void get_data(library* lib, std::ifstream* fin){
		// Obtain the number of books in the library.
		*fin >> lib->num_books;
		// Allocate memory to store the books.
		lib->book_ar = create_spellbooks(lib->num_books);
		// Get all the data for the spellbooks.
		get_spellbook_data(lib->book_ar, lib->num_books, *fin);
}
