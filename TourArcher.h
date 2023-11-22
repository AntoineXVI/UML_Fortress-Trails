#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Tourelle.h"
#include "Munition.h"
class TourArcher : public Tourelle
{
public:
	TourArcher(float x, float y, float width, float height, sf::Color couleur); //constructeur
	~TourArcher();// Destructeur

	void tirer(sf::RenderWindow& window, Munition* munition);
};

