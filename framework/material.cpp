#include "material.hpp"

Material::Material(): //define
  name {""},
  ka ({0, 0 ,0}),
  kd ({0, 0 ,0}),
  ks ({0, 0 ,0}),
  m {0}
  {}

Material::Material(std::string const& name, Color const& ka, Color const& kd, Color const& ks, float const& m): //custom
  name {name},
  ka {ka},//Ambient
  kd {kd},//Diffuse
  ks {ks},//Specular
  m {m}//Exponent
  {}

//print
std::ostream& Material::print(std::ostream& os) const
{
  os << name << "\n"
  << ka << "\n"
  << kd << "\n"
  << ks << "\n"
  << m  << "\n";
  return os;
}
//<< operator
std::ostream& operator << (std::ostream& os, Material const& mat) {
	return mat.print(os);
}
