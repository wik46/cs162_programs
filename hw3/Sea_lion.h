/* **************************************************************************************
 * Filename: Sea_lion.h
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Assignment: Program 3, Zoo Tycoon.
 * Date: November 8, 2020.
 * Description: This is the interface/header file for the Sea_lion class. Please see 
 * 		Sea_lion.cpp for more information.
 * Input: -
 * Output: -
 * **************************************************************************************/

#ifndef SEA_LION_H
#define SEA_LION_H

#include "Animal.h"
#include "Date.h"
#include <iostream>

class Sea_lion: public Animal{
private:
	static int m_total;
	// This variable will start of as 0.
	// If there was a boom in attendance then it will store the total boom.
	// After income was gathered, it will be set to 0.	
	static int m_boom_total;
public:
	// This will return a reference to the boom_total.
	int& get_boom_total(); 
	// This function will return the boom total for a month.
	int calc_boom_total()override;
	// The Sea_lion constructor.
	Sea_lion(const char* where, Date when);
	// The Sea_lion destructor.
	~Sea_lion();
};

#endif
