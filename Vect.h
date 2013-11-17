#ifndef _VECT_H
#define _VECT_H

#include "math.h"

/*
A vector describes a length and a direction. Two vectors are equal if they are located in different locations. Think of a vector as an arrow and not as coordinates or numbers. A unit vector has a length of 1. A zero vector has a length 0. Vectors can be used to store an offset (displacement). A vector can also be used to store a position or a point. Usually there is some understood origin location from which all other locations are stored as offsets. 

We assume a Cartesian coordinate system. 
*/

class Vect{

	double x,y,z;

	public:

	Vect ();

	Vect (double,double,double);

	// method functions
	double getVectX() { return x; }
	double getVectY() { return y; }
	double getVectZ() { return z; }

	/*
	by the principle of the Pythagoran theorem, a^2 + b^2 = c^2, when applied to a 3D coordinate system. 
	*/

	double magnitude (){
		return sqrt((x*x) + (y*y) + (z*z));
	}

	/*
	Returns a unit vector. How is the related to the "normal" parrallel to an intersection point of a ray and a surface?
	*/
	Vect normalize (){
		double magnitude = sqrt((x*x) + (y*y) + (z*z));
		return Vect(x/magnitude, y/magnitude, z/magnitude);
	}

	/*
	Returns the unary minus of a vector. A unary minus is a vector with the same length as a but in the opposite direction. 
	thus 	b-a = -a + b
	*/
	Vect negative (){
		return Vect (-x,-y,-z);
	}

	/*
	The simplest way to multiply two vectors. returns a scalar (represented here as a double). The dot product returns a value related to a its' arguments lengths and the angle theta between them. 

	a.dotProduct(b) = magnitude(a) * magnitude(b) * cos ( theta ) 

	The most common use of the dot product in graphics programs is to compute the cosine of the angle between two vectors. 
	*/
	double dotProduct (Vect v) {
		return x*v.getVectX() + y*v.getVectY() + z*v.getVectZ(); 
	}

	/*
	Returns a 3D vector that is perpendicular to the two arguments (in this case implicit and explicit arguments). 

	magnitude ( a.crossProduct(b) ) is related to the area of the parrallelogram formed between a and b. 

	cross product is not commutitive. 
	a.crossProduct(b) != b.crossProduct(b)

	Assumes right-handed coordinate system. 
	*/

	Vect crossProduct(Vect v){
		return Vect(y*v.getVectZ() - z * v.getVectY() , 
					z*v.getVectX() - x * v.getVectZ() ,
					x*v.getVectY() - y * v.getVectX() );
	}

	/*
	It usually does not make sense to add two locations unless it is an intermediate operation when computing weighted averages of a location. 

	Vectors are added using the parrallelogram rule: the sum of two vectors is found by placing the tail of either vector against the head of the other. The sum vector "completes the triangle" started by the two vectors.

	Vector addition is communitative: 
	a + b = b + a
	*/
	Vect vectAdd (Vect v){
		return Vect (x + v.getVectX(), y + v.getVectY(), z + v.getVectZ());
	}

	/*
	Multiplying a vector by a scalar value. Returns a vector. 
	*/
	Vect vectMult (double scalar){
		return Vect (x * scalar, y * scalar, z * scalar);
	}

};

Vect::Vect(){
	x = 0;
	y = 0;
	z = 0;
}

Vect::Vect( double i, double j, double k){
	x = i;
	y = j;
	z = k;
}


#endif