#include "box.hpp"
#include <cmath>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <shape.hpp>
#include "material.hpp"
 

//Default Konstruktor
Box::Box():
  Shape (std::string ("box"), {}),
  min ({0, 0, 0}),
  max ({0, 0, 0})
  {}
//Eigener Konstruktor
Box::Box(std::string const& name_, Material const& mat, glm::vec3 const& min, glm::vec3 const& max):
  Shape(name_, mat),
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
 os << mat << std::endl;
} 
//6.3
bool Box::intersect(Ray const& ray, float& t)
{
  glm::vec3 lichtbruch{1.0f,1.0f,1.0f};

//Lichtbrechung, wenn der Ray auf ein Objekt trifft und "weitergeleitet" wird!
  lichtbruch.x = 1.0f / ray.direction.x;
  lichtbruch.y = 1.0f / ray.direction.y;
  lichtbruch.z = 1.0f / ray.direction.z;
// 1:0 = unendlich

//x
  float rp1 = (min.x - ray.origin.x)*lichtbruch.x; //Neue Origin
  float rp2 = (max.x - ray.origin.x)*lichtbruch.x; //Origin ist der Startpunkt, direction die Richtung
std::cout << rp1 << std::endl;
std::cout << rp2 << std::endl;
//y
  float rp3 = (min.y - ray.origin.y)*lichtbruch.y;
  float rp4 = (max.y - ray.origin.y)*lichtbruch.y;
std::cout << rp3 << std::endl;
std::cout << rp4 << std::endl;
//z
  float rp5 = (min.z - ray.origin.z)*lichtbruch.z;
  float rp6 = (max.z - ray.origin.z)*lichtbruch.z;
std::cout << rp5 << std::endl;
std::cout << rp6 << std::endl;

//rp 1-6 werden durchgeprüft, die größte Zahl zwischen den minimalen Wertepaaren ist tmin
float tmin = std::max(std::max(std::min(rp1, rp2), std::min(rp3, rp4)), std::min(rp5, rp6));
//rp 1-6 werden druchgeprüft, die kleinste Zahl zwischen den maximalen Wertepaaren ist tmax
float tmax = std::min(std::min(std::max(rp1, rp2), std::max(rp3, rp4)), std::max(rp5, rp6));

//
  if (tmin > tmax)
  {
    t = tmax;
    return false; //nicht gebrochen
  }

  t = tmin;
  return true; //wird gebrochen, da mit eingebenen t übereinstimmt

}
