#ifndef SPHERE_HPP
#define SPHERE_HPP
#include <math.h>
#include <cmath>
#include <glm/vec3.hpp>

//5.2 Sphere Klasse

class Sphere{ 
public:
	Sphere();
	Sphere(float radius);
	Sphere(float area);
	Sphere(float volume);

//Variablen
	float radius;
	float area;
	float volume;

//Getter
	float getsarea() const;
	float getsvolume() const;
	float getsradius() const;

};
#endif
