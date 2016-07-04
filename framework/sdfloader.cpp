#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include "material.hpp"
#include <sstream>

int main()
{
  //aufruf des Files
  std::string line;
  std::ifstream myfile ("../Szene/Szene.txt");
  std::map<std::string,Material> materials;
  //solange
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
//
      std::cout << line << '\n';
      std::stringstream ss;
	ss << line;
	Material mat;
	std::string keyword;
	ss>>keyword;
	ss>>keyword;
	ss>>mat.name;
	ss>>mat.ka.r;
	ss>>mat.ka.g;
        ss>>mat.ka.b;
	ss>>mat.ks.r;
	ss>>mat.ks.g;
        ss>>mat.ks.b;
	ss>>mat.kd.r;
	ss>>mat.kd.g;
        ss>>mat.kd.b;
	ss>>mat.m;
	materials[mat.name]= mat;
	std::cout << mat;
    }
    myfile.close();
  }

  else std::cout << "Unable to open file"; 

  return 0;
}
