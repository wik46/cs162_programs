/* **************************************************************************************
 * Filename: Tiger.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Assignment: Program 3, Zoo Tycoon.
 * Date: November 8, 2020.
 * Description:  
 * Input: -
 * Output: -
 * **************************************************************************************/

#include "Tiger.h"


/* ***************************************************************************************
 * Function name: Tiger()
 * Description: This function is used to create a child of the Animal class.
 * 		Tiger's will be kept in the Zoo. The Zoo is an array of Animal*.
 * 		Polymorphism plays an enormous part in the Zoo.
 * Parameters: const char*, Date.
 * Pre-condtions: -
 * Post-conditions: An instance of a Tiger class is created where the place of birth and
 * 			location of birth is specified by the user.
 * **************************************************************************************/
Tiger::Tiger(const char* where, Date when): Animal(where, when)
{
	// The type of animal is set.
	m_type = "Tiger";
	// This will tell me the animals maximum amount of babies that they
	// can deliver at a time.
	m_max_babies = 3;
	// This will be the intial cost of the type of animal.
	m_cost = 15000;
	// This will help me calculate the food cost for the type of animal.
	m_food_cost_mult = 5;
	// This variable will help me calculate the the revenue earned per animal
	// of the class.
	m_perc_rev = 0.10;
}

