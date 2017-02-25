#include "HandleEvents.h"


void HandleEvents::handleEvents(Card &c_Card)
{
	flipCard(c_Card);
}

void HandleEvents::selectCard(int x, int y, Card Deck[13][4])
{
	for (int in_value = 0; in_value < 13; in_value++)
	{
		for (int in_symbol = 0; in_symbol < 4; in_symbol++)
		{
			sf::Sprite t_Sprite = Deck[in_value][in_symbol].getSprite();
			if (t_Sprite.getGlobalBounds().contains(float(x), float(y))) 
			{
				selected_value = in_value;
				selected_symbol = in_symbol;
				Deck[selected_value][selected_symbol].flipCard();
			}
		}
	}
}

void HandleEvents::flipCard(Card &f_card)
{
	f_card.flipCard();
}
