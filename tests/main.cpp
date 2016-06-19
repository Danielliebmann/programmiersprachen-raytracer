#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>

#include "sphere.hpp"
#include "box.hpp"
#include "shape.hpp"
#include "ray.hpp"


//AUfgabe 6 intersect

TEST_CASE("intersectRaySphere", "[5.6intersect]")
{
	//RAY
	glm::vec3 ray_origin{0.0,0.0,0.0};
	// ray direction has to be normalized!
	// you can use: v = glm:: normalize(vector)
	glm::vec3 ray_direction{0.0,0.0,1.0};

	//Sphere
	glm::vec3 sphere_center{0.0,0.0,5.0};
	float sphere_radius{1.0};

	float distance {0.0};

	auto result = glm::intersectRaySphere(
	ray_origin, 
	ray_direction, 
	sphere_center, 
	sphere_radius, 
	distance);
	REQUIRE(distance == Approx(4.0f));
}


//sphere tests
TEST_CASE("Spheredefault","[5.2 SDEF]")
{
  Sphere def;
  glm::vec3 center_default{0, 0, 0};

  REQUIRE(glm::all (glm::equal(def.get_spherecenter(), center_default)));
  REQUIRE(def.get_sphereradius() == Approx(0));
  REQUIRE(def.volume() == Approx(0));
  REQUIRE(def.area() == Approx(0));
}

TEST_CASE("Spherecustom","[5.2 SCUST]")
{
  Sphere cus {"Sphere1", {1, 0, 0}, {3, 4, 5}, 5};
  glm::vec3 center_custom{3, 4, 5};
  Color color_red{1, 0, 0};

  REQUIRE(glm::all (glm::equal(cus.get_spherecenter(), center_custom)));
  REQUIRE(cus.get_sphereradius() == Approx(5));
  REQUIRE(cus.volume() == Approx(4/3*M_PI*5*5*5));
  REQUIRE(cus.area() == Approx(4*M_PI*5*5));

}

//box tests
TEST_CASE("Boxdefault","[5.2 BDEF]")
{
  Box def;
  glm::vec3 min_default{0, 0, 0};
  glm::vec3 max_default{0, 0, 0};

  REQUIRE(glm::all (glm::equal(def.get_boxmin(), min_default)));
  REQUIRE(glm::all (glm::equal(def.get_boxmax(), max_default)));
  REQUIRE(def.volume() == Approx(0));
  REQUIRE(def.area() == Approx(0));
}

TEST_CASE("Boxcustom","[5.2 BCUST]")
{
  Box cus {"Box1", {1, 0, 0}, {1, 1, 1},{3, 2, 3}};
  glm::vec3 min_custom{1, 1, 1};
  glm::vec3 max_custom{3, 2, 3};
  Color color_red{1, 0, 0};

  REQUIRE(glm::all (glm::equal(cus.get_boxmin(), min_custom)));
  REQUIRE(glm::all (glm::equal(cus.get_boxmax(), max_custom)));
  REQUIRE(cus.volume() == Approx(4));
  REQUIRE(cus.area() == Approx(16));
}
//Aufgabe 5 Tests
TEST_CASE("AusgabeBoxSphere","[5.5 Output]")
{
  Box cus1 {"Box1", {1, 0, 0}, {1, 1, 1},{3, 2, 3}};
  Sphere cus2 {"Sphere1", {1, 0, 0}, {2, 2, 4}, 3};

  std::cout << cus1;
  std::cout << cus2 << std::endl; 
}

//Aufgabe 8 Destruktor
TEST_CASE("Destruktor", "[5.8 Destruktor]"){
	Color red (255, 0, 0);
	glm::vec3 position (0, 0, 0);
	Sphere * s1 = new Sphere ("sphere0", red, position, 1.2); //musste ich nach der KLasse anordnen
	Shape * s2 = new Sphere ("sphere0", red, position, 1.2);
	s1 -> print (std::cout);
	s2 -> print (std::cout);
	delete s1;
	delete s2;
}

int main(int argc, char *argv[])
{

  return Catch::Session().run(argc, argv);
}



