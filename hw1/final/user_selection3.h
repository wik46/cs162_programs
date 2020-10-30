/* **************************************************************************************
 * Filename: user_selection3.h.
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: October 11, 2020.
 * Description: This is the header file for my the user selection section
 * 		of the program. These functions are used to sort the data and prompt
 * 		the user whether they want it outputted to the screen or to a file.
 * Input: A library* and wizard* containing pointing to valid data obtained from
 * 	  login and building section of the program. 
 * Ouput: The User_selection() function will occur in a while loop in the main function.
 * 	  It will sort and output data untill the user enters "quit".
 * **************************************************************************************/

#ifndef USER_SELECTION_H
#define USER_SELECTION_H

#include "spellbook.h"
#include <iostream>
#include <cstdlib>

/* **************************************************************************************
 * Function name: swap() 
 * ***********************************************************************************+**/
void swap(spellbook* a, spellbook* b);

// 1. Sort by number of pages.
/* **************************************************************************************
 * Function name: quick_sort()
 * **************************************************************************************/
void quick_sort(spellbook* book_ar, int left, int right);
	
/* **************************************************************************************
 * Function name: sort_by_num_pages()
 * **************************************************************************************/
void sort_by_num_pages(library* lib);

// 2. Sort by spell effect.
/* **************************************************************************************
 * Function name: swap()
 * **************************************************************************************/
void swap(spell* p1, spell* p2);
	
/* **************************************************************************************
 * Function name: sort_by_spell_effect().
 * **************************************************************************************/
void sort_by_spell_effect(spell* spl_ar, int length, std::string pattern);	

/* ***************************************************************************************	
 * Function name: print_effect()
 * **************************************************************************************/
void print_effects(const spell* p_ar, const int length);

// 3. Sort by the average success rate.
/* **************************************************************************************
 * Function name: cal_avg_success_rate().
 * **************************************************************************************/
void calc_avg_success_rate(spellbook* s_ar, int size);

/* **************************************************************************************
 * Function name: quick_float_sort()
 * **************************************************************************************/

void quick_float_sort(spellbook* s_ar, int left, int right);
	
/* **************************************************************************************
 * Function name: sort_by_avg_success_rate()
 * **************************************************************************************/
void sort_by_avg_success_rate(library* lib_ptr);

// This part is all the function used in my print_to_write() function

/* **************************************************************************************
 * Function name: get_options()
 * ***************************************************************************************/
std::string get_options();

/* **************************************************************************************
 * Function name: is_death_or_poison()
 * **************************************************************************************/
bool is_death_or_poison(library* lib, int i);

/* **************************************************************************************
 * Function name: wizard_book_print()
 * **************************************************************************************/
// This will be the print function for if a student wizard is logged in.
// This function does not check if student is logged in it only prints to screen.
void wizard_book_print(library* lib, std::string option);

/* ***************************************************************************************
 * Function name: normal_book_print()
 * **************************************************************************************/
void print_1_or_3(library* lib, wizard* wiz, std::string option);

/* **************************************************************************************
 * Function name: get_file_name()
 * **************************************************************************************/
std::string get_file_name();

/* **************************************************************************************
 * Function name: write_1_or_3_student()
 * **************************************************************************************/
// This function does not check if student is logged in it only prints to screen.
void write_1_or_3_student(library* lib, std::string option);

/* **************************************************************************************
 * Function name: write_1_or_3_non_student()
 * **************************************************************************************/
void write_1_or_3_non_student(library* lib, std::string option);

/* **************************************************************************************
 * Function name: write_1_or_3()
 * **************************************************************************************/
void write_1_or_3(library* lib, wizard* wiz, std::string option);

/* **************************************************************************************
 * Function name: write_2_student()
 * **************************************************************************************/
void write_2_student(library* lib);

/* **************************************************************************************
 * Function: write_2_non_student()
 * **************************************************************************************/
void write_2_non_student(library* lib);

/* **************************************************************************************
 * Function name: write_2()
 * **************************************************************************************/
void write_2(library* lib, wizard* wiz);

/* **************************************************************************************
 * Function name: print_2_student()
 * **************************************************************************************/
void print_2_student(library* lib);

/* **************************************************************************************
 * Function name: print_2_non_student()
 * **************************************************************************************/
void print_2_non_student(library* lib);

/* **************************************************************************************
 * Function name: print_2()
 * **************************************************************************************/
void print_2(library* lib, wizard* wiz);

/* **************************************************************************************
 * Function name: get_print_or_write_selection()
 * **************************************************************************************/
std::string get_print_or_write_selection();

/* **************************************************************************************
 * Function name: print_or_write()
 * **************************************************************************************/
void print_or_write(library* lib, wizard* wiz, std::string option);

/* **************************************************************************************
 * Function name: User_options()
 * **************************************************************************************/
std::string User_option(library* lib, wizard* wiz);

#endif
