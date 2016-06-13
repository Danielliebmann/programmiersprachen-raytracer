#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <math.h>
#include <cmath>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include "box.hpp"
#include "sphere.hpp"
#include "shape.hpp"

TEST_CASE("Aufgabe 5.2 SphereBox", "[SphereBox]")
{
	SECTION("Sphere")
	{
	Sphere a;
	glm::vec3 ctr_b{2.0, 4.2, -5.0};
	glm::vec3 ctr_a{1.0, 1.0, 1.0};
	Sphere b{ctr_b, 2.0};

	REQUIRE(glm::all(glm::equal(a.get_ctr(), ctr_a)));
	REQUIRE(a.get_srad() == Approx(0));
	REQUIRE(a.get_srad() == Approx(1.0));
	REQUIRE(a.area() == Approx(1*1*M_PI*4));
	REQUIRE(a.volu() == Approx((4/3)*M_PI*1*1*1));

	REQUIRE(glm::all(glm::equal(b.get_ctr(), ctr_b)));
	REQUIRE(b.get_srad() == Approx(2.0));
	REQUIRE(b.area() == Approx(2*2*M_PI*4));
	REQUIRE(b.volu() == Approx((4/3)*M_PI*2*2*2));
	}

}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
