/* ***************************************************************************************
 * Filename: Node.hpp
 * Author: Lodewyk Jansen van Resnburg.
 * Student ID: 934 309 717
 * Date: December 6, 2020
 * Homework 5: Linked List
 * Description: The class defined in this file will represent a node in my list.
 * 		A node will contain two member namely the value stored at the node
 * 		and a pointer to the next node in the list. If this pointer = NULL
 * 		then the node is the last one in the list.
 * **************************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>

template <class T>
class Node{
public:
	// Member 1:This memmber stores the data in the container.
	T val;
	// Member 2: This member is the only way to get access to the next element in the
	// 		list. If it is NULL then the current node is the last node in the 
	// 		list
	Node* next;
	// Constructor.
	Node(T data): val{data}, next{NULL}
	{}
	
};	
// =======================================================================================
// Non-member functions:
// =======================================================================================

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Overloaded operators:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/* ***************************************************************************************
 * Function name: operator<=()
 * Description: This function is used so that I can compare two Nodes based
 * 		on the underlying value of the node.
 * Parameters: const Node&, const Node&.
 * Pre-conditions: Takes in two nodes an does uses the comparison operator on
 * 		   the underlying data. (for program 5 it is integers.)
 * **************************************************************************************/
template <class T>
bool operator<=(const Node<T>& n1, const Node<T>& n2){
	// the '<=' operator is defined on integers.
	return (n1.val <= n2.val);
}
/* ***************************************************************************************
 * Function name: operator>=()
 * Description: This function is used so that I can compare two Nodes based
 * 		on the underlying value of the node.
 * Parameters: const Node&, const Node&.
 * Pre-conditions: Takes in two nodes an does uses the comparison operator on
 * 		   the underlying data. (for program 5 it is integers.)
 * **************************************************************************************/
template <class T>
bool operator>=(const Node<T>& n1, const Node<T>& n2){
	// the '>=' operator is defined on integers.
	return (n1.val >= n2.val);
}
#endif
