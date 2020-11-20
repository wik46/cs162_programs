/* ***************************************************************************************
 * Filename: Vec2d.cpp
 * Author: Lodewyk Jansen van Rensburg
 * Date: November 13, 2020
 * Description: This is class that is a 2 dimensional mathematical vector. It will be 
 * 		used to indicate direction that a player moves in a board game.
 * 		The purpose of this file is to create a class that can be reused for
 * 		many future projects.
 * 		See VecNd.cpp for an n-dimensional vector.
 * **************************************************************************************/

#include "Vec2d.h"
#include <iostream>
#include <math.h>



// ======================================================================================
// 2 Dimensional mathematical vectors.
// ======================================================================================

// List of operator overloads.
// 1. Mathematical operators (binary): +, -, *, and /.
// 2. Unary operators: !, +, and -.
// 3. Overloaded I/O operators: << and >>.
// 4. Comparison operators: ==, !=, >, =>, <, and <=.
// 5. 
// 6.
// 7.
// 8. The subscript operator: []

/* ***************************************************************************************
 * Function name: operator+().
 * Description: This function is oveloaded as a normal function.
 * 		This is a binary operator.
 * **************************************************************************************/
Vec2d operator+(const Vec2d& l, const Vec2d& r){
	float x = l.get_x() + r.get_x();
	float y = l.get_y() + r.get_y();
	// Note that I am returning by values.
	// You cannot return a reference to an object that was made in the local
	// scope of the function becuase the memory will be freed when the function goes
	// out of scope.
	return Vec2d(x,y);
}
/* ***************************************************************************************
 * Function name: operator+().
 * Description: This function is oveloaded as a normal function.
 * 		This is a binary operator.
 * **************************************************************************************/
Vec2d operator+(Vec2d& l, Vec2d& r){
	float x = l.get_x() + r.get_x();
	float y = l.get_y() + r.get_y();
	// Note that I am returning by values.
	// You cannot return a reference to an object that was made in the local
	// scope of the function becuase the memory will be freed when the function goes
	// out of scope.
	return Vec2d(x,y);
}
/* ***************************************************************************************
 * Function name: operator+().
 * Description: This function is oveloaded as a normal function.
 * 		This is a binary operator.
 * **************************************************************************************/
Vec2d operator+(const Vec2d& l, Vec2d& r){
	float x = l.get_x() + r.get_x();
	float y = l.get_y() + r.get_y();
	// Note that I am returning by values.
	// You cannot return a reference to an object that was made in the local
	// scope of the function becuase the memory will be freed when the function goes
	// out of scope.
	return Vec2d(x,y);
}
/* ***************************************************************************************
 * Function name: operator+().
 * Description: This function is oveloaded as a normal function.
 * 		This is a binary operator.
 * **************************************************************************************/
Vec2d operator+(Vec2d& l, const Vec2d& r){
	float x = l.get_x() + r.get_x();
	float y = l.get_y() + r.get_y();
	// Note that I am returning by values.
	// You cannot return a reference to an object that was made in the local
	// scope of the function becuase the memory will be freed when the function goes
	// out of scope.
	return Vec2d(x,y);
}
/* ***************************************************************************************
 * Function name: operator-().
 * Description: This function is oveloaded as a normal function.
 * 		This is a binary operator.
 * **************************************************************************************/
Vec2d operator-(const Vec2d& l, const Vec2d& r){
	float x = l.get_x() - r.get_x();
	float y = l.get_y() - r.get_y();
	// Note that I am returning by values.
	// You cannot return a reference to an object that was made in the local
	// scope of the function becuase the memory will be freed when the function goes
	// out of scope.
	return Vec2d(x,y);
}
/* ***************************************************************************************
 * Function name: operator-().
 * Description: This function is oveloaded as a normal function.
 * 		This is a binary operator.
 * **************************************************************************************/
