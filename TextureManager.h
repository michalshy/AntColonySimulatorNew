#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class TextureManager
{
	sf::Texture ant;


public:
	TextureManager();

	sf::Texture* GetAntTex() { return &ant; }


};

