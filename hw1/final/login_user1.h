/* **************************************************************************************
 * Filename: login_user1.h.
 * Auhtor: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Description: This is the header file for the all the functions
 * 		that facilitate the wizard login process.
 * Pre-condtions: A text file wizards.txt that contain the data of all the wizards in
 * 		  Pogwarts.
 * Output: The data is stored inside the wizard struct and the program will
 *         continue if the user entered a matching set of ID-number/password.
 * **************************************************************************************/

#ifndef LOGIN_USER_H
#define LOGIN_USER_H

#include "wizard.h"
#include <iostream>
#include <fstream>

/* **************************************************************************************
 * Function name: open_file_read()
 * **************************************************************************************/
void open_file_read(std::fstream* file_in, /*const char* */std::string file_name);

/* **************************************************************************************
 * Function name: create_school()
 * **************************************************************************************/
// ###  Caution  ###
// Creates a dynamic array.
// This function assumes that the struct contains the size of the school.
void create_school(school* schl);

/* **************************************************************************************
 * Function name: delete_school()
 * **************************************************************************************/
void delete_school(school* schl);

/* **************************************************************************************
 * Function name: set_info()
 * **************************************************************************************/
// This function take the data from the stream object and saves it to each wizard in 
// 	the wizard array inside schl.
void set_info(school* schl, std::fstream* file_in);

/* **************************************************************************************
 * Function name: ask_for_id()
 * **************************************************************************************/

std::string ask_for_id();

/* **************************************************************************************
 * Function name: is_valid()
 * **************************************************************************************/
bool is_valid(std::string* str1);

/* **************************************************************************************
 * Function name: get_id()
 * **************************************************************************************/
// This is used for the first part of getting use input.
int get_id();
/* **************************************************************************************
 * Function name: ask_for_password()
 * **************************************************************************************/
// This function prompts the user to enter his/her password.
std::string ask_for_password();
/* **************************************************************************************
 * Function name: is_match()
 * **************************************************************************************/
// This function will return true if the ID-number and password entered as arguments match.
// Else it will return false.
bool is_match(int* id_num, std::string pswrd, school* schl);

/* **************************************************************************************
 * Function name: print_wiz()
 * **************************************************************************************/
void print_wiz(wizard* wiz);

/* **************************************************************************************
 * Function name: search_match()
 * **************************************************************************************/
int search_match(school* schl);

/* **************************************************************************************
 * Function name: Login_user()
 * **************************************************************************************/
int Login_user(school* schl, std::string str_in, std::fstream* f_in);

#endif
