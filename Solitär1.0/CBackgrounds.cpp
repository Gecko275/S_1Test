#include "CBackgrounds.h"

CBackgrounds::CBackgrounds()
{
	scale = 0.6f;

	OutlineGameStack.loadFromFile("Textures\\BorderStack.png");
	OutlineDeployStack.loadFromFile("Textures\\DeployStack.png");
	OutlineDeckStack.loadFromFile("Textures\\DeckStack.png");

	Gamestack.setTexture(OutlineGameStack);
	Gamestack.scale(scale, scale);

	Deploystack.setTexture(OutlineDeployStack);
	Deploystack.scale(scale, scale);

	Deckstack.setTexture(OutlineDeckStack);
	Deckstack.scale(scale, scale);
}

void CBackgrounds::DrawPlayfield(sf::RenderWindow & window)
{
	DrawDeckStack(window);
	DrawDeployStack(window);
	DrawGameStack(window);
}

//The seven playStacks
void CBackgrounds::DrawGameStack(sf::RenderWindow& window)
{
	for (int i = 0; i <= 6; i++)
	{
		Gamestack.setPosition(float(30 + (50 + 150 * scale)*i), 250.0f);
		window.draw(Gamestack);
	}
}

//The four topDeployStacks
void CBackgrounds::DrawDeployStack(sf::RenderWindow & window)
{
	for (int i = 0; i <= 3; i++)
	{
		Deploystack.setPosition(float(30 + (20 + 150 * scale)*i), 20.0f);
		window.draw(Deploystack);
	}
}

//The two Stacks dependent on the Deck
void CBackgrounds::DrawDeckStack(sf::RenderWindow & window)
{
	for (int i = 0; i <= 1; i++)
	{
		Deckstack.setPosition(float(700 + (30 + 150 * scale)*i), 20.0f);
		window.draw(Deckstack);
	}
}
