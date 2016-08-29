#ifndef _HPP	
#define SOURCE_HPP

#include <glm/glm.hpp>
#include <glm/vec3.hpp>

class Source
{
public:

  Source();

  virtual glm::vec3 getlightpos() { return glm::vec3(0, 0, 0); }
  virtual Colour getlightcolour() { return Colour(1, 1, 1, 0); }

};

Source::Source() {}

#endif
