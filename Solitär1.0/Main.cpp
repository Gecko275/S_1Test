#include "SFML\Graphics.hpp"
#include "Game.h"

#include <iostream>

#include "CGame.h"

int main()
{
	CGame game;
	while (game.isRunning())
	{
		game.Run();
	}
}