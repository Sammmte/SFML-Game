#pragma once
#include "SAMGameEntity.h"

using namespace std;

class Duck : public SAMGameEntity
{
public:

	Duck();
	~Duck();

	void Update(float elapsedTime);
	void Activate();
	void Deactivate();
	void OnMouseDown();

private:

	float xBegin;
	float yBegin;

	static float velocity;

	static string texturePath;
};