#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Tourelle.h"
#include "Munition.h"
class TourGel : public Tourelle
{
public:
	TourGel(float x, float y, float width, float height, sf::Color couleur); //constructeur
	~TourGel();// Destructeur

	void tirer(sf::RenderWindow& window, Munition* munition);
};