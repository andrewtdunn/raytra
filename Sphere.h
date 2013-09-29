#ifndef _SPHERE_H
#define _SPHERE_H

#include "math.h"
#include "Object.h"
#include "Vect.h"
#include "Color.h"

class Sphere : public Object{

	Vect center;
	double radius;
	Color color;

	public:

	Sphere ();

	Sphere (Vect, double, Color);

	// method functions
	Vect getSphereCenter () { return center; }
	double getSphereRadius () { return radius; }
	Color getSphereColor () { return color; }
	
};

Sphere::Sphere(){
	center = Vect (0,0,0);
	radius = 1.0;
	color = Color (0.5,0.5,0.5,0.0);
}

Sphere::Sphere( Vect centerValue, double radiusValue, Color colorValue){
	center = centerValue;
	radius = radiusValue;
	color = colorValue;
}


#endif