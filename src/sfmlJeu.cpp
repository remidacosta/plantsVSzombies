#include <cassert>
#include <time.h>
#include "sfmlJeu.h"
#include "EtapeTutoriel.h"
#include "ZoneDeTexte.h"
#include "sfmlJeuMenu.h"
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace sf;

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

sfmlJeu::sfmlJeu ()
{
    srand(time(NULL));
    int dimx = 1040;
    int dimy = 720;
    window = new RenderWindow(VideoMode(dimx,dimy), "Plants VS Zombies - par LACOTE Matthieu GROUSSET Ruben DA COSTA Rémi", sf::Style::Close);
    window->setFramerateLimit(35);

    pause.setDimension(Vecteur2D(100,50));
    pause.setPosition(Vecteur2D(dimx-pause.getDimension().getVectX()-20,20));
    pause.setTexteBouton("Pause");

    menu.setDimension(Vecteur2D(100,50));
    menu.setPosition((Vecteur2D(dimx-menu.getDimension().getVectX()-20,82)));
    menu.setTexteBouton("Menu");

    setEtapeTuto(NULL);
}

Jeu& sfmlJeu::getJeu (){
    return jeu;
}

void sfmlJeu::sfmlInit() {
	Sprite sprite;
   	if (!texture.loadFromFile("data/sprite.png"))
    {
        if(!texture.loadFromFile("../data/sprite.png"))
        {
            cout << "Error data/sprite.png non found" << endl;
        }
    }

   	int l=0;
   	for(int i=1;i<245;i=i+81)
    {
        int k=0;
        for(int j=1;j<326;j=j+81)
        {
            IntRect rect(i,j,80,80);
            Sprite tmp(texture,rect);
            tabSprite2D[k][l]=tmp;
            k++;
        }
        l++;
   	}

   	if(getJeu().getNiveau()->getModeJeu() == "Tutoriel")
    {
        EtapeTutoriel * tmp = new EtapeTutoriel(0);
        etapeTuto = tmp;
    }
}

sfmlJeu::~sfmlJeu ()
{
    if (window != NULL) delete window;
   	if(etapeTuto != NULL)
    {
        delete etapeTuto;
    }
    setEtapeTuto(NULL);
}

EtapeTutoriel * sfmlJeu::getEtapeTuto()const
{
    return etapeTuto;
}

void sfmlJeu::setEtapeTuto(EtapeTutoriel * etape)
{
    etapeTuto = etape;
}

