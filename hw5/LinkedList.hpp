/* ***************************************************************************************
 * Filename: LinkedList.hpp
 * Author: Lodewyk Jansen van Resnburg.
 * Student ID: 934 309 717
 * Date: December 6, 2020
 * Homework 5: Linked List
 * Description: This file is the header and the impementation file for my linked list
 * 		data structure.
 * 		** Note: This list is indexed from [0 - n-1]. ** 
 * 		Methods available for use:
 * 			a. int get_length()	
 * 				- returns the length of the list.
 * 			b. void print()
 * 				- Outputs all the integers inside the list
 * 			c. void clear() 
 * 				- Remove the entire list. Free's all memory used
 * 				by the list.
 * 			d. unsigned int push_front( T )
 * 				- Adds an node to the front of the list and returns the
 * 				new length of the list.
 * 			e. unsigned int push_back( T )
 * 				- Adds a node to the back of the list and returns the 
 * 				new length of the list.
 * 			f. unsigned int insert( T, int)
 * 				- Inserts a new node with value T at the index of the 
 * 				node specified.
 * **************************************************************************************/

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>
template <class T>
class LinkedList{
public:
	// Member 1:
	unsigned int m_length;
	// Member 2: Pointer to the first node in the list.
	Node<T>* m_head;
public:
	// ============================================================
	// Information functions:
	// ============================================================
	// 2.
	void print();
	
	// ============================================================
	// List change functions:
	// ============================================================
	// 1. Inserts data at the front of list and return new length.
	unsigned int push_front(T val);
	// 2. Inserts data at the end of the list and returns new length.
	unsigned int push_back(T val);
	// 3. This clears all the memory used by the list.
	void clear();
	// 4. This inserts a new node at the index specified. '[0:n-1]'
	unsigned int insert(T, unsigned int);
	
	// ============================================================
	// Sorting functions functions:
	// ============================================================
	// 1.1 Merge sort algorithm in ascending order.
	void merge_sort_ascending();
	// 1.2 Merge sort algorithm in descending order.
	void merge_sort_descending();
	// 2.1 Selection sort algorithm in ascending order.
	void selection_sort_ascending();
	// 2.2 Selection sort algorithm in descending order.
	void selection_sort_descending();
	
	// ============================================================
	// Constructors:
	// ============================================================
	// 1. Default constructor creates an empty list, head = NULL.
	LinkedList();
	// ============================================================
	// The Big Three:
	// ============================================================
	// 1. Destructor.
	~LinkedList();
	// 2. Assignment operator overload.
	// 3. Copy Constructor.
};	
// 1.
template <typename T>
void merge_sort(Node<T>**, bool (*f)(Node<T>*, Node<T>*));
// 2.
template <typename T>
Node<T>* merge_list(Node<T>* , Node<T>* , bool (*f)(Node<T>*, Node<T>*));
// 3.
template <class T>
void split(Node<T>*, Node<T>**, Node<T>**);
// 4.
template <typename T>
bool ascending(Node<T>*, Node<T>*);
// 5.
template <typename T>
bool descending(Node<T>*, Node<T>*);
// 6.
template <class T>
void swap(Node<T>** , Node<T>*);
// 7.
template <class T>
void selection_sort(Node<T>**, bool (*f)(Node<T>* , Node<T>*));
// 8.
template <typename T>
Node<T>* selection_sort(Node<T>*, bool (*f)(Node<T>*, Node<T>*));

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	
// Information functions:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	
/* ***************************************************************************************
 * Function name: get_length()
 * **************************************************************************************/

/* ***************************************************************************************
 * Function name: print()
 * Description: This function prints out the contents of the linked list.
 * 		It will print out a notification if the was called on an emtpy list.
 * **************************************************************************************/
