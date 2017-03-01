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
	backgrounds.DrawPlayfield(window);
	DrawGameStacks();
	DrawDeckStacks();
}

void CGame::DrawGameStacks()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < StackSize[i]; j++)
		{
			window.draw(Deck[CCard::getValuefromNumber(StackCards[i][j])][CCard::getSymbolfromNumber(StackCards[i][j])].getSprite());
		}
	}
}

void CGame::DrawDeckStacks()
{
	for (int i = upperCard; i < maxDeckSize; i++)
	{
		window.draw(Deck[CCard::getValuefromNumber(DeckCards[i])][CCard::getSymbolfromNumber(DeckCards[i])].getSprite());
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
	//DeckSize is 52-28 after creating the Stacks
	currDeckSize = 24;
	upperCard = 28;
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
