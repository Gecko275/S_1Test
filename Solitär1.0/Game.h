#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include "Card.h"
#include "HandleEvents.h"
#include "Playfield.h"
#include "Stacks.h"

class Game
{
private:
	bool running = false;
	HandleEvents eventHandler;
	Playfield board;
	Stacks stacks;
	Card Deck[13][4];
	void Draw();
	static int width;
	static int height;

	int currDeckSize;
	int DeckCards[52];
	int StackCards[7][52];
	int stackSize[7];

	void shuffleDeck(int Cards[]);
	void setupStack();

	void WindowEvents();
public:
	sf::RenderWindow window;
	Game();
	bool isRunnning() const;
	void Run();
	Card getCardFromNumber(int num);

	/*Delete after*/
	void debug();
	/**/
};

#endif
