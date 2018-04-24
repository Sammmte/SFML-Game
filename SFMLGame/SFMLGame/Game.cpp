#include "Game.h"

Game::Game()
{
	window = new RenderWindow(VideoMode(800, 600), "SAPEEE");

	sprite = new Sprite();
	
	Texture* texture = new Texture();
	texture->loadFromFile("Assets/img.png");

	sprite->setTexture(*texture);
}

Game::~Game()
{
	delete sprite;

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
		window->draw(*sprite);
		window->display();
	}
}