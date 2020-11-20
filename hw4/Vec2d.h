/* ***************************************************************************************
 * Filename: Vec2d.h
 * Author: Lodewyk Jansen van Rensburg
 * Date: November 13, 2020
 * Description: This is class that is a 2 dimensional mathematical vector. It will be 
 * 		used to indicate direction that a player moves in a board game.
 * 		The purpose of this file is to create a class that can be reused for
 * 		many future projects.
 * 		See VecNd.cpp for an n-dimensional vector.
 * **************************************************************************************/
#ifndef VEC2D_H
#define VEC2D_H

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
//	Vec2d& operator*(float);	
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
	// ==================
	// Non-const version.
	// ==================
	//float get_x();
	//float get_y();
	// =================
	// Mutators.
	// =================
	float& get_x();
	float& get_y();

};

// =========================
// Addition and Subtraction.
// =========================
Vec2d operator+(Vec2d& l, Vec2d& r);
Vec2d operator+(const Vec2d& l, const Vec2d& r);
Vec2d operator+(const Vec2d& l, Vec2d& r);
Vec2d operator+(Vec2d& l, const Vec2d& r);
Vec2d operator-(Vec2d& l, Vec2d& r);
Vec2d operator-(const Vec2d& l, const Vec2d& r);
Vec2d operator-(const Vec2d& l, Vec2d& r);
Vec2d operator-(Vec2d& l, const Vec2d& r);
Vec2d operator*(const Vec2d& v, int scalar);
Vec2d operator*(int scalar, const Vec2d& v);

#endif
