#ifndef COLOUR_HPP
#define COLOUR_HPP

class Colour {
	double red, green, blue, special;
	
	public:
	
	Colour ();
	
	Colour (double, double, double, double);

	//method functions
	double getColourRed() { return red; }
	double getColourGreen() { return green; }
	double getColourBlue() { return blue; }
	double getColourSpecial() { return special; }

	double set ColourRed(double redValue) {red = redValue};
	double set ColourGreen(double greenValue) {green = greenValue};
	double set ColourBlue(double blueValue) {blue = blueValue};
	double set ColourSpecial(double specialValue) {special = specialValue};

	//Farben manipulieren um Schatten herauszubekommen
	double brightness() {
		return(red + green + blue)/3;
	}

	Colour colourScalar(double scalar) {
		return Colour (red*scalar, green*scalar, blue*scalar, special);
	}

	Colour colourAdd(Colour colour) {
		return Colour (red + colour.getColourRed(), green + colour.getColourGreen(), blue + colour.getColourBlue(), special);			
	}

	Colour colourMultiply(Colour colour) {
		return Colour (red*colour.getColourRed(), green*colour.getColourGreen(), blue*colour.getColourBlue(), special);
	}
	
	Colour colourAverage(Colour colour) {
		return Colour ((red + colour.getColourRed())/2, (green + colour.getColourGreen())/2, (blue + colour.getColourBlue())/2, special);

	//Method function: normalizes Colour 
	Colour clip() {
		double alllight = red + green + blue;
		double excesslight = allight - 3;
		if (excesslight > 0) {
			red = red + excesslight*(red/alllight);
			green = green + excesslight*(green/alllight);
			blue = blue + excesslight*(blue/alllight);
		}
		if (red > 1) {red = 1;}
		if (green > 1) {green = 1;}
		if (blue > 1) {blue = 1;}
		if (red < 0) {red = 0;}
		if (green < 0) {green = 0;}
		if (blue < 0) {blue = 0;}

		return Colour (red, green, blue, special);
	   }
	};

Colour::Colour (double i, double j, double k) {
	x = 0;
	y = 0;
	z = 0;
}
Colour::Colour (double r, double g, double b, double s) {
	red = r;
	green = g;
	blue = b;
	special = s;
}

#endif
