#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Base : public GameObject
{
private:
	int vie;
	int argent;


public:
	Base(float x, float y, float width, float height, sf::Color couleur); //constructeur
	~Base();// Destructeur
	
	void takeDamage();
};