Vec2d operator-(Vec2d& l, Vec2d& r){
	float x = l.get_x() - r.get_x();
	float y = l.get_y() - r.get_y();
	// Note that I am returning by values.
	// You cannot return a reference to an object that was made in the local
	// scope of the function becuase the memory will be freed when the function goes
	// out of scope.
	return Vec2d(x,y);
}
/* ***************************************************************************************
 * Function name: operator-().
 * Description: This function is oveloaded as a normal function.
 * 		This is a binary operator.
 * **************************************************************************************/
Vec2d operator-(Vec2d& l, const Vec2d& r){
	float x = l.get_x() - r.get_x();
	float y = l.get_y() - r.get_y();
	// Note that I am returning by values.
	// You cannot return a reference to an object that was made in the local
	// scope of the function becuase the memory will be freed when the function goes
	// out of scope.
	return Vec2d(x,y);
}
/* ***************************************************************************************
 * Function name: operator-().
 * Description: This function is oveloaded as a normal function.
 * 		This is a binary operator.
 * **************************************************************************************/
Vec2d operator-(const Vec2d& l, Vec2d& r){
	float x = l.get_x() - r.get_x();
	float y = l.get_y() - r.get_y();
	// Note that I am returning by values.
	// You cannot return a reference to an object that was made in the local
	// scope of the function becuase the memory will be freed when the function goes
	// out of scope.
	return Vec2d(x,y);
}
/* ***************************************************************************************
 * Function name: operator++().
 * Description: This function is oveloaded as a member function.
 * Version: Pre-increment.
 * **************************************************************************************/
// This function will increment each component.
Vec2d& Vec2d::operator++(){
	++this->m_x;
	++this->m_y;
	// Returns a referenc to the object.
	return *this;
}

/* ***************************************************************************************
 * Function name: operator++().
 * Description: This function is oveloaded as a member function.
 * Version: Post-increment.
 * Note: In order to distinguish between the pre and post increment operator,
 * 	 we pass in a dummy variable as the paramter.
 * **************************************************************************************/
Vec2d Vec2d::operator++(int){
	// This is not as effiecient as pre-increment.
	// Shallow copy is okay becuase my vector does not contain any dynamic memory.
	Vec2d temp(*this);
	// This is where the actual instance is incremented.
	// Note that I used the pre-increment operator that is already defined above.
	++(*this);
	// Return the local copy because I need the value before the increment.
	temp;
}

/* ***************************************************************************************
 * Function name: operator*().
 * Description: This function is oveloaded as a member function.
 * 		This is a binary operator.
 * 		This operator overload will be used when I want to multiply my vector
 * 		with some scalar. The result will produce a vector.
 * **************************************************************************************/
//Vec2d& Vec2d::operator*(float scalar){
//	// Scalar multiplaction performed on the vector.
//	this->m_x *= scalar;
//	this->m_y *= scalar;
//	// The result is the new vector.
//	return *this;
///}
/* ***************************************************************************************
 * Function name: operator*().
 * Description: This function is oveloaded as a member function.
 * 		This is a binary operator.
 * 		This operator overload will be used when I want to multiply my vector
 * 		with some scalar. The result will produce a vector.
 * **************************************************************************************/
Vec2d operator*(int scalar, const Vec2d& v){
	int x = v.get_x();
	int y = v.get_y();
	// Scalar multiplaction performed on the vector.
	x *= scalar;
	y *= scalar;
	// The result is the new vector.
	return Vec2d(x,y);
}
/* ***************************************************************************************
 * Function name: operator*().
 * Description: This function is oveloaded as a member function.
 * 		This is a binary operator.
 * 		This operator overload will be used when I want to multiply my vector
 * 		with some scalar. The result will produce a vector.
 * **************************************************************************************/
Vec2d operator*(const Vec2d& v, int scalar){
	int x = v.get_x();
	int y = v.get_y();
	// Scalar multiplaction performed on the vector.
	x *= scalar;
	y *= scalar;
	// The result is the new vector.
	return Vec2d(x,y);
}

