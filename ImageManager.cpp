#include <iostream>
#include <SFML/Graphics.hpp>
#include "ImageManager.h"

ImageManager::ImageManager(sf::String chemin)
{
	texture.loadFromFile(chemin);
	sprite.setTexture(texture);
}

ImageManager::~ImageManager()//destructeur
{

}

void ImageManager::drawImage(sf::RenderWindow& window)
{
	window.draw(sprite);
}