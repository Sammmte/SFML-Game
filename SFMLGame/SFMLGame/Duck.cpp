#include "Duck.h"
#include <iostream>
#include "SAMGame.h"

string Duck::texturePath = "Assets/duck.png";
float Duck::velocity = 300;

Duck::Duck() : SAMGameEntity(texturePath)
{
	xBegin = -150;
	yBegin = 250;
}

Duck::~Duck()
{
	
}

void Duck::Activate()
{
	sprite->setPosition(xBegin, yBegin);

	active = true;
}

void Duck::Deactivate()
{
	cout << "HOLA";

	active = false;
}

void Duck::Update(float elapsedTime)
{
	Translate(Vector2f(1, 0) * elapsedTime * velocity);

	if (sprite->getPosition().x > 900)
	{
		Deactivate();
	}
}

void Duck::OnMouseDown()
{
	SAMGame::GetInstance()->CounterUp();
	Deactivate();
}