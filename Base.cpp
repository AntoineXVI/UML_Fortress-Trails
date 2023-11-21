#include "Base.h"

Base::Base(float x, float y, float width, float height, sf::Color couleur) : GameObject(x, y, width, height, couleur) //Constructeur 
{
	argent = 1;
	vie = 10;
}

Base::~Base()
{

}

void Base::takeDamage()
{
	vie -= 1;
}