/* ***************************************************************************************
 * Function name: operator==().
 * Description: This function is oveloaded as a member function.
 * 		This is a binary operator.
 * 		Two vectors are equal if there components are equal.
 * **************************************************************************************/
bool Vec2d::operator==(const Vec2d& vector) const{
	return ((this->m_x == vector.get_x())
	&& (this->m_y == vector.get_y()));
}
/* ***************************************************************************************
 * Function name: operator-().
 * Description: This function is oveloaded as a member function.
 * 		This is a unary operator.
 * 		This is used when I want to obtain the vector parallel to the current
 * 		instance, but in the opposite direction.
 * **************************************************************************************/
Vec2d Vec2d::operator-(){
	// This returns a new vector in the opposite direction.
	return Vec2d(-m_x, -m_y);
}

/* ***************************************************************************************
 * Function name: operator<<().
 * Description: This function is oveloaded as a friend function.
 * 		This is a binary operator.
 * 		Remember to return a reference to the ostream instance that you used.
 * 		This is a friend fuction of Vec2d. Therefore it has access to its privte
 * 		members but is not a member function.
 * 		Friend function do not have access to the classes 'this' pointer.
 * **************************************************************************************/
std::ostream& operator<<(std::ostream& stream_out, const Vec2d& vec3d){
	stream_out << "< " << vec3d.get_x() 
	<< ", "<< vec3d.get_y() << " >";
	// Always remember to return the instance of the ostream object.
	return stream_out;
}
/* ***************************************************************************************
 * Function name: operator>>().
 * Description: This function is oveloaded as a friend function.
 * 		This is a binary operator.
 * 		Remember to return a reference to the istream instance that you used.
 * 		This is a friend fuction of Vec2d. Therefore it has access to its privte
 * 		members but is not a member function.
 * 		Friend function do not have access to the classes 'this' pointer.
 * **************************************************************************************/
std::istream& operator>>(std::istream& stream_in, Vec2d& vec){
	// This function assumes that the user will enter floats.
	std::cout << "x component: ";
	stream_in >> vec.m_x;
	std::cout << "y component: ";
	stream_in >> vec.m_y;
	return stream_in;
}

// ======================================
// Mathematical Operattions:
// ======================================

/* **************************************************************************************
 * Function name: norm().
 * Description: This function will return the norm of the vector.
 * 		The norm will be a floating point number. 
 * 		By definition the norm is the sum of all the components square
 * 		under the square root.
 * Parameters: -
 * Pre-conditions: Assumes that the two components were correctly constructed.
 * Post-conditions: Returns the norm of the vector.
 * **************************************************************************************/
float Vec2d::norm() const{
	return sqrt( (m_x * m_x ) + (m_y * m_y)) ;
}
/* ***************************************************************************************
 * Function name: get_x().
 * Description: Accessor function and a mutator (getter and a setter.) 
 * **************************************************************************************/
float Vec2d::get_x() const{
	return this->m_x;
}
/* ***************************************************************************************
 * Function name: get_y().
 * Description: Accessor function and a mutator (getter and a setter.) 
 * **************************************************************************************/
float Vec2d::get_y() const{
	return this->m_y;
}
/* ***************************************************************************************
 * Function name: get_x().
 * Description: Accessor function and a mutator (getter and a setter.) 
 * **************************************************************************************/
//float Vec2d::get_x(){
//	return this->m_x;
//}
/* ***************************************************************************************
 * Function name: get_y().
 * Description: Accessor function and a mutator (getter and a setter.) 
 * **************************************************************************************/
//float Vec2d::get_y(){
//	return this->m_y;
//}
/* ***************************************************************************************
 * Function name: get_x().
 * Description: Accessor function and a mutator (getter and a setter.) 
 * **************************************************************************************/
float& Vec2d::get_x(){
	return this->m_x;
}
/* ***************************************************************************************
 * Function name: get_y().
 * Description: Accessor function and a mutator (getter and a setter.) 
 * **************************************************************************************/
float& Vec2d::get_y(){
	return this->m_y;
}


