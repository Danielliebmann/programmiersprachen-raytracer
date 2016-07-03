#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>

#include "sphere.hpp"
#include "box.hpp"
#include "shape.hpp"
#include "ray.hpp"
#include "material.hpp"



int main(int argc, char *argv[])
{


  return Catch::Session().run(argc, argv);
}

