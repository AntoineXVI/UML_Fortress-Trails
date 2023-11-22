#include "TourGel.h"
TourGel::TourGel(float x, float y, float width, float height, sf::Color couleur) : Tourelle(x, y, width, height, couleur) //Constructeur 
{
	i_degats = 0;
	i_prix = 100;
	f_portee = 70;
	i_exp = 0;
}
