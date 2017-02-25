#pragma once
#ifndef CBACKGROUNDS_HPP
#define CBACKGROUNDS_HPP

#include "SFML\Graphics.hpp"

class CBackgrounds
{
public:
	CBackgrounds();

	void DrawPlayfield(sf::RenderWindow& window);
private:
	float scale;

	sf::Sprite Gamestack;
	sf::Sprite Deploystack;
	sf::Sprite Deckstack;

	sf::Texture OutlineGameStack;
	sf::Texture OutlineDeployStack;
	sf::Texture OutlineDeckStack;

	void DrawGameStack(sf::RenderWindow& window);
	void DrawDeployStack(sf::RenderWindow& window);
	void DrawDeckStack(sf::RenderWindow& window);
};

#endif