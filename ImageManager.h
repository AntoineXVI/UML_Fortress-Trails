#pragma once
#include <SFML/Graphics.hpp>


class ImageManager
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

public: 
	ImageManager(sf::String chemin); //constructeur
	~ImageManager();// Destructeur

	void drawImage(sf::RenderWindow& window);
};

