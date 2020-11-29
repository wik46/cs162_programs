==========================================================================================
Author: Lodewyk Jansen van Rensburg
Student ID: 934 309 717
Course: CS162
Date: Decemeber 4, 2020
Assignment: Program 5, linked list.
==========================================================================================


==========================================================================================
Table of contents:
==========================================================================================

1. Files needed.
2. Description of main.
3. Where to find the sorting algorithms.
4. Description of extra credit.
5. Final remarks of CS 162.

==========================================================================================

==========================================================================================
1. Files.
==========================================================================================

Node.hpp, LinkedList.hpp, Function.cpp, Functions.h, main.cpp
** Makefile.

==========================================================================================
2. Description of main.
==========================================================================================

The user will see the linked list printed after every input that is received.
There are six different ways in which the user can manipulate the data.
	1. The user can add any number to the front of the list by selecting '1'
	2. The user can add any number to the back of the list by selecting '2',
	3. The user can enter the number of random numbers to append to the 		
		back of the linked list. This will store random number [0,99] 
		in the lists.
	4. The user can select to sort the linked list.
		After the selection the user must decide between the 4 available 
		sorting method.
	5. The user clear all the data inside the linked list.
	6. The user exits the program. After selecting '6', the user will be prompted
	   to enter 'exit' if they are certain that they want to leave the program.

==========================================================================================
3. Where to find the sorting algorithms.
==========================================================================================
	
All the sorting algorithms are defined at the bottom of LinkedList.hpp.
They are emplemented as normal functions that accept the address of the head of list
and sorts the list. 

These functions are used inside member functions of the LinkedList class to modularize
the code. Then lastly all of the function are bundled together inside sort_method()
so that only one line of code inside main is needed.

==========================================================================================
4. Description of extra credit.
==========================================================================================

	- There are 4 ways to sort the linked list namely:
		* Merge sort ascending,
		* Merge sort descending,
		* Selection sort ascending, and
		* Selection sort descending.

==========================================================================================
5. Final remarks of CS 162.
==========================================================================================

I really enjoyed the course and learned a lot from it. The course taught me the
importance of adequate planning that I always be thankful for. 
Have a great rest of the school year.

==========================================================================================

