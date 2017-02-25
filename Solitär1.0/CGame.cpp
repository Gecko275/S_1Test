#include "CGame.h"

void CGame::WindowEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			running = false;
			break;
		default:
			break;
		}
	}
}

CGame::CGame()
{
	running = true;
	window.create(sf::VideoMode(1280, 720), "Solitaer");
}

bool CGame::isRunning()
{
	return running;
}

void CGame::Run()
{
	window.clear();
	WindowEvents();
	window.display();
}

void CGame::debug()
{
}
