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
protected:

public:
	// The Sea_lion constructor.
	Sea_lion(const char* where, Date when);

};

#endif
