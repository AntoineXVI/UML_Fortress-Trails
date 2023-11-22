#pragma once
#include "GameObject.h"

class Ennemi : public GameObject
{
private:
	int vie;
	int degats;


public:
	Ennemi(float x, float y, float width, float height, sf::Color couleur, int vie, int degat); //constructeur
	~Ennemi();// Destructeur

	void takeDamage();

	bool isDead();

	sf::Vector2f getPosition();

	sf::Vector2f getDirection();

	void setDirection(float y, float x);

	void drawRect(sf::RenderWindow& window);
};