#include "TourSorcier.h"
TourSorcier::TourSorcier(float x, float y, float width, float height, sf::Color couleur) : Tourelle(x, y, width, height, couleur) //Constructeur 
{
	i_degats = 1;
	i_prix = 125;
	f_portee = 75;
	i_exp = 0;
}
