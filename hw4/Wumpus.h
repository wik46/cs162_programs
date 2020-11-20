/* ***************************************************************************************
 * Filename: Wumput.h
 * Author: Lodewyk Jansen van Rensburg.
 * Data: November 22, 2020.
 * Symbol: 'w'
 * Description: This is the header/interface file for the Wumpy class. See Wumpus.cpp
 * 		for any further descriptions.
 * Input: -
 * Output: -
 * **************************************************************************************/

#ifndef WUMPUS_H
#define WUMPUS_H

#include "Event.h"
#include <iostream>
class Wumpus: public Event{
	// All these members are defined as the Parent portion.
/*
	// Member variables.
	// 1. The sound that the event makes when the player is in the adjacent room.
	std::string m_sound;
	// 2. If true the event will get printed when the grid is displayed. Else
	// it won't get printed.
	bool m_debug_mode;
	// 3. This is the symbol that represent the Event in the room.
	// The default is a.
	char m_symbol;
public:	

	// Member functions.
	// ========================
	// Hard Working functions.	
	// ========================
	// 1. This function displays the user's symbol inside the room if
	//    m_debug_mode = false.
	void display() const;
	// 2. This function will display the sound of the event in the room.
	void make_sound() const;
	// 3. This function will perform an action on the player.
	//virtual void action() = 0;
	// =====================
	// Overloaded operators.
	// =====================
	// This displays the symbol of the Event.
	friend std::ostream& operator<<(std::ostream&, const Event&); 
	// ==============
	// Getters.
	// ==============
	// 1.
	std::string get_sound(){return m_sound;}
	// 2. 
	bool get_debug_mode(){return m_debug_mode;}
	// 3.
	char get_symbol(){return m_symbol;}
	
*/
public:
	// ==============
	// Constructors.
	// ==============
	// The default consrtuctor.
	// 	- default = false => symbol will not get printed on the Grid.
	Wumpus(bool _default = false);
	// ==============
	// The big three.
	// ==============
	// 1. Destructor.
	~Wumpus() = default;
};

#endif 
