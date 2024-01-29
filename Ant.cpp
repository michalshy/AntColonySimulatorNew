#include "Ant.h"

Ant::Ant(TextureManager * texM)
{
	
	ant.setSize(sf::Vector2f(10.0f, 10.0f));
	ant.setTexture((texM->GetAntTex()));
	ant.setFillColor(sf::Color::Red);
	ant.setOrigin(sf::Vector2f(5.0f, 5.0f));
	ant.setRotation(RandomFloat(0,360));
	
}

void Ant::SetPosition(sf::Vector2f pos)
{
	ant.setPosition(pos);
}

void Ant::SetRotation(float angle)
{
	ant.setRotation(angle);
}

void Ant::Behaviour(sf::Time* dt, Walls * walls, FoodPiles* food)
{
	/*sf::FloatRect aBox;
	sf::FloatRect fBox;
	for (int i = 0; i < food->GetRef().size(); i++)
	{
		aBox = ant.getGlobalBounds();
		fBox = food->GetRef()[i].GetGlobalBounds();
		if (fBox.intersects(aBox) && (food->GetRef()[i].GetShortestFood().size() == 0 || food->GetRef()[i].GetShortestFood().size() > pathFood.size()))
		{

			food->GetRef()[i].SetShortestFood(pathFood);
			state = 1;
		}
		else if (fBox.intersects(aBox) && (food->GetRef()[i].GetShortestHome().size() == 0 || food->GetRef()[i].GetShortestHome().size() > pathHome.size()))
		{
			food->GetRef()[i].SetShortestHome(pathHome);

			state = 1;
		}
		else if (fBox.intersects(aBox) && food->GetRef()[i].GetShortestFood().size() != 0 && food->GetRef()[i].GetShortestFood().size() < pathFood.size())
		{
			pathFood = food->GetRef()[i].GetShortestFood();

			state = 1;


		}
		else if (fBox.intersects(aBox) && food->GetRef()[i].GetShortestHome().size() != 0 && food->GetRef()[i].GetShortestHome().size() < pathHome.size())
		{
			pathHome = food->GetRef()[i].GetShortestHome();
			state = 1;

		}
	}*/

	
	if(state == 0)
	{
		sf::Time elapsed1 = production.getElapsedTime();
		if (elapsed1.asSeconds() > 0.1 && !pathHomeCreated)
		{
			PheromoneHome pher(GetPos());
			pathHome.push_back(pher);
			production.restart();
		}
		sf::FloatRect antBox;
		sf::FloatRect wallBox;
		sf::Vector2f velo;
		sf::Vector2f pos;
		int collisions = 0;
		antBox = ant.getGlobalBounds();
		velo = sf::Vector2(speed * cos(DegreesToRadians(ant.getRotation())), speed * -sin(DegreesToRadians(ant.getRotation())));
		for (auto& wall : walls->GetWalls())
		{
			wallBox = wall.GetWall().getGlobalBounds();
			if (wallBox.intersects(antBox))
			{
				pos = sf::Vector2f((ant.getPosition().x - wall.GetPos().x) / 100, (ant.getPosition().y - wall.GetPos().y) / 100);

				collisions++;
			}
		}
		if (collisions != 0)
		{
			ant.setRotation(ant.getRotation() + RandomFloat(150, 210));
			ant.move(pos);

		}
		if (collisions == 0)
		{
			ant.setRotation(ant.getRotation() + RandomFloat(-10, 10));
			ant.move(sf::Vector2(speed * sin(DegreesToRadians(ant.getRotation())), speed * -cos(DegreesToRadians(ant.getRotation()))) * dt->asSeconds());
		}

		sf::FloatRect foodBox;
		for (int i = 0; i < food->GetRef().size(); i++)
		{

			foodBox = food->GetRef()[i].GetGlobalBounds();
			if (foodBox.intersects(antBox))
			{
				PheromoneFood pher(food->GetRef()[i].GetPos());
				pathFood.push_back(pher);
			}
			if (foodBox.intersects(antBox) && (food->GetRef()[i].GetShortestHome().size() == 0 || food->GetRef()[i].GetShortestHome().size() > pathHome.size()))
			{
				food->GetRef()[i].SetShortestHome(pathHome);
				pathHomeCreated = true;
				/*pile.Decrement();*/
				state = 1;
			}
			if (foodBox.intersects(antBox) && food->GetRef()[i].GetShortestHome().size() != 0 && food->GetRef()[i].GetShortestHome().size() < pathHome.size())
			{
				
				pathHome = food->GetRef()[i].GetShortestHome();
				pathHomeCreated = true;
				state = 1;
			}
			if (foodBox.intersects(antBox) && food->GetRef()[i].GetShortestFood().size() != 0 && (food->GetRef()[i].GetShortestFood().size() < pathFood.size()))
			{
				pathFood = food->GetRef()[i].GetShortestFood();
				state = 1;
			}
		}
	}
	if (state == 1)
	{
		sf::Time elapsed1 = production.getElapsedTime();
		if (elapsed1.asSeconds() > 0.1 && !pathFoodCreated)
		{
			PheromoneFood pher(GetPos());
			pathFood.push_back(pher);
			production.restart();
		}
		PheromoneHome target = pathHome[pathHome.size()-counter];
		sf::Vector2f antPos = ant.getPosition();
		sf::Vector2f targetPos = target.GetPosition();

		float angle = atan2(antPos.y - targetPos.y, antPos.x - targetPos.x) * 180 / 3.141;

		SetRotation(angle-60);
		ant.move(sf::Vector2(speed * sin(DegreesToRadians(ant.getRotation())), speed * -cos(DegreesToRadians(ant.getRotation()))) * dt->asSeconds());


		sf::FloatRect pathBox = target.GetGlobalBounds();
		sf::FloatRect antBox = ant.getGlobalBounds();
		sf::FloatRect homeBox = home.getGlobalBounds();
		
		if (antBox.intersects(pathBox) && counter != pathHome.size())
		{
			counter++;
		}
		if (antBox.intersects(homeBox))
		{
			foodGathered++;
			state = 2;
			counter = 1;
			pathFoodCreated = true;
		}
		
	}
	if (state == 2)
	{
		int basic = 0;
		PheromoneFood target = pathFood[pathFood.size() - counter];
		sf::Vector2f antPos = ant.getPosition();
		sf::Vector2f targetPos = target.GetPosition();

		float angle = atan2(antPos.y - targetPos.y, antPos.x - targetPos.x) * 180 / 3.141;

		SetRotation(angle - 60);
		ant.move(sf::Vector2(speed * sin(DegreesToRadians(ant.getRotation())), speed * -cos(DegreesToRadians(ant.getRotation()))) * dt->asSeconds());

		sf::FloatRect pathBox = target.GetGlobalBounds();
		sf::FloatRect antBox = ant.getGlobalBounds();
		sf::FloatRect foodBox;
		
		for (int i = 0; i < food->GetRef().size(); i++)
		{
			foodBox = food->GetRef()[i].GetGlobalBounds();
			if (foodBox.intersects(antBox) && (food->GetRef()[i].GetShortestFood().size() == 0 || food->GetRef()[i].GetShortestFood().size() > pathFood.size()))
			{
				food->GetRef()[i].SetShortestFood(pathFood);
				counter = 1;
				state = 1;
				basic = 1;
			}
			if (foodBox.intersects(antBox) && (food->GetRef()[i].GetShortestHome().size() == 0 || food->GetRef()[i].GetShortestHome().size() > pathHome.size()))
			{

				food->GetRef()[i].SetShortestHome(pathHome);
				pathHomeCreated = true;
				/*pile.Decrement();*/
				counter = 1;
				state = 1;
				basic = 1;
			}
			if (foodBox.intersects(antBox) && food->GetRef()[i].GetShortestHome().size() != 0 && food->GetRef()[i].GetShortestHome().size() < pathHome.size())
			{
				pathHome = food->GetRef()[i].GetShortestHome();
				pathHomeCreated = true;
				counter = 1;
				state = 1;
				basic = 1;
			}
			if (foodBox.intersects(antBox) && food->GetRef()[i].GetShortestFood().size() != 0 && (food->GetRef()[i].GetShortestFood().size() < pathFood.size() || pathFood.size() < 3))
			{
				pathFood = food->GetRef()[i].GetShortestFood();
				counter = 1;
				state = 1;
				basic = 1;
			}
			if (foodBox.intersects(antBox) && basic == 0)
			{
				counter = 1;
				state = 1;
			}
		}
		if (antBox.intersects(pathBox) && counter != pathFood.size())
		{
			counter++;
		}
		
	}
	
	
}
void Ant::SetSpeed(float _speed)
{
	speed = _speed;
}

void Ant::SetMove(sf::Vector2f mov)
{
	ant.move(mov);
}


