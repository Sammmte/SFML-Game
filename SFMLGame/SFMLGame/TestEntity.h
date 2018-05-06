#pragma once
#include "SAMGameEntity.h"

class TestEntity : public SAMGameEntity
{
public:

	TestEntity(string texturePath, float xIni, float yIni);
	~TestEntity();

	void Update(float elapsedTime);
};