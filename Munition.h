#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Munition : public GameObject
{
private:
	float speed;
public:

	Munition(float x, float y, float radius, sf::Color couleur, float speed); //constructeur
	~Munition(); //destructeur

	sf::FloatRect getBallRect();

	void setBallPosition(float fX, float fY);

	void moveMunition(float time);
};
