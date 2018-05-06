#include "SAMGame.h"
#include "TestEntity.h"

SAMGame::SAMGame()
{
	window = new RenderWindow(VideoMode(800, 600), "URUTIMEITO GEIMU");
}

SAMGame::~SAMGame()
{
	delete window;
}

void SAMGame::Loop()
{
	TestEntity* testEntity = new TestEntity("Assets/img.png", 10, 10);

	while (window->isOpen())
	{
		UpdateTime();

		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}

		testEntity->Update(GetElapsedTime().asSeconds());

		window->clear();
		window->draw(*(testEntity->sprite));
		window->display();
	}

	delete testEntity;
}

Time SAMGame::GetElapsedTime()
{
	return elapsedTime;
}

void SAMGame::UpdateTime()
{
	elapsedTime = clock.restart();
}