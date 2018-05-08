#include "SAMGame.h"

#ifdef _DEBUG
#include "vld.h"
#endif

int main()
{
	SAMGame* game = new SAMGame();

	game->Loop();

	delete game;

	return 0;
}