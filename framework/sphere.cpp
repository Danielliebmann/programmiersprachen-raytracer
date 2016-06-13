#include "sphere.hpp"
#include <cmath>
#include <glm/vec3.hpp>



//Default-Konstruktor
Sphere::Sphere();
	ctr ({0,0,0});
	rad ({0});
	{}

//Custom-Konstruktor
Sphere::Sphere(float rad, glm::vec3 const& ctr)
	ctr (ctr),
	rad (rad)
	{} //gibt rad einen Value

//Getter
//Center
glm::vec3 Sphere::get_ctr() const{
return ctr;
}
//Radius
float Sphere::get_srad() const{
return rad;
}
//Volumen
float Sphere::volu() const{
return (4/3*M_PI*rad*rad*rad);
}
//Fläche
float Sphere::area() const{
return (4*M_PI*rad*rad);
}


