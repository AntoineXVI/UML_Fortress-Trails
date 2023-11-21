#include "Ennemi.h"

Ennemi::Ennemi(float x, float y, float width, float height, sf::Color couleur) : GameObject(x, y, width, height, couleur) //Constructeur 
{
	degats = 1;
	vie = 10;
}

Ennemi::~Ennemi()
{

}

void Ennemi::takeDamage()
{
	vie -= 1;
}

sf::Vector2f Ennemi::getPosition()
{
	sf::Vector2f positions;
	positions.x = xPosition;
	positions.y = yPosition;

	return positions;
}

sf::Vector2f Ennemi::getDirection()
{
	return direction;
}

void Ennemi::drawRect(sf::RenderWindow& window)
{
	window.draw(rShape);
}