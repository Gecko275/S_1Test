#include "Playfield.h"

Playfield::Playfield()
{
	scale = sf::Vector2f(0.6f, 0.6f);

	OutlineGameStack.loadFromFile("Textures\\BorderStack.png");
	OutlineDeployStack.loadFromFile("Textures\\DeployStack.png");
	OutlineDeckStack.loadFromFile("Textures\\DeckStack.png");

	Gamestack.setTexture(OutlineGameStack);
	Gamestack.setScale(scale);

	Deploystack.setTexture(OutlineDeployStack);
	Deploystack.setScale(scale);

	Deckstack.setTexture(OutlineDeckStack);
	Deckstack.setScale(scale);
}

void Playfield::DrawBoard(sf::RenderWindow & window)
{
	DrawGameStack(window);
	DrawDeployStack(window);
	DrawDeckStack(window);
}


/*
num:0 -> Deck
num:1 -> DeckDeploy

num:2 -> GameStack1
num:3 -> GameStack2
num:4 -> GameStack3
num:5 -> GameStack4
num:6 -> GameStack5
num:7 -> GameStack6
num:8 -> GameStack7

num:9 -> DeployStack1
num:10 -> DeployStack2
num:11 -> DeployStack3
num:12 -> DeployStack4
*/
/*
BoundarieValue[0] -> right
BoundarieValue[1] -> top
BoundarieValue[2] -> left
BoundarieValue[3] -> down
*/
std::array<int, 4> Playfield::getStackBoundries(int num)
{
	std::array<int, 4> BoundarieValue;
	switch (num)
	{
	case 0:
		BoundarieValue[0] = int(700 + (30 + 150 * scale.x) * 1);
		BoundarieValue[1] = 20;
		break;
	case 1:
		BoundarieValue[0] = int(700 + (30 + 150 * scale.x) * 0);
		BoundarieValue[1] = 20;
		break;
	case 2:
		BoundarieValue[0] = int(30 + (50 + 150 * scale.x) * (num - 2));
		BoundarieValue[1] = 250;
		break;
	case 3:
		BoundarieValue[0] = int(30 + (50 + 150 * scale.x) * (num - 2));
		BoundarieValue[1] = 250;
		break;
	case 4:
		BoundarieValue[0] = int(30 + (50 + 150 * scale.x) * (num - 2));
		BoundarieValue[1] = 250;
		break;
	case 5:
		BoundarieValue[0] = int(30 + (50 + 150 * scale.x) * (num - 2));
		BoundarieValue[1] = 250;
		break;
	case 6:
		BoundarieValue[0] = int(30 + (50 + 150 * scale.x) * (num - 2));
		BoundarieValue[1] = 250;
		break;
	case 7:
		BoundarieValue[0] = int(30 + (50 + 150 * scale.x) * (num - 2));
		BoundarieValue[1] = 250;
		break;
	case 8:
		BoundarieValue[0] = int(30 + (50 + 150 * scale.x) * (num - 2));
		BoundarieValue[1] = 250;
		break;
	case 9:
		BoundarieValue[0] = int(30 + (20 + 150 * scale.x) * (num - 9));
		BoundarieValue[1] = 20;
		break;
	case 10:
		BoundarieValue[0] = int(30 + (20 + 150 * scale.x) * (num - 9));
		BoundarieValue[1] = 20;
		break;
	default:
		break;
	}
	BoundarieValue[2] = BoundarieValue[0] + int((150 * scale.x));
	BoundarieValue[3] = BoundarieValue[1] + int((250 * scale.y));
	return BoundarieValue;
}

//The seven playStacks
void Playfield::DrawGameStack(sf::RenderWindow& window)
{
	for (int i = 0; i <= 6; i++)
	{
		Gamestack.setPosition(float(30 + (50 + 150 * scale.x)*i), 250.0f);
		window.draw(Gamestack);
	}
}

//The four topDeployStacks
void Playfield::DrawDeployStack(sf::RenderWindow & window)
{
	for (int i = 0; i <= 3; i++)
	{
		Deploystack.setPosition(float(30 + (20 + 150 * scale.x)*i), 20.0f);
		window.draw(Deploystack);
	}
}

//The two Stacks dependent on the Deck
void Playfield::DrawDeckStack(sf::RenderWindow & window)
{
	for (int i = 0; i <= 1; i++)
	{
		Deckstack.setPosition(float(700 + (30 + 150 * scale.x)*i), 20.0f);
		window.draw(Deckstack);
	}
}
