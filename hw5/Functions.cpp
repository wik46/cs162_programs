/* **************************************************************************************
 * Filename: Functions.cpp.
 * Author: Lodewyk Jansen van Rensburg.
 * Date: December 6, 2020.
 * Description: This is the implementation file for helper functions used for the
 * 		linked list demonstration program.
 * **************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

/* ***************************************************************************************
 * Function name: print_all_info()
 * Description: This will print all the information for the user to manipulate data 		
 * 		to the console with labels next to the member variables.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
void print_all_info(){
	std::cout << "-------------------------------------------------------"<< std::endl;
	std::cout << "Data manipulation options for a linked list.:" << std::endl;
	std::cout << "-------------------------------------------------------"<< std::endl;
	std::cout << "1.) Add a data value to the front of the list." << std::endl;
	std::cout << "2.) Add a data value to the end of the list." << std::endl;
	std::cout << "3.) Add x > 0 number of data elements to the list."<< std::endl;
	std::cout << "4.) Sort the list in for different ways."<< std::endl;
	std::cout << "5.) Clear the linked list of all its data." << std::endl;
	std::cout << "6.) Exit the program. " << std::endl;
	std::cout << "-------------------------------------------------------"<< std::endl;
	std::cout << std::endl;
	return;
}
/* ***************************************************************************************
 * Function name: sort()
 * Description: This function accepts the address of a linked list
 * 		and sorts it based on the integer passed as the second argument.
 * Parameters: T, int
 * Pre-conditions: This function will not sort the integer is not between 1 - 4
 * 		   inclusively.
 * Post-conditions: Ths functions sorts the linked list passed as the first argument.
 * **************************************************************************************/
template <class T>
void sort(){


}
/* **************************************************************************************
 * Function name: ask_for_input()
 * Description: This function only collects a string as a input from the user.
 * Parameters: -
 * Pre-conditions: -
 * Post-condtions: Returns the string entered as a input by the user.
 * **************************************************************************************/
std::string ask_for_input(){
	std::string temp;
	std::cin >> temp;
	return temp;
}

/* **************************************************************************************
 * Function name: is_valid()
 * Description: This function validates that the string only contains numeric charaters.
 * Parameters: - 
 * Pre-condtions: A string declared in an outer scope.
 * Post-condtions: Returns true if the pointer is pointing to an only-numeric charater
 * 		   string, else returns false.
 * **************************************************************************************/
bool is_valid(std::string* str1){
	// The case for a negative number.
	unsigned int i = 0;
	// If the first character is a negative sign.
	// And has at least one extra charater.
	if((*str1)[0] == '-' && (*str1).length() > 1){
		i = 1;
	}
	
	for(; i < (*str1).length(); i++){
		// This condition will be met if the charater is not a numeric value.
		if((*str1)[i] < 48 || (*str1)[i] > 57){
			std::cout << "Please enter an integer value." << std::endl;
			return 0;
		}
		// The empty string cannot be passed to stoi() later in the program.
	}
	return 1;
}
/* **************************************************************************************
 * Function name: get_int()
 * Description: This function promts the user for his/her input. It will only return
 * 		a valid input. That is a string that contains only numeric.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: The function returns the first valid integer entered by the user.
 * **************************************************************************************/
// This is used for the first part of getting use input.
int get_int(std::string prompt ,std::string error_msg){
	// This will be the output message to the user.
		std::cout << std::endl << prompt << std::endl;
	// The string is initialized to an invalid value so that the while-loop will iterate.
	std::string tmp = " ";
	// The id-number is invalid if the string contains any non-numeric characters.
	while(!is_valid(&tmp)){
		// this will prompt the user to enter a new string and save the value into tmp.
		tmp = ask_for_input();
		// This is used to display helpful input to the user.
		if(!is_valid(&tmp)){
			std::cout << error_msg << std::endl << std::endl;
		}
	}
	return stoi(tmp);
}

