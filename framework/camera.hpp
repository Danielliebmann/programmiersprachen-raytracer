#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/vec3.hpp>

class Camera
{
public:
//Default constructor
  Camera();

//custom constructor
  Camera(glm::vec3 const, glm::vec3 const, glm::vec3 const, glm::vec3 const);

//getter, koennte man auch alles in der HPP machen
glm::vec3 getcampos() const;
glm::vec3 getcamdir() const;
glm::vec3 getcamright() const;
glm::vec3 getcamdown() const;

private:
  glm::vec3 campos;
  glm::vec3 camdir;
  glm::vec3 camright;
  glm::vec3 camdown;
};

#endif //#define CAMERA_HPP
