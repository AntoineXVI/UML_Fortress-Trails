#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"


int main(int argc, char** argv)
{
    //création de la fenetre
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");

    GameObject Obj(100.f, 100.f, 20.f, 20.f, sf::Color::Red);

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


        //DRAW
        window.clear();

        Obj.drawRect(window);
        

        window.display();
    }

    return 0;
}