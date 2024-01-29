#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
class Wall
{
	sf::RectangleShape wall;
public:
	Wall();
	Wall(sf::Vector2f pos);
	void MakeHeight();
	void MakeWidth();
	sf::Vector2f GetPos() { return wall.getPosition(); }
	sf::FloatRect GetGlobalBounds() { return wall.getGlobalBounds(); }
	sf::RectangleShape GetWall() { return wall; }
};

