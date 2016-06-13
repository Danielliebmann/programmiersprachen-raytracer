#include "box.hpp"
#include <cmath>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include "shape.hpp"

//Default-Konstruktor
Box::Box(): 
min({0,0,0}), 
max({0,0,0}) 
{}

//Custom-Konstruktor
Box::Box(glm::vec3 const& min, glm::vec3 const& max): 
min(min), 
max(max) 
{} 

//Getter
glm::vec3 Box::get_bmin() const{
return min;
}
glm::vec3 Box::get_bmax() const{
return max;
}

float Box::volu() const{ //abs für negatives
	float x = abs(max.x - min.x);
	float y = abs(max.y - min.y);
	float z = abs(max.z - min.z);

	return x*y*z;
}
float Box::area() const{
	float x = abs(max.x - min.x);
	float y = abs(max.y - min.y);
	float z = abs(max.z - min.z);

	return 2*(x*y + x*z + y*z);

}


