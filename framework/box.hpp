#ifndef BOX_HPP
#define BOX_HPP

#include <glm/glm.hpp>
#include <glm/vec3.hpp>

#include "shape.hpp"
#include "color.hpp"

class Box : public Shape
{
public:
//Default Konstruktor
  Box();

//Eigener Konstruktor
  Box(std::string const&, Color const&, glm::vec3 const&, glm::vec3 const&); //const& points directly at the object, no copy!

//Get Methoden
glm::vec3 get_boxmin() const;
glm::vec3 get_boxmax() const;

float get_boxlength() const;
float get_boxwidth() const;
float get_boxheight() const;

float volume() const override;
float area() const override;

//AUfgabe 5.5 Print
std::ostream& print(std::ostream& os) const override;

//Set Methoden
glm::vec3 set_boxmin();
glm::vec3 set_boxmax();

private:
//variablen

  glm::vec3 min;
  glm::vec3 max;
};

#endif //#define BOX_HPP
