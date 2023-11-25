#pragma once
#include <SFML/Graphics.hpp>

class TextManager
{
private:
	sf::Font font;
	sf::Text text;

public:
	TextManager(float x, float y, int size, sf::String string); //constructeur
	~TextManager();// Destructeur

	void drawText(sf::RenderWindow& window);

	sf::FloatRect getRect();

	void setPosition(float x, float y);

	void setString(sf::String string); //pour mettre a jour le texte 
};

