/*
 * Filename:
 * Author: Wikus
 *
 * */

#include "spellbook.h"
#include <iostream>
#include <cstdlib>



/* **************************************************************************************
 * Function name: swap() 
 * Description: This function will swap the position of a spellbook in the 
 * 		array of spells. 
 * Parameters: spellbook*, spellbook*
 * Pre-conditions: -
 * Post-conditions: The function is used inside quick_float_sort().
 * ***********************************************************************************+**/
void swap(spellbook* a, spellbook* b){
	spellbook tmp = *a;
	*a = *b;
	*b = tmp;
}

// 1. Sort by number of pages.
/* **************************************************************************************
 * Function name: quick_sort()
 * Description: This function takes in a array of spellbooks as an arguments and sorts 
 * 		them according to the number of spells inside the spellbook ascending 
 * 		order.
 * Parameters: spellbook*, int, int.
 * Pre-conditions: The spellbook array must contain data (that is spells) and the length
 * 		   of the first and last index of the array needs to be passed as the 
 * 		   second and third arguments of the function.
 * Post-conditions: The function sort the array of spellbooks by the number of spells
 * 	            in each book in ascending order.
 * **************************************************************************************/
void quick_sort(spellbook* book_ar, int left, int right){
	// The base case. It is not needed to sort an array of length one.
	if(left >= right){
		return;
	}
	// Getting my pivot point. All the elements smaller/ equal to the pivot point
	// 	will go to the left subarray and the rest will be at the right subarray.
	// I am taking the last element in the array as my pivot point.
	int pivot = book_ar[right].num_pages;
	// This tracker will help me swap my elements in the array.
	int tracker = left;
	for(int i = left; i <= right; i++){
		if(book_ar[i].num_pages <= pivot){
			swap(&(book_ar[tracker]), &(book_ar[i]));
			tracker++;
		}
		// Note that tracker will end on the value
		// will end with the value tracker = pivot + 1 becuase s_ar[].id_num <= pivot.
	}
	// Now I will recuresively call the function to sort the left and right subarray.
	// 1. Sorting the left subarray.
	quick_sort(book_ar, left, tracker - 2);
	// 2. Sorting the right subarray.
	quick_sort(book_ar, tracker, right);
}
	
/* **************************************************************************************
 * Function name: sort_by_num_pages()
 * Description: This function accepts a pointer to a library as an argument and sorts
 * 		the spellbooks in the library according to the number of spells in each 
 * 		spellbook. It makes use of quick_sort(). The purpose of this function
 * 		is to modularize the code from quick_sort().
 * Parameters: library*
 * Pre-conditions: The function make use of the swap() and quick_sort() function.
 * Post-conditions: The array of spells in the library is sorted by the number of spells
 * 		    inside the spellbooks in ascending order.
 * **************************************************************************************/
void sort_by_num_pages(library* lib){
	if(lib != NULL){
		// This is to get the first index and the last index of the array.
		int f_index = 0;
		int l_index = lib->num_books - 1;
		// An implementation of a quick sort algorithm.
		quick_sort(lib->book_ar, f_index, l_index);
	}else{
		std::cout << "[sort_by_num_pages()]: You passed in a null pointer." 
		<< " Possible error could be that you library does not contain data."
		<< std::endl;
	}
}

// 2. Sort by spell effect.
/* **************************************************************************************
 * Function name: swap()
 * Description: This function swaps the position of two spells in an array of spells.
 * 		It is used inside my sort by pattern function.
 * Paramters: spell*, spell*
 * Pre-conditions: -
 * Post-conditions: The position of the two spells in the array is swapped.
 * **************************************************************************************/
void swap(spell* p1, spell* p2){
	if(p1 != NULL || p2 != NULL){	
		spell tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
	}else{
		std::cout << "[Error]: " << std::endl;
		std::cout << "[swap(spell*, spell*)]: You did not give the function"
		<< " spells that contain data." << std::endl;
	}
}

	
/* **************************************************************************************
 * Function name: sort_by_spell_effect().
 * Description: This algorithm is designed to sort an array of people based on a specified 
 * 	       string of letters. The array of persons will be sorted by the order of the 
 * 	       characters in the string.
 * Parameters: struct*, int, string.
 * Pre-conditions: The struct array passed as the first argument of the function needs
 * 		   to contain data. This function makes used of the swap function.
 * Post-conditions: The struct array is sorted according to the pattern of strings
 * 			passed in as the third argument of the function.
 * **************************************************************************************/
