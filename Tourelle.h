#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Tourelle : public GameObject
{
private:

public:
	Tourelle(float x, float y, float width, float height, sf::Color couleur); //constructeur
	~Tourelle();// Destructeur

	void tirer();
};

