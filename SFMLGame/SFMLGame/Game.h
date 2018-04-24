#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Game
{
public:

	Game();
	~Game();

	void Loop();

private:

	RenderWindow* window;

};