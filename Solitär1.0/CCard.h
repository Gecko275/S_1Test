#pragma once
#ifndef CCARD_HPP
#define CCARD_HPP

#include "SFML\Graphics.hpp"

class CCard
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
public:
	CCard(int in_value, int in_symbol);

	sf::Sprite getSprite();
};

#endif