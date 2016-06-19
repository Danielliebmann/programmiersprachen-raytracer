//Für 4.3 Color
#include <shape.hpp>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
#include <iostream>

//DEfault Konstruktor
Shape::Shape():
  name_ (""),
  color_ ({0, 0 ,0})
  {}

//Eigener KOnstruktor
Shape::Shape(std::string const& name_, Color const& color_):
  name_(name_),
  color_ (color_)
  {}

//5.8 Destruktor
 Shape::~Shape()
{
	std::cout << "Destruktor Shape" << std::endl;
}


//GET
//für Namen
std::string Shape::get_name_() const
{
  return name_;
}
//Für Color
Color Shape::get_color_() const
{
  return color_;
}

//5.4
std::ostream& Shape::print(std::ostream& os) const
{
 os << name_ << std::endl;
 os << color_ << std::endl;
} 

std::ostream& operator <<(std::ostream& os, Shape const& s)
{
  return s.print(os);
}
