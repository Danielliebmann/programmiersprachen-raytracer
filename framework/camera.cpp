#include <glm/glm.hpp>
#include <glm/vec3.hpp>

#include "camera.hpp"

Camera::Camera():
  campos ({0, 0, 0}),
  camdir ({0, 0, 1}),
  camright ({0, 0, 0}),
  camdown ({0, 0, 0})
  {}

Camera::Camera(glm::vec3 const campos, glm::vec3 constcamdir,
		glm::vec3 const camright, glm::vec3 const camdown):
  campos (campos),
  camdir (camdir),
  camright (camright),
  camdown (camdown)
  {}

glm::vec3 Camera::getcampos() const
{
  return campos;
}
glm::vec3 Camera::getcamdir() const
{
  return camdir;
}
glm::vec3 Camera::getcamright() const
{
  return camright;
}
glm::vec3 Camera::getcamdown() const
{
  return camdown;
}

