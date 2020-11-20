/* ***************************************************************************************
 * Filename: _2d_Array.hpp
 * Author: Wikus
 * Date: November 12, 2020.
 * Description: This file contains the first attempt to create a universal container
 * 		that I can use for future projects. 
 * 		The container will add extra functionality such as it will print the
 * 		be a 2d array that is at essecence a 2d std::vector.
 * 		I will uss this class to inherent from.
 * 		Methods:
 *			1. display(bool print_grid = false): If true, then the member will
 *							     print a grid around the 
 *							     element.
 * 			2. search_around(int, int): This will search 
 * 						    around the point given and print
 * 						    the contents of the adjacent elemnts.
 *
 * Learning resource: Learn cpp 13.1 - 13.3
 * **************************************************************************************/
#ifndef _2D_ARRAY_HPP
#define _2D_ARRAY_HPP

#include "Vec2d.h"
#include <cassert>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>

// ===================
// Class templates: 
// ===================

// Before using this class.
// Note that it is meant to be used as a square grid. That is an n x n matrix.


/* 
 Why do we need class templates? It enables us to build containers to store data of
 different types but that are very similar in functionality.
 Note that the compiler creates a template instance of an object if is used by the 
 program. Because cpp compiles files seperatly, we need to add our implementation
 file along with our header file in a .hpp file.
*/




// In this context the 'class' and 'typename' keyword has the same meaning.
// It is best practises to use the 'class' keyword here and 'typename' with 
// function templates.
template <class T>
class _2d_Array{
//public:	// This will represent the array.
	// This is an array of vectors. "vector of vectors"
	std::vector< std::vector<T> > m_array;
	// This function will be used to print the contents of the array.
public: 
	// =========================
	// Overloaded operators:
	// =========================
	
	// A) Assignement operators.
	// =========================
	// 1. The standard one is deleted for now.
	_2d_Array& operator=(const _2d_Array&) = delete;
	// 2. This one will be used to insert one data type into the array.
	_2d_Array& operator=(T);
	// 1. Getter
	std::vector<std::vector<T> >& get_v(){m_array;}
	// 2. Getter: Use only for square n x n containers.
	int get_dim(){return m_array.size();}
	
	// ======================
	// Functionality:
	// ======================
	// 1. This function will return true of the head of the mathematical vector
	// is inside the grid.
	bool is_inside(const Vec2d&);
	// 2. This function will be used to perform an action on all the block N/E/S/W
	// 	from the head of the vector passed to the function.
	void search_around(const Vec2d&);
	// =====================
	// Displaying the array.
	// =====================
	// 1. This displays all the elemnts in the array with a nice grid around.
	// Note** If you store custom objects you must redefine the function.
	void print_with_grid(bool index = false);
	// 2. This print will list all the elements.
	void print() const ;
	// =============
	// Constructors:
	// =============
	// 1. Default: Will intialize the std::vector with out any elements.
	_2d_Array();
	// 2. Version 1: This will construct the array with a given size.
	// This uses resize(n) to construct the vector.
	_2d_Array(int);	
	// 3. Version 2: This will construct the array of a set size with uniform elements.
	_2d_Array(T, int);
	// ============
	// Destructor:
	// ============	
	~_2d_Array();
private:	
	void print_line(int);
	void print_space(int);
};

/* ***************************************************************************************
 * Function name: operator=() 
 * Version: 2
 * Description:  This assignment will insert one element inside the array at the back
 * 		 because it makes use of the push_back() member function from
 * 		 std::vector.
 * Parameters: <template T>
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
template <typename T>
_2d_Array<T>& _2d_Array<T>::operator=(T var){
	// This will insert the element at the end of the constainer.
	// m_array.push_back(var);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Functionality:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


// ** A. **
/* **************************************************************************************
 * Function name: is_inside()
 * Description: This function will be used to determine if the head of the vector is
 * 		inside the 2d array. Note that the vector can't be used to indicated
 * 		direction in the array because the (0,0) point is in the top left
 * 		corner and not the bottom left.
 * Parameters: const Vec2d&
 * Pre-conditions: Assumes that the vector class header file is included.
 * Post-conditions: Returns true if the head of the vector is inside the 2d-array, else
 * 		    it will return false.
 * **************************************************************************************/
