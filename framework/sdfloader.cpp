#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include "scene.hpp"
#include "material.hpp"

Scene loadFromFile(std::string filename);

int main(int argc, char* argv[])
{
	std::string filePath = "../../../Szene/Szene.txt";
	Scene scene1 = loadFromFile(filePath);
	std::cout << "\nDer Container beinhaltet (Materials):\n" << std::endl;
	for (auto i : scene1.materials) { std::cout << "Key: " << i.first << "\n" << i.second << std::endl; }
}


// SceneLoader

int getNext(int curPos, std::string const& txt)
{
	return txt.find_first_of(" ", curPos);
}

Scene loadFromFile(std::string filename)
{
	Scene scene{};
	std::map<std::string,Material> materials; //Material >materials(map)

	std::ifstream file(filename);
	std::string line;

	while(std::getline(file, line))
	{
		// suche bis text beginnt
		auto begin = line.find_first_not_of(" ");
		line = line.substr(begin);

		std::vector<std::string> input;

		while(line.length() > 0)
		{
			int end = getNext(0, line);
			std::string cmd = line.substr(0, end);

			input.push_back(cmd);

			if (line.length() > 1 && end <= line.length()) { line = line.substr(end+1); }
			else { break; }
		}

		//AUsgabe des INputs

		//Was ist Material?
		if (input[0] == "define" && input[1] == "material")
		{
			std::string name = input[2];
			std::cout << "\nCreating material " << name << "...";

			Color ka = input.size() > 5 ? Color{std::stof(input[3]),std::stof(input[4]),std::stof(input[5])} : Color{0.0f,0.0f,0.0f};
			std::cout << "\nka: " << ka.r << "," << ka.g << "," << ka.b;

			Color kd = input.size() > 8 ? Color{std::stof(input[6]),std::stof(input[7]),std::stof(input[8])} : Color{0.0f,0.0f,0.0f};
			std::cout << "\nkd: " << kd.r << "," << kd.g << "," << kd.b;

			Color ks = input.size() > 11 ? Color{std::stof(input[9]),std::stof(input[10]),std::stof(input[11])} : Color{0.0f,0.0f,0.0f};
			std::cout << "\nks: " << ks.r << "," << ks.g << "," << ks.b;

			float exp = input.size() > 12 ? std::stof(input[12]) : 1.0f;
			std::cout << "\nm: " << exp;


			Material m{name,ka,kd,ks,exp}; //Neue Material
			materials[name] = m; //Map speichert die Material

			std::cout << "\n Fertig." << std::endl;
		}
	}

	scene.materials = materials;
	return scene;
}
