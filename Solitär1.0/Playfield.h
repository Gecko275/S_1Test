#pragma once
#ifndef PLAYFIELD_HPP
#define PLAYFIELD_HPP

#include "SFML\Graphics.hpp"
#include <array>

class Playfield
{
public:
	Playfield();
	void DrawBoard(sf::RenderWindow& window);

	//int* getStackBoundries(int num);
	std::array<int, 4> getStackBoundries(int num);
private:
	sf::Vector2f scale;

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