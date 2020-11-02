/* **************************************************************************************
 * Filename: Login.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: October 11, 2020.
 * Assignment: Program 1 - Wizard Spellbook Catalog.
 * Description:
 * Input: - A existing file that contains all the login information needed to verify if
 * 		a wizard exist.
 * 	  - This variable will be of type const char*.
 * Output: The user is prompted for his/her ID.
 * 		- If the user entered did not enter a string of representing a positive
 * 		  integer, then the user will be asked to re-enter his/her ID. 
 * 		  (This does not count towards an invalid attempt.)
 * 	   After a successful user ID was entered, the user will be prompted for a password.
 * 	   	- If the password and ID matches a wizard from the text file, then the
 * 	   	  information from the text file will be saved in one wizard struct represeting
 * 	   	  the wizard that is logged in.
 * 	   	- Else, the wizards will be asked to re-enter his/her ID and password.
 * 	   	  After three invalid attempts, the program will print an error message and
 * 	   	  terminate the program.  	    
 * **************************************************************************************/

#include "wizard.h"
#include "spellbook.h"

#include <fstream>
#include <iostream>

/* **************************************************************************************
 * Function name: create_spellbooks()
 * Description: ### Caution: Allocates dynamic memory. ###
 * 		This function will create a dynamic array of spellbooks.
 * 		It is used inside the get_data() function.
 * Parameters: int
 * Pre-conditions: - 
 * Post-conditions: The function creates dynamic memory.
 * *************************************************************************************/
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
 * Functionname: Build_library()
 * Description: This function uses a text file that contains information of all the 
 * 		spellbooks that the wizards have and stores all the books inside a 
 * 		library struct, stores the information for each spellbook in a
 * 		spellbook struct, and stores the information of each spell inside a spell
 * 		struct.
 * Parameters: library*, char*, wizard*.
 * Pre-conditions: An instance of a library object needs to be declared in an outer scope.
 * Post-condtions: All the data inside the spellbooks.txt file will be stored in
 * 			the above mentioned data structures.
 * **************************************************************************************/ 
// This function will be used in my driver file/ client code/ main program.
void Build_library(library* lib, char* text_file){
	std::ifstream fin;
	fin.open(text_file);
	// The case when the file successfully opened.
	if(fin.is_open()){
		get_data(lib, &fin);
	// ====================================
	// Testing.
		print_books(lib);
	// ====================================
	// The case when the file is not successfully opened.	
	}else{
		std::cout << "The file " << text_file << " was unalbe to open." << std::endl;
	}
	fin.close();
}

// This is an example on how to use the Build_library() function.
// ==============================================================
/*int main(int argc, char* argv[]){
	library lib;
	wizard wiz;

	Build_library(&lib,argv[1]);
		


	std::cout << lib.book_ar[5].s[0].effect << std::endl; 
	// Cleaning up memory.
	// NB! You must first free the memory used by the array of spells before
	// 	freeing the memory used by the spellbook array.
	delete_library(&lib);
	//for(int i = 0; i < lib.num_books;i++){
	//	delete_spell_array(lib.book_ar[i].s);	
	//}
	//delete_spellbook_array(lib.book_ar);


	return 0;
}
// ==============================================================
*/
