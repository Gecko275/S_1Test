#pragma once
#ifndef HANDLEEVENTS_HPP
#define HANDLEEVENTS_HPP

#include "Card.h"

class HandleEvents
{
public:
	void handleEvents(Card &c_Card);
	void selectCard(int x, int y, Card Deck[13][4]);
private:
	void flipCard(Card &f_card);

	int selected_value;
	int selected_symbol;
};

#endif
