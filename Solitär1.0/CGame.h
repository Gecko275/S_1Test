#pragma once
#ifndef CGAME_HPP
#define CGAME_HPP

#include "CCard.h"
#include "CBackgrounds.h"

class CGame
{
private:
	CBackgrounds backgrounds;
	CCard Deck[13][4];
	int DeckCards[52];
	int StackCards[7][52];
	int StackSize[7];
	const int maxDeckSize = 52;
	int upperCard;
	int currDeckSize;

	bool running;

	void WindowEvents();
	void Draw();

	void DrawGameStacks();
	void DrawDeckStacks();

	bool DeckClicked(int Pos_x, int Pos_y);
public:
	CGame();

	sf::RenderWindow window;

	bool isRunning();
	void Run();
	

	/**/
	void debug();
	/**/
};

#endif