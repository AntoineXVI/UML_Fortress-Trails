#include "TourArcher.h"
TourArcher::TourArcher(float x, float y, float width, float height, sf::Color couleur) : Tourelle(x, y, width, height, couleur) //Constructeur 
{
	i_degats = 1;
	i_prix = 100;
	f_portee = 100;
	i_exp = 0;
}
