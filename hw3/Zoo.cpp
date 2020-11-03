/* **************************************************************************************
 * Filename: Zoo.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Description: This is the file for my Animal class. This class will be frequently used.
 * 
 *
 * **************************************************************************************/

// ======
// Note that if using tis class.
// ======
//  - The destructor will free non-NULL memory. Therefore
//  	you need to store Animal* allocated on the heap
//  	in the zoo.

#include "Animal.h"
#include "Date.h"
#include "Zoo.h"
#include <assert.h>

#include <cassert>
#include <iomanip>
#include <iostream>

/* ***************************************************************************************
 * Function name: operator++().
 * Description: This function will increase the size of the Zoo by 1.
 * 		I will only define the pre-increment operator.
 * Parameters: -
 * Input: The user wants one extra cage in the Zoo.
 * Ouput: The Animal** array is increase by a size of 1.
 * **************************************************************************************/
Zoo& Zoo::operator++(){
	// We create the new array of size + 1.
	Animal** tmp_ar = new Animal*[m_num_animals + 1];
	// Now we save all the data into the new array.
	for(int i = 0; i < m_num_animals; i++){
		tmp_ar[i] = this->m_all_animals[i];
	}
	// Now we increment the size of the current size of the Zoo.
	m_num_animals++;
	// Now I can free the old memory.
	delete[] this->m_all_animals;
	// And lastly I put all the animals in the Zoo with the extra cage.
	this->m_all_animals = tmp_ar;
	// We return the object with an increas of cages/elements of one.
	return (*this);
	
}

/* ***************************************************************************************
 * Function name: operator<<().
 * Description: This is a friend function. Therefore it has access to the private 
 * 		members of the Zoo class but itseld is not a member of the class.
 * Parameters: std::ostream&, const Zoo&.
 * Input: An instace of a Zoo object.
 * Output: All the information currently avalable regarding the Zoo is printed to the 
 * 		screen.
 * **************************************************************************************/
std::ostream& operator<<(std::ostream& stream_out, const Zoo& zoo){
	stream_out << std::setfill(' ') 
	<< std::setprecision(3) << std::left;
	stream_out << std::endl;
	stream_out << "-------------------------------------------------------------------" 
	<< std::endl;
	stream_out << "| Id-number | Name | Type | Age | Date of purchase | Born in Zoo? |"	
	<< std::endl;
	stream_out << "-------------------------------------------------------------------" 
	<< std::endl;
	for(int i = 0; i < zoo.m_num_animals; i++){
		std::cout << *(zoo.m_all_animals[i]) << std::endl;	
	}

	stream_out << "-------------------------------------------------------------------" 
	<< std::endl;
	return stream_out;
}

/* *******************************************************************************+*******
 * Function name: Zoo().
 * Description: This is the constructor for the Zoo class. An user must create a Zoo of
 * 		at least one empty cage. An empty cage will be represented by a NULL 
 * 		Animal pointer.
 * Parameters: int ( =1 by default).
 * Input: The size of the Zoo that is created.
 * Output: A Zoo that stores an array of Animal*'s is created.
 * **************************************************************************************/
Zoo::Zoo(int size): m_num_animals(size)
{
	// This makes sure that the Zoo is intantiaed with at least one
	// instance in the array/
	assert(m_num_animals > 0
	&& "[Zoo()]: A zoo must be created with at least one empty cage.");
	// Create an array to store different animals.
	m_all_animals = new Animal*[m_num_animals];
	// Set all the Animal* to NULL.
	for(int i = 0; i < m_num_animals; i++){
		// This is so that I freed only non-NULL data.
		m_all_animals[i] = NULL;
	}
}
	
/* *******************************************************************************+*******
 * Function name: ~Zoo().
 * Description: The Zoo class destructor. The purpose of the Zoo class destructor is to
 * 		free the memory used by the Animal** m_all_animals. Not that at each
 * 		element in the array of Animal*, the memory is dynamically allocated.
 * 		Therefore we first need to free all the Animals before freeing the cage.
 * Parameters: -
 * Input: -
 * Output: All dynamic memory used by the program is freed accordingly.
 * **************************************************************************************/
Zoo::~Zoo(){
	// This will clean up all the memory used by the class.
	for(int i = 0; i < m_num_animals; i++){
		// Freeing all the animals.
		if(m_all_animals[i] != NULL){
			delete m_all_animals[i];
		}
	}
	// Then you can delete the cage.
	delete[] m_all_animals;
}