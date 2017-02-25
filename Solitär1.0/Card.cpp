#include "Card.h"

sf::Sprite Card::getSprite()
{
	if (flipped)
	{
		//std::cout << "front\n";
		sideSprite.setTexture(Frontside);
	}
	else
	{
		//std::cout << "back\n";
		sideSprite.setTexture(Backside);
	}
	return sideSprite;
}

Card::Card(int in_value, int in_symbol)
{
	scale.x = 0.5f;
	scale.y = 0.5f;
	value = in_value;
	symbol = in_symbol;
	flipped = true;

	Backside.loadFromFile("Textures\\Backside.png");
	std::string imgPath = "Textures\\";
	std::string Symbol;
	switch (in_symbol)
	{
	case 0:
		Symbol = "Karo";
		break;
	case 1:
		Symbol = "Pik";
		break;
	case 2:
		Symbol = "Heart";
		break;
	case 3:
		Symbol = "Cross";
		break;
	default:
		break;
	}
	imgPath += Symbol;
	imgPath += std::to_string(in_value);
	imgPath += ".png";

	Frontside.loadFromFile(imgPath);

	sideSprite.setScale(scale);

	width = getWidth();
	height = getHeight();
}

Card::Card()
{
	symbol = 0;
	flipped = false;
	value = 0;
	sideSprite.setScale(sf::Vector2f(0.5f, 0.5f));
}

void Card::flipCard()
{
	if (flipped)
	{
		flipped = false;
		//std::cout << "Flipped to false";
	}
	else
	{
		//std::cout << "Flipped to true";
		flipped = true;
	}
}

void Card::createDeck(Card newDeck[13][4])
{
	for (int in_value = 0; in_value < 13; in_value++)
	{
		for (int in_symbol = 0; in_symbol < 4; in_symbol++)
		{
			newDeck[in_value][in_symbol] = Card(in_value+1, in_symbol);
		}
	}
}

void Card::debug()
{
	std::cout << "Symbol" << symbol << "value" << value << "flipped" << flipped << "\n";
	std::cout << sideSprite.getGlobalBounds().width;
}

float Card::getHeight() const
{
	return sideSprite.getGlobalBounds().height;
}

float Card::getWidth() const
{
	return sideSprite.getGlobalBounds().width;
}

void Card::translate(int x, int y)
{
	sideSprite.setPosition((getWidth() + 25)*x, (getHeight() + 60)*y);
}


