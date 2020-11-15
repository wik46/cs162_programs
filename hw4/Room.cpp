/* ***************************************************************************************
 * Filename: Room.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Data: November 22, 2020.
 * Description: This is the implementation file for my Room class. The room class will
 * 		represent a single unit inside a grid. That is a Room will be a single
 * 		space where at most one event can live. A Room can also be empry meaning
 * 		that that no Event is currently in the Room.
 * 		1. m_event* : This will be NULL if there is no Event in the Room.
 * 			      If there is an Event in the Room it will point to
 * 			      a Dynamically allocated member of a Room.
 * 			      The constructor will properly clean up the
 * 			      memory allocation.
 * 		======
 * 		2. The Room will have to important member function:
 * 			- insert(): This function will accept an event and insert
 * 				    it in the room. The objects must be dynamically
 * 				    allocated otherwise it will lead to a invalid 
 * 				    free error.
 * 			- remove(): This function will return the Event in the room
 * 				    as well as delete the old event in the room and
 * 				    set m_event* = NULL so that the destructor
 * 				    does not try to free the memory.
 * Input: -
 * Output: -
 * **************************************************************************************/


#include "Event.h"
#include "Room.h"

#include <cassert>
#include <iostream>
	

// Member functions.
// ========================
// Hard Working functions.	
// ========================
/* ***************************************************************************************
 * Function name: display()
 * Description: This function will make use of the event inside the room's display
 * 		function. This room will not display its event if the Event is 
 * 		instantiated in debug mode.
 * Parameters: -
 * Pre-conditions: Only displays the Room's Event if the Event allows it.
 * Post-conditions: -
 * **************************************************************************************/
void Room::display() const {
	// This also makes sure that there is an Event in the Room.
	if(m_event != NULL){
		m_event->display();
	}
	return;
}
/* ***************************************************************************************
 * Function name: insert().
 * Notes: ** You must only insert dynamic memory into the room to avoid invalid free
 * 	     errors cause by the destructor.
 * Description: This function will be used to insert an Event* into an empty room. This 
 * 		function will not allow you to insert an Event* into a Room if there is
 * 		already an Event inside. You will first need to remove() the event before
 * 		inserting a new one.
 * Parameters: Event*
 * Pre-conditions: The function will only insert an Event into the room if it is empty.
 * Post-conditions: A new event is inserted into the Room if it was empty.
 * **************************************************************************************/
// ** NB!!! The Event* must be pointing to dynamic memory.
void Room::insert(Event* e){
	assert(m_event == NULL && "[insert()]: You may only insert Event* into an empty room");
	// Now the m_event pointer is set to the event passed by the function.
	m_event = e; 
	return;
}

/* ***************************************************************************************
 * Function name: remove()
 * Description: This function will remove an Event* out of a room and return it to
 * 		a caller. This will not allow the user to remove an empty event out
 * 		of the room.
 * Parameters: -
 * Pre-conditions: This will makes sure there is memory to free.
 * Post-conditions: If there is memory to free the function will return that
 * 		    memory to the caller and the set this room as empty.
 * **************************************************************************************/
Event* Room::remove(){
	assert(m_event != NULL 
	&& "[remove()]: You cannot remove an event out of an empty room.");
	// Make sure that there is something to remove.
	// I want to set m_event = NULL but I also need to return the memory
	Event* tmp = this->m_event;
	// No I can set m_event to NULL so that the caller is responsible for
	// cleaning up the memory used by the event.
	this->m_event = NULL;
	return tmp;
}
	
// =====================
// Overloaded operators.
// =====================
/* ***************************************************************************************
 * Function name: operator<<()
 * Description: This is the overloaded '<<' opertator. It will output the contents
 * 		of the Room to the console. If there is nothing in the room it
 * 		will output an empty space.
 * Parameters: std::ostream&, const Room&
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
std::ostream& operator<<(std::ostream& stream_out, const Room& room){
	// This will output what is in the room. That is the event.
	// This will output nothing if there is nothing in the room.
	if(room.m_event != NULL){
		stream_out << *room.m_event; 
	}else{
		stream_out << ' ';
	}
	return stream_out;
} 
// ==============
// Constructors.
// ==============
/* ***************************************************************************************
 * Function name: Room()
 * Description: The default constructor. This function will defualt to NULL initialzation
 * 		of m_event. 
 * 		** NB!! ** You may only intantiate the class with a dynamic member Event.
 * 		The destructor will try to free the member and if it is allocated on the
 * 		stack it will cause an invalid free by the compiler.
 * Parameters: Event* : Must be dynamically allocated.
 * Pre-conditions: The Event* must be dynamically allocated.
 * Post-conditions: Create an objects a the Room class.
 * **************************************************************************************/
// The default consrtuctor.
Room::Room(Event* e): m_event(e)
{}
// ==============
// The big three.
// ==============
// 1. Destructor.
/* ***************************************************************************************
 * Function name: ~Room()
 * Description: This is the Room class destructor. It will free the one member variable
 * 		of the class that points to dynamic memory, m_event. This member points
 * 		to an Event*.
 * Parameter: -
 * Pre-condtions: Assumes that the memory that m_event is pointing to is on the heap.
 * Post-conditions: Free's dynamic memory if it was allocated.
 * **************************************************************************************/
Room::~Room(){
	// NB!! Make sure you are instantiating the class with dynamic memory.
	if(m_event != NULL){
		delete m_event;
	}
}
