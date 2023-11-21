#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Base.h"
#include "Ennemi.h"
#include "Munition.h"
#include "Tourelle.h"


int main(int argc, char** argv)
{
    //création de la fenetre
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");

    Ennemi ennemi1(100.f, 100.f, 20.f, 20.f, sf::Color::Red);


    //liste des munitions tirés
    std::vector <Munition> oMunitions;



    sf::Clock TimeShoot;
    float deltaTime = 0;

    //GameLoop
    while (window.isOpen())
    {
        //EVENT
        sf::Event oEvent;
        while (window.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                window.close();
            if (oEvent.type == sf::Event::MouseButtonReleased)
            {
               
            }
        }
        // UPDATE
      
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        if (TimeShoot.getElapsedTime().asSeconds() > 0.5f)
        {
            Munition oMunition1((ennemi1.getPosition().x), (ennemi1.getPosition().y), 10.f, sf::Color::Red, 1);
            oMunition1.setDirection(ennemi1.getDirection().y, ennemi1.getDirection().x);
            oMunitions.push_back(oMunition1);

            TimeShoot.restart().asSeconds();
        }


        //DRAW
        window.clear();

        ennemi1.drawRect(window);
        

        window.display();
    }

    return 0;
}