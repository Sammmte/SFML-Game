#include "SAMGame.h"

int main()
{
	SAMGame* game = new SAMGame();

	game->Loop();

	delete game;

	return 0;
}