void sfmlJeu::sfmlAff()
{

    for(int i=0;i<jeu.getTerrain().getNbLignes();i++)
    {
        if(jeu.getTerrain().getLigne(i).getContientTondeuse())
        {
            Sprite tmp=tabSprite2D[3][0];
            tmp.setPosition(Vector2f(80,getJeu().getTerrain().getPosition().getVectY()+i*80));
            window->draw(tmp);
        }
		for(int j=0;j<getJeu().getTerrain().getLigne(i).getNbCases();j++)
		{
			Sprite tmp;
			if((i+j)%2==1)
			{
                tmp=tabSprite2D[0][0];
			}
			else
            {
				tmp=tabSprite2D[0][2];
			}
			if(getJeu().getNiveau()->getModeJeu()=="Cauchemar")
            {
                tmp.setColor(sf::Color(192, 192, 192));
            }
			tmp.setPosition(getJeu().getTerrain().getPosition().getVectX()+j*80,getJeu().getTerrain().getPosition().getVectY()+i*80);
			window->draw(tmp);
		}
	}
	for(int i=0;i<jeu.getTerrain().getNbLignes();i++)
	{
		for(list<Plante>::iterator it=getJeu().getTerrain().getLigne(i).beginPlante();it!=jeu.getTerrain().getLigne(i).endPlante();it++)
		{
			int id=(*it).getId();
			Sprite tmp=tabSprite2D[1][id-1];

			tmp.setPosition(Vector2f((*it).getPosition().getVectX(),(*it).getPosition().getVectY()));

			window->draw(tmp);
		}
		for(list<Zombie>::iterator it=getJeu().getTerrain().getLigne(i).beginZombie();it!=jeu.getTerrain().getLigne(i).endZombie();it++)
		{
			int id=(*it).getId();
			Sprite tmp=tabSprite2D[4][id-1];

            tmp.setPosition(Vector2f((*it).getPosition().getVectX(),(*it).getPosition().getVectY()));

            if((*it).getEtatTouche())
            {
                tmp.setColor(sf::Color(255, 128, 128));
                (*it).setEtatTouche(false);
            }

			window->draw(tmp);
		}
		if(getJeu().getTerrain().getLigne(i).getTondeuse()!=NULL)
		{
			Sprite tmp=tabSprite2D[3][0];
			tmp.setPosition(Vector2f(getJeu().getTerrain().getLigne(i).getTondeuse()->getPosition().getVectX(),
						getJeu().getTerrain().getLigne(i).getTondeuse()->getPosition().getVectY()));
            if(getJeu().getNiveau()->getModeJeu()=="Cauchemar")
            {
                tmp.setColor(sf::Color(192, 192, 192));
            }
			window->draw(tmp);
		}
		for(list<Projectile>::iterator it=getJeu().getTerrain().getLigne(i).beginProjectile();it!=jeu.getTerrain().getLigne(i).endProjectile();it++)
		{
			Sprite tmp=tabSprite2D[2][0];
			tmp.setPosition(Vector2f((*it).getPosition().getVectX(),(*it).getPosition().getVectY()));
			if(getJeu().getNiveau()->getModeJeu()=="Cauchemar")
            {
                tmp.setColor(sf::Color(192, 192, 192));
            }
			window->draw(tmp);
		}
		for(list<Soleil>::iterator it=getJeu().getTerrain().getLigne(i).beginSoleil();it!=jeu.getTerrain().getLigne(i).endSoleil();it++)
		{
			Sprite tmp=tabSprite2D[2][1];
			tmp.setPosition(Vector2f((*it).getPosition().getVectX(),(*it).getPosition().getVectY()));
			if(getJeu().getNiveau()->getModeJeu()=="Cauchemar")
            {
                tmp.setColor(sf::Color(192, 192, 192));
            }
			window->draw(tmp);
		}
	}
	afficheHud();
	afficheAvancement();
	afficheNbrSoleil();
	afficherNiveau();
	window->draw(getBoutonPause().getRectBouton());
	window->draw(getBoutonPause().getTexte());
	window->draw(getBoutonMenu().getRectBouton());
	window->draw(getBoutonMenu().getTexte());

	if(etapeTuto != NULL)
    {
        window->draw(etapeTuto->getZonetxt().getFond());
        for(int i =0; i<etapeTuto->getZonetxt().getTailleTabLignes();i++)
        {
            window->draw(etapeTuto->getZonetxt().getLigne(i));
        }
    }
}

void sfmlJeu::afficheHud()
{
    sf::RectangleShape rectHud;
    rectHud.setPosition(sf::Vector2f(getJeu().getHud().getPosition().getVectX() , getJeu().getHud().getPosition().getVectY()));
    rectHud.setSize(sf::Vector2f(getJeu().getHud().getDimension().getVectX() , getJeu().getHud().getDimension().getVectY()));
    rectHud.setFillColor(sf::Color(150,150,150));

    window->draw(rectHud);

    for(int i=0; i<getJeu().getHud().getTailleTabBoutons();i++)
    {
        window->draw(getJeu().getHud().getBouton(i).getRectBouton());
    }
	Sprite plante1=tabSprite2D[1][0]; Text cout1("100",font,40);
	Sprite plante2=tabSprite2D[1][1]; Text cout2("50",font,40);
	Sprite plante3=tabSprite2D[1][2]; Text cout3("50",font,40);

	plante1.setPosition(Vector2f(getJeu().getHud().getPosition().getVectX() + 10,getJeu().getHud().getPosition().getVectY() + 10));
	plante2.setPosition(Vector2f(getJeu().getHud().getPosition().getVectX() + 100,getJeu().getHud().getPosition().getVectY() + 10));
	plante3.setPosition(Vector2f(getJeu().getHud().getPosition().getVectX() + 190,getJeu().getHud().getPosition().getVectY() + 10));
	cout1.setPosition(Vector2f(getJeu().getHud().getPosition().getVectX() + 20,getJeu().getHud().getPosition().getVectY() + 40));
	cout2.setPosition(Vector2f(getJeu().getHud().getPosition().getVectX() + 110,getJeu().getHud().getPosition().getVectY() + 40));
	cout3.setPosition(Vector2f(getJeu().getHud().getPosition().getVectX() + 200,getJeu().getHud().getPosition().getVectY() + 40));
	window->draw(plante1); window->draw(cout1);
	window->draw(plante2); window->draw(cout2);
	window->draw(plante3); window->draw(cout3);
}


