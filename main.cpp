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

    //liste des ennemis
    std::vector <Ennemi> oEnnemis;

    //liste des tourelles
    std::vector <Tourelle> oTourelles;

    Ennemi ennemi1(0.f, 300.f, 50.f, 50.f, sf::Color::Red, 5, 1);
    oEnnemis.push_back(ennemi1);

    //Ennemi ennemi2(20.f, 300.f, 50.f, 50.f, sf::Color::Red, 15, 1);
    //oEnnemis.push_back(ennemi2);

    Tourelle tourelle1(200.f, 350.f, 50.f, 50.f, sf::Color::Green);
    oTourelles.push_back(tourelle1);

    //creation de la base a defendre
    Base oBase(750.f, 300.f, 100.f, 100.f, sf::Color::Cyan);


    //liste des munitions tirés
    std::vector <Munition> oMunitions;


    sf::Clock oClock;
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

        
        for (int i = 0; i < oEnnemis.size(); i++)
        {
            oEnnemis[i].setDirection(0.f, oBase.getPosition().x );
            oEnnemis[i].move(deltaTime);

            for (int j = 0; j < oTourelles.size(); j++)
            {
                oTourelles[j].setDirection(oEnnemis[i].getPosition().y - oTourelles[j].getPosition().y, oEnnemis[i].getPosition().x - oTourelles[j].getPosition().x);

                if (TimeShoot.getElapsedTime().asSeconds() > 0.5f)
                {
                    Munition oMunition1((oTourelles[j].getPosition().x), (oTourelles[j].getPosition().y), 10.f, sf::Color::Blue, 10.f);
                    oMunition1.setDirection(oTourelles[j].getDirection().y, oTourelles[j].getDirection().x);
                    oMunitions.push_back(oMunition1);

                    TimeShoot.restart().asSeconds();
                }
            }
        }

        for (int k = oMunitions.size() - 1; k >= 0; k--)
        {
            for (int l = oEnnemis.size() - 1; l >= 0; l--)
            {
                if (oMunitions[k].OnCollisionEnter(oMunitions[k].getBallRect(), oEnnemis[l].getRectangleRect())) 
                {
                    oEnnemis[l].takeDamage();
                    oMunitions.erase(oMunitions.begin() + k);
                }
                
                if (oEnnemis[l].OnCollisionEnter(oEnnemis[l].getRectangleRect(), oBase.getRectangleRect()))
                {
                    oBase.takeDamage();
                    oEnnemis.erase(oEnnemis.begin() + l);
                }
            }
        }

        for (int i = 0; i < oMunitions.size(); i++)
        {
            oMunitions[i].moveMunition(deltaTime);
        }

        //DRAW
        window.clear();

        for (int i = 0; i < oEnnemis.size(); i++)
        {
            oEnnemis[i].drawRect(window);
        }
       
        oBase.drawRect(window);

        for (int i = 0; i < oMunitions.size(); i++)
        {
            oMunitions[i].drawCircle(window);
        }

        for (int i = 0; i < oTourelles.size(); i++)
        {
            oTourelles[i].drawRect(window);
        }
        
        window.display();

        deltaTime = oClock.restart().asSeconds();
    }

    return 0;
}