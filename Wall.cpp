#include "Wall.h"


Wall::Wall()
{
	wall.setSize(sf::Vector2f(10.0f, 10.0f));
	wall.setOrigin(wall.getSize().x / 2, wall.getSize().y / 2);
	wall.setFillColor(sf::Color::Yellow);
}
Wall::Wall(sf::Vector2f pos)
{
	wall.setSize(sf::Vector2f(1000.0f, 1000.0f));
	wall.setOrigin(wall.getSize().x / 2, wall.getSize().y / 2);
	wall.setFillColor(sf::Color::Yellow);
	wall.setPosition(pos);
}

void Wall::MakeHeight()
{
	wall.setSize(sf::Vector2f(1920, 100));
	wall.setOrigin(wall.getSize().x / 2, wall.getSize().y / 2);
}

void Wall::MakeWidth()
{
	wall.setSize(sf::Vector2f(100, 1080));
	wall.setOrigin(wall.getSize().x / 2, wall.getSize().y / 2);
}