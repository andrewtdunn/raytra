#ifndef _CYLINDER_H
#define _CYLINDER_H

#include "math.h"
#include "Object.h"
#include "Vect.h"
#include "Color.h"

class Cylinder : public Object{

	Vect center;
	double radius, height;
	Color color;

	public:

	Cylinder ();

	Cylinder (Vect, double, double, Color);

	// method functions
	Vect getCylinderCenter () { return center; }
	double getCylinderRadius () { return radius; }
	double getCylinderHeight () {return height; }
	virtual Color getColor () { return color; }

	virtual Vect getNormalAt(Vect point){
		// normal always points away from the center of a Cylinder
		Vect normal_Vect = point.vectAdd(center.negative()).normalize();
		return normal_Vect;
	}

	virtual double findIntersection(Ray ray){
		Vect ray_origin = ray.getRayOrigin();
		double ray_origin_x = ray_origin.getVectX();
		double ray_origin_y = ray_origin.getVectY();
		double ray_origin_z = ray_origin.getVectZ();

		Vect ray_direction = ray.getRayDirection();
		double ray_direction_x = ray_direction.getVectX();
		double ray_direction_y = ray_direction.getVectY();
		double ray_direction_z = ray_direction.getVectZ();

		Vect Cylinder_center = center;
		double Cylinder_center_x = Cylinder_center.getVectX();
		double Cylinder_center_y = Cylinder_center.getVectY();
		double Cylinder_center_z = Cylinder_center.getVectZ();

		

		double a = pow(ray_direction_x,2) + pow(ray_direction_y,2);	
		double b = 2 * (ray_origin_x*ray_direction_x + ray_origin_y * ray_direction_y);	 

		double c = pow(ray_origin_x, 2) + pow(ray_origin_y, 2) - (radius*radius);

		double discriminant = b*b - 4*a*c;

		if (discriminant > 0){
			// the ray intersects the Cylinder

			// the first root
			double root_1 = ((-1 * b - sqrt(discriminant))/2) - 0.000001;

			if (root_1 > 0){
				// the first root is the smallest positive root
				return root_1;
			}
			else{
				// the second root is the smallest positive root
				double root_2 = ((sqrt(discriminant) - b)/2) - 0.000001;
				return root_2;
			}

		}
		else{
			// the ray misses the Cylinder
			return -1;
		}

	}
	
};

Cylinder::Cylinder(){
	center = Vect (0,0,0);
	radius = 1.0;
	height = 2.0;
	color = Color (0.5,0.5,0.5,0.0);
}

Cylinder::Cylinder( Vect centerValue, double radiusValue, double heightValue, Color colorValue){
	center = centerValue;
	radius = radiusValue;
	height = heightValue;
	color = colorValue;
}


#endif