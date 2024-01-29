#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "Ant.h"
#include <iostream>
#include <thread>
#include "Walls.h"
#include "FoodPiles.h"
#include "InputManager.h"
import Utils;
class Colony
{
	std::vector<Ant> colonyAnts;
	sf::RectangleShape colonyHeart;

public:
	void Reproduction(TextureManager* texM);
	Colony(TextureManager* texM, InputManager * i);
	std::vector<Ant> GetColony() { return colonyAnts; }
	void DrawColony(sf::RenderWindow* window);
	sf::RectangleShape GetHeart() { return colonyHeart; }
	void Check(Walls * walls, sf::Time* dt, FoodPiles* food);
	//void Simulation();
	void CreateColony(int amount, TextureManager* texM);
	

	
	
};

