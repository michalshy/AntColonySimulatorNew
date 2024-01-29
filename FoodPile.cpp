#include "FoodPile.h"

FoodPile::FoodPile(sf::Vector2f pos)
{
	pile.setSize(sf::Vector2f(50.0f, 50.0f));
	pile.setOrigin(pile.getSize().x / 2, pile.getSize().y / 2);
	pile.setFillColor(sf::Color::Green);
	pile.setPosition(pos);
}
