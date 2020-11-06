/* **************************************************************************************
 * Filename: Tiger.h
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Assignment: Program 3, Zoo Tycoon.
 * Date: November 8, 2020.
 * Description: This is the interface/header file for the Tiger class. Please see 
 * 		Tiger.cpp for more information.
 * Input: -
 * Output: -
 * **************************************************************************************/

#ifndef TIGER_H
#define TIGER_H

#include "Animal.h"
#include "Date.h"
#include <iostream>

class Tiger: public Animal{
protected:

public:
	// The constructor.
	Tiger(const char* where, Date when);
	

};
#endif
