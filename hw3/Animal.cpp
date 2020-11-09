/* **************************************************************************************
 * Filename: Animal.cpp
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

// Note on naming convention for this class.
// _________________________________________
// The member variables are prefixed with an m_ and the same getter function
// used to get the value of that member variable the m_ is replaced with get_


#include "Animal.h"
#include "Date.h"
#include <assert.h>

#include <iomanip>
#include <iostream>

int Animal::m_total_animals{0};

/* ***************************************************************************************
 * Function name: get_name().
 * Description: This function is used to get access of the m_name member variable.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns the member variable m_name.
 * **************************************************************************************/
std::string Animal::get_name() const {
	return m_name;
}
/* ***************************************************************************************
 * Function name: get_id_number().
 * Description: This function is used to get access of the m_id_number member variable.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns the member variable m_id_number.
 * **************************************************************************************/
int Animal::get_id_number() const {
	// This will be a unique id. It will be based on the order at which the player
	// brought the animal to the zoo or when they were born.
	return m_id_number;
}
/* ***************************************************************************************
 * Function name: get_type().
 * Description: This function is used to get access of the m_type member variable.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns the member variable m_type.
 * **************************************************************************************/
std::string Animal::get_type() const {
	// This will be so that I know which type the animal is.
	return m_type;
}
/* ***************************************************************************************
 * Function name: get_age_months() const.
 * Description: This function is used to get access of the m_age_months member variable.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns the member variable m_age_months.
 * **************************************************************************************/
int Animal::get_age_months() const {
	// This will represent the age of the animal (in months.)
	return m_age_months;
}
/* ***************************************************************************************
 * Function name: get_age_months().
 * Description: This function is used to get access of the m_age_months member variable.
 * Non-const version.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns the member variable m_age_months.
 * **************************************************************************************/
int& Animal::get_age_months(){
	// This will represent the age of the animal (in months.)
	return m_age_months;
}
/* ***************************************************************************************
 * Function name: get_place_of_birth().
 * Description: This function is used to get access of the m_place_of_birth member variable.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns the member variable m_place_of_birth.
 * **************************************************************************************/
const std::string Animal::get_place_of_birth() const {
	// This string variable will tell me if the animal was born in the zoo.
	// It will be either "zoo" or "other".
	return m_place_of_birth;
}
/* ***************************************************************************************
 * Function name: get_birth_date().
 * Description: This function is used to get access of the m_birth_date member variable.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns the member variable m_birth_date.
 * **************************************************************************************/
// +====== Test this one =========+  //
const Date& Animal::get_birth_date() const {
	// This variable will be the date of birth of the animal if it was
	// born in the zoo.
	return m_birth_date; 
}
/* ***************************************************************************************
 * Function name: get_max_babies().
 * Description: This function is used to get access of the m_max_babies member variable.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns the member variable m_max_babies.
 * **************************************************************************************/
int Animal::get_max_babies() const {
	return m_max_babies;
}
/* ***************************************************************************************
 * Function name: get_cost().
 * Description: This function is used to get access of the m_cost member variable.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns the member variable m_cost.
 * **************************************************************************************/
int Animal::get_cost() const {
	// This will be the intial cost of the type of animal.
	return m_cost;
}
/* ***************************************************************************************
 * Function name: get_food_cost_mult().
 * Description: This function is used to get access of the m_food_cost_mult member variable.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns the member variable m_food_cost_mult.
 * **************************************************************************************/
int Animal::get_food_cost_mult() const{
	// This will help me calculate the food cost for the type of animal.
	// Bear - x3 monthly food cost, Sea Lion - base food cost, and
	// Tiger - x5 monthly base food cost.
	return m_food_cost_mult;
}
/* ***************************************************************************************
 * Function name: get_perc_rev().
 * Description: This function is used to get access of the m_perc_rev member variable.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns the member variable m_perc_rev.
 * **************************************************************************************/
float Animal::get_perc_rev() const{
	// This variable will help me calculate the the revenue earned per animal
	// of the class.
	return m_perc_rev;
}
/* ***************************************************************************************
 * Function name: is_baby().
 * Description: This function will tell me if the instance of an Animal is a baby.
 * 		An animal is a baby if it is 6 or less months old. Babies cost
 * 		twice as much to take care of when they are sick, but the
 * 		earn twice as much revenu as an adult. Babies cannot deliver babies.
 * Parameters: -
 * Input: Note that it is a const function.
 * Output: A boolean value depending in the Animal instance's age.
 * **************************************************************************************/
bool Animal::is_baby() const{
	// Six months or less is a baby.
	const short baby_age = 6;
	if(m_age_months <= baby_age){
		// The animal is a baby.
		return 1;	
	}else{
		// The animal is not a baby.
		return 0;
	}
}

/* ***************************************************************************************
 * Function name: is_adult().
 * Description: This function will tell me if the instance of an Animal is an adult.
 * 		An animal is an adult if it is 4 year (48 months) or older. Only adults 
 * 		can deliver babies.
 * Parameters: -
 * Input: Note that it is a const function.
 * Output: A boolean value depending in the Animal instance's age.
 * **************************************************************************************/