template <class T>
void LinkedList<T>::print(){
	// Case 1: empty list.
	if(m_head == NULL){
		std::cout << "\n** [print() called on and empty list.] **\n"<< std::endl;
	}
	// Case 2: The list is non-empty.
	Node<T>* tmp = m_head;
	int i = 1;
	// If this condition is true means that I reached the end of the list.
	while(tmp != NULL){
		// Note that the data stored inside the list needs to have a definition
		// 	for the '<<' operator.	
		std::cout << i << ".) " << tmp->val << std::endl;
		// Walking to the next element in the list.
		tmp = tmp->next;
		i++;
	
	}
	return;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	
// List change functions:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	
/* ***************************************************************************************
 * Function name: push_front()
 * Description: This function adds a node to the front of the list.
 * 		It returns the new length of the list after the node has been added.
 * Parameters: T - The data stored inside the node.
 * Pre-conditions: This function only inserts a node at the front of the list.
 * Post-conditions: All the data created by the function is dynamically allocated.
 * **************************************************************************************/
template <class T>
unsigned int LinkedList<T>::push_front(T val){
	// Creating a temporary storage.
	Node<T>* tmp = new Node<T>(val); // A node has a contructor to store data.
	// The new element points to the old head of the list.
	tmp->next = m_head;
	// The head no points to the new element of the list.
	m_head = tmp;
	// Incrementing the length of the list.
	m_length++;
	return m_length;
}	

/* ***************************************************************************************
 * Function name: push_back()
 * Description: This function will insert an element at the end of the list.
 * Parameters: The data that needs to be contained inside the new node at the end of
 * 		the list.
 * Pre-conditions: -
 * Post-conditions: The function inserts a new node containing the data specified by 
 * 		    the user at the end of the list, increments the size of the list
 * 		    , and returns the new size of the list.	
 * **************************************************************************************/
template <class T>
unsigned int LinkedList<T>::push_back(T val){
	// Case 1: Inserting into an empty list.
	if(m_head == NULL){
		// push_front will increment the length of the list.
		push_front(val);
	}else{
	// Case 2: tail insertion.
		// This variable will be used to traverse though teh end of the list.
		Node<T>* walker = m_head;
		// Walking to the end of the list.
		while(walker->next != NULL){
			walker = walker->next;
		}
		// Creating a temporary variable to create a new node.
		Node<T>* tmp = new Node<T>(val);
		// walker is currently the end of the list.
		tmp->next = walker->next;
		// Now the new node is at the end and walker needs to connect the last
		// 	node to the list.
		walker->next = tmp;
		// Increasing the length of the list to the appropriate number of nodes.
		m_length++;
	}	
	return m_length;
}
/* ***************************************************************************************
 * Function name: clear()
 * Description: This function frees all the memory of the list and should be used inside 
 * 		the denstructor as well.
 * 		It creates two temporary variables to assist with the freeing of memory.
 * 		** Note: It is very important to set the m_head to Null after all the 
 * 			 nodes are freed. Otherwise a lot of the functions will use the 
 * 			 freed memory without realizing that the list is empty.
 * Parameters: -
 * Pre-conditions: Free's all the memory used by the linked list.
 * Post-conditions: All the memory is freed as well as the head of the list is set 
 * 		    to NULL.	
 * **************************************************************************************/
template <class T>
void LinkedList<T>::clear(){
	// If the list is non-empty.
	if(m_head != NULL){
		Node<T>* tmp = m_head;
		Node<T>* prev = m_head;
		// Continue to free memory untill the end is reached.
		while(tmp != NULL){
			// NB! This order of operations is very important.
			tmp = tmp->next;
			delete prev;
			
			prev = tmp;
		}
		// Set the length to zero.
		m_length = 0;
		// Remember to set the head of the array to NULL so that
		// 	you know the list is empty.
		m_head = NULL;
	}
	return;
}
/* ***************************************************************************************
 * Function name: insert()
 * Description: This function will insert a node into the list at the specified index.
 * 		Index - 0: First node in the list.
 * 		Index - n-1: Last node in the list. (n is the length of the list)
 * 		Error checking: Throws a invalid insertion error if the user wants
 * 				to insert a node outside of the list index range.
 * 		Case 1: The user wants to insert a node at the head		
 * 			- push_front() is used.
 * 		Case 2: The user want to insert a node at the tail.
 * 			- push_back() is used.  
 * 		Case 3: The user inserts a node at the index [1:n-2]
 *			- definition lives in the body of this function.
 * Parameters: T value "data that is stored inside the node", int index.
 * Pre-conditions: The function ensures that the user inserts a node inside the node 
 * 			index range.
 * Post-conditions: A new node is inserted at the index that the user specified and the
 * 		    length of the list is increased.
 * **************************************************************************************/
template <class T>
unsigned int LinkedList<T>::insert(T val, unsigned int index){
	// Error checking: 
	if(index < 0 || index > m_length - 1){ // index of list [ 0 : m_length - 1 ]
		std::cerr << "[insert()]: inserting data at an index out of range." << std::endl;
		std::exception a;
		throw a;
	}
	// Case 1: Head insertion.
	if(index == 0 || m_head == NULL){ // Inserting into an empty list can only be head insert.
		push_front(val);
	// Case 2: Tail insertion.
	}else if(index == m_length - 1){
		push_back(val);
	// Case 3: [ 1: m_length - 2 ]
	}else{
		// Part 1: Walking to the correct node. 
		Node<T>* tmp = m_head->next;
		Node<T>* prev = m_head; // m_head is non-NULL.
		for(int i = 1; i < index; i++){
			// Setting the prev to the current node.
			prev = tmp;
			// Walking to the next node.
			tmp = tmp->next;
		}
		// Part 2: Inserting the new node.
		prev->next = new Node<T>( val );
		(prev->next)->next = tmp;
		// Part 3: Increasing the length of the list.
		m_length++;
	}
	return m_length;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	
// Sorting functions functions:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	
// 1.1 Merge sort algorithm in ascending order.
/* ***************************************************************************************
 * Function name: merge_sort_ascend()
 * Description: This function sorts the list in descending order using the merge
 * 		sort divide and conquer algorithm.
 * Information: See implementation of merge_sort() defined at line 460*
 * **************************************************************************************/
template <class T>
void LinkedList<T>::merge_sort_ascending(){
	merge_sort(&m_head, ascending);
	return;
}
// 1.2 Merge sort algorithm in descending order.
/* ***************************************************************************************
 * Function name: merge_sort_descending()
 * Description: This function sorts the list in descending order using the merge
 * 		sort divide and conquer algorithm.
 * Information: See implementation of merge_sort() defined at line 460*
 * **************************************************************************************/
template <class T>
void LinkedList<T>::merge_sort_descending(){
	merge_sort(&m_head, descending);
	return;
}
// 2.1 Selection sort algorithm in ascending order.
/* ***************************************************************************************
 * Function name: selection_sort_ascending()
 * Description: This function sorts the list in descending order using the selection
 * 		sort algorithm.
 * Information: See implementation of selection_sort() defined at lines below.
 * **************************************************************************************/
template <class T>
void LinkedList<T>::selection_sort_ascending(){
	selection_sort(&m_head, ascending);
	return;
}
// 2.2 Merge sort algorithm in descending order.
/* ***************************************************************************************
 * Function name: selection_sort_descending()
 * Description: This function sorts the list in descending order using the selection
 * 		sort algorithm.
 * Information: See implementation of selection_sort() defined below.
 * **************************************************************************************/
template <class T>
void LinkedList<T>::selection_sort_descending(){
	selection_sort(&m_head, descending);
	return;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	
// Constructors:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	
/* ***************************************************************************************
 * Function name: LinkedList()
 * Description: This function creates an empty list. The head = NULL and the size
 * 		of the list is 0.
 * Parameters: -
 * Pre-conditions: Only specify the data type that you want used for the list.
 * Post-condtinos: Memory is set asside to use a linked list.
 * **************************************************************************************/
template <class T>
LinkedList<T>::LinkedList(): m_length{0}, m_head{NULL}
{
	std::cout << "[default LinkedList constructed]"<< std::endl;
} 

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	
// The Big Three:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	
// 1. Destructor.
/* ***************************************************************************************
 * Function name: ~LinkedList()
 * Description: This free's all the memory used by the program. It makes used of the 
 * 		clean function defined above. More more information look under
 * 		the 'List change functions' category.
 * Parameters: -
 * Pre-conditions: This function makes sure that the list is non-empty before trying
 * 		   to free the memory.
 * Post-conditions: All the memory is freed and the head of the list points to NULL
 * 		    to indicate that the list is empty.
 * **************************************************************************************/	
template <class T>
LinkedList<T>::~LinkedList(){
	this->clear();
	// Temporary.
	std::cout << "[~LinkedList() called]"<< std::endl;
}



// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	
// Non-member functions:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	

// Recursive Merge Sort for Linked Lists. 
/* ***************************************************************************************
 * Function name: split()
 * Description: This function function takes in a head of the list and two empty
 * 		heads for the new list. Then it searches for the middle of the list
 * 		and assigns the right head to middle->next. It also breaks the link
 * 		between the two nodes.
 * 		** Assumes that the original head has at least two nodes.
 * Parameters: Node* , Node*, Node*.
 * Pre-conditions: Assumes that the left list and the right list is already sorted.
 * Post-conditions: Combines the two sorted lists into one large list.
 * **************************************************************************************/
template <class T>
void split(Node<T>* head, Node<T>** l, Node<T>** r){
	// Think of the l and r node references as the heads of the two new list.
	// Steps to take:
	// --------------
	// Part 1: find the middle node.
	// Part 2: Assign the l node to the start of the list and assign the 
	// 		r node to middle->next.
	// Part 3: Break the link between the list to seperate them. 
	*l = head; // Assigning the head of the list to the left list.
	// These two nodes will traversse through the list.
	Node<T>* one_step = head;
	Node<T>* two_step = head->next;
	// Now for every step that one_step takes, two_step wil take two steps if possible.
	while(two_step != NULL){
		two_step = two_step->next;
		// If the two step is not on the tail it will take another step.
		// This is necesarry to make sure that the two step does not jump over the tail.
		if(two_step != NULL){
			one_step = one_step->next;
			two_step = two_step->next;
		}
	}
	// Now our left list already has a head of the original list.
	// We no need to set the right list's head to the middel->next (one_step->next)
	*r = one_step->next;
	// Now we break the list into 2.
	one_step->next = NULL;
	// Now l is the list from the original list with the tail as the middle node.
	// Now r is the list from the middle + 1 node to the original tail of the list.
}


/* ***************************************************************************************
 * Function name: merge_list()
 * Description: This function is implemented recuresively. It has two base cases:
 * 		Base case 1: If the left list is empty it returns the only node, the 
 * 		right list head. Base case 2: If the right list is empty is returns 
 * 		the only node, the left list head. I the base cases are not satisfied 
 * 		then the program continues to compare the first two node's in the list. 
 * 		The node with the least value (in the ascending case) will
 * 		be added to the new list. The function will be called agaign, but without 
 * 		includinig the
 * 		already added node.
 * Parameters: Node<T>*, Node<T>*
 * Pre-conditions: The function assumes that the two list that we received the head 
 * 			from are already sorted.
 * Post-conditions: The function returns the head of the combined sorted list.
 * **************************************************************************************/	
template <typename T>
Node<T>* merge_list(Node<T>* l, Node<T>* r, bool (*f)(Node<T>*, Node<T>*)){
	// The creates the head that will store the head for the new node.
	Node<T>* new_list = NULL;
	// Base case1: If the left node is null then we can assume that the only
	// 		node to merge is the right list.
	if(l == NULL){
		return r;
	// Base case 2:
	}else if(r == NULL){
		return l;
	}
	// If the base cases was not called then we know both lists l and r has at least 
	// node.
	// ** Remember that your data type in the node needs to have an 
	// 	overloaded <= operator** 
	if((f(l, r)) ){ // f will be a function that decides ascending/descending order.
		// Add the first element in list l to the new list.
		new_list = l;
		// Perform the same operation for the rest of the list, excluding the 
		// 	element in l.
		new_list->next = merge_list(l->next, r, f);
	}else{
		// Add the first node in the right list to the new list
		// 	and perform the function again.
		new_list = r;	
		// Search through the rest of the lists, excluding the node that was just 
		// added to the list.
		new_list->next = merge_list(l, r->next, f);
	}
	// This is the head of the newly linked list.
	return new_list;
}


/* **************************************************************************************
 * Function name: ascending()
 * Description: This function will be used to pass into merge sort to determine the order
 * 		of sorting that the function should implement.
 * Parameters: Node<T>*, Node<T>*
 * Pre-conditions: The data stored inside the node needs to have a definition for
 * 			'<='
 * Post-condition: Sorts the list in ascending order.
 * **************************************************************************************/
template <typename T>
bool ascending(Node<T>* a, Node<T>* b){
	return *a <= *b;
}
/* **************************************************************************************
 * Function name: descending()
 * Description: This function will be used to pass into merge sort to determine the order
 * 		of sorting that the function should implement.
 * Parameters: Node<T>*, Node<T>*
 * Pre-conditions: The data stored inside the node needs to have a definition for
 * 			'>='
 * Post-condition: Sorts the list in decending order.
 * **************************************************************************************/
template <typename T>
bool descending(Node<T>* a, Node<T>* b){
	return *a >= *b;
}

/* ***************************************************************************************
 * Function name: merge_sort()
 * Description: This function accepts the address of a list's head pointer so that
 * 		it can change the value of the head of the list.
 * 		It takes in the head of the list and reconnets the nodes
 * 		in the list so that they are sorted. It is a recursively implemented
 * 		version of merge sort for linked lists.
 * Parameters: Node<T>**
 * Pre-conditions: This function defines a list with a single element or no element as
 * 			sorted.
 * Post-conditions: The function reconnects the nodes so that they are sorted.
 * **************************************************************************************/
template <typename T>
void merge_sort(Node<T>** head_ad, bool (*f)(Node<T>*, Node<T>*)){
	// A empty list or a list with one node is by definition sorted.
	if((*head_ad) == NULL ||(*head_ad)->next == NULL){
		return;
	}
	// Part 1: create temporary heads to store the splitted lists.
	Node<T>* l;
	Node<T>* r;
	Node<T>* head = *head_ad;
	// Now we split the list in half and break the link between the two halves.
	// l will contain all the nodes from head to middle, and r will start from
	// middle + 1 to tail.
	// This function will continue to seperate the lists untill they only have one or
	// no nodes. There after it will start climbing up the stack.
	split(head, &l, &r);
	// Now we sort the two seperated lists.
	// Remember to add a function to determine descending or ascending order.
	merge_sort(&l, f);
	merge_sort(&r, f);
	// 3. This function takes the two sorted list's and combines them into a single
	// 	sorted list and returns the head of the list.
	// We store the newly sorted list at the address of the previous list.
	*head_ad = merge_list(l, r, f);
	return;
}

// Recursive Selection Sort for Linked Lists. 

/* ***************************************************************************************
 * Function name: swap()
 * Description: This function takes in two nodes and the head of the list. It swaps the
 * 		position of the nodes and not the data values of the nodes.
 * Paremeters: Node**, Node*, Node*
 * Pre-conditions: This function assumes that the current value is not the head of the 
 * 		   list.
 * Post-condition: -
 * **************************************************************************************/
// This function swaps the node provided with the head of the list node.
template <class T>
void swap(Node<T>** head, Node<T>* min_max){
	// Setting the new head as min_max.
	Node<T>* old_head= *head;
	// This function assumes that there is at least two nodes in the list.
	Node<T>* prev = *head;
	// Traversing to the element before min_max.
	while(prev->next != min_max){
		prev = prev->next;
	}
	// Setting the link where min_max is removed.
	prev->next = min_max->next;
	min_max->next = old_head;
	// The new head.
	(*head) = min_max;
	
	// The previous head.
	return;

}


/* ***************************************************************************************
 * Function name: selection_sort()
 * Description: This function will sort a linked list base on the function passed as
 * 		the second argument for the function.
 * 		It uses a selection sort algirithm.
 * Parameters: Node<T>** , bool (*f)(Node<T>, Node<T>)
 * Pre-conditions: -
 * Post-conditions: Returns the sorted linked list.
 * **************************************************************************************/
template <typename T>
Node<T>* selection_sort(Node<T>* head, bool (*f)(Node<T>*, Node<T>*))
{
	// Thes case for a single node in a list.
	// Base case.
	if(head->next == NULL){
		return head;
	}
	// Searching for the minimum value
	Node<T>* min_max = head;
	// This is how to traverse through a linked list.
	Node<T>* walker = head;


	while(walker->next != NULL){
		// The function passed in as argument will determine the order of sorting.
		if( f(walker->next, min_max) ){
			min_max = walker->next;
		}		
		// Walking to the new node.
		walker = walker->next;
		//std::cout << walker->val << std::endl;	
	}
	// There is no need to swap any node if the first node was the one we wanted.
	if(min_max != head){
		swap(&head, min_max);
	}	
	// Now we do the same but for the rest of th list.
	head->next = selection_sort(head->next, f);

	// Lastly we return the sorted list.
	return head;
}


/* ***************************************************************************************
 * Function name: selection_sort()
 * Description: This function uses  a recursive selction sort algorithm to
 * 		sort the nodes in a list. The type of sorting is base on the algorithm
 * 		passed as the second argument of the function. 
 * Parameters: Node<T>**, bool(*f)(Node<T>*, Node<T>*)
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
template <class T>
void selection_sort(Node<T>** head, bool (*f)(Node<T>* , Node<T>*)){
	// There is no point in sorting an empty list or a list with one node.
	if( (*head) == NULL || (*head)->next == NULL){
		return;
	}
	// For a list of two or more nodes.
	*head = selection_sort(*head, f);
	
}
#endif
