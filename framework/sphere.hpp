#ifndef SPHERE_HPP
#define SPHERE_HPP
#include <math.h>
#include <cmath>
#include <glm/vec3.hpp>
#include "shape.hpp"

//5.2 Sphere Klasse

class Sphere : public Shape
{
public:
	Sphere();
	Sphere(glm::vec3 const& ctr, float rad);

//Getter
	glm::vec3 const& get_ctr() const;
	float get_srad() const;
	float get_svolu() const;
	float area() const override;
	float volu() const override;

//Setter
	float set_srad(float nsrad);

};
#endif
