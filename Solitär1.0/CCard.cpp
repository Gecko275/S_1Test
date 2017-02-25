#include "CCard.h"

CCard::CCard(int in_value, int in_symbol)
{
	scale = 0.6f;
	value = in_value;
	symbol = in_symbol;
	flipped = true;

	sideSprite.setScale(scale, scale);

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
}

CCard::CCard()
{
}

sf::Sprite CCard::getSprite()
{
	if (flipped)
	{
		sideSprite.setTexture(Frontside);
	}
	else
	{
		sideSprite.setTexture(Backside);
	}
	return sideSprite;
}

void CCard::translate(float n_PosX, float n_PosY)
{
	sideSprite.setPosition(n_PosX, n_PosY);
}

void CCard::createDeck(CCard n_Deck[13][4])
{
	for (int in_value = 0; in_value < 13; in_value++)
	{
		for (int in_symbol = 0; in_symbol < 4; in_symbol++)
		{
			n_Deck[in_value][in_symbol] = CCard(in_value + 1, in_symbol);
		}
	}
}

void CCard::shuffleDeck(int shuffleStack[52])
{
	int i = 0;
	bool unique;
	while (i < 52)
	{
		unique = true;
		shuffleStack[i] = rand() % 52;
		for (int j = i - 1; j >= 0; j--)
		{
			if (shuffleStack[j] == shuffleStack[i])
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
