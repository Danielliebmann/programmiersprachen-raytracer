#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include "color.hpp"
#include <iostream>

class Shape
{
public:
//DEfault KOnstruktor
  Shape();

//Eigener Konstruktor
  Shape(std::string const&, Color const&);

//Die Virtuelle Methode
  virtual float area() const = 0;	//pure virtual, no implementation on this level, override needed

  virtual float volume() const = 0;	//pure virtual, no implementation on this level, override needed

//The = 0; is also known as the "pure specifier". The virtual function does not have the value of 0 now.

//Get Methoden
std::string get_name_() const;
Color get_color_() const;

//Aufgabe 5.4 
  virtual std::ostream& print(std::ostream&) const;  //virtual, override possible


protected: //Geschützt für abgeleitete Klassen
  std::string name_;
  Color color_;
};

std::ostream& operator <<(std::ostream&, Shape const&);

#endif //#define SHAPE_HPP
