/*
 * Filename: sort_by_list.cpp.
 * Author: Wikus
 * Date: October 11, 2020.
 * Description: The purpose of this program is the study methods of sorting based on a 
 * 		given string.
 * Input: -
 * Output: -
 * */

// This program sorts a an array of strings in order specified by another list/string.
// Learning resourse is GeeksForGeeks

#include "spellbook.h"
#include <iostream>
	

// This function swaps to person structs.
void swap(spell* p1, spell* p2){
	spell tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
	
/* **************************************************************************************
 * Function name: sort_by_pattern().
 * Description: This algorithm is designed to sort an array of people based on a specified 
 * 	       string of letters. The array of persons will be sorted by the order of the 
 * 	       characters in the string.
 * Parameters: struct*, int, string.
 * Pre-conditions: The struct array passed as the first argument of the function needs
 * 		   to contain data. This function makes used of the swap function.
 * Post-conditions: The struct array is sorted according to the pattern of strings
 * 			passed in as the third argument of the function.
 * **************************************************************************************/
void sort_by_pattern(spell* spl_ar, int length, std::string pattern){	
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
// This function is used to print an array of people.
void print_ar(spell* p_ar, int length){
	std::cout << std::fixed;
	for(int i = 0; i < length ; i++){
		std::cout<< i << ".) " << p_ar[i].effect << std::endl;
	}
}

// The driver code for my program.
int main(){
	int length = 20;
	std::string pattern2 = "mdpb";
	spell* spell_ar = new spell[length];

	spell_ar[0].effect = "Bubbles";
	spell_ar[1].effect = "fire";
	spell_ar[2].effect = "memory_loss";	
	spell_ar[3].effect = "death";
	spell_ar[4].effect = "poison";
	spell_ar[5].effect = "poison";
	spell_ar[6].effect = "poison";
	spell_ar[7].effect = "memory_loss";	
	spell_ar[8].effect = "memory_loss";	
	spell_ar[9].effect = "memory_loss";	
	spell_ar[10].effect = "memory_loss";	
	spell_ar[11].effect = "Bubbles";
	spell_ar[12].effect = "Bubbles";
	spell_ar[13].effect = "Bubbles";
	spell_ar[14].effect = "Bubbles";
	
	// Before sorting attempt.
	print_ar(spell_ar, length);
	std::cout << std::endl;
	sort_by_pattern(spell_ar, length,"bmfpd");

	print_ar(spell_ar, length);

	delete[] spell_ar;
	return 0;
}
