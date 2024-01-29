#pragma once
#include "Pheromone.h"

class PheromoneHome : public Pheromone
{
	sf::RectangleShape pher;
public:
	PheromoneHome(sf::Vector2f pos);
	void DrawPheromone(sf::RenderWindow* window);
	sf::FloatRect GetGlobalBounds() { return pher.getGlobalBounds(); }
	sf::Vector2f GetPosition() { return pher.getPosition(); }
};

