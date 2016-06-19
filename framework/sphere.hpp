#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
#include <iostream>
#include "shape.hpp"
#include "color.hpp"
#include "ray.hpp"

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
//5.6
void center(glm::vec3 const& ctr);
void radius(float const& rad);

bool intersect(Ray const&, float&);

//5.5
std::ostream& print(std::ostream& os) const override;

private:
//Variablen
  float radius_;
  glm::vec3 center_;

};
#endif //#define SPHERE_HPP
