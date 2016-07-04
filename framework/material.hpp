#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <string>
#include "color.hpp"

struct Material
{
  Material(): //define
  name {""},
  ka ({0, 0 ,0}),
  kd ({0, 0 ,0}),
  ks ({0, 0 ,0}),
  m {0}
  {}
  
  Material(std::string const& name, Color const& ka, Color const& kd, Color const& ks, float const& m): //custom
  name {name},
  ka {ka},//Ambient
  kd {kd},//Diffuse
  ks {ks},//Specular
  m {m}//Exponent
  {}

//Variablen
  std::string name;
  Color ka;
  Color kd;
  Color ks;
  float m;

 friend std::ostream& operator<<(std::ostream& os, Material const& m)
  {
  os << m.name << "\n"
  << m.ka << "\n"
  << m.kd << "\n"
  << m.ks << "\n"
  << m.m << "\n";
  return os;
  }
};

std::ostream& operator <<(std::ostream& os, Material const& mat); //streamop <<

#endif
