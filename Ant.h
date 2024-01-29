#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "TextureManager.h"
#include "Walls.h"
#include "FoodPiles.h"
#include "PheromoneFood.h"
#include "PheromoneHome.h"
import Utils;
class Ant
{
	sf::RectangleShape ant;
	float speed = 100.0f;
	std::vector<PheromoneFood> pathFood;
	std::vector<PheromoneHome> pathHome;
	int state = 0; //0-scattering,1-taking food home,2-following path to food
	int counter = 1; //counter for tracking vectors
	sf::Clock production; //clock for pheromone production
	bool pathHomeCreated = false;
	bool pathFoodCreated = false;
	sf::RectangleShape home;
public:
	void SetHome(sf::RectangleShape _home) { home = _home; }
	sf::RectangleShape GetHome() { return home; }
	Ant(TextureManager * texM);
	float GetRotation() { return ant.getRotation(); }
	float GetSpeed() { return speed; }
	sf::Vector2f GetPos() { return ant.getPosition(); }
	sf::FloatRect GetGlobalBounds() { return ant.getGlobalBounds(); }
	void SetPosition(sf::Vector2f pos);
	void SetRotation(float angle);
	void SetSpeed(float _speed);
	void SetMove(sf::Vector2f mov);
	void Behaviour(sf::Time* dt, Walls * walls, FoodPiles * food);
	sf::RectangleShape GetAnt() { return ant; }
	std::vector<PheromoneFood> GetPathHome() { return pathFood; }
	std::vector<PheromoneHome> GetPathFood() { return pathHome; }
};

