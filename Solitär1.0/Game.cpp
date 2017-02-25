#include "Game.h"

void Game::Draw()
{
	for(int in_value = 0;in_value<13;in_value++)
	{ 
		for (int in_symbol = 0; in_symbol < 4; in_symbol++)
		{
			Deck[in_value][in_symbol].translate(in_value, in_symbol);
			board.DrawBoard(window);
			stacks.drawGameStacks(*this, stackSize, StackCards, window);
			//window.draw(Deck[in_value][in_symbol].getSprite());
		}
	}
}

void Game::shuffleDeck(int Cards[])
{
	int i = 0;
	bool unique;
	while (i < currDeckSize)
	{
		unique = true;
		Cards[i] = rand() % 52;
		for (int j = i-1; j >= 0; j--)
		{
			if (Cards[j] == Cards[i])
			{
				unique = false;
				break;
			}
		}
		if (unique)
		{
			i++;
		}
	}
}

void Game::setupStack()
{
	//set StackSize
	for (int i = 0; i < 7; i++)
	{
		stackSize[i] = i + 1;
	}

	int takenCards = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < stackSize[i]; j++)
		{
			StackCards[i][j] = DeckCards[takenCards];
			takenCards++;
		}
	}
}

void Game::WindowEvents()
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
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Return) { eventHandler.handleEvents(Deck[0][0]);}
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				eventHandler.selectCard(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, Deck);
			}
		default:
			break;
		}
	}
}

Game::Game()
{
	srand(time(NULL));

	Card::createDeck(Deck);
	currDeckSize = 52;

	shuffleDeck(DeckCards);

	setupStack();

	running = true;
	window.create(sf::VideoMode(1280, 720), "Solitär");
}

bool Game::isRunnning()const
{
	return running;
}

void Game::Run()
{
	while (window.isOpen())
	{
		WindowEvents();
		window.clear(sf::Color::Blue);
		Draw();
		window.display();
	}
}

Card Game::getCardFromNumber(int num)
{
	return Deck[int(num/13)][num%13];
}

void Game::debug()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < stackSize[i]; j++)
		{
			std::cout << StackCards[i][j] << ", ";
		}
		std::cout << "\n";
	}
}
