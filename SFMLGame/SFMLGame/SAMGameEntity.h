#pragma once
#include <SFML\Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class SAMGameEntity
{
public:

	Sprite* sprite;

	SAMGameEntity(string texturePath, float xIni, float yIni);
	~SAMGameEntity();

	Vector2f GetPosition();

	void Translate(Vector2f direction);

	void virtual Update(float elapsedTime) = 0;
};