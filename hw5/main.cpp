/* ***************************************************************************************
 * Filename: main.hpp
 * Author: Lodewyk Jansen van Resnburg.
 * Student ID: 934 309 717
 * Date: December 6, 2020
 * Homework 5: Linked List
 * Description: This file is the header and the impementation file for my linked list
 * 		data structure. 
 * 		Methods available for use:
 * 			a. int get_length()	
 * 				- returns the length of the list.
 * 			b. void print()
 * 				- Outputs all the integers inside the list
 * 			c. void clear() 
 * 				- Remove the entire list. Free's all memory used
 * 				by the list.
 * 			d. unsigned int push_front( T )
 * 				- Adds an node to the front of the list and returns the
 * 				new length of the list.
 * 			e. unsigned int push_back( T )
 * 				- Adds a node to the back of the list and returns the 
 * 				new length of the list.
 * 			f. unsigned int insert( T, int)
 * 				- Inserts a new node with value T at the index of the 
 * 				node specified.
 * **************************************************************************************/

#include "Functions.h"
#include "LinkedList.hpp"
#include "Node.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

int main(int argc, char** argv){

	// Declaring data used by the user.	
	LinkedList<int>* ll = new LinkedList<int>;
	// Seeding the random number generator.
	srand(time(NULL));
	// ==================================
	// Start of the Linked list testing.
	// ==================================
	do{
		// 1. This displays all the options that the user has to manipulate
		// 	the data inside the linked list.
		print_all_info();
		
		// 2. Display current list.
		ll->print();
		
		// 3. This gets the input from the user. get() returns any int
		// 	but entered by the user and does error-handeling on other
		// 	data types.
		// Obtaining input.
		int input = get_int("Enter 1 - 6 here: ", "");
	
		switch (input){
			// A. Inserting one instance of data in the front.
			case 1:{
				std::string msg = "Enter the number to insert at the head of the list";
				int result = get_int(msg,"Error msg");
				ll->push_front(result);	
				break;
			}
			// B. Insert one instance of data at the back.
			case 2:{	
				std::string msg = "Enter the number to insert at the tail of the list";
				int result = get_int(msg,"");
				ll->push_back(result);	
				break;
			}
			// C. Add an x amount of random data.
			case 3:{
				std::string msg = "Enter the number of random variables for the list";
				int result = get_int(msg,"[error]: must be > 0.");
				for(int i = 0; i < result; i++){
					ll->push_back( rand() % 100);
				}
				break;
			}
			// D. Sort the lists.( 4 different ways)
			case 4:{
				std::string msg = "1-Merge, a\n2-Merge, d\n3-Selection, a\n4-Selection, d";
				int result = get_int(msg, "");
				// 1. - merge sort ascending,
				// 2. - merge sort descending,
				// 3. - selection sort ascending, and
				// 4. - selection sort descending.
				sort_method( ll ,result );
				break;
			}
			// E. Clear all the data from the list.
			case 5:{
				ll->clear();
				break;
			}
			// F. Clear all the data from the list.
			case 6:{
				std::cout << "Are you sure you want to exit? - ('exit' to confirm): ";
				std::cin >> argv[0];	
				break;
			}
			// G. The user did not enter a valid integer.
			default:{
				std::cout << std::endl << 
				"** Please enter an integer 1 - 6.** " << std::endl;
				break;
			}
		}	
		std::cout << std::endl;
		
		
	}while(argv[0][0] != 'e');
	// Print out a goodbye message.		
	std::cout << "\n\n ** Goodbey! ** \n\n" << std::endl;
	// Freeing up the memory used by the containers.
	delete ll;
	
	return 0;
}

