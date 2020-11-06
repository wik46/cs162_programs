/* **************************************************************************************
 * Filename: Bear.h
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Assignment: Program 3, Zoo Tycoon.
 * Date: November 8, 2020.
 * Description: This is the interface/header file for the Bear class. Plese see 
 * 		Bear.cpp for more information.
 * Input: -
 * Output: -
 * **************************************************************************************/

#ifndef BEAR_H
#define BEAR_H

#include "Animal.h"
#include "Date.h"

#include <iostream>

class Bear: public Animal{
protected:

public:
	// The Bear constructor.
	Bear(const char* where, Date when);

};

#endif
