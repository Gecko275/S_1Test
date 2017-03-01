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
	float scale;

	sf::Texture Backside;
	sf::Texture Frontside;

	sf::Sprite sideSprite;
public:
	CCard(int in_value, int in_symbol);
	CCard();

	sf::Sprite getSprite();

	void translate(float n_PosX, float n_PosY);

	void moveDeckCards(int currDeckSize, int upperCard, CCard n_Deck[13][4], int Deck[52]);

	static void createDeck(CCard n_Deck[13][4]);
	static void shuffleDeck(int shuffleStack[52]);
	static void createStacks(CCard n_Deck[13][4], int Deck[52], int Stack[7][52]);

	static int getValuefromNumber(int num);
	static int getSymbolfromNumber(int num);
};

#endif