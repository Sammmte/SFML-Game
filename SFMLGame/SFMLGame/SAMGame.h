#pragma once
#include <SFML\Graphics.hpp>
#include <list>

#include "SAMGameEntity.h"

using namespace sf;
using namespace std;

class SAMGame
{
public:

	SAMGame();
	~SAMGame();

	void Loop();

	Time GetElapsedTime();

private:

	

	RenderWindow* window;

	list<SAMGameEntity*> entities;

	float timerTop = 2;
	float duckTimer = 0;

	Time elapsedTime;

	Clock clock;

	void UpdateTime();

	void ActivateDuck();
};