void sfmlJeu::afficheAvancement()
{
    sf::RectangleShape rectbackground;
    rectbackground.setPosition(sf::Vector2f(getJeu().getHud().getPosition().getVectX()+getJeu().getHud().getDimension().getVectX()+10,
                                              getJeu().getHud().getPosition().getVectY()+60));
    rectbackground.setSize(sf::Vector2f(400,40));
    rectbackground.setFillColor(sf::Color(150,150,150));
    rectbackground.setOutlineColor(sf::Color(0,0,0));
    rectbackground.setOutlineThickness(1);
    window->draw(rectbackground);

    sf::RectangleShape rectprogressBar;
    rectprogressBar.setPosition(sf::Vector2f(getJeu().getHud().getPosition().getVectX()+getJeu().getHud().getDimension().getVectX()+10,
                                              getJeu().getHud().getPosition().getVectY()+60));
    rectprogressBar.setSize(sf::Vector2f(getJeu().getNiveau()->getAvancement()*4,40));
    rectprogressBar.setFillColor(sf::Color(194, 247, 50));
    window->draw(rectprogressBar);

}


void sfmlJeu::afficheNbrSoleil()
{
    sf::RectangleShape rectSoleil;
    rectSoleil.setPosition(sf::Vector2f(getJeu().getHud().getPosition().getVectX()+getJeu().getHud().getDimension().getVectX()+10,
                                              getJeu().getHud().getPosition().getVectY()));
    rectSoleil.setSize(sf::Vector2f(400,60));
    rectSoleil.setFillColor(sf::Color(150,150,150));
    rectSoleil.setOutlineColor(sf::Color(0,0,0));
    rectSoleil.setOutlineThickness(1);
    window->draw(rectSoleil);

    font.loadFromFile("../data/big_noodle_titling.ttf");

    stringstream ss;
    ss << getJeu().getNbSoleils();
    string str = ss.str();

    Sprite logoSoleil=tabSprite2D[2][1];
    logoSoleil.setPosition(sf::Vector2f(getJeu().getHud().getPosition().getVectX()+getJeu().getHud().getDimension().getVectX()+240,
                                        getJeu().getHud().getPosition().getVectY()-10));

    sf::Text text(str,font);
    text.setCharacterSize(58);

    text.setPosition(sf::Vector2f(getJeu().getHud().getPosition().getVectX()+getJeu().getHud().getDimension().getVectX()+400-text.getLocalBounds().width - 20,
                                  getJeu().getHud().getPosition().getVectY()-5));
    window->draw(text);
    window->draw(logoSoleil);


}

void sfmlJeu::afficherNiveau()
{
    font.loadFromFile("../data/big_noodle_titling.ttf");

    stringstream ss;
    ss << getJeu().getNiveau()->getId();
    string str = ss.str();

    string niveautxt = "Niveau " + str;
    sf::Text text(niveautxt,font);
    text.setCharacterSize(58);

    text.setPosition(sf::Vector2f(getJeu().getHud().getPosition().getVectX()+getJeu().getHud().getDimension().getVectX()+20,
                                              getJeu().getHud().getPosition().getVectY()-5));
    window->draw(text);

}


