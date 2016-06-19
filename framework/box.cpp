#include "box.hpp"
#include <cmath>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <shape.hpp>
//Default Konstruktor
Box::Box():
  Shape (std::string ("box"), {0, 0, 0}),
  min ({0, 0, 0}),
  max ({0, 0, 0})
  {}
//Eigener Konstruktor
Box::Box(std::string const& name_, Color const& color_, glm::vec3 const& min, glm::vec3 const& max):
  Shape(name_, color_),
  min (min),
  max (max)
  {}

//Get Methoden
 //Für Min
glm::vec3 Box::get_boxmin() const
{
  return min;
}

 //Für Max
glm::vec3 Box::get_boxmax() const
{
  return max;
}

//Volumen
float Box::volume() const
{
	float x = abs(max.x - min.x);
	float y = abs(max.y - min.y);
	float z = abs(max.z - min.z);

	return x*y*z;
}

//Flächeninhalt
float Box::area() const
{
	float x = abs(max.x - min.x);
	float y = abs(max.y - min.y);
	float z = abs(max.z - min.z);

	return 2*(x*y + x*z + y*z);
}

//5.5
std::ostream& Box::print(std::ostream& os) const
{
 os << name_ << std::endl;
 os << color_ << std::endl;
} 