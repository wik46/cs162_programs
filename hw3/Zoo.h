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
#include "Probability.h"

#include <cassert>
#include <iostream>
//
class Zoo{
	// This will the array that stores all my animals.
	// This is an array of various animals: Bears, Tigers ...
	// We use an array of Animal*.
	Animal** m_all_animals;
	int m_num_animals;
	// This will be the base cost of the round that is updated by 80 - 120 %.
	float m_base_cost;
	// This will be a way for the game to see which food was selected.
	std::string m_which_food;
public:
	// This function will be used inside the driver.cpp.
	// It simulates the 4 random events that can occur during a single round.
	void Random_events(Player&, const Probability&);
	// This function will be used to get the number of animals
	// in the Zoo.
	int get_num_animals() const;
	// This will return the food type.
	const std::string& get_food_type();
	// This function will prompt the user to buy animals.
	int Auction();
	// This function will return the income earned from the animals in the zoo.
	float Income();
	// This function will calculate the expenses occured from the foor cost.
	float Expenses(float);
	// 1st RANDOM EVENT. ====
	// This function will get called when an animal is sick and will return the
	// cost if the user can afford it, else the animal dies and returns 0.
	int Hospital(int);
	// 2nd RANDOM EVENT. ====
	void babies_born();
	// 3rd RANDOM EVENT. ====
	// This function will be used in my random event function.
	// It will be called if a boom in the attendce occurs.
	// If there are no Sea lions in the Zoo is will tell the user.
	int attendance_boom();	
	// This function prompts the user to select the quality food.
	void which_food();
	// This subscript operator overload will return the animal at the index
	// passed in as argument.
	// This is the version that the is allowed for use outside the class.
	Animal* operator[](int) const;
	// This function increases the age of all my animals by the integer specified.
	void x_month_older(int num_month = 1);
private:
	Animal*& operator[](int);
	// This will increase the number of cages in the Zoo by 1.
	Zoo& operator++();
	// This function will be used to to remove th last element in the array of 
	// Animal*.
	Zoo& operator--();
public:
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

void swap(Animal*, Animal*);
int search_adult(const Zoo&);

#endif
