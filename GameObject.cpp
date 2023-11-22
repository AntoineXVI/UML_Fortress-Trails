#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

GameObject::GameObject(float x, float y, float width, float height, sf::Color couleur) //constructeur RectangleShape
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

GameObject::GameObject(float x, float y, float radius, sf::Color couleur) //constructeur CircleShape
{
	this->xPosition = x;
	this->yPosition = y;
	this->radius = radius;

	cShape.setOrigin(0.5 * radius, 0.5 * radius);
	cShape.setPosition(sf::Vector2f(xPosition, yPosition));
	cShape.setRadius(radius);
	cShape.setFillColor(couleur);
	direction.x = 1;
	direction.y = 0;
}

GameObject::~GameObject()//destructeur
{

}

void GameObject::drawRect(sf::RenderWindow& window)
{
	window.draw(rShape);
}

void GameObject::drawCircle(sf::RenderWindow& window)
{
	window.draw(cShape);
}

void GameObject::move(float time)
{
	rShape.getPosition();
	xPosition += direction.x * time * 100.f;
	yPosition += direction.y * time * 100.f;

	rShape.setPosition(sf::Vector2f(xPosition, yPosition));
}

void GameObject::setDirection(float y, float x)
{
	direction.x = x;

	direction.y = y;


	float norme = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	direction.x = direction.x / norme; //direction X normée
	direction.y = -direction.y / norme; //direction Y normée
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

sf::FloatRect GameObject::getRectangleRect()
{
	sf::FloatRect shapeRect;

	shapeRect.width = width;
	shapeRect.height = height;

	shapeRect.left = rShape.getPosition().x - rShape.getOrigin().x;
	shapeRect.top = rShape.getPosition().y - rShape.getOrigin().y;

	return shapeRect;
}

int GameObject::OnCollisionEnter(sf::FloatRect shape1, sf::FloatRect shape2)
{
	bool isX = false;
	bool isY = false;

	float overlapX = 0.0f;
	float overlapY = 0.0f;

	// Test de collision sur l'axe X
	if (shape1.left + shape1.width > shape2.left &&
		shape1.left < shape2.left + shape2.width)
	{
		isX = true;

		// Calcul de la quantité de chevauchement sur l'axe X
		overlapX = std::min(shape1.left + shape1.width - shape2.left, shape2.left + shape2.width - shape1.left);
	}

	// Test de collision sur l'axe Y
	if (shape1.top + shape1.height > shape2.top &&
		shape1.top < shape2.top + shape2.height)
	{
		isY = true;

		// Calcul de la quantité de chevauchement sur l'axe Y
		overlapY = std::min(shape1.top + shape1.height - shape2.top, shape2.top + shape2.height - shape1.top);
	}

	// Détermination de la face de collision
	if (isX && isY)
	{
		if (overlapX < overlapY)
		{
			// Collision sur l'axe X, déterminez si c'est à gauche ou à droite
			if (shape1.left <= shape2.left)
			{
				// Collision sur le côté gauche de la brique
				return 1;
			}
			else
			{
				// Collision sur le côté droit de la brique
				return 1;
			}
		}
		else
		{
			// Collision sur l'axe Y, déterminez si c'est en haut ou en bas
			if (shape1.top <= shape2.top)
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

		// Vous pouvez également renvoyer un code ou une valeur spécifique pour indiquer la face de collision
		return true;
	}
	else
	{
		return 0;
	}
}