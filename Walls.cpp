#include "Walls.h"
void Walls::AddWalls(sf::Vector2f pos)
{
	Wall wall(pos);
	walls.push_back(wall);
}

void Walls::AddWallsHeight(sf::Vector2f pos)
{
	Wall wall(pos);
	wall.MakeHeight();
	walls.push_back(wall);
}

void Walls::AddWallsWidth(sf::Vector2f pos)
{
	Wall wall(pos);
	wall.MakeWidth();
	walls.push_back(wall);
}


void Walls::DrawWalls(sf::RenderWindow* window)
{
	for (int i = 0; i < walls.size(); i++)
	{
		window->draw(walls[i].GetWall());
	}
}

