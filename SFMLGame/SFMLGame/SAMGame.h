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

	static SAMGame* GetInstance();

	void CounterUp();

private:

	RenderWindow* window;

	list<SAMGameEntity*> entities;

	Texture bg;
	Sprite background;

	Font* textFont;
	Text score;

	float timerTop = 2;
	float duckTimer = 0;

	static int duckCounter;

	Time elapsedTime;

	Clock clock;

	
	void UpdateTime();

	void ActivateDuck();

	static SAMGame* instance;
};