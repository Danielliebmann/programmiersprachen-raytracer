//Für 4.3 Color
#include <shape.hpp>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
#include <iostream>
#include "material.hpp"

//DEfault Konstruktor
Shape::Shape():
  name_ (""),
  mat {}
  {
	std::cout << "Konstruktor Shape" << std::endl;
  }

//Eigener KOnstruktor
Shape::Shape(std::string const& name_, Material const& mat):
  name_(name_),
  mat (mat)
  {
	std::cout << "Konstruktor Shape" << std::endl;
  }

//5.8 Destruktor
//Bei Aufruf ohne virtual(.hpp) wird das Shape Objekt mit dem Destruktor von Shape bearbeitet und nicht dem von 
//Sphere, da er keinen Zugriff mehr auf den Sphere Destruktor hat. (Deshalb fehlt die Ausgabe von Sphere")
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
Material Shape::get_material() const
{
  return mat;
}

//5.4
std::ostream& Shape::print(std::ostream& os) const //& call-by-reference
//Anstatt zu kopieren, werden Referenzen auf die Datei übergeben. Aufruf + Funktion zeigen auf selbes Objekt und arbeiten auch mit demselbigen, dass außerhalb sichtbar ist.
{
 os << name_ << std::endl;
 os << mat << std::endl;
} 

std::ostream& operator <<(std::ostream& os, Shape const& s)
{
  return s.print(os);
}
