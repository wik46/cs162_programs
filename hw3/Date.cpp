/* **************************************************************************************
 * Filename: driver.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Assignment: Program 3, Zoo Tycoon.
 * Date: November 8, 2020.
 * **************************************************************************************/

#include "Date.h"
#include <iostream>


// Default constructor.
Date::Date(): m_month{1}, m_day{1}, m_year{2001}
{
	create_month_names();	
}

// Parameterized constructor.
Date::Date(int month, int day, int year): m_month{month}, m_day{day}, m_year{year}
{
	create_month_names();	
}

/* ***************************************************************************************
 * Function name: add_month()
 * Description: This function will be used to add one month to the date object. 
 * 		If it reaches December - represented by 11 in the array - it will
 * 		revert the month to January - represented by 0 - and
 * 		add one the the year.
 * Parameters: -
 * Input: - 
 * Output: The month of the object is added.
 * **************************************************************************************/
void Date::add_month(){
	// December is the 11th index in the string array of month names.
	if(m_month < 11){
		m_month++;
	}else{
		// This will change the date to Jan of the next year.
		// When I want to index Jan in the string array remeber to -1.
		m_month = 1;
		m_year++;
	}
}

// This function prints the date of the object in the format "mm/dd/yyyy"
void Date::print_fnumeric() const{
	std::cout << m_month << "/"
	<< m_day << "/"
	<< m_year ;
	return;
}

// This function will print out the month as a string.
void Date::print_fstr() const{
	std::cout << m_month_names[m_month - 1]
	<< " " << m_day << ", " << m_year << std::endl;;
	return;
}

/* **************************************************************************************
 * Function name: operator<<().
 * Description: This is the overloaded '<<' operator that will ouput an instance
 * 		of Date.
 * Parameters: ostream&, const Date&.
 * Input: A ostream object and an instance of an Date.
 * Output: The neccesary output is displayed to the user.
 * **************************************************************************************/
std::ostream& operator<<(std::ostream& stream_out, const Date& d){
	// Format: dd/mmm/yyyy
	stream_out << d.m_month_names[d.m_month - 1]
	<< ", " << d.m_day << ", " << d.m_year ;
	return stream_out;
}

// This function creates the list of month names.
void Date::create_month_names()
{
	m_month_names[0] = "January";
	m_month_names[1] = "February";
	m_month_names[2] = "March";
	m_month_names[3] = "April";
	m_month_names[4] = "May";
	m_month_names[5] = "June";
	m_month_names[6] = "July";
	m_month_names[7] = "August";
	m_month_names[8] = "September";
	m_month_names[9] = "October";
	m_month_names[10] = "Novemeber";
	m_month_names[11] = "December";
	return;
}
