#include "SFML\Graphics.hpp"
#include "Game.h"

#include <iostream>

int main()
{
	Game game;
	while (game.isRunnning())
	{
		game.Run();
	}
}