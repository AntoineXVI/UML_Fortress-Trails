#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextManager.h"


TextManager::TextManager(float x, float y, int size, sf::String string)
{
	font.loadFromFile("../SFML-2.6.1/Fonts/Arial.ttf");

	text.setFont(font);

	text.setCharacterSize(size);
	text.setFillColor(sf::Color::White);
	text.setString(string);
	text.setPosition(x, y);
}

TextManager::~TextManager()//destructeur
{

}


void TextManager::drawText(sf::RenderWindow& window)
{
	window.draw(text);
}


sf::FloatRect TextManager::getRect()
{
	return text.getGlobalBounds();
}

void TextManager::setPosition(float x, float y)
{
	text.setPosition(x, y);
}

void TextManager::setString(sf::String newString)
{
	text.setString(newString);
}
