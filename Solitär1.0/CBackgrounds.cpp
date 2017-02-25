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

/*
num:0 -> DeckDeploy
num:1 -> Deck

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
float CBackgrounds::getLeft(int num)
{
	switch (num)
	{
	case 0:
		return float(700 + (30 + 150 * 0.6f)*num);
		break;
	case 1:
		return float(700 + (30 + 150 * 0.6f)*num);
		break;
	case 2:
		return float(30 + (50 + 150 * 0.6f)*(num-2));
		break;
	case 3:
		return float(30 + (50 + 150 * 0.6f)*(num - 2));
		break;		 
	case 4:			 
		return float(30 + (50 + 150 * 0.6f)*(num - 2));
		break;		 
	case 5:			 
		return float(30 + (50 + 150 * 0.6f)*(num - 2));
		break;		
	case 6:			
		return float(30 + (50 + 150 * 0.6f)*(num - 2));
		break;		 
	case 7:			 
		return float(30 + (50 + 150 * 0.6f)*(num - 2));
		break;		 
	case 8:			 
		return float(30 + (50 + 150 * 0.6f)*(num - 2));
		break;
	case 9:
		return float(30 + (50 + 150 * 0.6f)*(num - 2));
		break;
	case 10:
		return float(30 + (50 + 150 * 0.6f)*(num - 2));
		break;
	case 11:
		return float(30 + (20 + 150 * 0.6f)*(num - 9));
		break;
	case 12:
		return float(30 + (20 + 150 * 0.6f)*(num - 9));
		break;
	default:
		break;
	}
	return 0.0f;
}

float CBackgrounds::getTop(int num)
{
	switch (num)
	{
	case 0:
		return 20.0f;
		break;
	case 1:
		return 20.0f;
		break;
	case 2:
		return 250.0f;
		break;
	case 3:
		return 250.0f;
		break;
	case 4:
		return 250.0f;
		break;
	case 5:
		return 250.0f;
		break;
	case 6:
		return 250.0f;
		break;
	case 7:
		return 250.0f;
		break;
	case 8:
		return 250.0f;
		break;
	case 9:
		return 250.0f;
		break;
	case 10:
		return 250.0f;
		break;
	case 11:
		return 20.0f;
		break;
	case 12:
		return 20.0f;
		break;
	default:
		break;
	}
	return 0.0f;
}

float CBackgrounds::getRight(int num)
{
	return (getLeft(num) + 150*0.6f);
}

float CBackgrounds::getDown(int num)
{
	return (getTop(num) + 250 * 0.6f);
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
