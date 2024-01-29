#include "PheromoneFood.h"

void PheromoneFood::DrawPheromone(sf::RenderWindow* window)
{
	window->draw(pher);
}

PheromoneFood::PheromoneFood(sf::Vector2f pos)
{
	pher.setSize(sf::Vector2f(4.0f, 4.0f));
	pher.setOrigin(pher.getSize().x / 2, pher.getSize().y / 2);
	pher.setFillColor(sf::Color::Red);
	pher.setPosition(pos);
}