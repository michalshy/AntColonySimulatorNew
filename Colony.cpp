#include "Colony.h"


void Colony::CreateColony(int amount, TextureManager* texM)
{
	for (int i = 0; i < amount; i++)
	{
		Ant ant(texM);
		ant.SetPosition(colonyHeart.getPosition());
		ant.SetHome(colonyHeart);
		colonyAnts.push_back(ant);
	}
}

Colony::Colony(TextureManager* texM, InputManager * i)
{
	colonyHeart.setSize(sf::Vector2f(100.0f,100.0f));
	colonyHeart.setOrigin(colonyHeart.getSize().x / 2,colonyHeart.getSize().y/2);
	colonyHeart.setPosition(sf::Vector2f(950.0f, 500.0f));
	colonyHeart.setFillColor(sf::Color::Cyan);	
	int size = i->GetSize();
	CreateColony(size, texM);
}



void Colony::DrawColony(sf::RenderWindow* window)
{
	window->draw(colonyHeart);
	for (auto& ant : colonyAnts)
	{
		window->draw(ant.GetAnt());
		
	}
}

//void Colony::Simulation()
//{
//	for (auto& ant : colonyAnts)
//	{
//		ant.Behaviour();
//	}
//}


void Colony::Check(Walls* walls, sf::Time* dt, FoodPiles* food)
{
	auto Thread1 = [=](sf::Time* dt, Walls* walls)
	{

		for (int i = 0; i < colonyAnts.size() / 6; i++)
		{
			colonyAnts[i].Behaviour(dt, walls, food);
		}
	};

	auto Thread2 = [=](sf::Time* dt, Walls* walls)
	{
		for (int i = colonyAnts.size() / 6; i < colonyAnts.size() / 3; i++)
		{
			colonyAnts[i].Behaviour(dt, walls, food);
		}
	};

	auto Thread3 = [=](sf::Time* dt, Walls* walls)
	{
		for (int i = colonyAnts.size() / 3; i < colonyAnts.size() / 2; i++)
		{
			colonyAnts[i].Behaviour(dt, walls, food);
		}
	};

	auto Thread4 = [=](sf::Time* dt, Walls* walls)
	{
		for (int i = (colonyAnts.size() / 2); i < (colonyAnts.size()/3)*2; i++)
		{
			colonyAnts[i].Behaviour(dt, walls, food);
		}
	};

	auto Thread5 = [=](sf::Time* dt, Walls* walls)
	{
		for (int i = (colonyAnts.size()/3)*2; i < colonyAnts.size()-(colonyAnts.size()/6); i++)
		{
			colonyAnts[i].Behaviour(dt, walls, food);
		}
	};

	auto Thread6 = [=](sf::Time* dt, Walls* walls)
	{
		for (int i = colonyAnts.size() - (colonyAnts.size() / 6); i < colonyAnts.size(); i++)
		{
			colonyAnts[i].Behaviour(dt, walls, food);
		}
	};



	std::thread thread1(Thread1, dt, walls);
	std::thread thread2(Thread2, dt, walls);
	std::thread thread3(Thread3, dt, walls);
	std::thread thread5(Thread4, dt, walls);
	std::thread thread4(Thread5, dt, walls);
	std::thread thread6(Thread6, dt, walls);

	thread1.detach();
	thread2.detach();
	thread3.detach();
	thread4.detach();
	thread5.detach();
	thread6.detach();

	
	/*for (int i = 0; i < colonyAnts.size(); i++)
	{
		colonyAnts[i].Behaviour(dt, walls);
	}*/
}

void Colony::Reproduction(TextureManager* texM)
{
	if (foodGathered >= 4)
	{
		CreateColony(1, texM);
		foodGathered = 0;
	}

}



