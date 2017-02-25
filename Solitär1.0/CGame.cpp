#include "CGame.h"

#include <iostream>

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
	srand(time(NULL));

	running = true;
	window.create(sf::VideoMode(1280, 720), "Solitaer");
	CCard::createDeck(Deck);
	CCard::shuffleDeck(DeckCards);
}

bool CGame::isRunning()
{
	return running;
}

void CGame::Run()
{
	window.clear(sf::Color::Green);
	debug();
	backgrounds.DrawPlayfield(window);
	WindowEvents();
	window.display();
}

void CGame::debug()
{
	Deck[3][2].translate(300.0f, 100.0f);
	window.draw(Deck[3][2].getSprite());
}
