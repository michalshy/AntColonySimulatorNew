#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
class Pheromone
{
public:
	virtual void DrawPheromone(sf::RenderWindow * window) = 0;
	virtual sf::FloatRect GetGlobalBounds() = 0;
};

