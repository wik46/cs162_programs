/* **************************************************************************************
 * Filename: driver.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Assignment: Program 3, Zoo Tycoon.
 * Date: November 8, 2020.
 * Description: This is a reinvention of the classic Microsoft game Zoo Tycoon. This is
 * 		a very basic version of the game that allows the owner of the zoo to only
 * 		buy 3 types of animals for his/her zoo. Namely: bears, sea lions, 
 * 		and tigers. The user will start out with no-animals in the zoo and
 * 		a bank account that containing $100 000 inside. 
 * 		One round played will represent one month in real life. Each round the 
 * 		user is allowed to buy at most two animals from a single species, income 
 * 		will be generated based on the number and types of animals currently in
 * 		the zoo, and the user will pay the monthly zoo expenses.. 
 *
 * 		Random events that occurs each round:
 * 			1. An animal gets sick and the user needs to pay medical cost.
 * 			2. An adult(4 years+) will give birth to the specified number of
 * 			   babies of her type.
 * 			3. A boom in attendance will occur where each sea lion generates
 * 			   between $150 - $400 extra revenue.
 * 			4. Nothing happens, unfortunately.
 * Input: Files needed:
 * 		Game.cpp and Game.h,
 * 		Zoo.cpp and Zoo.h,
 * 		Player.cpp and Player.h,
 * 		Animal.cpp and Animal.h,
 * 		Bear.cpp and Bear.h,
 * 		Bear_cage.cpp and Bear_cage.h,
 * 		Sea_lion.cpp and Sea_lion.h,
 * 		Sea_lion_cage.cpp and Sea_lion_cage.h,
 * 		Tiger.cpp and Tiger.h,
 * 		Tiger_cage.cpp and Tiger_cage.h,
 * 		Date.cpp and Date.h,
 * 
 * Output: A friendly user experience while playing Zoo Tycoon in a command
 * 	   line interface
 * **************************************************************************************/

#include "Animal.h"
#include "Date.h"

#include <iomanip>
#include <iostream>

int main(){
	Date current(5,1,2000);
	
	Animal a("zoo", current);
	std::cout << a.m_place_of_birth << std::endl;
	std::cin >> a.m_cost;
	std::cin >> a.m_perc_rev;
	a.m_birth_date.print_fnumeric();
	std::cout << a << std::endl;
		
	std::cout << Animal::m_total_animals << std::endl;

}
