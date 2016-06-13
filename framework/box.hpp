#ifndef BOX_HPP
#define BOX_HPP
#include <math.h>
#include <cmath>
#include <glm/vec3.hpp>
#include "shape.hpp"

//5.2 Box Klasse

class Box : public Shape
{ 
public:
	Box(); 
	Box(glm::vec3 const& max, glm::vec3 const& min);
	
//Getter
	glm::vec3 const& min() const; //automatische Erkennung des Dateityps
	glm::vec3 const& max() const;
	
	float area() const override;
	float volu() const override;

//setter
	glm::vec3 set_min();
	glm::vec3 set_max();
	



};
#endif
