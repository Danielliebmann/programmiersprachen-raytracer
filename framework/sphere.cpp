#include "sphere.hpp"
#include <cmath>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <shape.hpp>
#define M_PI 3.14159265358979323846
#include <iostream>
#include "material.hpp"

//Default Konstruktor
Sphere::Sphere():
  Shape (std::string ("sphere"), {}),
  center_ ({0, 0, 0}),
  radius_ (0)
  {
	std::cout << "Konstruktor Sphere" << std::endl;
  }

//Eigener Konstruktor
Sphere::Sphere(std::string const& name_, Material const& mat, glm::vec3 const& center, float radius):
  Shape (name_, mat),
  center_ (center),
  radius_ (radius)
  {
	std::cout << "Destruktor Sphere" << std::endl;	
  }

//5.8 Destruktor
Sphere::~Sphere()
{
	std::cout << "Destruktor Sphere" << std::endl;
}

//Get Methoden
//Radius
float Sphere::get_sphereradius() const
{
  return radius_;
}

//Mittelpunkt
glm::vec3& Sphere::get_spherecenter()
{
  return center_;
}

//VOlumen
float Sphere::volume() const
{
  return (4/3*M_PI*radius_*radius_*radius_);
}

//Flächeninhalt
float Sphere::area() const
{
  return (4*M_PI*radius_*radius_);
}
//5.5
std::ostream& Sphere::print(std::ostream& os) const
{
 os << name_ << std::endl;
 os << mat << std::endl;
} 

//5.6
bool Sphere::intersect(Ray const& ray, float& distance) {
	return glm::intersectRaySphere(ray.origin, ray.direction, center_, radius_, distance);
}