bool Animal::is_adult() const{
	const short adult_age = 4 * 12;
	if(m_age_months >= adult_age){
		// The animal is an adult.
		return 1;	
	}else{
		// The animal is not an adult.
		return 0;
	}
}

/* ***************************************************************************************
 * Function name: get_sick().
 * Description: This function will return the cost associate with an Animal getting sick.
 * 		If the animal is a baby, the cost of getting sick will be double that of 
 * 		an adult. Baby cost: The initial cost of the animal.
 * 			  Adult cost: Half the intial cost of the animal.
 * Parameters: -
 * Input: The function will be called if an event happens that makes the Animal sick.
 * Ouput: The price associated with sick animal.
 * **************************************************************************************/
float Animal::get_sick() const{
	if(this->is_baby()){
		// The price that it costs to care for a sick baby.
		return m_cost;
	}else{
		// The price that it cost to care for a sick non-baby.
		return m_cost / 2;
	}
}
/* ***************************************************************************************
 * Function name: give_birth().
 * Description: This function will return the number of babies that a animal delivers
 * 		at a time. If it is called on a non-adult instance, then it will return
 * 		0.
 * Parameters: - 
 * Input: The function will be called when a random event happens in the game.
 * Output: The number of babies that the animal delivers. 
 * **************************************************************************************/
int Animal::give_birth() const{
	// Only adults can have babies.
	if(this->is_adult()){
		return m_max_babies;
	}else{
		return 0;
	}
}
/* ***************************************************************************************
 * Function name: earn_revenue().
 * Description: This function will return the revenue earned from owning the particulae 
 * 		instance of an animal that it is called on. 
 * 		Bears: 10% of initial cost.
 * 		Tigers: 10% of intitial cost.
 * 		Sea lions: 20% of initial cost.
 * Parameters: int - A random event can occure where the sea lion exibition get a boom
 * 		in attendance. The integer passed in as the argument will be the 
 * 		additional revenue earned.
 * Input: The function will be called fore each intance of an Animal or any inherited
 * 	  class once per round/"month".
 * Output: The function returns the floating point number associated with the 
 * 	   revenue earned from owning the animal.
 * **************************************************************************************/
float Animal::earn_revenue(unsigned int bonus) const{
	// The bonus will default to zero if no
	// argument was passed to the function.
	return m_cost * m_perc_rev + bonus;
}

// ## Friend function, not a member function.##
// ** Note that you are passing the animal as a reference.
//      Therefore you need to be careful using this function if it is not virtual
// 	with derived class instances of Animal.

/* **************************************************************************************
 * Function name: operator<<().
 * Description: This is the overloaded '<<' operator that will ouput an instance
 * 		of an animal in an eligent format. The idea is that the when the
 * 		animals get printed out in the as the Zoo, that they will have an
 * 		uniform output.
 * Parameters: ostream&, const Animal&.
 * Input: A ostream object and an instance of an animal.
 * Output: The neccesary output is displayed to the user.
 * **************************************************************************************/
std::ostream& operator<<(std::ostream& stream_out, const Animal& a){
	stream_out << std::left;
	stream_out << std::setprecision(3); 
	stream_out << std::setw(12) << a.m_id_number  
	<< std::setw(12) << a.m_name << 
	std::setw(12) << a.m_type << std::setw(7) << a.m_age_months <<
	std::setw(17) << a.m_birth_date <<
	std::setw(17)<< a.m_place_of_birth;
	return stream_out;
}


/* ***************************************************************************************
 * Function name: Animal()
 * Description: This will be used to instantiate an animal that is born in the zoo 
 * 		or bought from another zoo. 
 * 		This function needs to increment the static variable m_total_animals
 * 		so that I can keep track of the number of animals in the zoo.
 *		There will be three ways that I want to construct an animal.
 *		1. Just for quick use,
 *		2. as a baby born in the zoo, or
 *		3. as an adult brought to the zoo. 	
 * Parameters: const char*: This will specify if the animal is born in the zoo or bought
 * 		from another zoo. ("bought" or "born").
 * 		Date: this will be the date that the animal was born.
 * Input: The loaction where the animal was born.
 * **************************************************************************************/
Animal::Animal(const char* where, Date when)
:m_place_of_birth{where}, m_birth_date{when}, m_id_number{100000} 
{
	assert(m_place_of_birth == "zoo" || m_place_of_birth == "other"
	&& "[Animal()]: You need to specify 'zoo' or 'other' for place of birth.");
	std::cout << std::endl;
	std::cout << "Please enter the name of your new animal: ";
	std::cin >> m_name; 
	// This will set the age of the animal base on where it was born.
	// Age is counted in months.
	if(m_place_of_birth == "zoo"){
		// A baby is born.	
		m_age_months = 0;
	}else if(m_place_of_birth == "other"){
		// An animal is bought from another zoo.
		// Age is measure in months and an animal not bought
		// in the zoo starts at 4 years of age.
		m_age_months = 4*12;
	}else{
		std::cout << "[Animal()]: Error while contructing an animal instance."
		<< std::endl;
	}
	// This give my animal a unique id.
	m_id_number += Animal::m_total_animals;
	Animal::m_total_animals++;
}

