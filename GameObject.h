#include <iostream>
#include <SFML/Graphics.hpp>

class GameObject
{
protected :
	float xPosition;
	float yPosition;
	float width;
	float height;

	sf::Vector2f direction;
	sf::RectangleShape rShape;

public:
	GameObject(float x, float y, float weight, float height, sf::Color couleur);

	void drawRect(sf::RenderWindow& window);

	void setDirection(float y, float x);

	sf::Vector2f getDirection();

	sf::Vector2f getPosition();

	int OnCollisionEnter(sf::FloatRect shapeBall, sf::FloatRect shapeBrick);
};