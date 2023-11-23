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

    Ennemi ennemi2(60.f, 300.f, 50.f, 50.f, sf::Color::Red, 15, 1);
    oEnnemis.push_back(ennemi2);

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
            oEnnemis[i].setDirection(0.f, oBase.getPosition().x);
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
        /*

        //liste des ennemis a jour
        std::vector <Ennemi> oEnnemis_update;

        for (int l = 0; l < oEnnemis.size(); l++)
        {
            oEnnemis_update.push_back(oEnnemis[l]);
        }

        //liste des munitions a jour
        std::vector <Munition> oMunitions_update;

        for (int k = 0; k < oMunitions.size(); k++)
        {
            oMunitions_update.push_back(oMunitions[k]);
        }


        for (int k = 0; k < oMunitions_update.size(); k++)
        {
            for (int l = 0; l < oEnnemis_update.size(); l++)
            {
                if (oMunitions_update[k].OnCollisionEnter(oMunitions_update[k].getBallRect(), oEnnemis_update[l].getRectangleRect()))
                {
                    oEnnemis_update[l].takeDamage();
                    oMunitions.erase(oMunitions_update.begin() + k);
                }
                

                if (oEnnemis_update[l].OnCollisionEnter(oEnnemis_update[l].getRectangleRect(), oBase.getRectangleRect()))
                {
                    oBase.takeDamage();
                    oEnnemis.erase(oEnnemis_update.begin() + l);
                }
                if (oEnnemis_update[l].isDead())
                {
                    oEnnemis.erase(oEnnemis_update.begin() + l);
                }
            }
        }

        for (int k = 0; k < oMunitions_update.size(); k++)
        {
            oMunitions_update[k].moveMunition(deltaTime);
        }


        //DRAW
        window.clear();

        for (int i = 0; i < oEnnemis_update.size(); i++)
        {
            oEnnemis_update[i].drawRect(window);
        }

        oBase.drawRect(window);

        for (int i = 0; i < oMunitions_update.size(); i++)
        {
            oMunitions_update[i].drawCircle(window);
        }

        for (int i = 0; i < oTourelles.size(); i++)
        {
            oTourelles[i].drawRect(window);
        }

        window.display();

        deltaTime = oClock.restart().asSeconds();
        */


        // Suppression des ennemis touchés
        for (auto itMunition = oMunitions.begin(); itMunition != oMunitions.end();)
        {
            itMunition->moveMunition(deltaTime);

            for (auto itEnnemi = oEnnemis.begin(); itEnnemi != oEnnemis.end();)
            {
                if (itMunition->OnCollisionEnter(itMunition->getBallRect(), itEnnemi->getRectangleRect()))
                {
                    itEnnemi->takeDamage();
                    itEnnemi = oEnnemis.erase(itEnnemi);
                    itMunition = oMunitions.erase(itMunition);
                }
                else
                {
                    ++itEnnemi;
                }
            }
        }

        // Suppression des ennemis touchant la base
        for (auto itEnnemi = oEnnemis.begin(); itEnnemi != oEnnemis.end();)
        {
            if (itEnnemi->OnCollisionEnter(itEnnemi->getRectangleRect(), oBase.getRectangleRect()))
            {
                oBase.takeDamage();
                itEnnemi = oEnnemis.erase(itEnnemi);
            }
            else
            {
                ++itEnnemi;
            }
        }

        
        // Suppression des munitions hors de l'écran
        oMunitions.erase(
            std::remove_if(oMunitions.begin(), oMunitions.end(),
                []( Munition& munition) {
                    return munition.isOutOfScreen();
                }),
            oMunitions.end());


            
        // DRAW
        window.clear();

        for ( auto& ennemi : oEnnemis)
        {
            ennemi.drawRect(window);
        }

        oBase.drawRect(window);

        for ( auto& munition : oMunitions)
        {
            munition.drawCircle(window);
        }

        for ( auto& tourelle : oTourelles)
        {
            tourelle.drawRect(window);
        }

        window.display();

        deltaTime = oClock.restart().asSeconds();




    }

    return 0;
}