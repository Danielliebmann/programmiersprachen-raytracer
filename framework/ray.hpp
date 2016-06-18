
#include <glm/vec3.hpp>


struct Ray
{
	Ray();
	Ray(glm::vec3 const& origin, glm::vec3 const& direction):
	 origin_{origin};
	 direction_{direction};
	 {}
	
	glm::vec3 origin_;
	glm::vec3 direction_;

};
