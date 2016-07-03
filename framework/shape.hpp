#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
#include <string>
#include <iostream>
#include "color.hpp"
#include "material.hpp"
#include "ray.hpp"


class Shape
{
public:
//DEfault KOnstruktor
  Shape();
 

//Eigener Konstruktor
  Shape(std::string const&, Material const&);
//6.3
virtual bool intersect(Ray const& ray, float& t) = 0;

//5.8 destruktor
virtual ~Shape();

//Die Virtuelle Methode
  virtual float area() const = 0;	
//pure virtual, no implementation on this level, override needed

  virtual float volume() const = 0;	

//The = 0; is also known as the "pure specifier". The virtual function does not have the value of 0 now.

//Get Methoden
std::string get_name_() const;
Material get_material() const;

//Aufgabe 5.4 
  virtual std::ostream& print(std::ostream&) const;  //virtual, override possible

//5.5 für abgeleitete Klassen
protected: //kann im Gegensatz zu private auch von abgeleiteten Klassen benutzt werden
  std::string name_;
  Material mat;
};
//5.4
std::ostream& operator <<(std::ostream&, Shape const&);

#endif //#define SHAPE_HPP
