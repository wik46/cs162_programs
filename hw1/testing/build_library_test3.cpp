/* **************************************************************************************
 * Filename: build_library_test3.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: October 11, 2020.
 * Assignment: Program 1 - Wizard Spellbook Catalog.
 * Description:
 * Input:
 * Ouput:
 * **************************************************************************************/

#include "wizard.h"
#include "spellbook.h"
#include "user_selection_test4.cpp"
#include "login_test2.cpp"

#include <fstream>
#include <iostream>

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
// This function frees the memory allocated by create_spellbooks().
void delete_spellbook_array(spellbook* spell_bk_ar){
	if(spell_bk_ar != NULL){	
		delete[] spell_bk_ar;
	}else{
		std::cout << "[delete_spellbook_array()]:" 
		<< "Error, unable to free memory allocated by the spellbook array."<< std::endl;
	}
}

// This function is used to free the memory allocated by create_spells().
void delete_spell_array(spell* spell_ar){
	if(spell_ar != NULL){
		delete[] spell_ar;
	}else{
		std::cout << "[delete_spell_array()]: You passed in a null pointer." << std::endl;
	}
}

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

// This function will retrieve the data for all the spells contained inside one book.
// This function assumes that memory of the correct size is already allocated for the spell_ar.
void get_spell_data(spell* spell_ar, int num_spells, std::ifstream& fin){
	for(int i = 0; i < num_spells; i++){
		fin >> spell_ar[i].name >> spell_ar[i].success_rate
		>> spell_ar[i].effect;
	}
}

// ### Caution: This function creates dynamic memory.###
// This function will retrieve all the data needed for 1 spellbook. 
// It creates an dynamic array of spells.
// This function assumes that memory of the correct size is already allocated for the spellbook_ar.
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

// This function is created to help modularize my program.
void get_data(library* lib, std::ifstream* fin){
		// Obtain the number of books in the library.
		*fin >> lib->num_books;
		// Allocate memory to store the books.
		lib->book_ar = create_spellbooks(lib->num_books);
		// Get all the data for the spellbooks.
		get_spellbook_data(lib->book_ar, lib->num_books, *fin);
}
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
		std::cout << std::endl << "[Error]: File name " << file_name << " is invalid." << std::endl;
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

int main(int argc, char* argv[]){
	if(argc < 3){
		std::cout << "Please enter two files: wizards.txt and spellbooks.txt" << std::endl;
		return 1;
	}
	// This stream object is only used with the wizard login process.
	std::fstream f;
	// The school is a struct that contains an array of wizards and the number
	// of wizards in the school
	school schl;
	const int wiz_index = Login_user(&schl, argv[1],&f);
	if(wiz_index  == -1){
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
