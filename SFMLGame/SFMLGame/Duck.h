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

	static float velocity;

private:

	float xBegin;
	float yBegin;

	

	static string texturePath;
};