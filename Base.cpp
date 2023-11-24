#include "Base.h"

Base::Base(float x, float y, float width, float height, sf::Color couleur) : GameObject(x, y, width, height, couleur) //Constructeur 
{
	argent = 0;
	vie = 25;
}

Base::~Base()
{

}

void Base::takeDamage(int degatEnnemi)
{
	vie -= degatEnnemi;
}

bool Base::Isdead()
{
	if (vie <= 0)
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

void Base::looseReward(int priceTower) //perte de piece a l'achat d'une tour
{
	argent -= priceTower;
}

int Base::printArgent()
{
	return argent;
}

int Base::printPv()
{
	return vie;
}
