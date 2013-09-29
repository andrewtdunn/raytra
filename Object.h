#ifndef _OBJECT_H
#define _OBJECT_H

#include "Ray.h"
#include "math.h"
#include "Vect.h"
#include "Color.h"

class Object{

	public:

	Object ();

	Object (Vect, double, Color);

	// method functions
	Color getObjectColor () { return Color(0.0,0.0,0.0,0.0); }

	double findIntersection(Ray ray){
		return 0;
	}
	
};

Object::Object(){
}

#endif