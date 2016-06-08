#ifndef BOX_HPP
#define BOX_HPP
#include <math.h>
#include <cmath>
#include <glm/vec3.hpp>

//5.2 Box Klasse

class Box{ 
public:
	Box();
	Box(float area);
	Box(float volume);

//Variablen
	float area;
	float volume;

//Getter
	float getbarea() const;
	float getbvolume() const;


};
#endif
