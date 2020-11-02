/* **************************************************************************************
 * Filename: build_library2.h
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: October 11, 2020.
 * Assignment: Program 1 - Wizard Spellbook Catalog.
 * Description: This is all the function associated with the storing of the spellbooks.txt
 * 		file inside the library struct.
 * Input: spellbooks.txt.
 * Ouput: The data from the text file is stored inside the programs's library struct.
 * **************************************************************************************/

#ifndef BUILD_LIBRARY_2_H
#define BUILD_LIBRARY_2_H

#include "spellbook.h"
#include "wizard.h"

#include <fstream>
#include <iostream>

/* **************************************************************************************
 * Function name: calc_total_spells()
 * **************************************************************************************/
int calc_total_spells(library* lib);

/* **************************************************************************************
 * Function name: set_all_spells()
 * **************************************************************************************/
void set_all_spells(library* lib);

/* **************************************************************************************
 * Function name: print_books()
 * **************************************************************************************/
// This function is created during the testing process.
void print_books(library* lib);	

/* **************************************************************************************
 * Function name: open_file_read()
 * **************************************************************************************/
void open_file_read(std::ifstream* file_in, /*const char* */std::string file_name);

/* **************************************************************************************
 * Function name: Build_library()
 * **************************************************************************************/
// This function will be used in my driver file/ client code/ main program.
void Build_library(library* lib, char* text_file, wizard* logged_in_wiz);

#endif