void sfmlJeu::sfmlBoucle () {
    Clock clockGeneral;

    while (window->isOpen())
    {
        while(!getJeu().getPartieTerminee())
        {
            if(!enPause())
            {
                if(clockGeneral.getElapsedTime().asSeconds()>=0.02) /* 0.03*/
                {
                    getJeu().actionsAuto();
                    clockGeneral.restart();
                }
            }
            else
            {
                clockGeneral.restart();
            }
            if(menu.getEtat())
            {
				    menu.setEtat(false);
					window->setVisible(false);
					sfmlJeuMenu fenetremenu;
					fenetremenu.sfmlMenuInit();
					fenetremenu.sfmlBoucleMenu();
            }

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
                        if(event.type == sf::Event::KeyPressed)
                        {
                            if(etapeTuto != NULL)
                            {
                                if(getEtapeTuto()->getNumEtape()<9)
                                {
                                        if(event.key.code == sf::Keyboard::Space)
                                        {
                                            getEtapeTuto()->setNumEtape(getEtapeTuto()->getNumEtape()+1);
                                        }
                                }
                                else
                                {
                                    setEtapeTuto(NULL);
                                }
                            }
                        }
                    }
        	}

        	if(getJeu().getNiveau()->getModeJeu()=="Cauchemar")
            {
                window->clear(Color(0,100,0));
            }
            else    window->clear(Color(58,157,35));

            sfmlAff();
            afficheCurseur(x,y);
            gestionAffichageTutoriel();
            window->display();
        }

        window->close();
        cout<<"PERDU"<<endl;

    }
}


