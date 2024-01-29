#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Wall.h"
class Walls
{
	std::vector<Wall> walls;
public:

	std::vector<Wall> GetWalls() { return walls; }

	void DrawWalls(sf::RenderWindow* window);

	void AddWalls(sf::Vector2f pos);

	void AddWallsHeight(sf::Vector2f pos);

	void AddWallsWidth(sf::Vector2f pos);
};

