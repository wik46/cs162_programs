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

#include "LinkedList.hpp"
#include "Node.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

int main(int argc, char** argv){
	

	try{
		// This is just to help with the testing of the program
		std::string tmp = argv[1];
		argc = std::stoi( tmp ); 
	}catch(std::exception a){
		// Using the standard excpetions class.
		std::cout << a.what() << std::endl;
		std::cout << "[remember the size of the list as com arg]"<< std::endl;
		return -1;
	}
	// Seeding the random number generator.
	srand(time(NULL));
	// ==================================
	// Start of the Linked list testing.
	// ==================================

	LinkedList<int> ll;
	ll.push_front(13);
	ll.push_back(12);
	ll.push_front(-123238);
	ll.push_front(113);
	ll.push_front(-111);
	ll.push_front(1123230);

	// Gets a memory leak when execeuted.
	// ========
	if( *(ll.m_head) <= *(ll.m_head->next)){
		std::cout << "Node at m_head <= node at m_head->next "<< std::endl;

	}
	for(int i = 0; i < argc; i++){
		int tmp = rand() % 100;
		ll.insert( tmp, i );
		ll.push_front(tmp + i);
	}
	
	ll.print();
	// ** ** //	
	std::cout << "====================" << std::endl;
	std::cout << "Ascending order (m):" << std::endl;
	std::cout << "====================" << std::endl;
	// Sorting occurs here.

	ll.merge_sort_ascending();
	ll.print();
	std::cout << "====================" << std::endl;
	std::cout << std::endl;
	// ** ** //	
	std::cout << "=====================" << std::endl;
	std::cout << "Descending order(m):" << std::endl;
	std::cout << "=====================" << std::endl;
	ll.merge_sort_descending();
	ll.print();
	
	std::cout << "=====================" << std::endl;
	
	std::cout << std::endl;
	std::cout << std::endl;
	// ** ** //	
	std::cout << "====================" << std::endl;
	std::cout << "Ascending order (s):" << std::endl;
	std::cout << "====================" << std::endl;
	// Sorting occurs here.
	ll.selection_sort_ascending();
	ll.print();
	std::cout << "====================" << std::endl;
	std::cout << std::endl;
	// ** ** //	
	std::cout << "=====================" << std::endl;
	std::cout << "Descending order(s):" << std::endl;
	std::cout << "=====================" << std::endl;
	ll.selection_sort_descending();
	ll.print();
	std::cout << "=====================" << std::endl;
	
	
	std::cout << std::endl;
	
	// This function free's all the memory used by the program and should be used 
	// 	by the destructor.
	//ll.clear();
	
	//ll.print();
	
	return 0;
}

