/* **************************************************************************************
 * Filename: Sea_lion.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Assignment: Program 3, Zoo Tycoon.
 * Date: November 8, 2020.
 * Description:  This file is where my member functions of the Sea lion class is defined.
 * 		  The Sea_lion has an additinol feautures in that it produces extra 
 * 		  revenue.
 * Input: -
 * Output: -
 * **************************************************************************************/

#include "Sea_lion.h"

// This static variable will keep track of the number of Sea_lion instances in 
// during the program.
int Sea_lion::m_total{0};

int Sea_lion::m_boom_total{0};

/* ***************************************************************************************
 * Function name: get_boom_total().
 * Description: This function will return the boom total occured for one round.
 * 		It will return a reference to the member so that I can set
 * 		it to zero afterwards.
 * Parameters: - 
 * Pre-conditions: -
 * Post-conditions: Return the total income received from a boom in attendece.
 * **************************************************************************************/
int& Sea_lion::get_boom_total(){
	return Sea_lion::m_boom_total;
}
/* ***************************************************************************************
 * Function name: calc_boom_total().
 * Description: This function will calculate the total of income earned from a boom in 
 * attendence.
 * Parameters: - 
 * Pre-conditions: -
 * Post-conditions: Return the total income received from a boom in attendece.
 * **************************************************************************************/
int Sea_lion::calc_boom_total(){
	if(Sea_lion::m_total > 0){
		// This is the random boom attendence additional fund per animal.
		int extra = rand() % 251 + 150; // Returns a number between 150 - 400.
		Sea_lion::m_boom_total = Sea_lion::m_total * extra;
	}else{
		// Then the function will have no influence on the total.
		return 0;
	}
}
/* ***************************************************************************************
 * Function name: Sea_lion()
 * Description: This function is used to create a child of the Animal class.
 * 		Sea_lion's will be kept in the Zoo. The Zoo is an array of Animal*.
 * 		Polymorphism plays an enormous part in the Zoo.
 * Parameters: const char*, Date.
 * Pre-condtions: -
 * Post-conditions: An instance of a Sea_lion class is created where the place of birth and
 * 			location of birth is specified by the user.
 * **************************************************************************************/
Sea_lion::Sea_lion(const char* where, Date when): Animal(where, when)
{
	// The type of animal is set.
	m_type = "Sea lion";
	// This will tell me the animals maximum amount of babies that they
	// can deliver at a time.
	m_max_babies = 1;
	// This will be the intial cost of the type of animal.
	m_cost = 800;
	// This will help me calculate the food cost for the type of animal.
	m_food_cost_mult = 1;
	// This variable will help me calculate the the revenue earned per animal
	// of the class.
	m_perc_rev = 0.20;
	// This increments the Sea_lion total to count the number of Sea_lions.
	Sea_lion::m_total++;
}
/* ***************************************************************************************
 * Function name: ~Sea_lion()
 * Description: The only purpose of this is to decrement the m_total that keeps track of
 * 		the number of Sea_lions;
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: The instance of a Sea_lion is destroyed and the m_total is
 * 			decremented.
 * **************************************************************************************/
Sea_lion::~Sea_lion() {
	Sea_lion::m_total--;
}
