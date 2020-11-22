/* ***************************************************************************************
 * Filename: Room.h
 * Author: Lodewyk Jansen van Rensburg.
 * Data: November 22, 2020.
 * Description: This is the header/interface file for the Room class. See Room.cpp
 * 		for any further descriptions.
 * Input: -
 * Output: -
 * **************************************************************************************/
//
//
//  REMEMBER THA RANDOM FUNCTION THAT CAN SHUFFLE A VECTOR.
//
//
#ifndef ROOM_H
#define ROOM_H

#include "Event.h"
#include <cassert>
#include <iostream>
class Room{
	// Member variables.
	// This will store a child of the Event class or be empty.
	Event* m_event;
public:	
	Event* get_event(){return m_event;}
	bool is_empty(){
		if(m_event == NULL){
			return true;
		}else{
			return false;
		}
	}
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
	Room(Event* e = NULL);
	// ==============
	// The big three.
	// ==============
	// 1. Destructor.
	~Room();
};
// Used alongside std::find to find the wumpus or gold at the end of the game
// 	so that they can be replaced if necesssary.
//bool IsWump(const Room& r);
//bool IsGold(const Room& r);

#endif 
