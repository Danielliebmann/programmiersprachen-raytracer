#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <shape.hpp>
#include "color.hpp"

class Sphere : public Shape
{
public:
//Default Konstruktor
  Sphere();

//Eigener Konstruktor
  Sphere(std::string const&, Color const&, glm::vec3 const&, float);

//Get Methoden
float get_sphereradius() const;
glm::vec3& get_spherecenter();

float volume() const override;
float area() const override;
std::ostream& print(std::ostream& os) const override;

private:
//Variablen
  float radius;
  glm::vec3 center;

};
#endif //#define SPHERE_HPP
