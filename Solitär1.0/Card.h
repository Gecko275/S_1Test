#pragma once
#ifndef CARD_HPP
#define CARD_HPP

#include "SFML\Graphics.hpp"

#include <iostream>

class Card
{
private:
	/*
	Ass -> 1
	Bube -> 11
	Dame -> 12
	König -> 13
	*/
	int value;
	/*
	Karo -> 0
	Pik -> 1
	Herz -> 2
	Kreuz -> 3
	*/
	int symbol;

	bool flipped;

	sf::Texture Backside;
	sf::Texture Frontside;

	sf::Sprite sideSprite;

	float width;
	float height;

	sf::Vector2f scale;
public:
	sf::Sprite getSprite();
	Card(int in_value, int in_symbol);
	Card();

	void flipCard();

	static void createDeck(Card newDeck[13][4]);

	float getHeight() const;
	float getWidth() const;

	void translate(int x, int y);

	/*Dubtfull*/
	/**/

	/*Delete after*/
	void debug();
	/**/
};

#endif