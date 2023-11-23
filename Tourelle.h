#pragma once
#include "GameObject.h"

class Tourelle : public GameObject
{
protected:
	int i_degats;
	int i_prix;
	float f_portee;
	int i_exp;

public:
	Tourelle(float x, float y, float width, float height, sf::Color couleur); //constructeur
	~Tourelle();// Destructeur

	void tirer();
};