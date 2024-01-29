#pragma once
#include "Pheromone.h"


class PheromoneFood : public Pheromone
{
	sf::RectangleShape pher;
public:
	PheromoneFood(sf::Vector2f pos);
	void DrawPheromone(sf::RenderWindow* window);
	sf::FloatRect GetGlobalBounds() { return pher.getGlobalBounds(); }
	sf::Vector2f GetPosition() { return pher.getPosition(); }
};