template <typename T>
bool _2d_Array<T>::is_inside(const Vec2d& v){
	if( 0 <= v.get_x() && v.get_x() < m_array.size() 
	&& 0 <= v.get_y() && v.get_y() < m_array.size()){
		// The point is inside the 2d-array.
		return true;
	}else{
		// The point is not inside the 2d-array.
		return false;
	}
}

/* **************************************************************************************
 * Function name: search_around()
 * Description: This function will accept a head of a vector and search around the 
 * 		position given. This function will only print the N/E/S/W blocks
 * 		on the 2d-array. Note that becuase this is a 2d array with rows
 * 		and tables and not a cartesian plane, the vectors are not used correctly
 * 		to determine direction. Exampl <1,0> wich means one unit upwards
 * 		will go one unit downards if you add it to a point in the 2d_array.
 * Parameters: const Vec2d&
 * Pre-conditions: Takes in the head of a vector.
 * Post-conditions: Searches around the point given. Note that here it only prints the
 * 		    point. It can be used to do other tasks.
 * **************************************************************************************/
template <typename T>
void _2d_Array<T>::search_around(const Vec2d& v){
	// If the point inserted is not in the 2d_array then the function will inform the 
	// designer of the program.
	if(is_inside(v)){
		// Note that you are working with a table like array where (0,0) is
		// top left and not a cartesian plane. 
		Vec2d N(-1,0), E(0,1), S(1,0), W(0,-1);
		// This is so that I have the position of the adjacent blocks.
		Vec2d vN = v + N;
		Vec2d vE = v + E;
		Vec2d vS = v + S;
		Vec2d vW = v + W;
		// If the adjacent block is in the grid I want to perform an action on it.
		// ** Note that the objects stored in the array needs to be able to 
		// be printed to the console.
		// This only prints the elements but you can do anything with them.
		if(is_inside(vN)){
			// Going up and down rows is is moving parallel to the y axis
			std::cout << m_array[vN.get_y()][vN.get_x()] << std::endl;
		}
		if(is_inside(vE)){
			// Going up and down rows is is moving parallel to the y axis
			std::cout << m_array[vE.get_y()][vE.get_x()] << std::endl;
		}
		if(is_inside(vS)){
			// Going up and down rows is is moving parallel to the y axis
			std::cout << m_array[vS.get_y()][vS.get_x()] << std::endl;
		}
		if(is_inside(vW)){
			// Going up and down rows is is moving parallel to the y axis
			std::cout << m_array[vW.get_y()][vW.get_x()] << std::endl;
		}
	}else{
		// This is when the point inserted is not in the 2d array.
		std::cerr << "[_2d_Array.search_around() was passed a vector outside "
		<< " the array]" << std::endl;
	}
	return;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Display:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// 1. This displays all the elemnts in the array with a nice grid around.
// Note** If you store custom objects you must redefine the function.
/* ***************************************************************************************
 * Function name: print_with_grid()
 * Description: This function will print all the elements in the 2d vector with a nice 
 * 		grid around is for display purposes.
 * 		Note that for the "Hunt the Wumpus" game remember to change the cout with
 * 		their own print function.
 * Parameters: -
 * Pre-conditions: Assumes that the container has data inside it.
 * Post-conditions: Prints all the elements with a nice grid around it.
 * **************************************************************************************/
template <typename T>
void _2d_Array<T>::print_with_grid(bool index){
	print_line(m_array.size());
	std::cout << std::endl;
	print_space(m_array.size());
	std::cout << std::endl;
	
	for(int i = 0; i < m_array.size(); i++){
		for(int j = 0; j < m_array[i].size(); j++){
			// This is so that I can see the indices alongside it.
			// It is false by default.
			
			if(j == 0){
				std::cout << "|";
			}
			if(index){
				std::cout << "(" << i << "," << j << ")"<< m_array[i][j] << ' ';
				
			}else{
				std::cout << std::setw(3) << std::setfill(' ')<< m_array[i][j] <<  "  |";
			}
		
		}
		std::cout << std::endl;
		print_space(m_array.size());
		std::cout << std::endl;
		print_line(m_array.size());
		std::cout << std::endl;
		// This should not print on the last iterattion.
		if(i != m_array.size() - 1){
			print_space(m_array.size());	
			std::cout << std::endl;
		}
	}
	return;
	
}
// n is the number of elements in the container.
template <class T>
void _2d_Array<T>::print_line(int n){
	std::cout << "x";
	for(int i = 0; i < n; i++){
		std::cout << std::setfill ('*')<< std::setw(6) << 'x';
	}
}
// This prints the open part.
template <class T>
void _2d_Array<T>::print_space(int n){
	std::cout << "|";
	for(int i = 0; i < n; i++){
		std::cout << std::setfill (' ')<< std::setw(6) << '|';
	}
}
// You function can take in just one template parameter.
/* ***************************************************************************************
 * Function name: print() 
 * Description: This function will be used to list the contents of the area. See display()
 * 		for other version to ouput the contents of the array to the screen. 
 * 		This function is for development purposes and should not be used for
 * 		an application.
 * Parameters: -
 * Pre-conditions: Assumes that the array constains data.
 * Post-conditions: -
 * **************************************************************************************/
// == Remember that to add the template parameters in the definition outside of the class
//    as well. ==
template <typename T>
void _2d_Array<T>::print() const{
	std::cout << std::endl;
	// This is the array way to iterate through a vector and print out the content
	// of the 2 dimensional vector.
	for(int i = 0; i < m_array.size(); i++){
		for(int j = 0; j < m_array[i].size(); j++){
			std::cout << "(" << i << "," << j << ")"<< m_array[i][j] << ' ';
		}
	std::cout << std::endl;
	}
}



// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Constructors:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/* ***************************************************************************************
 * Function name: Array() 
 * Version: default
 * Description: This will be the default constructor. It will intialise the std::vector
 * 		array as if you normally initalize the vector. 
 * Parameters: - 
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
template <typename T>
_2d_Array<T>::_2d_Array(){
	// Temporary.
	std::cout << "Default constructor for the Array." << std::endl;
}
/* ***************************************************************************************
 * Function name: Array() 
 * Version: 1
 * Description: This constructor creates a n x n matrix square.
 * 		This constructor will be used to create the Array with a given size passed
 * 		in as the parameter of the constructor. This constructor makes use of the
 * 		fact that the vector class can be instantiated in the same manner. 
 * Parameters: int: Size of the array.
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
template <typename T>
_2d_Array<T>::_2d_Array(int n)
{
	std::cout << "_2d_Array constructor 2"<< std::endl;
	assert(n > 0 && "[Unable to construct array]: Must have size of at leaste one");	
	// setting size of the vector for to store the vectors inside.
	m_array.resize(n);
	// Now each vector will also contain a vector of size n.
	for(int i = 0; i < n; i++){
		m_array[i].resize(n);
	}

}
/* ***************************************************************************************
 * Function name: Array() 
 * Version: 2
 * Description: Creating a 2d-array of elements the same elements.
 * 		This will create a square matrix.
 * 		This constructor will construct the array with the set size and the 
 * 		uniform type that is passed as the first argument.
 * Parameters: int - size, and <typename T> .
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
template <typename T>
_2d_Array<T>::_2d_Array(T var, int n) 
{
	// Making sure that the array has at least one element.
	assert(n > 0 && "[Unable to construct array]: Must have size of at leaste one");	
	// setting size of the vector for to store the vectors inside.
	m_array.resize(n);
	// Now each vector will also contain a vector of size n.
	for(int i = 0; i < n; i++){
		// First I resize the vector so that there is room to insert variables.
		m_array[i].resize(n);
		auto it = m_array[i].begin();
		// testing purposes.
		//int j = 0;
		for(it; it < m_array[i].end(); it++){
			//(*it) = i + j;
			(*it) = var;
			//j++;
		}
	}


}


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Destructor:
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/* ***************************************************************************************
 * Function name: Array() 
 * Version: default
 * Description: The destructor is not yet needed for the container/class but will in the 
 * 		future be needed.
 * Parameters: - 
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
template <typename T>
_2d_Array<T>::~_2d_Array(){
	// Temporary.
	std::cout << "_2d_Array is destructed" << std::endl;
}

#endif

