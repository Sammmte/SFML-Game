#include "SAMGameEntity.h"

SAMGameEntity::SAMGameEntity(string texturePath, float xIni, float yIni)
{
	Texture* texture = new Texture();
	texture->loadFromFile(texturePath);

	sprite = new Sprite(*texture);

	sprite->setPosition(xIni, yIni);
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