#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Ennemi : public GameObject
{
private:
	int vie;
	int degats;


public:
	Ennemi(float x, float y, float width, float height, sf::Color couleur); //constructeur
	~Ennemi();// Destructeur

	void takeDamage();

	sf::Vector2f getPosition();

	sf::Vector2f getDirection();

	void drawRect(sf::RenderWindow& window);
};