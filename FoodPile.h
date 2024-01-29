#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "PheromoneFood.h"
#include "PheromoneHome.h"
class FoodPile
{
	sf::RectangleShape pile;
	int amount = 1;

	std::vector<PheromoneFood> shortestFood;
	std::vector<PheromoneHome> shortestHome;
public:
	FoodPile();
	FoodPile(sf::Vector2f pos);
	sf::Vector2f GetPos() { return pile.getPosition(); }
	sf::FloatRect GetGlobalBounds() { return pile.getGlobalBounds(); }
	sf::RectangleShape GetPile() { return pile; }
	void Decrement() { amount--; }
	int GetAmount() { return amount; }

	std::vector<PheromoneHome> & GetShortestHome() { return shortestHome; }
	std::vector<PheromoneFood> & GetShortestFood() { return shortestFood; }
	void SetShortestFood(std::vector<PheromoneFood>& temp) { shortestFood = temp; }
	void SetShortestHome(std::vector<PheromoneHome>& temp) { shortestHome = temp; }
};

