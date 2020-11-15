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

class Vec2d{
	// This class will be used to demonstrate operator overloading.
	float m_x;
	float m_y;
public:
	// Constructors:
	// ================
	// 1. Default constructor: This will be the constructor that creates a vector with the 
	//                      given components.
	Vec2d(float x = 0.0, float y = 0.0): m_x{x}, m_y{y}
	{}
	// 2. Constructor 1.
	// =================
	
	// The Big Three.
	// ===============
	// A.) The copy constructor.
	// -------------------------------------
	Vec2d(const Vec2d& vec)
	: m_x{vec.get_x()}, m_y{vec.get_y()}
	{}
	// B.) Assignment operator overload: defualt
	// -------------------------------------
	// C.) Destructor: default
	// -------------------------------------
	
	// Overloaded operators:
	// ====================
	// -----------------------------------
	// 1. Addition operator '+'.
	// -----------------------------------
	// - a. Member function overload (type 2).
//	Vec2d& operator+(const Vec2d&);
	// - b. Pre-increment. (no dummy variable.)
	Vec2d& operator++();
	// - c. Post-increment. (dummy variable.)
	Vec2d operator++(int);
	// -----------------------------------
	// 2. Multiplication operator '*'.
	// -----------------------------------
	// It does not make sense to multiply two vectors.
	// This will be used to do scalar multiplacation.
	Vec2d& operator*(float);	
	// -----------------------------------
	// 3. Boolean operators.
	// -----------------------------------
	// - a. This is the overloaded comparison operator.
	bool operator==(const Vec2d&) const;
	// The unary operator.
	// I do not want to change the value of the object, I only want the negative of 
	// it.
	Vec2d operator-();
	// -------------------------
	// Overloaded I/O operator.
	// -----------------------------------
	// - a. The overloaded '<<' operator.
	friend std::ostream& operator<<(std::ostream&, const Vec2d&);
	// The oveloaded '>>' operator.
	// Note that it is not a const Vec2d& becuase I want to change the value
	// - b. The overloaded '>>' operator.
	friend std::istream& operator>>(std::istream&, Vec2d&); 
	// ========================
	// Mathematical Operations.
	// ========================
	// This function will return the norm (magnitude/ length) of the vector.
	float norm() const;

	// =================
	// Accessors.
	// =================
	float get_x() const;
	float get_y() const;
	float get_z() const;
	// ==================
	// Non-const version.
	// ==================
	float get_x();
	float get_y();
	float get_z();

};

/* ***************************************************************************************
 * Function name: operator+().
 * Description: This function is oveloaded as a member function.
 * 		This is a binary operator.
 * **************************************************************************************/
/*
Vec2d& Vec2d::operator+(const Vec2d& vec3){
	// Vector additions is component wise.
	this->m_x += vec3.get_x();
	this->m_y += vec3.get_y();
	// This is only to see when the functions is called.
	std::cout << "[operator+()]: As member function" << std::endl;
	// Return the Vec2d instance.
	return *this;
}
*/
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
Vec2d& Vec2d::operator*(float scalar){
	// Scalar multiplaction performed on the vector.
	this->m_x *= scalar;
	this->m_y *= scalar;
	// The result is the new vector.
	return *this;
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
float Vec2d::get_x(){
	return this->m_x;
}
/* ***************************************************************************************
 * Function name: get_y().
 * Description: Accessor function and a mutator (getter and a setter.) 
 * **************************************************************************************/
float Vec2d::get_y(){
	return this->m_y;
}


// Testing the code.

int main(){
	Vec2d v1(0,0);
	Vec2d v2(0,10);
	Vec2d v3(2,3);
	// Example1 :Use of the oveloaded '+' operator.
	// This will add v2 to v1 and store the new vector in v1.
	// NB! v1 is changed.
	v1 + v2;
	std::cout << "1.) Vector addition: "<< v1 << std::endl << std::endl;
	// =============
	// Example 2: Scalar multiplication.
	float scalar = 4.6;
	v1 = v1 * scalar;
	std::cout << "2.) Scalar multiplication: "<< v1 << std::endl << std::endl;
	// =============
	// Example 3: Vector addition with a normal function.
	// Note that this will change the value of v2 if you uncomment the member function method.
	std::cout << "3.) Vector addition: " << v2 + v3 << std::endl; 
	std::cout << "v2: " << v2 << std::endl;
	std::cout << "v3: " << v3 << std::endl;
	std::cout << std::endl << std::endl;
	// =============
	// Example 4: The overloaded >> operator.
	std::cin >> v1;
	std::cout << std::endl << "4.) Your input: " << v1 << std::endl;
	std::cout << std::endl << std::endl;
	// =============
	// Example 5: Using the comparison operator.
	std::cout << std::endl << "5.) Comparison between: " << v1 << " and "
	<< v3 << std::endl;
	if(v1 == v3){
		std::cout << "Equal." << std::endl;
	}else{
		std::cout << "Not equal." << std::endl;
	}
	std::cout << std::endl << std::endl;
	// =============
	// Example 6: Pre/Post - increment.
	Vec2d v4(0,0);
	Vec2d v5(0,0);
	std::cout << std::endl;
	std::cout << "6.) Pre/Post - increment." << std::endl
	<< "Before: "<< std::endl;
	std::cout << "v4: " << v4 <<std::endl
	<< "v5: " << v5 << std::endl;
	// Showing the pre/post working.
	std::cout << "v4 - pre: " << ++v4<<std::endl
	<< "v5 - post: " << v5++ << std::endl;
	// =============
	std::cout << std::endl << "7.) The unary operator '-': Note that this " 
	<< "returns a value for the program to use and does not change the value of the instance used."
	<< std::endl;
	Vec2d v7 = Vec2d(23,1);
	std::cout << "With operator: " << -v7 << " and without operator " << v7 << std::endl;
	
	// =============
	// Example 7: Norm/ Magnitude/ Length.
	Vec2d v9(10,-2);
	Vec2d v10(2,5);
	std::cout << std::endl;
	std::cout << "7.) The norm of the two vectors." << std::endl
	<< "Vector: " << v9 << " and norm: " << v9.norm() << std::endl
	<< "Vector: " << v10 << " and norm: " << v10.norm() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << std::endl << "Summary of all the vectors used." << std::endl;	
	std::cout << "v1: " << v1 << std::endl
	<< "v2: " << v2 << std::endl
	<< "v3: " << v3 << std::endl;
	return 0;
}