void sfmlJeu::gestionAffichageTutoriel()
{
    if(getEtapeTuto() != NULL)
    {
        int compt = 0;
        switch(getEtapeTuto()->getNumEtape())
        {
            case 0:
                getBoutonPause().setEtat(true);
                window->draw(getEtapeTuto()->getZonetxt().getFond());
                for(int i=0; i<getEtapeTuto()->getZonetxt().getTailleTabLignes();i++)
                {
                    window->draw(getEtapeTuto()->getZonetxt().getLigne(i));
                }
                break;
            case 1:
                getBoutonPause().setEtat(true);
                window->draw(getEtapeTuto()->getZonetxt().getFond());
                for(int i=0; i<getEtapeTuto()->getZonetxt().getTailleTabLignes();i++)
                {
                    window->draw(getEtapeTuto()->getZonetxt().getLigne(i));
                }
                break;
            case 2:
                getBoutonPause().setEtat(true);
                window->draw(getEtapeTuto()->getZonetxt().getFond());
                for(int i=0; i<getEtapeTuto()->getZonetxt().getTailleTabLignes();i++)
                {
                    window->draw(getEtapeTuto()->getZonetxt().getLigne(i));
                }
                break;
            case 3:
                getBoutonPause().setEtat(true);
                window->draw(getEtapeTuto()->getZonetxt().getFond());
                for(int i=0; i<getEtapeTuto()->getZonetxt().getTailleTabLignes();i++)
                {
                    window->draw(getEtapeTuto()->getZonetxt().getLigne(i));
                }
                break;
            case 4:
                getBoutonPause().setEtat(true);
                window->draw(getEtapeTuto()->getZonetxt().getFond());
                for(int i=0; i<getEtapeTuto()->getZonetxt().getTailleTabLignes();i++)
                {
                    window->draw(getEtapeTuto()->getZonetxt().getLigne(i));
                }
                break;
            case 5:
                getBoutonPause().setEtat(true);
                window->draw(getEtapeTuto()->getZonetxt().getFond());
                for(int i=0; i<getEtapeTuto()->getZonetxt().getTailleTabLignes();i++)
                {
                    window->draw(getEtapeTuto()->getZonetxt().getLigne(i));
                }
                break;
            case 6:
                getBoutonPause().setEtat(false);
                for(int i=0; i<getJeu().getTerrain().getNbLignes();i++)
                {
                    if(getJeu().getTerrain().getLigne(i).getSizeSoleils() != 0)
                    {
                        window->draw(getEtapeTuto()->getZonetxt().getFond());
                        for(int i=0; i<getEtapeTuto()->getZonetxt().getTailleTabLignes();i++)
                        {
                            window->draw(getEtapeTuto()->getZonetxt().getLigne(i));
                        }
                    }
                }
                if(getJeu().getNbSoleils() == 125)
                {
                    getBoutonPause().setEtat(true);
                    getEtapeTuto()->setNumEtape(getEtapeTuto()->getNumEtape()+1);
                }
                break;
            case 7:
                getBoutonPause().setEtat(false);
                for(int i=0 ; i<getJeu().getTerrain().getNbLignes();i++)
                {
                    if(getJeu().getTerrain().getLigne(i).getSizeZombies() != 0)
                    {
                        window->draw(getEtapeTuto()->getZonetxt().getFond());
                        for(int i=0; i<getEtapeTuto()->getZonetxt().getTailleTabLignes();i++)
                        {
                            window->draw(getEtapeTuto()->getZonetxt().getLigne(i));
                        }
                        getBoutonPause().setEtat(true);
                    }
                }
                break;
            case 8:
                getBoutonPause().setEtat(false);
                window->draw(getEtapeTuto()->getZonetxt().getFond());
                for(int i=0; i<getEtapeTuto()->getZonetxt().getTailleTabLignes();i++)
                {
                    window->draw(getEtapeTuto()->getZonetxt().getLigne(i));
                }
                for(int i=0; i<getJeu().getTerrain().getNbLignes();i++)
                {
                    if(getJeu().getTerrain().getLigne(i).getSizeZombies() == 0)
                    {
                        compt++;
                    }
                }
                if(compt == getJeu().getTerrain().getNbLignes())
                {
                    getEtapeTuto()->setNumEtape(getEtapeTuto()->getNumEtape()+1);
                }
                break;
            case 9:
                getBoutonPause().setEtat(false);
                window->draw(getEtapeTuto()->getZonetxt().getFond());
                for(int i=0; i<getEtapeTuto()->getZonetxt().getTailleTabLignes();i++)
                {
                    window->draw(getEtapeTuto()->getZonetxt().getLigne(i));
                }
                break;
        }
    }
}

void sfmlJeu::gestionsActionsClique(sf::Event & event,int x,int y)
{
    int posY = getJeu().getTerrain().getPosition().getVectY();
    int dimY = getJeu().getTerrain().getDimension().getVectY();
    int posX = getJeu().getTerrain().getPosition().getVectX();
    int dimX = getJeu().getTerrain().getDimension().getVectX();

    if(event.mouseButton.button==Mouse::Left)
    {
		if(getBoutonMenu().curseurEstDessus(x,y))
        {
            getBoutonMenu().estAppuye();
        }
        if(!enPause())
        {
            if((posX<=x)&&(x<=posX+dimX)&&(posY<=y)&&(y<=posY+dimY))
            {
                jeu.ramasserSoleil(x,y);
            }

            for(int i=0; i<getJeu().getHud().getTailleTabBoutons();i++)
            {
                if(getJeu().getHud().getBouton(i).curseurEstDessus(x,y))
                {
                    getJeu().getHud().getBouton(i).estAppuye();
                    getJeu().getHud().getBouton(i).setEtat(true);
                    getJeu().getHud().choixPlante();
                }
            }
            getJeu().traitementChoix(x,y);
        }

        if(getBoutonPause().curseurEstDessus(x,y))
        {
            getBoutonPause().estAppuye();
        }
    }

}

