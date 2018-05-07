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
	Text timerText;
	Text conditionText;

	float duckTimerTop = 2;
	float duckTimerBottom = 0.5;
	float duckTimer = 0;

	float gameTimer = 10;

	static int duckCounter;

	Time elapsedTime;

	Clock clock;

	
	void UpdateTime();

	void ActivateDuck();

	static SAMGame* instance;
};