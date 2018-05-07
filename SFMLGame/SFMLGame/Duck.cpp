#include "Duck.h"

string Duck::texturePath = "Assets/duck.png";

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
	active = false;
}

void Duck::Update(float elapsedTime)
{
	Translate(Vector2f(1, 0) * elapsedTime * velocity);
}