void sort_by_spell_effect(spell* spl_ar, int length, std::string pattern){	
	if(spl_ar != NULL && length > 0){
		int index = 0;
		for( int i = 0;i < pattern.length(); i++){
			// length is the length of the person array.
			for(int j = 0; j < length; j++){
				if(tolower((spl_ar[j].effect)[0]) == pattern[i]){
					swap(&spl_ar[index], &spl_ar[j]);
				index++;
				}
			}
		}
	}else{
		std::cout << "[sort_by_pattern()]: The array passed into the function"
		<< " does not contain data or the length of the array is incorrect."
		<< std::endl;
	}
}
/*	
* This function is used to print an array of spells.
*
*
*/

void print_effects(spell* p_ar, int length){
	std::cout << std::fixed;
	for(int i = 0; i < length ; i++){
		std::cout<< i << ".) " << p_ar[i].effect << std::endl;
	}
}

// 3. Sort by the average success rate.
/* **************************************************************************************
 * Function name: cal_avg_success_rate().
 * Description: This function calculate the total success rate of all the spells inside
 * 		the spellbook and divides it by the number of spells. That is the average
 * 		success rate of a spell in the specified book.
 * Pre-conditions: The spellbook array needs to contains spellbooks with spells and 
 * 			data that is already inside the spells.
 * Post-conditions: Each spellbook.avg_success_rate is set to the correct value.
 * **************************************************************************************/

void calc_avg_success_rate(spellbook* s_ar, int size){
	if(size > 0 && s_ar != NULL){
		// Iteration will occur for each spellbook in the array.
		for(int i = 0; i < size; i++){
			// Iteration will occur for each spell in spellbook i.
			for(int j = 0; j < s_ar[i].num_spells; j++){
				s_ar[i].avg_success_rate += s_ar[i].s[j].success_rate;
			}
			s_ar[i].avg_success_rate /= s_ar[i].num_spells;
		}
	}else{
		// The error message that will be displayed if the array of spellbooks does
		// not contains data.
		std::cout << "[calc_avg_success_rate]:You spellbook array has a "
		<< "size smaller than one." << std::endl;
	}
}	

/* **************************************************************************************
 * Function name: quick_float_sort()
 * Description: This is function uses a quick sort algorithm. It is used to sort an 
 * 		array of spellbooks in decending order by the average success rate
 * 		of the spells inside the book.
 * Parameters: student*, int, int.
 * Pre-conditions: This function requires that calc_ave() has already set values to
 * 			the members ave_s_rate.
 * Post-conditions: The function sorts the array of spellbooks by their average success 
 * 			rate.
 * **************************************************************************************/

void quick_float_sort(spellbook* s_ar, int left, int right){
	// The base case. It is not needed to sort an array of length one.
	if(left >= right){
		return;
	}
	// This integer will help me compare two floats.
	int rounder = 10000;
	// Getting my pivot point. All the elements smaller/ equal to the pivot point
	// 	will go to the left subarray and the rest will be at the right subarray.
	// I am taking the last element in the array as my pivot point.
	// The float will be implicitly cassed to an intiger.
	int pivot = (s_ar[right].avg_success_rate * rounder);
	// This tracker will help me swap my elements in the array.
	int tracker = left;
	for(int i = left; i <= right; i++){
		// The idea behind rounder is that I obtain all the decimal values when I 
		// cast the float to an int for comparison.
		// This condition is what ensures that the function is sorting the array 
		// in descining order.
		 	                        /* if " <= " then sort in ascending*/
		if(((int)(s_ar[i].avg_success_rate * rounder)) >= pivot){
			swap(&(s_ar[tracker]), &(s_ar[i]));
			tracker++;
		}
		// Note that tracker will end on the value
		// will end with the value tracker = pivot + 1 becuase s_ar[].id_num <= pivot.
	}
	// Now I will recuresively call the function to sort the left and right subarray.
	// 1. Sorting the left subarray.
	quick_float_sort(s_ar, left, tracker - 2);
	// 2. Sorting the right subarray.
	quick_float_sort(s_ar, tracker, right);
}
	
