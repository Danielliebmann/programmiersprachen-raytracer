#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <math.h>
#include <cmath>

//Eine virtuelle Methode ist in C++ eine Methode einer Klasse, deren Einsprungadresse erst zur Laufzeit ermittelt wird.

//5.1 Shape Klasse
//Pure Virtual Methoden
class Shape{ 
public:
	virtual float area() const = 0; //=0 auch bekannt als 'pure specifier'. Valure =0 nicht mehr gegeben
	virtual float volu() const = 0;
	};







//5.4
/*
class Shape
{
public:
	//...
	virtual std::ostream& print(std::ostream& os) const;

	//...
};

std::ostream& operator<<(std::ostream& os, Shape const& s)
{
	//not implemented yet
}
*/
//vr vr2016_buw_ss

#endif
