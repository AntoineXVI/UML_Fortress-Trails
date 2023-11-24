#pragma once
#include "GameObject.h"

class Munition : public GameObject
{
private:
	float speed;
	int sourceTourelle;
public:

	Munition(float x, float y, float radius, sf::Color couleur, float speed); //constructeur
	~Munition(); //destructeur

	sf::FloatRect getBallRect();

	void moveMunition(float time);

	bool isOutOfScreen();
};
