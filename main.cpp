#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Ant.h"
#include "TextureManager.h"
#include "Walls.h"
#include "Colony.h"
#include <math.h>
#include "FoodPiles.h"
#include "InputManager.h"
import Utils;

int main()
{
	bool simulation = false;
	InputManager manager;
	manager.operator>>(std::cin);

	TextureManager texM;
	int WINDOW_HEIGHT = 1080;
	int WINDOW_WIDTH = 1920;
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Ants", sf::Style::Default);
	sf::View view(sf::FloatRect(0, 0, 1920, 1080));
	window.setView(view);
	
	Walls obstacles;
	FoodPiles food;
	Colony colony(&texM, &manager);
	
	window.setFramerateLimit(120);

	sf::Clock deltaClock;

	sf::Vector2i PixelPos;
	sf::Vector2f MousePos;
	while (window.isOpen())
	{
		PixelPos = sf::Mouse::getPosition(window);
		MousePos = window.mapPixelToCoords(PixelPos, view);

		sf::Event evt;
		while (window.pollEvent(evt))
		{
			switch (evt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				view.move(sf::Vector2f(-10.0f, 0.0f));
				window.setView(view);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				view.move(sf::Vector2f(10.0f, 0.0f));
				window.setView(view);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				view.move(sf::Vector2f(0.0f, -10.0f));
				window.setView(view);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				view.move(sf::Vector2f(0.0f, 10.0f));
				window.setView(view);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				view.zoom(1.2f);
				window.setView(view);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			{
				view.zoom(0.8f);
				window.setView(view);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				simulation = true;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !simulation)
			{
				obstacles.AddWalls(MousePos);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && !simulation)
			{
				food.AddPiles(MousePos);
			}
			
		}

		sf::Time dt = deltaClock.restart();

		if (simulation == true)
		{
			colony.Reproduction(&texM);

			colony.Check(&obstacles, &dt, &food);
		}
		window.clear(sf::Color::White);
		colony.DrawColony(&window);
		food.DrawPiles(&window);
		obstacles.DrawWalls(&window);
		window.display();
	}
}