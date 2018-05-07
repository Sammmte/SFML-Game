#include "SAMGameEntity.h"

SAMGameEntity::SAMGameEntity(string texturePath, float xIni, float yIni) : SAMGameEntity(texturePath)
{
	sprite->setPosition(xIni, yIni);
}

SAMGameEntity::SAMGameEntity(string texturePath)
{
	Texture* texture = new Texture();
	texture->loadFromFile(texturePath);

	sprite = new Sprite(*texture);

	active = false;
}

SAMGameEntity::~SAMGameEntity()
{
	delete sprite;
}

Vector2f SAMGameEntity::GetPosition()
{
	return sprite->getPosition();
}

void SAMGameEntity::Translate(Vector2f direction)
{
	sprite->move(direction);
}

void SAMGameEntity::DoOnPointerOverObject(Vector2i mousepos)
{
	Vector2f auxPos = Vector2f(mousepos.x, mousepos.y);

	if (sprite->getGlobalBounds().contains(auxPos))
	{
		OnMouseDown();
	}
}