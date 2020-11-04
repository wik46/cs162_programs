/* **************************************************************************************
 * Filename: Animal.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Assignment: Program 3, Zoo Tycoon.
 * Date: November 8, 2020.
 * Description: This is my probabilty class. It will be used to set the probability
 * 		of animals getting sick when the user decides on different types 
 * 		of food. The idea is that I start with 4 events and a total events of
 * 		4. If the probabilty of the event number that the class was create with
 * 		increase, then the number of total events will increase.
 * 		Since I use an else condition to calculate the probability of the
 * 		certain event, if the total events increase then the probability of that
 * 		event occuring will increase.
 * **************************************************************************************/
#include "Probability.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

/* ***************************************************************************************
 * Function name: get_event().
 * Description: This function will return the event based on the probability of
 * 		each event occuring.
 * Parameters: -
 * Input: -
 * Output: 0,1,2, or 3 based on the event selected.
 * **************************************************************************************/
const int Probability::get_event(){
	int decider = rand() % m_total_events;
	if(decider == m_event1){
		// This is a babies getting born.
		return m_event1;
	}else if(decider == m_event2){
		// This is a boom in attendance.
		return m_event2;
	}else if(decider == m_event3){
		// This is when nothing happens.
		return m_event3;
	}else{
		// As the decider increases because m_total_events increase,
		// the probability of this condition will increase.
		// This is the event specified to change when creating the object.
		return m_event0;
	}
}

/* ***************************************************************************************
 * Function name: increase()
 * Description: m_event0 is the event who's probability will be changed. If this
 * 		function is called. What happens is that the m_total events will increase.
 * 		This will increase the prob of event0 occuring because the event will
 * 		occur if the else statement is true. Increase the number of
 * 		possibilities will therefore increase the chances of selecting the 0th 
 * 		event.
 * Parameters: -
 * Input: -
 * Output: The probability of event0 occuring is increased.
 * **************************************************************************************/
void Probability::increase(){
	// Example: m_total_events = 4, m_prob0 = 1
	// Then 1/4 is the prob of the event occuring.
	// After the function it is 2/5
	// If it is increase again, then 4/7
	// Then 7/10
	m_total_events += m_prob0;
	m_prob0++;
	return;
}

/* ***************************************************************************************
 * Function name: decrease()
 * Description: This will half the probability of event0 if it is
 * 		above 1/4. That it is above the intial probability.
 * Parameters: -
 * Input: -
 * Output: The probability of event0 occuring is halfed.
 * **************************************************************************************/
void Probability::decrease(){
	// This will only decrease the probability if it is greater than 1/4.
	if(m_prob0 > 1){
		m_prob0--;
		m_total_events -= m_prob0;
	}
	return;
}


/* ***************************************************************************************
 * Function name: Probability().
 * Description: This is the constructor. It will intialize the members so that
 * 		the probability of each event occuring is 25%. Afterwards the 
 * 		classes will change the probabilities based on the requirements 
 * 		needed.
 * 		The user can specify the integer representing the event when
 * 		creating the object. The default value is the number next to
 * 		the variable.
 * Parameters: int, int, int ,int.
 * Input: Integers representing the event names.
 * Output: An instance of a Probability class is constructed. 
 * **************************************************************************************/

Probability::Probability(int e_name0, int e_name1, int e_name2, int e_name3)
 :m_prob0{1}, m_prob1{1}, m_prob2{1}, m_prob3{1}, 
 // setting the names of the events.
 m_event0{e_name0}, m_event1{e_name1}, m_event2{e_name2}, m_event3{e_name3}
,	// 1/4 is the probability of an event occuring at the start.
	m_total_events{m_prob0 + m_prob1 + m_prob2 + m_prob3}	
{
	srand(time(NULL));
}