/* **************************************************************************************
 * Function name: sort_by_avg_success_rate()
 * Description: This function takes a library of spellbooks as an argument and
 * 		calculates all the average success rates of the spellbooks.
 * 		Thereafter it sorts the spellbooks in the library according to average 
 * 		success rate of the spells inside the spellbooks in decending order.
 * Parameters: library*.
 * Pre-conditions: The library passed in as argument to the function need to contain
 * 			the data of numerous spellbooks each one fille with spell data.
 * Post-conditions: The spellbooks in the library are sorted by the average success rate
 * 			of the spells in the spellbooks.
 * **************************************************************************************/

void sort_by_avg_success_rate(library* lib_ptr){
	// Safety check for ensuring that the library contains an array of spellbooks.
	if(lib_ptr != NULL){
		// This will calculate the average success rate of each spellbook.
		calc_avg_success_rate(lib_ptr->book_ar, lib_ptr->num_books);
		// The second arguments is the left most index of the array and the
		// right argument is the right most index of the array.
		quick_float_sort(lib_ptr->book_ar, 0, lib_ptr->num_books - 1);

	}else{
		std::cout << "[sort_by_avg_success_rate]: You passed in a NULL pointer."
		<< " It is likely that your library struct does not contains data." << std::endl;
	}
}

// This part is all the function used in my print_to_write() function

/* **************************************************************************************
 * Function name: get_options()
 * Description: This function is used to obtain the selection made by the user.
 * 		The user must select an integer between [1,4] inclusively. The program 
 * 		will accept the integer entered as a string and if it is in the valid
 * 		range return it to the program. Else the function wil repromt the user
 * 		to enter new input.
 * Paramters: -
 * Pre-conditions: Prompts the user to enter an integer between 1-4 (inclusively).
 * Post-condtions: Return the integer as a string if it is between 1-4(inclusively), else
 * 		   reprompt the user.
 * ***************************************************************************************/
std::string get_options(){
	std::string tmp_str = "";
	std::cout << "1 - sort by num_pages." << std::endl;
	std::cout << "2 - sort by spell effect." << std::endl;
	std::cout << "3 - sort by avg success rate." << std::endl;
	std::cout << "4 - quit." << std::endl
	<< std::endl << "Please enter your selection: ";
	std::cin >> tmp_str;
	std::cout << std::endl;
	if(tmp_str == "1" || tmp_str == "2" 
	|| tmp_str == "3" || tmp_str == "4"){
		return tmp_str;
	}else{
		return get_options();
	}
}
/* **************************************************************************************
 * Function name: is_death_or_poison()
 * Description: This function will determine if a spellbook contains a spell 
 * 		with the spell effect of death or poison. If so it will return
 * 		true. Otherise it will return false. 
 * Parameters: library*, int.
 * Pre-conditions: The function takes in the data as a library* and the index of the 
 * 		   current book to search. 
 * Post-conditions: The funcion will return true if a spellbook contains at least one 
 * 		    spell with the effect of death or poison. Else it will return true.
 * **************************************************************************************/

bool is_death_or_poison(library* lib, int i){
	// The loop will go through all the spells in book_ar[i].
	// If one spell with the effect of death or poison is found the loop will break.
	// If the loop break before the last iteration then j will never be equal to
	// 	the maximum number of iteration of the loop.
	int j = 0;
	for(; j < lib->book_ar[i].num_spells; j++){
		if(((lib->book_ar[i].s[j].effect)) == "death" 
		|| ((lib->book_ar[i].s[j].effect)) == "poison")
		{ 
			break;
		}
	}
	if(lib->book_ar[i].num_spells == j){
	// This means that the loop iterated through the entire spellbook
	// without finding a spell with the effect of death or poison.
		return 0;
	}else {
	// This means that the spellbook contains at least one spell of death or poison.
		return 1;
	}
}

