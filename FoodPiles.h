#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "FoodPile.h"


class FoodPiles
{
	std::vector<FoodPile> piles;
public:
	std::vector<FoodPile> GetPiles() { return piles; }
	std::vector<FoodPile> & GetRef() { return piles; }
	void DrawPiles(sf::RenderWindow* window);
	void AddPiles(sf::Vector2f pos);
};

