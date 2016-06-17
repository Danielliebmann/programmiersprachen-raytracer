#include "sphere.hpp"
#include <cmath>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <shape.hpp>
#define M_PI 3.14159265358979323846

//Default Konstruktor
Sphere::Sphere():
  Shape (std::string ("sphere"), {0, 0, 0}),
  center ({0, 0, 0}),
  radius (0)
  {}

//Eigener Konstruktor
Sphere::Sphere(std::string const& name_, Color const& color_, glm::vec3 const& center, float radius):
  Shape (name_, color_),
  center (center),
  radius (radius)
  {}

//Get Methoden
//Radius
float Sphere::get_sphereradius() const
{
  return radius;
}

//Mittelpunkt
glm::vec3& Sphere::get_spherecenter()
{
  return center;
}

//VOlumen
float Sphere::volume() const
{
  return (4/3*M_PI*radius*radius*radius);
}

//Flächeninhalt
float Sphere::area() const
{
  return (4*M_PI*radius*radius);
}

std::ostream& Sphere::print(std::ostream& os) const
{
 os << name_ << std::endl;
 os << color_ << std::endl;
} 