/* **************************************************************************************
 * Function name: wizard_book_print()
 * Description: This funnction is used when the user wants to print the data from	
 * 		from the library of spellbooks to the screen. (option 1 or option 3)
 * 		The function will not print books containing spells that have the effect
 * 		of death or poison in the.
 * Paramters: library*, string.
 * Pre-conditions: The library and the wizard needs to contain data that is valid
 * 		   for the program to use. That is the spelling of "death" and "poison"
 * 		   needs to be in all lowercase letters.
 * Post-conditions: The information from the spellbooks are printed to the screen.
 * 		    And the function will no give print deat/poison spells if a student is
 * 		    logged in.
 * **************************************************************************************/
// This will be the print function for if a student wizard is logged in.
// This function does not check if student is logged in it only prints to screen.
void wizard_book_print(library* lib, std::string option){
	// This index variable is used for displaying purposes.
	short index = 1;
	for(int i = 0; i < lib->num_books; i++){
		// This if condition will only execute if the current book does no contain
		// a spell with the effect of death or poison.
		if(is_death_or_poison(lib, i)){
			// If the option is 1 then the user selected to sort by number of pages.
			if(option == "1"){
				std::cout<< index << ".) Spellbook title: " << lib->book_ar[i].title << std::endl;
				std::cout << " Number of pages: " << lib->book_ar[i].num_pages << std::endl; 
				index++;
			// If the option is 3, then the user the user selected to print by average success
			// rate of the spells.
			}else if(option == "3"){
				std::cout<< index << ".) Spellbook title: " << lib->book_ar[i].title << std::endl;
				std::cout << "Average success rate of spells in the book: " 
				<< lib->book_ar[i].avg_success_rate << std::endl;
				index++;
			}
		}
	}
}

/* ***************************************************************************************
 * Function name: normal_book_print()
 * Description: This function is used when a headmaster or teacher is logged in to display
 * 		all the types of spells contained in the spellbooks. It will display the 
 * 		number of pages of the spellbooks or the average success rate of the
 * 		spells base on the string variable option passed in as argument to the 
 * 		function.
 * Parameter: library*, string.
 * Pre-conditions: The function will only print the books and will not validate that
 * 		   it is a headmaster/teacher who is logged in.
 * Post-conditions: The function prints out the number of spells per book or the
 * 		    average success rate of all the spells per book.
 * **************************************************************************************/

void normal_book_print(library* lib, std::string option){	
	// Index is for display purposes.
	short index = 1;
	for(int i = 0; i < lib->num_books; i++){
		// Option 1 is to print the spellbooks number of pages.
		if(option == "1"){
			std::cout<< index << ".) Spellbook title: " << lib->book_ar[i].title
			 << std::endl;
			index++;	
			std::cout << "Number of pages: "
			<< lib->book_ar[i].num_pages << std::endl; 
		// Option 3 is to print the average success rate of the spells in a spellbook.
		}else if(option == "3"){
			std::cout<< index << ".) Spellbook title: " 
			<< lib->book_ar[i].title << std::endl;
			index++;
			std::cout << "Average success rate: " << std::endl
			<< lib->book_ar[i].avg_success_rate << std::endl;
		}
		std::cout << std::endl;
	}
}

/* **************************************************************************************
 * Function name: print_1_or_3()
 * Description: This function will used when the user selected option
 * 		1 or 3 and the user want to output it to the screen.
 * 		The function will determine what information is allowed to 
 * 		be printed based on the wizard that is logged int.
 * Paramters: library*, wizard*, and string.
 * Pre-condtions: The library and wizard pointers must point to data that is in the
 * 		  correct format. That is the position titles needs to be
 * 		  "Headmaster", "Teacher", and "Student". If the format is
 * 		  incorrect the function will assume a student is logged in and
 * 		  print the restricted version of the data.
 * Post-conditions: The information is printed to the screen.
 * **************************************************************************************/
