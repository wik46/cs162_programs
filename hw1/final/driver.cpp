/* **************************************************************************************
 * Filename: driver.cpp.
 * Author: Lodewyk Petrus Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: October 11, 2020.
 * Description: This is the driver file for The Wizards Spellbook Catalog. 
 * 		The purpose of this program is for the great wizard school Pogwarts to
 * 		keep track of all their spellbooks in the library. They want a program
 * 		to give easy access to their wizards to learn the spells in the library.
 * 		They do on want wizards with student status to have access to spells with
 * 		the effects of death or poison. If a spellbook contains at least one
 * 		spell with the effects of death or poison, the student wizards is not
 * 		allowed access. 
 * 		This program needs the following files for support.
 * 		- wizards.txt and spellbooks.txt,
 * 		- login_user1.cpp and login_user1.h,
 * 		- build_library2.cpp and build_library.h,
 * 		- user_login3.cpp and user_login3.h, and
 * 		- clean_up4.cpp and clean_up4.h.
 * Input: The program is provided with two textfiles. One named wizards.txt which contains
 * 	  data of various wizards in the school
 * Output: The program allows the wizard to sort the spellbooks and print the data or 
 * 	   write the data to a file of their choice. The program will continue untill 
 * 	   the user enters the string "quit".		                
 * **************************************************************************************/
#include "wizard.h"
#include "spellbook.h"

#include "login_user1.h"
#include "build_library2.h"
#include "user_selection3.h"


#include <fstream>
#include <iostream>

int main(int argc, char* argv[]){
	if(argc < 3){
		std::cout << "Please enter two files: " << 
		"wizards.txt and spellbooks.txt" << std::endl;
		return 1;
	}
	// This stream object is only used with the wizard login process.
	std::fstream f;
	// The school is a struct that contains an array of wizards and the number
	// of wizards in the school
	school schl;
	const int wiz_index = Login_user(&schl, argv[1],&f);
	if(wiz_index  == -1){
		delete_school(&schl);
		return 1;
	}	
	
	// The library contains an array of spellbooks, the number of spellbooks in the array,
	// an array of spells, and the number of spells in the array.
	library lib;	
	Build_library(&lib,argv[2], &schl.wiz_ar[wiz_index]);
	// This part of the program handles the sorting and outputting of data.
	while(User_option(&lib, &schl.wiz_ar[wiz_index]) != "quit");	
	
	// Cleaning up memory.
	// NB! You must first free the memory used by the array of spells before
	// 	freeing the memory used by the spellbook array.
	delete_school(&schl);
	delete_library(&lib);
	return 0;
}

