#include "CCard.h"

CCard::CCard(int in_value, int in_symbol)
{
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
