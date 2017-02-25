#include "Stacks.h"
#include "Game.h"


void Stacks::drawGameStacks(Game& g, int stackSize[7], int stackCards[7][52], sf::RenderWindow& window)
{
	for (int i = 0; i < 7; i++)
	{
		//std::array<int,4> Boundaries = pf.getStackBoundries(i+2);
		for (int j = 0; j < stackSize[i]; j++)
		{
			//Card t_Card = g.getCardFromNumber(stackCards[i][j]);
			//t_Card.translate(Boundaries[0], Boundaries[1] + 10 * j);
			//window.draw(t_Card.getSprite());
		}
	}
}
