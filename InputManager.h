#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <filesystem>
class InputManager
{
	int size = 0;
public:
	InputManager();
	int GetSize() { return size; }
	void SetSize(int i) { size = i; }
	std::istream& operator >> (std::istream& in)
	{
		std::string pathToFile = "C:\\Users\\Michin\\Desktop\\projekty\\neural network\\Neural Network\\data\\colony.json";
		std::filesystem::path p{ pathToFile };
		if (!std::filesystem::exists(p))
		{
			std::cout << "Path doesnt exist!";
		}
		else
		{
			std::ifstream file;
			file.open(pathToFile);
			std::string line;
			int it = 0;
			int s = 0;
			while (std::getline(file, line))
			{
				if (it % 2 == 1)
				{
					std::regex rgx("[0-9]+");
					std::smatch match;
					std::regex_search(line, match, rgx);
					size = std::stoi(match[0]);
				}
				it++;

			}
		}
		return in;

	}
};


