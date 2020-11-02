/* **************************************************************************************
 * Filename: Probability.h
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Assignment: Program 3, Zoo Tycoon.
 * Date: November 8, 2020.
 * Description: See Probability.cpp for further details.
 * **************************************************************************************/


#ifndef PROBABILITY_H
#define PROBABILITY_H
#include <cstdlib>
#include <iostream>
#include <ctime>
class Probability{
	// These members will represent the event number. 
	// There value does not represent the event number.
	// There value is used to help calculate the probability of the event
	// occcuring.
	int m_prob0;
	int m_prob1;
	int m_prob2;
	int m_prob3;
	// These fields represent the event number.
	const int m_event0{0};
	const int m_event1{1};
	const int m_event2{2};
	const int m_event3{3};
	// This member represent the size of the sample space.
	int m_total_events;
public:	
	// This function will return the event that occured.
	// It uses a random number generator.
	const int get_event();
	// This function will double the probability of an event occuring.
	// Pass in the event that you want to increase.
	void increase();
	// This function will decrease the probability by half if m_probx > 1.
	void decrease();
	// The constructor will create the probability object where each
	// event starts with a 25% of occuring.
	Probability(int e0 = 0, int e1 = 1, int e2 = 2, int e3 = 3);

};

#endif
