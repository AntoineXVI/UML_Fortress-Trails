#include "Ennemi.h"

Ennemi::Ennemi(float x, float y, float width, float height, sf::Color couleur, int vie, int degat) : GameObject(x, y, width, height, couleur) //Constructeur 
{
	this->degats = degat;
	this->vie = vie;
}

Ennemi::~Ennemi()
{

}

void Ennemi::takeDamage()
{
	vie -= 1;
}

bool Ennemi::isDead()
{
	if (vie <= 0)
	{
		return true;
	}
	else
	{
		return  false;
	}
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

void Ennemi::setDirection(float y, float x)
{
	direction.x = x;

	direction.y = y;


	float norme = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	direction.x = direction.x / norme; //direction X normée
	direction.y = -direction.y / norme; //direction Y normée
}


void Ennemi::drawRect(sf::RenderWindow& window)
{
	window.draw(rShape);
}