#include "Game.h"

int main()
{
	Game* game = new Game();

	game->Loop();

	delete game;

	return 0;
}