void print_1_or_3(library* lib, wizard* wiz, std::string option){
	if((wiz->position_title) == "Headmaster" 
	|| wiz->position_title == "Teacher") {
		std::cout << "------"<< std::endl;
		normal_book_print(lib, option);
		std::cout << "------"<< std::endl;
	}else{
		std::cout << "------"<< std::endl;
		// to print the files to the screen.
		wizard_book_print(lib, option);
		std::cout << "------"<< std::endl;
	}
}

/* **************************************************************************************
 * Function name: get_file_name()
 * Description: The purpose of this function is to retrieve a name
 * 		for a file from the user to write data to.
 * Paramters: - 
 * Pre-condtitions: -
 * Post-conditions: Returns the a filename(string).
 * **************************************************************************************/
std::string get_file_name(){
	std::string tmp_input = "";
	std::cout << "Please enter a name for the file that you wish "
	<< "to output the data: ";
	std::cin >> tmp_input;
	// This part of the function is if the programmer does not want to allow the
	// wizards to manipulate the original files used by the program.
	// It is commented out because for the purpose of the assignment the wizard
	// should be allowed to append data to existing files.
	/*
	if(tmp_input == "spellbooks.txt"
	|| tmp_input == "wizards.txt"){
		std::cout << std::endl << "You cannot overide the spellbooks.txt" 
		<< " or the wizards.txt files." << std::endl;
		return get_file_name();
	}else{
	*/
		return tmp_input;
	/*
	}
	*/
}

/* **************************************************************************************
 * Function name: write_1_or_3_student()
 * Description: This function will be called when a student wizard is logged in and 
 * 		he/she wants to write the spellbooks to a file. The spellbooks will 
 * 		be ordered by the number of spells (option 1) or by the average success 
 * 		rate of the spells (option 3) inside each book. 
 * 		This function assumes that the order the spellbooks are already sorted. 
 * 		This function will be used inside write_1_or_3().
 *		This function makes use of is_death_or_poison().
 * Parameters: library*, string. 
 * Pre-conditions: The function assumes that the order of the spellbooks are pre-sorted
 * 		   and that a wizard with student status is currently logged in.
 * Post-conditions: The spellbooks sorted by number of pages/ average success rate of
 * 		    spells are written to a file provided by the user.
 * **************************************************************************************/
// This function does not check if student is logged in it only prints to screen.
void write_1_or_3_student(library* lib, std::string option){
	// This index variable is used for displaying purposes.
	short index = 1;
	std::fstream f;
	std::string file_name = get_file_name();
	f.open(file_name, std::ios::out|std::ios::app);
	if(f.is_open()){
		for(int i = 0; i < lib->num_books; i++){
			// This if condition will only execute if the current book does no contain
			// a spell with the effect of death or poison.
			if(is_death_or_poison(lib, i)){
				// If the option is 1 then the user selected to sort by number of pages.
				if(option == "1"){
					f << index << ' '<< lib->book_ar[i].title << ' '
					 << lib->book_ar[i].num_pages << std::endl; 
					index++;
				// If the option is 3, then the user the user selected to write to a file
				// by average success rate of the spells.
				}else if(option == "3"){
					f << index << ' ' << lib->book_ar[i].title 
					<< ' ' << lib->book_ar[i].avg_success_rate << std::endl;
					index++;
				}
			}
		}
	}
	f.close();
}


/* **************************************************************************************
 * Function name: write_1_or_3_non_student()
 * Description: This function will be called when a wizard with non-student status
 * 		is logged in. The functionality is identical to write_1_or_3_student()
 * 		except that the condition for checking if a spell has the effect of death
 * 		or poison is omitted.
 * Parameters: library*, string.
 * Pre-conditions: The function assumes that a wizard with Headmaster/ Teacher status
 * 		   is logged in and that the array of spellbooks is pre-sorted.
 * Post-conditions: The function writes the information of all the spellbooks to
 * 		    a file provided by the user and sorted according to the option
 * 		    selected by the user.
 * **************************************************************************************/
