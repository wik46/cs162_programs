/* **************************************************************************************
 * Filename: Bear.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Assignment: Program 3, Zoo Tycoon.
 * Date: November 8, 2020.
 * Description: This is the file for my Animal class. This class will be frequently used.
 * 		One thing to take note of that each type of animal will be stored in
 * 		a "cage". That is an array of the desired type. 
 * 		Animals are babies if they are between [0,6] months old. 
 * 		-	They will have a birth date if they were born in the zoo.
 *		- 	If they were born outside the Zoo they arrive at the zoo
 *			at age 4.
 *		- 	The "cages" - array of the types - will keep track of the number
 *			of babies and adults in the zoo.
 *		-	An adult is any animal 4 years or greater.
 *		- 	Any non-adult cannot give birth to a baby.
 *		- 	Each specie gives birth to a set number of babies.
 * **************************************************************************************/

#include "Bear.h"

/* ***************************************************************************************
 * Function name: Bear()
 * Description: This function is used to create a child of the Animal class.
 * 		Bear's will be kept in the Zoo. The Zoo is an array of Animal*.
 * 		Polymorphism plays an enormous part in the Zoo.
 * Parameters: const char*, Date.
 * Pre-condtions: -
 * Post-conditions: An instance of a Bear class is created where the place of birth and
 * 			location of birth is specified by the user.
 * **************************************************************************************/
Bear::Bear(const char* where, Date when): Animal(where, when)
{
	// The type of animal is set.
	m_type = "Bear";
	// This will tell me the animals maximum amount of babies that they
	// can deliver at a time.
	m_max_babies = 2;
	// This will be the intial cost of the type of animal.
	m_cost = 6000;
	// This will help me calculate the food cost for the type of animal.
	m_food_cost_mult = 3;
	// This variable will help me calculate the the revenue earned per animal
	// of the class.
	m_perc_rev = 0.10;
}
