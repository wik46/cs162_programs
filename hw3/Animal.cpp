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

#include "Animal.h"
#include <assert.h>

#include <iomanip>
#include <iostream>

int Animal::m_total_animals{0};

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
	stream_out << std::setfill(' ')
	<< std::setprecision(3) << std::setw(1); 
	stream_out << '|'<< a.m_id_number << "" << a.m_name << ' ' << a.m_type << ' '; 
	stream_out << a.m_age_months  << " " <<  a.m_birth_date << ' ' << a.m_place_of_birth 
	<< '.' << std::endl;
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

