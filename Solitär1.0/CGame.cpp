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
	debug();
	backgrounds.DrawPlayfield(window);
	WindowEvents();
	window.display();
}

void CGame::debug()
{
	CCard t_Card(2, 3);
	t_Card.translate(300.0f, 100.0f);
	window.draw(t_Card.getSprite());
}
