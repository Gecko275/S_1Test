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

	bool running;

	void WindowEvents();
	void Draw();
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