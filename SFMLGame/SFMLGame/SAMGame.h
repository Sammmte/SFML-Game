#pragma once
#include <SFML\Graphics.hpp>

#ifdef _DEBUG
#include <iostream>
#endif

using namespace sf;

class SAMGame
{
public:

	SAMGame();
	~SAMGame();

	void Loop();

	Time GetElapsedTime();

private:

	RenderWindow* window;

	Time elapsedTime;

	Clock clock;

	void UpdateTime();
};