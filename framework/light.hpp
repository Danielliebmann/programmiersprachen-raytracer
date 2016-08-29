#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <glm/glm.hpp>

#include "source.hpp"
#include "colour.hpp"

class Light : public Source
{
public:

  Light();

  Light(glm::vec3, Colour);

  //getter
  virtual glm::vec3 getlightpos() { return position; }
  virtual Colour getlightcolour() { return colour; }

private:
  glm::vec3 position;
  Colour colour;
};

Light::Light():
  position ({0, 0, 0}),
  colour ({1, 1, 1, 0})
  {}

Light::Light(glm::vec3 const& p, Colour const& c):
  position (p),
  colour (c)
  {}

#endif
