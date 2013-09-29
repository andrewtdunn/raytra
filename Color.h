#ifndef _COLOR_H
#define _COLOR_H


class Color{

	double red, green, blue, special;

	public:

	Color ();

	Color (double,double,double, double);

	// method functions
	double getColorRed() { return red; }
	double getColorGreen() { return green; }
	double getColorBlue() { return blue; }
	double getColorSpecial() { return special; }


	double setColorRed(double redValue) { red = redValue; }
	double setColorGreen(double greenValue) { green = greenValue; }
	double setColorBlue(double blueValue) { blue = blueValue; }
	double setColorSpecial(double specialValue) { special = specialValue; }

};

Color::Color(){
	red = 0.5;
	green = 0.5;
	blue = 0.5;
}

Color::Color( double r, double g, double b, double s){
	red = r;
	green = g;
	blue = b;
	special = s;
}


#endif