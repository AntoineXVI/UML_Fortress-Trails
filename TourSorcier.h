#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Tourelle.h"
#include "Munition.h"
class TourSorcier : public Tourelle
{
public:
	TourSorcier(float x, float y, float width, float height, sf::Color couleur); //constructeur
	~TourSorcier();// Destructeur

	void tirer(sf::RenderWindow& window, Munition* munition);
};

