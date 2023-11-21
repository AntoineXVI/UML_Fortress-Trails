#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

GameObject::GameObject(float x, float y, float width, float height, sf::Color couleur) //constructeur
{
	this->xPosition = x;
	this->yPosition = y;
	this->width = width;
	this->height = height;

	rShape.setOrigin(0.5 * width, 0.5 * height);
	rShape.setPosition(sf::Vector2f(xPosition, yPosition));
	rShape.setSize(sf::Vector2f(width, height));
	rShape.setFillColor(couleur);
}

GameObject::~GameObject()//destructeur
{

}

void GameObject::drawRect(sf::RenderWindow& window)
{
	window.draw(rShape);
}

void GameObject::setDirection(float y, float x)
{
	direction.x = x;

	direction.y = y;


	float norme = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	direction.x = direction.x / norme; //direction X norm�e
	direction.y = -direction.y / norme; //direction Y norm�e
}

sf::Vector2f GameObject::getDirection()
{
	return direction;
}

sf::Vector2f GameObject::getPosition()
{
	sf::Vector2f positions;
	positions.x = xPosition;
	positions.y = yPosition;

	return positions;
}

int GameObject::OnCollisionEnter(sf::FloatRect shapeBall, sf::FloatRect shapeBrick)
{
	bool isX = false;
	bool isY = false;

	float overlapX = 0.0f;
	float overlapY = 0.0f;

	// Test de collision sur l'axe X
	if (shapeBall.left + shapeBall.width > shapeBrick.left &&
		shapeBall.left < shapeBrick.left + shapeBrick.width)
	{
		isX = true;

		// Calcul de la quantit� de chevauchement sur l'axe X
		overlapX = std::min(shapeBall.left + shapeBall.width - shapeBrick.left, shapeBrick.left + shapeBrick.width - shapeBall.left);
	}

	// Test de collision sur l'axe Y
	if (shapeBall.top + shapeBall.height > shapeBrick.top &&
		shapeBall.top < shapeBrick.top + shapeBrick.height)
	{
		isY = true;

		// Calcul de la quantit� de chevauchement sur l'axe Y
		overlapY = std::min(shapeBall.top + shapeBall.height - shapeBrick.top, shapeBrick.top + shapeBrick.height - shapeBall.top);
	}

	// D�termination de la face de collision
	if (isX && isY)
	{
		if (overlapX < overlapY)
		{
			// Collision sur l'axe X, d�terminez si c'est � gauche ou � droite
			if (shapeBall.left <= shapeBrick.left)
			{
				// Collision sur le c�t� gauche de la brique
				return 1;
			}
			else
			{
				// Collision sur le c�t� droit de la brique
				return 1;
			}
		}
		else
		{
			// Collision sur l'axe Y, d�terminez si c'est en haut ou en bas
			if (shapeBall.top <= shapeBrick.top)
			{
				// Collision en haut de la brique
				return 2;
			}
			else
			{
				// Collision en bas de la brique
				return 2;
			}
		}

		// Vous pouvez �galement renvoyer un code ou une valeur sp�cifique pour indiquer la face de collision
		return true;
	}
	else
	{
		return 0;
	}
}