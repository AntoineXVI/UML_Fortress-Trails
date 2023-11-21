#include "Tourelle.h"

Tourelle::Tourelle(float x, float y, float width, float height, sf::Color couleur) : GameObject(x, y, width, height, couleur) //Constructeur 
{
	exp = 0;
	prix = 10;
	portee = 10.f;
	degats = 1;
}

Tourelle::~Tourelle()
{

}

void Tourelle::tirer()
{

}