void write_1_or_3_non_student(library* lib, std::string option){
	// This index variable is used for displaying purposes.
	short index = 1;
	std::fstream f;
	std::string file_name = get_file_name();
	f.open(file_name, std::ios::out|std::ios::app);
	if(f.is_open()){
		for(int i = 0; i < lib->num_books; i++){
			// If the option is 1 then the user selected to sort by number of pages.
			if(option == "1"){
				f << index << ' ' << lib->book_ar[i].title << ' '
				 << lib->book_ar[i].num_pages << std::endl; 
				index++;
			// If the option is 3, then the user the user selected to write to a file
			// by average success rate of the spells.
			}else if(option == "3"){
				f << index << ' ' << lib->book_ar[i].title 
				<< ' ' << lib->book_ar[i].avg_success_rate << std::endl;
				index++;
			}
		}	
	}
	f.close();
}



/* **************************************************************************************
 * Function name: write_1_or_3()
 * Description: This function makes use of write_1_or_3_student(), 
 * 		write_1_or_3_non_student(),and get_file_name(). 
 * 		It determines if a wizard with Student
 * 		status or with Headmaster/ Teacher status is logged in.
 * 		(Note: The capital letters are neccesary for the position title. 
 * 		If they are omitted the function will assume a Student is logged in and
 * 		print the list of spells without death/poison effects spells)
 * Parameters: library*, wizard*, string.
 * Pre-conditions: The function assumes that the array of spellbooks is presorted and that
 * 		   the wizard requisted to print the data to a file.
 * Post-conditions: The sorted list of spellbooks is written to the file specified by the
 * 		    user.
 * **************************************************************************************/
void write_1_or_3(library* lib, wizard* wiz, std::string option){
	if((wiz->position_title) == "Headmaster" 
	|| wiz->position_title == "Teacher") {
		write_1_or_3_non_student(lib, option);
	// This is the case when a student is logged in or there is an
	// incorrect format of Heamaster/ Teacher.
	}else{
		write_1_or_3_student(lib, option);
	}
}

/* **************************************************************************************
 * Function name: write_2_student()
 * Description: The purpose of this function is to write the list of spells
 * 		to a file entered by the user if a student wizard is logged in.
 * Paramters: library*
 * Pre-conditions: The library must contain and array of spells and the number
 * 		   of spells used by the program.
 * Post-conditions: The function writes the spells without the effects of death or poison 
 * 		    to a file provided by the user.
 * **************************************************************************************/
void write_2_student(library* lib){
	std::fstream f;
	std::string file_name = get_file_name();
	f.open(file_name, std::ios::out|std::ios::app);
	f << lib->num_spells  << std::endl;
	if(f.is_open()){
		int index = 1;
		for(int i = 0; i < lib->num_spells ; i++){
			// The spells will be written to the file if they do not
			// have an effect of death or poison.
			if(lib->all_spells[i].effect != "death" 
			&& lib->all_spells[i].effect != "poison"){
				f << index << ' ' << lib->all_spells[i].name << 
				 ' ' << lib->all_spells[i].effect << std::endl;
				index++;
			}	
		}
	}
	f.close();
}

/* **************************************************************************************
 * Function: write_2_non_student()
 * Description: The purpose of this function is to write the spells to a file
 * 		provided by the user when a headmaster or teacher is logged in.
 * 		It will right all the spells to the file.
 * Parameters: library*
 * Pre-condtions: The library must contains information on all the spells
 * 		  as well as the number of spells used by the program.
 * Post-conditions: All the spell names and effects will be written to a file provided 
 *    		    by the user. 
 * **************************************************************************************/

void write_2_non_student(library* lib){
	std::fstream f;
	std::string file_name = get_file_name();
	f.open(file_name, std::ios::out|std::ios::app);
	f << lib->num_spells << std::endl;
	if(f.is_open()){
		int index = 1;
		for(int i = 0; i < lib->num_spells ; i++){
			// The spells will be written to the file if they do not
			// have an effect of death or poison.
			f << index << ' ' << lib->all_spells[i].name << 
			 ' ' << lib->all_spells[i].effect << std::endl;
			index++;
		}	
	}
	f.close();
}

