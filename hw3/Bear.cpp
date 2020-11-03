/* **************************************************************************************
 * Filename: Bear.cpp
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


