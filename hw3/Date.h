/* **************************************************************************************
 * Filename: Date.h
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Assignment: Program 3, Zoo Tycoon.
 * Date: November 8, 2020.
 * **************************************************************************************/

#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date{
	int m_month;
	int m_day;
	int m_year;
	std::string m_month_names[12];
public:
	// Default constructor.
	Date();
	// Parameterized contructor.
	Date(int, int, int);
	// This function will add the date by a month.
	void add_month();
	// Print format 1.
	void print_fnumeric() const;
	// Print format 2.
	void print_fstr() const;
	// The overloaded << operator.
	friend std::ostream& operator<<(std::ostream&, const Date&);
private:
	// Create the month names.
	void create_month_names();
};

#endif
