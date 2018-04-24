#include "Game.h"

Game::Game()
{
	window = new RenderWindow(VideoMode(800, 600), "SAPEEE");
}

Game::~Game()
{
	delete window;
}

void Game::Loop()
{
	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}

		window->clear();
	}
}