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
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (DeckClicked(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
				{
					CCard::moveDeckCards(currDeckSize, upperCard, Deck, DeckCards);
				}
			}
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
	for (int i = maxDeckSize - 1; i >= upperCard; i--)
	{
		window.draw(Deck[CCard::getValuefromNumber(DeckCards[i])][CCard::getSymbolfromNumber(DeckCards[i])].getSprite());
	}
	for (int i = maxDeckSize - currDeckSize; i < upperCard; i++)
	{
		window.draw(Deck[CCard::getValuefromNumber(DeckCards[i])][CCard::getSymbolfromNumber(DeckCards[i])].getSprite());
	}
}

bool CGame::DeckClicked(int Pos_x, int Pos_y)
{
	return (Pos_x > CBackgrounds::getLeft(1) && Pos_x < CBackgrounds::getRight(1) && Pos_y > CBackgrounds::getTop(1) && Pos_y < CBackgrounds::getBottom(1));

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
	for (int j = 0; j < 7; j++)
	{
		window.draw(Deck[CCard::getValuefromNumber(StackCards[6][j])][CCard::getSymbolfromNumber(StackCards[6][j])].getSprite());
	}
}
