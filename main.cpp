#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Base.h"
#include "Ennemi.h"
#include "Munition.h"
#include "Tourelle.h"


int main(int argc, char** argv)
{
    //cr�ation de la fenetre
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");

    //creation d'une police et d'un texte
    sf::Font font;
    font.loadFromFile("../SFML-2.6.1/Fonts/Arial.ttf");
    sf::Text compteurArgent; 
    compteurArgent.setFont(font); 
    compteurArgent.setCharacterSize(50); 
    compteurArgent.setFillColor(sf::Color::White); 


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

    //liste des munitions tir�s
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

            // Vérifier si le temps de tir est écoulé
            if (TimeShoot.getElapsedTime().asSeconds() > 0.5f)
            {
                // Boucle à travers toutes les tourelles
                for (int j = 0; j < oTourelles.size(); j++)
                {
                    oTourelles[j].setDirection(oEnnemis[i].getPosition().y - oTourelles[j].getPosition().y, oEnnemis[i].getPosition().x - oTourelles[j].getPosition().x);

                    // Tirer une munition pour chaque tourelle
                    Munition oMunition1((oTourelles[j].getPosition().x), (oTourelles[j].getPosition().y), 10.f, sf::Color::Blue, 10.f);
                    oMunition1.setDirection(oTourelles[j].getDirection().y, oTourelles[j].getDirection().x);
                    oMunitions.push_back(oMunition1);
                }

                // Redémarrer le chronomètre après avoir tiré
                TimeShoot.restart();
            }
        }


        // Liste des munitions à supprimer
        std::vector<int> munitionsToRemove;

        // Suppression des ennemis touchés
        for (int k = 0; k < oMunitions.size(); k++)
        {
            oMunitions[k].moveMunition(deltaTime);

            // Variable pour indiquer si la munition a touché un ennemi
            bool munitionHitEnemy = false;

            for (int j = 0; j < oEnnemis.size(); j++)
            {
                if (oMunitions[k].OnCollisionEnter(oMunitions[k].getBallRect(), oEnnemis[j].getRectangleRect()))
                {
                    oEnnemis[j].takeDamage();
                    munitionHitEnemy = true;
                    if (oEnnemis[j].isDead())
                    {
                        oEnnemis.erase(oEnnemis.begin() + j);
                        oBase.getReward();
                    }
                }
            }

            // Si la munition a touché un ennemi, ajoutez-la à la liste des munitions à supprimer
            if (munitionHitEnemy)
            {
                munitionsToRemove.push_back(k);
            }
        }

        // Supprime les munitions de la liste principale après avoir terminé la boucle
        for (int i : munitionsToRemove) 
        {
            oMunitions.erase(oMunitions.begin() + i); 
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

        for (int k = 0; k < oMunitions.size(); k++)
        {
            oMunitions[k].moveMunition(deltaTime);
        }


        // Suppression des munitions hors de l'�cran
        for (int k = 0; k < oMunitions.size(); k++)
        {
            if (oMunitions[k].isOutOfScreen())
            {
                oMunitions.erase(oMunitions.begin() + k);
            }
        }



        //mis a jour du compteur d'argent 
        compteurArgent.setString("Argent : " + std::to_string(oBase.printArgent())); 

        float offsetX = 10.0f;  // Marge à partir du X
        float offsetY = 10.0f;  // Marge à partir du Y
        compteurArgent.setPosition(window.getSize().x - compteurArgent.getLocalBounds().width - offsetX, offsetY);



        // DRAW
        window.clear();

        for(int l = 0; l < oEnnemis.size(); l++) 
        {
            oEnnemis[l].drawRect(window); 
        }

        oBase.drawRect(window);

        for (int k = 0; k < oMunitions.size(); k++)
        {
            oMunitions[k].drawCircle(window);
        }

        for (auto& tourelle : oTourelles)
        {
            tourelle.drawRect(window);
        }

        window.draw(compteurArgent);
       
        window.display();

        deltaTime = oClock.restart().asSeconds();

    }

    return 0;
}
