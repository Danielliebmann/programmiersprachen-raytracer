#ifndef SCENE_HPP
#define SCENE_HPP

#include <string>
#include <map>
#include <memory>
#include "shape.hpp"
#include "material.hpp"

struct Scene
{
	std::vector<std::shared_ptr<Shape>> shapes;
	std::map<std::string,Material> materials; //Map um Materials zu speichern
};

#endif
