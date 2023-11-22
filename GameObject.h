#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class GameObject
{
protected :
	float xPosition;
	float yPosition;
	float width;
	float height;
	float radius;

	sf::Vector2f direction;
	sf::CircleShape cShape;
	sf::RectangleShape rShape;

public:

	GameObject(float x, float y, float width, float height, sf::Color couleur); //constructeur RectangleShape

	GameObject(float x, float y, float radius, sf::Color couleur); //constructeur CircleShape

	~GameObject();

	void drawRect(sf::RenderWindow& window);

	void drawCircle(sf::RenderWindow& window);

	void move(float time);

	void setDirection(float y, float x);

	sf::Vector2f getDirection();

	sf::Vector2f getPosition();

	sf::FloatRect getRectangleRect();

	int OnCollisionEnter(sf::FloatRect shapeBall, sf::FloatRect shapeBrick);
};