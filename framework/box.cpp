#include "box.hpp"
#include <cmath>

Box::Box(float area):
area_{area}{}

Box::Box(float volu):
volu_{volu}{}

//Getter
float Box::get area(){
	return area_;}

float Box::get volume(){
	return volume_;}
