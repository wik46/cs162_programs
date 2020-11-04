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
#include "Bear.h"
#include "Sea_lion.h"
#include "Tiger.h"
#include "Zoo.h"

#include "Date.h"
#include "Probability.h"

#include <iomanip>
#include <iostream>

int main(){
	Date current(5,1,2000);
	std::cin.get();
	
	Animal a("zoo", current);
	Zoo z;
	++z;
	
	Animal* dynamic = new Animal("zoo",current);
	Animal* dynamic1 = new Animal("zoo",current);
	z[0] = dynamic;
	z[1] = dynamic1;
	std::cout << z << std::endl;

	// All these classes inherit from Animal.
	Animal* bear  = new Bear("zoo", current);
	Animal* sea_lion = new Sea_lion("zoo", current);
	Animal* tiger = new Tiger("zoo", current);
	++z;	
	++z;	
	++z;	
	z[2] = bear;
	z[3] = sea_lion;
	z[4] = tiger;

	for(int i = 0; i < z.get_num_animals(); i++){
		std::cout << *(z[i]) << std::endl;
	}	
	
	
	Probability p;
	p.increase();
	p.increase();
	
	p.decrease();
	p.decrease();
	for(int i = 0; i < 20; i++){
	
		std::cout << i << ". "<< p.get_event() << std::endl;
	}
	return 0;
}
