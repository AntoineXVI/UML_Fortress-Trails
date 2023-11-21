#include <SFML/Graphics.hpp>
#include <iostream>
#include "Munition.h"

Munition::Munition(float x, float y, float radius, sf::Color couleur, float speed) : GameObject(x, y, radius, couleur) //Constructeur 
{
	speed = 1.f;
}

Munition::~Munition()
{

}

sf::FloatRect Munition::getBallRect()
{
	sf::FloatRect shapeRect;

	shapeRect.left = cShape.getPosition().x - cShape.getOrigin().x;
	shapeRect.top = cShape.getPosition().y - cShape.getOrigin().y;
	shapeRect.width = radius;
	shapeRect.height = radius;

	return shapeRect;
}

void Munition::setBallPosition(float fX, float fY)
{
	xPosition = fX;
	yPosition = fY;
}

void Munition::moveMunition(float time)
{
	cShape.getPosition();
	xPosition += speed * direction.x * time * 100.f;
	yPosition += speed * direction.y * time * 100.f;

	cShape.setPosition(sf::Vector2f(xPosition, yPosition));
}

void Munition::setDirection(float y, float x)
{
	direction.x = x;

	direction.y = y;


	float norme = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	direction.x = direction.x / norme; //direction X normée
	direction.y = -direction.y / norme; //direction Y normée
}