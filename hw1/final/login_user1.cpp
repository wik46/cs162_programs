/* **************************************************************************************
 * Filename: login_user1.cpp.
 * Auhtor: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Description: This is the implementation file for the all the functions
 * 		that facilitate the wizard login process.
 * Pre-condtions: A text file wizards.txt that contain the data of all the wizards in
 * 		  Pogwarts.
 * Output: The data is stored inside the wizard struct and the program will
 *         continue if the user entered a matching set of ID-number/password.
 * **************************************************************************************/


#include "wizard.h"
#include <iostream>
#include <fstream>

/* **************************************************************************************
 * Function name: open_file_read()
 * Description: The purpose of this function is to take in a string that may/may not
 * 		contain the data of the wizards.txt file. If the function is 
 * 		able to open the file successfully, the function will return to
 * 		the main program. Else the user/wizard will be promted to enter
 * 		a valid file to the program. The user/wizard will be promted untill
 * 		a valid file is entered.
 * Parameters: fstream*, string.
 * Pre-conditions: The fstream object needs to be declared in an outer scope.
 * Post-conditions: The fstream object is associated with the wizard.txt file.
 * **************************************************************************************/
void open_file_read(std::fstream* file_in, /*const char* */std::string file_name){
	// First conditional statement makes sure that the wizard did not
	// provide the spellbooks.txt file for wizard data.
	const char wrong_data_file = 's';
	if(file_name[0] != wrong_data_file){
		(*file_in).open(file_name, std::ios::in);
	}else{
		// If the user entered an existing file containing the wrong
		// data he/she will be prompted to re-enter a file name. 
		// The program assumes that there is not a file named DNE.txt inside
		// the current directory.
		(*file_in).open("DNE.txt", std::ios::in);
	}
	// This function will not open the spellbooks.txt file
	if((*file_in).is_open() && file_name[0] != 's'){	
		return;
	}else{
		std::cout << std::endl << "[Error]: Filename " << file_name << " is invalid." << std::endl;
		std::cout << "Please re-enter the name of the file that contains the" <<
		" wizard data: ";
		std::string in_str = "";
		std::cin >> in_str;
		std::cout << std::endl;
		open_file_read(file_in, in_str);
		return;
	}	
}
/* **************************************************************************************
 * Function name: create_school().
 * Description: (###  Caution  ###) Creates a dynamic array.
 *              This function assumes that the struct contains the size of the school.
 * Parameters: school*.
 * Pre-conditions: The data from the wizards.txt file needs to be obtained regarding
 * 		   the number of wizards in the school.
 * Post-conditions: An array of a specified size is created to store wizards.
 * **************************************************************************************/              
void create_school(school* schl){
	if(schl->num_wiz_in_school > 0){
		schl->wiz_ar = new wizard[schl->num_wiz_in_school];			
	}else{
		std::cout << "[Error]: The number of wizards in your school is " << schl->num_wiz_in_school
		<< "." << std::endl;
	}
}
/* **************************************************************************************
 * Function name: delete_school()
 * Description: (###  Caution  ###) Frees a dynamic array.
 * Parameters: school*.
 * Pre-conditions: If an array of wizards was created on the heap, then the function
 * 		   will free the memory at that address. 
 * Post-conditions: Memory at the address of is freed only if it was allocated.
 * **************************************************************************************/              
void delete_school(school* schl){
	if(schl->wiz_ar != NULL){
		delete[] schl->wiz_ar;
	}
}
/* **************************************************************************************
 * Function name: set_info()
 * Description: This function take the data from the stream object and saves it to 
 * 	        each wizard in the wizard array inside schl.
 * Parameters: school*, fstream*
 * Pre-condtions: The funcion assumes that a school object and fstream object
 * 		  is created in an outer scope.
 * Post-condtions: Stores the data from the file associated with the stream object	
 * 		   in the school struct.
 * **************************************************************************************/
void set_info(school* schl, std::fstream* file_in){
	*file_in >> schl->num_wiz_in_school;
	create_school(schl);
	while(*file_in/*!(*file_in).eof()*/){
		for(int i = 0; i < schl->num_wiz_in_school; i++){
			*file_in >> (schl->wiz_ar[i]).name >>
			(schl->wiz_ar[i]).id >> (schl->wiz_ar[i]).password >>
			(schl->wiz_ar[i]).position_title 
			>> (schl->wiz_ar[i]).beard_length;
		}
	}
}
/* **************************************************************************************
 * Function name: as_for_id()
 * Description: This function only collects a string as a ID-number from the user.
 * Parameters: -
 * Pre-conditions: -
 * Post-condtions: Returns the string entered as a ID-number by the user.
 * **************************************************************************************/
std::string ask_for_id(){
	std::string temp;
	std::cout << "Please enter you ID-number: ";
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
	for(int i = 0; i < (*str1).length(); i++){
		// This condition will be met if the charater is not a numeric value.
		if((*str1)[i] < 48 || (*str1)[i] > 57){
			// This returns false.
			return 0;
		}
		// The empty string cannot be passed to stoi() later in the program.
	}
	return 1;
}
/* **************************************************************************************
 * Function name: get_id()
 * Description: This function promts the user for his/her password. It will only return
 * 		a valid password. That is a password that contains only numeric.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: The function returns the first valid integer entered by the user.
 * **************************************************************************************/
// This is used for the first part of getting use input.
int get_id(){
	// The string is initialized to an invalid value so that the while-loop will iterate.
	std::string tmp = " ";
	// The id-number is invalid if the string contains any non-numeric characters.
	while(!is_valid(&tmp)){
		// this will prompt the user to enter a new string and save the value into tmp.
		tmp = ask_for_id();
		// This is used to display helpful input to the user.
		if(!is_valid(&tmp)){
			std::cout << "Your ID-number is invalid." << std::endl;
		}
	}
	return stoi(tmp);
}
/* **************************************************************************************
 * Function name: ask_for_password()
 * Description: This function only collects a string as a password from the user.
 * Parameters: -
 * Pre-conditions: -
 * Post-condtions: Returns the string entered as a password by the user.
 * **************************************************************************************/
