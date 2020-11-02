/* **************************************************************************************
 * Filename: build_library2.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: October 11, 2020.
 * Assignment: Program 1 - Wizard Spellbook Catalog.
 * Description: This is all the function associated with the storing of the spellbooks.txt
 * 		file inside the library struct.
 * Input: spellbooks.txt.
 * Ouput: The data from the text file is stored inside the programs's library struct.
 * **************************************************************************************/


#include "wizard.h"
#include "spellbook.h"

#include <fstream>
#include <iostream>

/* **************************************************************************************
 * Function name: calc_total_spells()
 * Description: This function uses an spellbooks array to calculate the total number of 
 * 		number of spells in all the books. It is used inside set_all_spells().
 * Parameters: library*.
 * Pre-conditions: The function assumes that the library used already contains the 
 * 		   spellbook data and spells inside the spellbook.
 * Post-conditions: The function returns the total number of spells in the library.
 * **************************************************************************************/

int calc_total_spells(library* lib){
	if(lib->book_ar != NULL && lib->num_books > 0){
		int total = 0;
		for(int i = 0; i < lib->num_books; i++){
			total += lib->book_ar[i].num_spells;
		}
		return total;
	}else{
		std::cout << "[calc_total_spells()]: Your array of books does not " 
		<< "contain data." << std::endl; 
		return 0;
	}
}


/* **************************************************************************************
 * Function name: set_all_spells()
 * Description: Later in the program the user will have the opportunity to	
 * 		print/ write all the spells by spell effect to the screen/ a file. 
 * 		This function sets the spell array declared inside the library struct 
 * 		with all the spell data used by the program. This will be extremely helpful
 * 		when sorting the spells.
 * Parameters: library*.
 * Pre-conditions: This function makes use of calc_total_spells() and assumes that 
 * 		   the library contains all the spellbook and spell data.
 * Post-conditions: All the spells used during the program is stored in
 * 		    the spell array all_spells.
 * ***************************************************************************************/
void set_all_spells(library* lib){
	if(lib != NULL){
		// This function returns the total number of spells in all the spellbooks.
		lib->num_spells = calc_total_spells(lib);
		// ### Caution: Dynamic memory allocation.###
		// This creates a dynamic array of spells.
		lib->all_spells = create_spells(lib->num_spells);
		// This int variable is used as the index for my spell array.
		int index = 0;
		for(int i = 0; i < lib->num_books; i++){
			for(int j = 0; j < lib->book_ar[i].num_spells; j++){
				// This is retrieving each spell in every spellbook
				// to store in one array declared inside the library.
				lib->all_spells[index] = lib->book_ar[i].s[j];
				index++;
			}
		}
	}else{
		std::cout << "[set_all_spells]: Your library does not contain data." 
		<< std::endl;
	}
}

// This function is not use by the program but is very helpful for development and
// making additions to the program
/*
// This function is created during the testing process.
void print_books(library* lib){	
	for(int i = 0; i < lib->num_books; i++){
		std::cout << "Spellbook name: "<< lib->book_ar[i].title << std::endl; 
		std::cout << "Author : "<< lib->book_ar[i].author << std::endl; 
		std::cout << "Number of pages: "<< lib->book_ar[i].num_pages << std::endl; 
		std::cout << "Edition: "<< lib->book_ar[i].edition << std::endl; 
		std::cout << "Number of spells: "<< lib->book_ar[i].num_spells << std::endl; 
		std::cout << std::endl;
		std::cout << "The spells inside: " << lib->book_ar[i].title << std::endl;
		//print_spells(lib->book_ar[i].s);
		std::cout << std::endl;
	}
}
*/

/* **************************************************************************************
 * Function name: open_file_read()
 * Description: The purpose of this function is to take in a string that may/may not
 * 		contain the data of the spellbooks.txt file. If the function is 
 * 		able to open the file successfully, the function will return to
 * 		the main program. Else the user/wizard will be promted to enter
 * 		a valid file to the program. The user/wizard will be promted untill
 * 		a valid file is entered.
 * Parameters: ifstream*, string.
 * Pre-conditions: The ifstream object needs to be declared in an outer scope.
 * Post-conditions: The ifstream object is associated with the spellbooks.txt file.
 * **************************************************************************************/
void open_file_read(std::ifstream* file_in, /*const char* */std::string file_name){
	// This will ensure that if the wizard entered an existing but incorrect file 
	// file name.
	const char wrong_data_file = 'w';
	if(file_name[0] != wrong_data_file){
		(*file_in).open(file_name, std::ios::in);
	}else{
		// If the user entered an existing file containing the wrong
		// data he/she will be prompted to re-enter a file name. 
		(*file_in).open("DNE.txt", std::ios::in);
	}
	// This function will not open the spellbooks.txt file
	if((*file_in).is_open() && file_name[0] != 'w'){	
		return;
	}else{
		std::cout << std::endl << "[Error]: Filename " << file_name << " is invalid." << std::endl;
		std::cout << "Please re-enter the name of the file that contains the" <<
		" spellbook data: ";
		std::string in_str = "";
		std::cin >> in_str;
		std::cout << std::endl;
		open_file_read(file_in, in_str);
		return;
	}	
}
/* **************************************************************************************
 * Function name: Build_library()
 * Description: The purpose of this function is to validate, obtain, and store
 * 		the data received from the spellbooks.txt file. The function will
 * 		prompt the user to enter a new file name if the file opening was 
 * 		unsuccessful. 
 * 		After the file is successfully openened, the function will store
 * 		the data inside a library struct.
 * Paramters: library*, char*, wizard*
 * Pre-conditions: The function makes use of the following sub-functions:
 * 		   - open_file_read(), get_data(), and set_all_spells(). 
 * Post-condtions: The program stored the data received from the textfile
 * 		   into a library struct.
 * **************************************************************************************/
// This function will be used in my driver file/ client code/ main program.
void Build_library(library* lib, char* text_file, wizard* logged_in_wiz){
	std::ifstream fin;
	// Use file_open() here ####
	open_file_read(&fin, text_file);
	//fin.open(text_file);
	// The case when the file successfully opened.
	if(fin.is_open()){
		get_data(lib, &fin);
		set_all_spells(lib);
	// ====================================
	// Testing.
//		print_books(lib);
	// ====================================
	// The case when the file is not successfully opened.	
	}else{
		std::cout << "The file " << text_file << " was unalbe to open." << std::endl;
	}
	fin.close();
}
