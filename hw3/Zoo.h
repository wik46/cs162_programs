/* **************************************************************************************
 * Filename: Zoo.h
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Assignment: Program 3, Zoo Tycoon.
 * Date: November 8, 2020.
 * Description: This is the interface/header file for the Zoo class. Please see 
 * 		Zoo.cpp for more information.
 * Input: -
 * Output: -
 * **************************************************************************************/
// Naming convention.
// Any member function that is written with a capital letter will be used in driver.cpp
// directly.


#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"
#include "Bear.h"
#include "Sea_lion.h"
#include "Tiger.h"
#include "Date.h"
#include "Player.h"

#include <cassert>
#include <iostream>
//
class Zoo{
	// This will the array that stores all my animals.
public:
	// This is an array of various animals: Bears, Tigers ...
	// We use an array of Animal*.
	Animal** m_all_animals;
	int m_num_animals;
	// This will be the base cost of the round that is updated by 80 - 120 %.
	float m_base_cost;
	// This will be a way for the game to see which food was selected.
	std::string m_which_food;
public:
	// This function will be used to get the number of animals
	// in the Zoo.
	int get_num_animals() const;
	// This function will prompt the user to buy animals.
	void Auction();
	// This function will calculate the expenses occured from the foor cost.
	float Expenses(float);
	
	// This subscript operator overload will return the animal at the index
	// passed in as argument.
	// Note that this returns an animal reference.
	// +++ private +++.
	Animal*& operator[](int);
	// This will increase the number of cages in the Zoo by 1.
	Zoo& operator++();
	// This function will be used to print all the animals in the Zoo.
	friend std::ostream& operator<<(std::ostream&, const Zoo&);
	// This constructor will create a Zoo given size.
	// It will also set all the Animal* to the zoo as NULL.
	Zoo(int size = 1);
	// The destructor.
	~Zoo();
	// Copy constructor.
	// Assignment operator overload.
	Zoo& operator=(const Zoo&);
};

#endif
