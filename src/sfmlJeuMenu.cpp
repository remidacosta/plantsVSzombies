#include "sfmlJeuMenu.h"
#include <cassert>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
using namespace sf;

#include <iostream>
#include <string>
using namespace std;


sfmlJeuMenu::sfmlJeuMenu()
{
    srand(time(NULL));
    int dimx = 1040;
    int dimy = 720;
    window = new RenderWindow(VideoMode(dimx,dimy), "Plants VS Zombies - par LACOTE Matthieu GROUSSET Ruben DA COSTA Rémi", sf::Style::Close);
    window->setFramerateLimit(35);

    tutoriel.setDimension(Vecteur2D(200,100));
    tutoriel.setPosition(Vecteur2D(420,260));
    tutoriel.setTexteBouton("Tutoriel");

    jouer.setDimension(Vecteur2D(200,100));
    jouer.setPosition(Vecteur2D(420,372));
    jouer.setTexteBouton("Jouer");

    continuer.setDimension(Vecteur2D(200,100));
    continuer.setPosition(Vecteur2D(420,484));
    continuer.setTexteBouton("Continuer");

    quitter.setDimension(Vecteur2D(100,50));
    quitter.setPosition(Vecteur2D(dimx-quitter.getDimension().getVectX()-20,70));
    quitter.setTexteBouton("Quitter");

}



sfmlJeuMenu::~sfmlJeuMenu()
{
    if (window != NULL) delete window;
}

Jeu& sfmlJeuMenu::getJeu ()
{
    return jeu;
}

void sfmlJeuMenu::sfmlMenuInit()
{
    if (!texture.loadFromFile("data/fondmenu.png"))
    {
        if(!texture.loadFromFile("../data/fondmenu.png"))
        {
            cout << "Error data/fondmenu.png not found" << endl;
        }
    }

}



void sfmlJeuMenu::sfmlAffMenu()
{
    Sprite sprite;
    IntRect rect(0,0,window->getSize().x,window->getSize().y);
    Sprite fondmenu(texture,rect);
    window->draw(fondmenu);
    window->draw(getBoutonTutoriel().getRectBouton());
	window->draw(getBoutonTutoriel().getTexte());
    window->draw(getBoutonJouer().getRectBouton());
	window->draw(getBoutonJouer().getTexte());
	window->draw(getBoutonContinuer().getRectBouton());
	window->draw(getBoutonContinuer().getTexte());
    window->draw(getBoutonQuitter().getRectBouton());
	window->draw(getBoutonQuitter().getTexte());

}

void sfmlJeuMenu::sfmlBoucleMenu()
{
    while (window->isOpen())
    {
            int x,y;
        	Event event;
        	while (window->pollEvent(event))
        	{
        	    	if (event.type == Event::Closed)
        	        {
        	       		window->close();
        	        }
        	        else
                    {
                        if (event.type == Event::MouseButtonPressed)
                        {
                            x  = event.mouseButton.x;                                 /* lecture de la coord x de la souris */
                            y  = event.mouseButton.y;
                            gestionsActionsClique(event,x,y);
                        }
                        if(event.type == Event::MouseButtonReleased)
                        {
                            x  = event.mouseButton.x;                                 /* lecture de la coord x de la souris */
                            y  = event.mouseButton.y;
                            gestionsActionsRelacheClique(event,x,y);
                        }
                        if(event.type == sf::Event::MouseMoved)
                        {
                            x  = event.mouseMove.x;                                 /* lecture de la coord x de la souris */
                            y  = event.mouseMove.y;
                            gestionsActionsBougeCurseur(event,x,y);
                        }
                    }
        	}
        	if(jouer.getEtat())
            {
				window->setVisible(false);
                sfmlJeu jeu;
                jeu.getJeu().setIdNiveau(1);
                jeu.sfmlInit();
                jeu.sfmlBoucle();

            }
            if(continuer.getEtat())
            {
				window->setVisible(false);
                sfmlJeu jeu;
                jeu.sfmlInit();
                jeu.sfmlBoucle();

            }
            if(tutoriel.getEtat())
            {
				window->setVisible(false);
                sfmlJeu jeu;
                jeu.getJeu().setIdNiveau(0);
                jeu.sfmlInit();
                jeu.sfmlBoucle();

            }
            if(quitter.getEtat())
            {
                window->close();
            }

        	window->clear(Color(192,192,192));

            sfmlAffMenu();

            window->display();
        }

}

void sfmlJeuMenu::gestionsActionsClique(sf::Event & event, int x, int y)
{

    if(event.mouseButton.button==Mouse::Left)
    {
        if(getBoutonTutoriel().curseurEstDessus(x,y))
        {
            getBoutonTutoriel().estAppuye();
        }

        if(getBoutonJouer().curseurEstDessus(x,y))
        {
            getBoutonJouer().estAppuye();
        }

        if(getBoutonQuitter().curseurEstDessus(x,y))
        {
            getBoutonQuitter().estAppuye();
        }
        if(getBoutonContinuer().curseurEstDessus(x,y))
        {
            getBoutonContinuer().estAppuye();
        }

    }
}

void sfmlJeuMenu::gestionsActionsRelacheClique(sf::Event & event, int x, int y)
{
    if(event.mouseButton.button==Mouse::Left)
    {

        if(getBoutonTutoriel().curseurEstDessus(x,y))
        {
            getBoutonTutoriel().changeEtat();
            getBoutonTutoriel().estRelache();
        }

        if(getBoutonJouer().curseurEstDessus(x,y))
        {
            getBoutonJouer().changeEtat();
            getBoutonJouer().estRelache();
        }

        if(getBoutonQuitter().curseurEstDessus(x,y))
        {
            getBoutonQuitter().changeEtat();
            getBoutonQuitter().estRelache();
        }
        if(getBoutonContinuer().curseurEstDessus(x,y))
        {
            getBoutonContinuer().changeEtat();
            getBoutonContinuer().estRelache();
        }


    }
}

void sfmlJeuMenu::gestionsActionsBougeCurseur(sf::Event & event, int x, int y)
{
    if(getBoutonTutoriel().curseurEstDessus(x,y))
    {
        getBoutonTutoriel().estRelache();
    }
    if(getBoutonJouer().curseurEstDessus(x,y))
    {
        getBoutonJouer().estRelache();
    }
    if(getBoutonQuitter().curseurEstDessus(x,y))
    {
        getBoutonQuitter().estRelache();
    }
    if(getBoutonContinuer().curseurEstDessus(x,y))
    {
        getBoutonContinuer().estRelache();
    }

}



Bouton& sfmlJeuMenu::getBoutonTutoriel()
{
    return tutoriel;
}

Bouton& sfmlJeuMenu::getBoutonJouer()
{
    return jouer;
}

Bouton& sfmlJeuMenu::getBoutonContinuer()
{
    return continuer;
}

Bouton& sfmlJeuMenu::getBoutonQuitter()
{
    return quitter;
}

