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

private:

	float xBegin;
	float yBegin;

	float velocity = 70;

	static string texturePath;
};