// This function prompts the user to enter his/her password.
std::string ask_for_password(){
	std::string temp;
	std::cout << "Please enter your password: ";
	std::cin >> temp;
	return temp;
}

/* **************************************************************************************
 * Function name: is_match()
 * Description: This function will return true if the ID-number and password entered 
 * 		as arguments match. Else it will return false.
 * Paramters: int*, string, school*.
 * Pre-condtions: The function assumes that the school contains the data of 
 * 		  all the wizards.
 * Post-conditions: If the ID-number and password entered by the user matches a wizard 
 * 		    in the school, the function will return true. Else return false.
 * **************************************************************************************/

bool is_match(int* id_num, std::string pswrd, school* schl){
	// This function will iterate through all the wizards to search for a match.
	for(int i = 0; i < schl->num_wiz_in_school; i++){
		if(*id_num == (schl->wiz_ar[i]).id && pswrd == (schl->wiz_ar[i]).password){
			//std::cout << "[is_match()]: match found." << std::endl;
			// This ID-number is set to the index number in the wizard array.
			// This number will be return by the Login_user() function.
			*id_num = i;
			return 1;
		}
	}
	// The function will return false if no match was found.
	return 0;
}

/* **************************************************************************************
 * Function name: print_wiz()
 * Description: The purpose of the function is to print a single wizard. 
 * 		It is mainly used by search_match() which is part of the user 
 * 		login process.
 * Paramters: wizard*
 * Pre-conditions: The wizard* that is passed into the function needs to point to a memory 
 * 		   address that contains the data of a wizard.
 * Post-conditions: The function prints all the information of the wizard to the screen.
 * **************************************************************************************/
void print_wiz(wizard* wiz){
	
			std::cout << "=============" << std::endl
			<< "Found a match" << std::endl
			<< "=============" << std::endl
			<< "Wizard name: "<< wiz->name << std::endl
			<< "Title: " << wiz->position_title << std::endl
			<< "ID-number: " << wiz->id << std::endl
			/*<< "Password: " << wiz->password << std::endl*/
			<< "=============" << std::endl
			<< std::endl;
}

/* **************************************************************************************
 * Function name: search_match()
 * Description: The purpose of the function is to prompt the user for their 
 * 		ID-number and password. If they supply an invalid match then the function
 * 		will inform the user that they only have max attemps (3) - 1 left.
 * Parameters: school, 
 * Pre-conditions: The function makes use of get_id(), ask_for_password(), and is_match().
 * Post-conditions: The user is either logged in to the program or the program is 
 * 		    termintated.
 * **************************************************************************************/
int search_match(school* schl){
	
	// This will all be used inside search_match();
	int id_number = get_id();
	std::string password = ask_for_password();
	const short max_attempts = 3 - 1;
	for(int i = 0; i < max_attempts; i++){
		if(is_match(&id_number, password, schl)){
		// The case when the login information of the wizard was found.
			// is_match() will set the id_number variable to the index of
			// 	the wizard found to his/her position in the wizard array.
			int index = id_number;
			print_wiz(&schl->wiz_ar[index]);
			// This indec will use to find the wizard in my array in the main program.
			return index;
		}else if(!is_match(&id_number, password, schl)){
			std::cout << std::endl;
			std::cout << "You entered an invalid ID-number or password."
			<< std::endl << "You have " << max_attempts - i << " attmepts left.\n\n";
		// If the user does not enter a numeric id-number, then it will not count towards
		// 	an invalid attempt.
			id_number = get_id();
			password = ask_for_password();
		}else{
			// This should never execute.
			// If it does then there is a bug in the is_match() function.
			std::cout << "[Error]: something went wrong with id/password mathcing."
			<< std::endl; 
		}
	}
	// This is the case when the user was not able to login.
	const short unsuccessful = -1;
	return unsuccessful;
}


/* **************************************************************************************
 * Function name: Login_user()
 * Description: This function will be used in my driver file of the program.
 * 		The purpose is to handle all aspects of the user/wizard login process.
 * 		It assumes that the const char* passed in as argument contains a valid
 * 		file that holds the data of all the wizards in the school. It will save all that 
 * 		data inside a school. The function will terminate the program if the user
 * 		did not enter a valid ID-number/password combintation after three attempts.
 * 		The function will return the index of the wizard that is logged in.
 * Paramters: school*, const char*, fstream*.
 * Pre-condtions: The const char* needs to contain valid data of wizards an needs
 * 		  to be secure to read data from.
 * Post-condtions: If the wizard entered valid login information, the function will
 * 	           return the index of the wizard in the array of wizards. Else the 
 * 	           function will terminate the program.
 * **************************************************************************************/
int Login_user(school* schl, std::string str_in, std::fstream* f_in){
	// This function will re-prompt the user/wizard to re-enter the a valid file
	// if an it was unable to open the initial file provided.
	open_file_read(f_in, str_in);
	// This function assumes that f_in is already associated with the wizards.txt 
	// file.
	set_info(schl, f_in);
	// This function takes the data stored in the school struct to handle
	// the login process.
	// search_match() will return -1 if the no match was found.
	int index = search_match(schl);
	// If the function returns -1 then the wizard was unable to login.
	if(index == -1){
		std::cout << "I am sorry you were unable to login. " 
		<< "Please restart the program and try again." << std::endl;
	}
	return index;
}
