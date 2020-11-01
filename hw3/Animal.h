/* **************************************************************************************
 * Filename: Animal.h
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Assignment: Program 3, Zoo Tycoon.
 * Date: November 8, 2020.
 * Description: This is the interface/header file for the Animal class. Plese see 
 * 		Animal.cpp for more infor.
 * Input: -
 * Output: -
 * **************************************************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include "Date.h"

#include <assert.h>
#include <iomanip>
#include <iostream>

class Animal{
public:
	// ##### NEed a static function to intializes ther variable.
	// This will be a static variable that keeps track of the number of 
	// Animal instances in the game.
	static int m_total_animals;

	// #########
	// You need to write all the getters and setters and set the private access
	// specifier back.
	// ======
//private:
	// Each animal will have the following attributes.
	std::string m_name;
	// This will be a unique id. It will be based on the order at which the player
	// brought the animal to the zoo or when they were born.
	int m_id_number;
	// This will be so that I know which type the animal is.
	std::string m_type;
	// This will represent the age of the animal (in months.)
	int m_age_months;
	// This string variable will tell me if the animal was born in the zoo.
	// It will be either "zoo" or "other".
	const std::string m_place_of_birth;
	// This variable will be the date of birth of the animal if it was
	// born in the zoo.
	const Date m_birth_date; 
	// ==================
	// The following members will be changed based on the type of animal.
	// =============== 
	// This will tell me the animals maximum amount of babies that they
	// can deliver at a time.
	int m_max_babies;
	// This will be the intial cost of the type of animal.
	int m_cost;
	// This will help me calculate the food cost for the type of animal.
	// Bear - x3 monthly food cost, Sea Lion - base food cost, and
	// Tiger - x5 monthly base food cost.
	int m_food_cost_mult;
	// This variable will help me calculate the the revenue earned per animal
	// of the class.
	float m_perc_rev;
public:
	// This function will tell me if the Animal is a baby.
	bool is_baby() const;
	// This function will tell me if the animal is an adult.
	bool is_adult() const;
	// This function will return the cost associated with an animal getting sick.
	float get_sick() const;
	// This function will return the number of babies that the animal will deliver.
	// ** Note: It will return 0 if the instance is non-adult.
	int give_birth() const;
	// This function will return the revenue earned by the instance of Animal that
	// it is called with.
	float earn_revenue(unsigned int bonus = 0) const;
	
	// Overloaded operators.
	friend std::ostream& operator<<(std::ostream&, const Animal&);

	// This constructor is used when an animal is born in the zoo or bought.	
	Animal(const char*, Date when = Date(0,0,0) );
	
};
#endif 
