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

	bool running;

	void WindowEvents();

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