/* **************************************************************************************
 * Function name: write_2()
 * Description: This function uses write_2_student() and write_2_non_student()
 *              to determine what spelldata the wizard is allowed to have access to.
 * Parameters: library*, wizard*.
 * Pre-conditions: The function makes use of write_2_student() and write_2_non_student().
 * Post-conditions: The spell information is written to a file and the spells that are
 * 		    written is determined by the wizard's position title in the school.
 * **************************************************************************************/

void write_2(library* lib, wizard* wiz){
	if(wiz->position_title == "Headmaster"
	|| wiz->position_title == "Teacher"){
		write_2_non_student(lib);
	}else{
		write_2_student(lib);
	}

}

/* **************************************************************************************
 * Function name: print_2_student()
 * Description: This function will be used when a student is logged in and he/she
 * 		decided to print the number of spells to the screen. It will 	
 * 		be used inside print_2().
 * Parameters: library*
 * Pre-conditions: The function assumes that the all_spells* member of library contains
 * 		   the pre-sorted list of spells used by the program and that the 
 * 		   num_spells member contains the number of spells in the array.
 * Post-conditions: The restricted list of spells is printed to the screen.
 * **************************************************************************************/
void print_2_student(library* lib){
	int index = 1;
	std::cout << std::endl << "List of Spells: \n" << std::endl;
	for(int i = 0; i < lib->num_spells ; i++){
		// The spells will be printed to the screen if they do not
		// have an effect of death or poison.
		if(lib->all_spells[i].effect != "death" 
		&& lib->all_spells[i].effect != "poison"){
			std::cout << index << ".) " << lib->all_spells[i].name << 
			 ' ' << lib->all_spells[i].effect << std::endl;
			index++;
		}	
	}
	std::cout << std::endl;
}


/* **************************************************************************************
 * Function name: print_2_non_student()
 * Description: The function will be used when a non-student (Headmaster/ Tescher) 
 * 		is logged in and he/she wants to print all the spells stored in the
 * 		spellbooks.txt file to the screen. The function will be used inside 
 * 		print_2().
 * Pre-conditions: The function assumes that the all_spells* member of library contains
 * 		   the pre-sorted list of spells and that the num_spells member of library
 * 		   contains the number of elements in the array.
 * Post-conditions: The function prints all the spells to the screen in the order that 
 * 		    they are indexed in the array.
 * **************************************************************************************/
void print_2_non_student(library* lib){
	int index = 1;
	std::cout << std::endl << "List of Spells: \n" << std::endl;
	for(int i = 0; i < lib->num_spells ; i++){
		// All the spells in the array all_spells will be printed
		// to the screen because the function will be called when a Headmaster or 
		// Teacher is logged in.
		std::cout << index << ".) " << lib->all_spells[i].name << 
		 ' ' << lib->all_spells[i].effect << std::endl;
		index++;
	}	
	std::cout << std::endl;
}

/* **************************************************************************************
 * Function name: print_2()
 * Description: This function makes use of print_2_non_student() and print_2_student().
 * 		Based on the wizard that is logged in, the function will decide to print
 * 		the restricted list of spells or the entire list of spells.
 * Parameters: library*, wizard*
 * Pre-conditions: The functions makes use of print_2_student() and print_2_non_student().
 * 		   See their pre-condtions for the further information.
 * Post-conditions: The list of spells stored in the all_spells member of library will
 * 		    be printed to the screen.
 * **************************************************************************************/

void print_2(library* lib, wizard* wiz){
	// The function will only print all the spells if the format of the position
	// titles of the wizards are correct. If their is any error with the formatting
	// the function will, as a pre-caution, only print the student acceptable
	// list of spells. 
	if(wiz->position_title == "Headmaster"
	|| wiz->position_title == "Teacher"){
		print_2_non_student(lib);
	}else{
		print_2_student(lib);
	}
}


/* **************************************************************************************
 * Function name: get_print_or_write_selection()
 * Description: This function is used to asked the user whether they want to print the 
 * 		data to the screen or write it to a file. It is used inside 	
 * 		print_or_write().
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: Returns "print" if the user selected the print option 
 * 		and "write" if the user selcted to write the data to the file.
 * **************************************************************************************/

