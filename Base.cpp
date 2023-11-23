#include "Base.h"

Base::Base(float x, float y, float width, float height, sf::Color couleur) : GameObject(x, y, width, height, couleur) //Constructeur 
{
	argent = 0;
	vie = 10;
}

Base::~Base()
{

}

void Base::takeDamage()
{
	vie -= 1;
}

bool Base::Isdead()
{
	if (vie == 0)
	{
		return true;
	}
	else
		return false;
}

void Base::getReward() //gain de pieces a chaque kills
{
	argent += 5;
}

int Base::printArgent()
{
	return argent;
}
