/* **************************************************************************************
 * Filename: Functions.h
 * Author: Lodewyk Jansen van Rensburg.
 * Date: December 6, 2020.
 * Description: This is the header file for helper functions used for the
 * 		linked list demonstration program.
 * **************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
/* ***************************************************************************************
 * Function name: print_all_info()
 * **************************************************************************************/
void print_all_info();
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
int get_int(std::string prompt ,std::string error_msg);

