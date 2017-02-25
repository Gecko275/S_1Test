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

void CGame::Draw()
{
	/*for (int in_value = 0; in_value<13; in_value++)
	{
		for (int in_symbol = 0; in_symbol < 4; in_symbol++)
		{
			backgrounds.DrawPlayfield(window);
			window.draw(Deck[in_value][in_symbol].getSprite());
		}
	}*/
	backgrounds.DrawPlayfield(window);
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < StackSize[i]; j++)
		{
			window.draw(Deck[CCard::getValuefromNumber(StackCards[i][j])][CCard::getSymbolfromNumber(StackCards[i][j])].getSprite());
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
	CCard::createStacks(Deck, DeckCards, StackCards);
	//Set StackSize
	{
		for (int i = 0; i < 7; i++)
		{
			StackSize[i] = i + 1;
		}
	}
}

bool CGame::isRunning()
{
	return running;
}

void CGame::Run()
{
	window.clear(sf::Color::Green);
	//debug();
	//backgrounds.DrawPlayfield(window);
	Draw();
	WindowEvents();
	window.display();
}

void CGame::debug()
{
	//Deck[3][2].translate(300.0f, 100.0f);

	for (int i = 0; i < 13; i++)
	{
		window.draw(Deck[i][3].getSprite());
	}
	window.draw(Deck[4][2].getSprite());
}
