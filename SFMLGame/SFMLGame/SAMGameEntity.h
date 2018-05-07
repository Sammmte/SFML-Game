#pragma once
#include <SFML\Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class SAMGameEntity
{
public:

	SAMGameEntity(string texturePath, float xIni, float yIni);
	SAMGameEntity(string texturePath);
	~SAMGameEntity();

	Sprite* sprite;
	Texture texture;
	bool active;

	Vector2f GetPosition();

	void Translate(Vector2f direction);

	void virtual Update(float elapsedTime) = 0;

	void virtual Activate() = 0;
	void virtual Deactivate() = 0;

	void DoOnPointerOverObject(Vector2i mousepos);

	void virtual OnMouseDown() = 0;
};