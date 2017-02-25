#pragma once
#ifndef CGAME_HPP
#define CGAME_HPP

#include "CCard.h"

class CGame
{
private:
	
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