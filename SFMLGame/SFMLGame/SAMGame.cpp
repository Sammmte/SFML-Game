#include "SAMGame.h"
#include "Duck.h"
#include <iostream>

int SAMGame::duckCounter = 0;
SAMGame* SAMGame::instance = nullptr;

SAMGame::SAMGame()
{
	window = new RenderWindow(VideoMode(800, 600), "Duck Game!");

	for (int i = 0; i < 5; i++)
	{
		SAMGameEntity* entity = new Duck();

		entities.push_back(entity);
	}

	bg.loadFromFile("Assets/background.png");

	background.setTexture(bg);

	textFont = new Font();
	textFont->loadFromFile("Assets/arial.ttf");

	
	score.setPosition(700, 500);
	score.setFont(*textFont);
	score.setString(to_string(duckCounter));
	score.setCharacterSize(30);
	score.setColor(Color::Red);

	instance = this;
}

SAMGame::~SAMGame()
{
	delete window;

	while(entities.empty() == false)
	{
		delete entities.front();
		entities.pop_front();
	}

	delete textFont;
}

void SAMGame::Loop()
{

	while (window->isOpen())
	{
		UpdateTime();

		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window->close();
			}
		}

		if (Mouse::isButtonPressed(Mouse::Button::Left))
		{
			for (list<SAMGameEntity*>::iterator iterator = entities.begin(); iterator != entities.end(); ++iterator)
			{
				if ((*iterator)->active == true)
				{
					(*iterator)->DoOnPointerOverObject(Mouse::getPosition(*window));
				}
			}
		}

		if (duckTimer >= timerTop)
		{
			ActivateDuck();

			duckTimer = 0;
		}
		else
		{
			duckTimer += GetElapsedTime().asSeconds();
		}


		window->clear();
		
		window->draw(background);
		window->draw(score);

		for (list<SAMGameEntity*>::iterator iterator = entities.begin(); iterator != entities.end(); ++iterator)
		{
			if ((*iterator)->active == true)
			{
				(*iterator)->Update(GetElapsedTime().asSeconds());
				window->draw((*(*iterator)->sprite));
			}
		}

		window->display();
	}
}

Time SAMGame::GetElapsedTime()
{
	return elapsedTime;
}

void SAMGame::UpdateTime()
{
	elapsedTime = clock.restart();
}

void SAMGame::ActivateDuck()
{
	for (list<SAMGameEntity*>::iterator iterator = entities.begin(); iterator != entities.end(); ++iterator)
	{
		if ((*iterator)->active == false)
		{
			(*iterator)->Activate();

			break;
		}
	}
}

SAMGame* SAMGame::GetInstance()
{
	return instance;
}

void SAMGame::CounterUp()
{
	duckCounter++;
	score.setString(to_string(duckCounter));
}