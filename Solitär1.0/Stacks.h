#pragma once
#ifndef STACKS_HPP
#define STACKS_HPP

#include "Playfield.h"

class Game;

class Stacks
{
public:
	void drawGameStacks(Game& g, int stackSize[7], int stackCards[7][52], sf::RenderWindow& window);
private:
	Playfield pf;
};

#endif