void sfmlJeu::gestionsActionsRelacheClique(sf::Event & event,int x,int y)
{
    if(event.mouseButton.button==Mouse::Left)
    {
		if(getBoutonMenu().curseurEstDessus(x,y))
        {
            getBoutonMenu().changeEtat();
            getBoutonMenu().estRelache();
        }
        if(!enPause())
        {
            for(int i=0; i<getJeu().getHud().getTailleTabBoutons();i++)
            {
                if(getJeu().getHud().getBouton(i).curseurEstDessus(x,y))
                {
                    getJeu().getHud().getBouton(i).estRelache();
                }
            }
        }

        if(getBoutonPause().curseurEstDessus(x,y))
        {
            getBoutonPause().changeEtat();
            if(getBoutonPause().getEtat())
            {
                getBoutonPause().setTexteBouton("PLAY");
            }
            else getBoutonPause().setTexteBouton("PAUSE");
            getBoutonPause().estRelache();
        }
    }

    if(event.mouseButton.button==Mouse::Right)
    {
        getJeu().getHud().setChoix("");

        afficheStats(x,y);
    }
}

void sfmlJeu::gestionsActionsBougeCurseur(sf::Event & event, int x,int y)
{
    for(int i=0; i<getJeu().getHud().getTailleTabBoutons();i++)
    {
        if(getJeu().getHud().getBouton(i).curseurEstDessus(x,y))
        {
            getJeu().getHud().getBouton(i).estRelache();
        }
    }

    if(getBoutonPause().curseurEstDessus(x,y))
    {
        getBoutonPause().estRelache();
    }
	 if(getBoutonMenu().curseurEstDessus(x,y))
    {
        getBoutonMenu().estRelache();
    }
}


Bouton& sfmlJeu::getBoutonPause()
{
    return pause;
}

Bouton& sfmlJeu::getBoutonMenu()
{
    return menu;
}

bool sfmlJeu::enPause()
{
    return pause.getEtat();
}

void sfmlJeu::afficheCurseur(int x,int y)
{
    if(getJeu().getHud().getChoix() != "")
    {
        for(int i=0; i<getJeu().getHud().getTailleTabActions();i++)
        {
            if(getJeu().getHud().getChoix() == getJeu().getHud().getAction(i))
            {
                int id=i+1;
                Sprite tmp=tabSprite2D[1][id-1];
                tmp.setOrigin(40, 40);
                tmp.setPosition(Vector2f(x,y));
                window->draw(tmp);
            }
        }
    }
}

void sfmlJeu::afficheStats(int x,int y)
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    for(int i=0; i<getJeu().getTerrain().getNbLignes();i++)
    {
        for(list<Soleil>::iterator it=getJeu().getTerrain().getLigne(i).beginSoleil();it!=jeu.getTerrain().getLigne(i).endSoleil();it++)
        {
            if((*it).curseurEstDessus(x,y)) (*it).afficheStats();
        }
        for(list<Zombie>::iterator it=getJeu().getTerrain().getLigne(i).beginZombie();it!=jeu.getTerrain().getLigne(i).endZombie();it++)
        {
            if((*it).curseurEstDessus(x,y)) (*it).afficheStats();
        }
        for(list<Plante>::iterator it=getJeu().getTerrain().getLigne(i).beginPlante();it!=jeu.getTerrain().getLigne(i).endPlante();it++)
        {
            if((*it).curseurEstDessus(x,y)) (*it).afficheStats();
        }
        for(list<Projectile>::iterator it=getJeu().getTerrain().getLigne(i).beginProjectile();it!=jeu.getTerrain().getLigne(i).endProjectile();it++)
        {
            if((*it).curseurEstDessus(x,y)) (*it).afficheStats();
        }
        for(int j=0; j<getJeu().getTerrain().getLigne(i).getNbCases();j++)
        {
            if(getJeu().getTerrain().getLigne(i).getCase(j).curseurEstDessus(x,y))  getJeu().getTerrain().getLigne(i).getCase(j).afficheStats();
        }
    }

    if(getJeu().getHud().curseurEstDessus(x,y)) getJeu().getHud().afficheStats();

    cout<<"------------------------------"<<endl;
}
