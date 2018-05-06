#include "TestEntity.h"

TestEntity::TestEntity(string texturePath, float xIni, float yIni) : SAMGameEntity(texturePath, xIni, yIni)
{
	
}

TestEntity::~TestEntity()
{

}

void TestEntity::Update(float elapsedTime)
{
	Translate(Vector2f(1, 0) * elapsedTime);
}