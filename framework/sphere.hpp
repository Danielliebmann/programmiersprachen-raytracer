#ifndef SPHERE_HPP
#define SPHERE_HPP
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <shape.hpp>


//AUFGABE 5.2
class Sphere : public Shape
{
public:
//default Constructor
  Sphere();

//custom constructor
  Sphere(glm::vec3 const&, float);

//getter
float get_sphereradius() const;
glm::vec3& get_spherecenter();

float volume() const override;
float area() const override;

//setter
//float set_sphereradius(float nradius);
//glm::vec3 set_spherecenter(glm::vec3 center)

private:
//variablen
  float radius;
  glm::vec3 center;

};
#endif //#define SPHERE_HPP
