#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Base.h"
#include "Ennemi.h"
#include "Munition.h"
#include "Tourelle.h"


int main(int argc, char** argv)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); //pour la fonction random

    //cr�ation de la fenetre
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");

    //creation d'une police et d'un texte
    sf::Font font;
    font.loadFromFile("../SFML-2.6.1/Fonts/Arial.ttf");
    sf::Text compteurArgent; 
    compteurArgent.setFont(font); 
    compteurArgent.setCharacterSize(50); 
    compteurArgent.setFillColor(sf::Color::White); 

    sf::Clock TimeSpawnEnnemis;

    //liste des ennemis
    std::vector <Ennemi> oEnnemis;

    //liste des tourelles
    std::vector <Tourelle> oTourelles;


    //Ennemi ennemi2(0.f, 300.f, 50.f, 50.f, sf::Color::Red, 5, 1);
    //oEnnemis.push_back(ennemi2);

    Tourelle tourelle1(200.f, 350.f, 50.f, 50.f, sf::Color::Green);
    oTourelles.push_back(tourelle1);

    //creation de la base a defendre
    Base oBase(750.f, 300.f, 100.f, 100.f, sf::Color::Cyan);

    //liste des munitions tir�s
    std::vector <Munition> oMunitions;

    sf::Clock oClock;
    sf::Clock TimeShoot;
    float deltaTime = 0;
    int ennemiCount = 0;
    int rngSpawn = 0;
    int min = 1;
    int max = 2;

    //GameLoop
    while (window.isOpen())
    {

        if (ennemiCount < 10) // vague 1
        {
            
            // Vérifier si le temps de spawn est écoulé
            if (TimeSpawnEnnemis.getElapsedTime().asSeconds() > 3.f)
            {
                Ennemi ennemi1(0.f, 300.f, 50.f, 50.f, sf::Color::Red, 5, 1);
                oEnnemis.push_back(ennemi1);

                // Redémarrer le chronomètre après avoir fait spawn un ennemi
                TimeSpawnEnnemis.restart();
                ennemiCount += 1;
            }
            
        }
        else if (ennemiCount >= 10 && ennemiCount < 20) //vague 2
        {
            std::cout << "vague 1 terminé" << std::endl;
            // Vérifier si le temps de spawn est écoulé
            if (TimeSpawnEnnemis.getElapsedTime().asSeconds() > 2.f)
            {
                rngSpawn = rand() % (max - min + 1) + min;
                if (rngSpawn == 2)
                {
                    Ennemi ennemi2(0.f, 300.f, 50.f, 50.f, sf::Color::Magenta, 7, 3);
                    oEnnemis.push_back(ennemi2);
                }
                else if (rngSpawn == 1)
                {
                    Ennemi ennemi1(0.f, 300.f, 50.f, 50.f, sf::Color::Red, 5, 1);
                    oEnnemis.push_back(ennemi1);
                }
                else if (rngSpawn == 0)
                {
                    std::cout << "oui";
                }
               

                // Redémarrer le chronomètre après avoir fait spawn un ennemi
                TimeSpawnEnnemis.restart();
                ennemiCount += 1;
            }
        }
        else if (ennemiCount >= 20 && ennemiCount < 35) //vague 3
        {
            std::cout << "vague 2 terminé" << std::endl;
            int max = 3;

            // Vérifier si le temps de spawn est écoulé
            if (TimeSpawnEnnemis.getElapsedTime().asSeconds() > 2.f)
            {
                rngSpawn = rand() % (max - min + 1) + min;
                if (rngSpawn == 3)
                {
                    Ennemi ennemi3(0.f, 300.f, 50.f, 50.f, sf::Color::Yellow , 15, 5);
                    oEnnemis.push_back(ennemi3);
                }
                else if (rngSpawn == 2)
                {
                    Ennemi ennemi2(0.f, 300.f, 50.f, 50.f, sf::Color::Magenta, 7, 3);
                    oEnnemis.push_back(ennemi2);
                }
                else if (rngSpawn == 1)
                {
                    Ennemi ennemi1(0.f, 300.f, 50.f, 50.f, sf::Color::Red, 5, 1);
                    oEnnemis.push_back(ennemi1);
                }
                else if (rngSpawn == 0)
                {
                    std::cout << "oui";
                }


                // Redémarrer le chronomètre après avoir fait spawn un ennemi
                TimeSpawnEnnemis.restart();
                ennemiCount += 1;
            }
        }
        else if ( ennemiCount == 35) //vague 4, boss
        {
            std::cout << "vague 3 terminé" << std::endl;
            // Vérifier si le temps de spawn est écoulé
            if (TimeSpawnEnnemis.getElapsedTime().asSeconds() > 8.f)
            {
                Ennemi boss(0.f, 300.f, 70.f, 70.f, sf::Color::Red, 50, 20);
                oEnnemis.push_back(boss);
                
                // Redémarrer le chronomètre après avoir fait spawn un ennemi
                TimeSpawnEnnemis.restart();
                ennemiCount += 1;
            }
        }

        //EVENT
        sf::Event oEvent;
        while (window.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                window.close();
            if (oEvent.type == sf::Event::MouseButtonReleased)
            {
                if (oEvent.mouseButton.button == sf::Mouse::Left && (oBase.printArgent() >= 10))
                {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    sf::Vector2f worldMousePosition = window.mapPixelToCoords(mousePosition);

                    Tourelle tourelle2(worldMousePosition.x, worldMousePosition.y, 50.f, 50.f, sf::Color::Green);
                    oTourelles.push_back(tourelle2);
                    oBase.looseReward(10);
                }
            }
        }
        // UPDATE

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
                        if (ennemiCount > 35)
                        {
                            std::cout << "Bravo, tu as gagné !";
                            sf::sleep(sf::seconds(5));
                            return 0;
                        }
                        else
                        {
                            oEnnemis.erase(oEnnemis.begin() + j);
                            oBase.getReward();
                        }
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

        //verification de la defaite -> si la base n'a plus de vie 
        if (oBase.Isdead())
        {
            std::cout << "dommage, tu as perdu !";
            sf::sleep(sf::seconds(5));
            break;
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

        for (int m = 0; m < oTourelles.size(); m++)
        {
            oTourelles[m].drawRect(window);
        }

        window.draw(compteurArgent);
       
        window.display();

        deltaTime = oClock.restart().asSeconds();

    }

    return 0;
}
