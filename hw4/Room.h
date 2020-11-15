/* ***************************************************************************************
 * Filename: Room.h
 * Author: Lodewyk Jansen van Rensburg.
 * Data: November 22, 2020.
 * Description: This is the header/interface file for the Room class. See Room.cpp
 * 		for any further descriptions.
 * Input: -
 * Output: -
 * **************************************************************************************/

#ifndef ROOM_H
#define ROOM_H

#include "Event.h"
#include <cassert>
#include <iostream>
class Room{
public:	// Member variables.
	// This will store a child of the Event class or be empty.
	Event* m_event;
public:	
	// Member functions.
	// ========================
	// Hard Working functions.	
	// ========================
	// 1. This will use the display symbol from Event. If the event is not
	//    intantiated in debug_mode then the stream will output nothing.
	void display() const ;	
	// 2. This function will accept a dynamically allocated child of Event*.
	//    It will assert that there is nothing currently stored in the Room.
	//    ** NB!! Make sure you insert dynamic memory. **
	void insert(Event*);
	// 3. This function removes the event and returns it to the console.
	//    It will assert that you are not trying to remove a NULL pointer.
	//    It will return a NULL pointer if there is nothing to remove.
	//    It will not free the memory but it will return it to the caller.
	//    It will set m_event = NULL so that the caller is responsible of
	//    freeing the memory.
	Event* remove();
	

	// =====================
	// Overloaded operators.
	// =====================
	// This will use the display symbol from Event. If the event is not
	// intantiated in debug_mode then the stream will output nothing.
	friend std::ostream& operator<<(std::ostream&, const Room&); 
	// ==============
	// Constructors.
	// ==============
	// The default consrtuctor.
	Room(Event* = NULL);
	// ==============
	// The big three.
	// ==============
	// 1. Destructor.
	~Room();
};

#endif 