std::string get_print_or_write_selection(){
	// the value that will be returned by the function.
	std::string tmp_out = "";
	// Output message to the user.
	std::cout << std::endl << "Do you want to print the data to "
	<< "the screen or write it to a file? (1 - print or 2 - write)" << std::endl;
	std::cin >> tmp_out;
	if(tmp_out == "1"){
		// The condition outside the function evaluates "print"/"write".
		return "print";
	}else if(tmp_out == "2"){
		return "write";
	}else{	
		// Message that will display if the user entered invalid input.
		std::cout << std::endl << "Please enter 1 or 2."<< std::endl; 
		return get_print_or_write_selection();
	}

}

/* **************************************************************************************
 * Function name: print_or_write()
 * Description: This is function that will prompt the user to print or write
 * 		the sorted data inside the library. The function will act if the
 * 		option argument is "1", "2", or "3". Base on this and the sorted
 * 		library of spellbooks or spells, the function will output the
 * 		data to the screen or a file provided by the user. The function is used 
 * 		inside User_option(). 
 * Parameters: library*, wizard*, string.
 * Pre-conditions: The function assumes that the data passed in in the library is 
 * 	           already sorted.
 * Post-conditions: The data is outputted to the screen or a file based on the 
 * 		    user's choice.
 * **************************************************************************************/

void print_or_write(library* lib, wizard* wiz, std::string option){
	// Ask the user if he/she wants to print or write the data.
	// The wizard should not be promted if he/she wishes to quit the program.
	std::string output_option = "";
	if(option != "4"){
		output_option = get_print_or_write_selection();
	}
	// If the user want to sort the list of spellbooks.
	// This is when the user wants to list the spellbooks in a specified order.
	if(option == "1" || option == "3"){
		// The option 1 or three will determine what data is outputted.
		if(output_option == "print"){
			print_1_or_3(lib, wiz, option);
		}else if(output_option == "write"){
			write_1_or_3(lib, wiz, option);
		}
	// This is when the user want to see the list of spells.
	}else if(option == "2"){
		if(output_option == "print"){
			print_2(lib, wiz);
		}else if(output_option == "write"){
			write_2(lib, wiz);
		}
	}else{}
}
/* **************************************************************************************
 * Function name: User_options()
 * Description: This function will be used inside the driver file of the program. The 
 * 		purpose of the function is prompt the user on how he/she wishes
 * 		to sort their data and to what output device they want it. This function
 * 		will determine what spell data is allowed to be viewed by the wizard
 * 		based on his/her status. The function will return the option selected
 * 		by the user. If the user selects "1" - "3", data will be sorted and
 * 		outputted to an output device and the user function will return the 
 * 		option selected. If the user enters "4" - indicating that he/she wishes
 * 		to quit the program, the the function will return the string "quit".
 * 		The string returned by the function is the variable used in the
 * 		condition of the main while loop of the program.
 * Parameters: library* and wizard*.
 * Pre-conditions: The value at the address the pointer parameters are pointing to 
 * 		   needs to hold valid data.
 * Post-condtions: The function will sort the data according to the user's selection,
 * 		   output it to an output device (screeen/ file) and return the
 * 		   string entered by the user. 
 * **************************************************************************************/
std::string User_option(library* lib, wizard* wiz){
	std::string option = get_options();
	// This is the pattern by which the array of spells inside the library
	// will be sorted if the wizard selects to sort the spells by effect.
	std::string pattern = "bmfpd";
	
	if(option == "1"){
		sort_by_num_pages(lib);
	}else if(option == "2"){
		sort_by_spell_effect(lib->all_spells, lib->num_spells,pattern);
	}else if(option == "3"){
		sort_by_avg_success_rate(lib);	
	}else if(option == "4"){
		// The main while condition ins my program is 
		//  " while(option != "quit")"
		// Therefore if the user selects 4 then the program will end
		return "quit";	
	}else{
		std::cout << "Error with if-statement inside print_or_write()" 
		<< std::endl;
	}
	// This part of the function takes the sorted data and determines to what 
	// output device the user wants the data to be outputted.	
	print_or_write(lib, wiz, option);
	// If the user did not whish to quit the function will not return "quit"
	// and the main while loop of the program will iterated again.
	return option;
}


