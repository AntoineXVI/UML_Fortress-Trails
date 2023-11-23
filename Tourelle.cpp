#include "Tourelle.h"

Tourelle::Tourelle(float x, float y, float width, float height, sf::Color couleur) : GameObject(x, y, width, height, couleur) //Constructeur 
{
	i_exp = 0;
	i_prix = 10;
	f_portee = 10.f;
	i_degats = 1;
}

Tourelle::~Tourelle()
{

}

void Tourelle::tirer()
{

}