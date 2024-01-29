#include "FoodPiles.h"

void FoodPiles::AddPiles(sf::Vector2f pos)
{
	FoodPile pile(pos);
	piles.push_back(pile);
}

void FoodPiles::DrawPiles(sf::RenderWindow* window)
{
	for (int i = 0; i < piles.size(); i++)
	{
		window->draw(piles[i].GetPile());
	}
}