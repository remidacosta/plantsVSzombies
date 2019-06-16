#include "Jeu.h"
#include <list>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <time.h>

Jeu::Jeu()
{
    srand(time(NULL));
    Niveau * tmp = new Niveau;
	niveau = tmp;
	initConfigJeu();
    initHud();
}


Jeu::~Jeu()
{
	if(niveau != NULL)
	{
		delete niveau;
	}
	setNiveau(NULL);
}


Hud& Jeu::getHud()
{
	return hud;
}


void Jeu::setHud(const Hud & hud)
{
	this->hud=hud;
}


Terrain& Jeu::getTerrain()
{
    return terrain;
}


void Jeu::setTerrain(const Terrain & terrain)
{
    this->terrain=terrain;
}


Niveau * Jeu::getNiveau() const
{
	return niveau;
}


void Jeu::setNiveau(Niveau * niveau)
{
	this->niveau=niveau;
}


int Jeu::getNbSoleils() const
{
	return nbSoleils;
}


void Jeu::setNbSoleils(int nbSoleils)
{
	this->nbSoleils=nbSoleils;
}


bool Jeu::getPartieTerminee() const
{
	return partie_terminee;
}


void Jeu::setPartieTerminee(bool partie_terminee)
{
	this->partie_terminee=partie_terminee;
}


float Jeu::getComptCadenceSpawnSoleil()const
{
    return cadenceSpawnSoleil[0];
}

void Jeu::setComptCadenceSpawnSoleil(float c)
{
    assert(c>=0);

    cadenceSpawnSoleil[0] = c;
}

float Jeu::getCadenceSpawnSoleil()const
{
    return cadenceSpawnSoleil[1];
}

void Jeu::setCadenceSpawnSoleil(float c)
{

    cadenceSpawnSoleil[1] = c;
}


float Jeu::getComptCadenceSpawnZombie()const
{
    return cadenceSpawnZombie[0];
}

void Jeu::setComptCadenceSpawnZombie(float c)
{
    cadenceSpawnZombie[0] = c;
}

float Jeu::getCadenceSpawnZombie()const
{
    return cadenceSpawnZombie[1];
}

void Jeu::setCadenceSpawnZombie(float c)
{
    cadenceSpawnZombie[1] = c;
}


void Jeu::apparitionSoleil()
{
    int randomLigne = rand()%getTerrain().getNbLignes();

    int posXLigne = getTerrain().getLigne(randomLigne).getPosition().getVectX();
    int posYLigne = getTerrain().getLigne(randomLigne).getPosition().getVectY();
    int dimXLigne = getTerrain().getLigne(randomLigne).getDimension().getVectX();
    int dimYLigne = getTerrain().getLigne(randomLigne).getDimension().getVectY();

    int posX=rand()%(dimXLigne-80)+posXLigne;
    int posY=rand()%(dimYLigne-70)+posYLigne;

    Soleil soleil=Soleil(Vecteur2D(posX,posY));
    terrain.getLigne(randomLigne).addSoleil(soleil);
}


void Jeu::apparitionZombie()
{
    if(!(*niveau).estFini())
    {
        int id=(*niveau).getIdZombieFront();
        int randomLigne = rand()%getTerrain().getNbLignes();
        int posXLigne = getTerrain().getLigne(randomLigne).getPosition().getVectX()+
                        getTerrain().getLigne(randomLigne).getDimension().getVectX()-40;
        int ecartY = 40 - (getTerrain().getLigne(randomLigne).getSizeZombies())*5;
        int posYLigne;
        if(ecartY >=10) posYLigne = getTerrain().getLigne(randomLigne).getPosition().getVectY()-ecartY;
        else           posYLigne = getTerrain().getLigne(randomLigne).getPosition().getVectY()-10;

        Zombie zombie;
        (*niveau).rmIdZombie();
        if(100%(*niveau).getNbTotZombies() == 0)
            {
                (*niveau).setAvancement((*niveau).getAvancement()+ (100/(*niveau).getNbTotZombies()));
            }
            else (*niveau).setAvancement((*niveau).getAvancement()+ (100/(*niveau).getNbTotZombies()+1));

        zombie.setId(id);
        zombie.setPosition(Vecteur2D(posXLigne, posYLigne));
        zombie.setPV(getConfigZombie(id,"pv"));
        zombie.setDegats(getConfigZombie(id,"degats"));
        zombie.setCadence(getConfigZombie(id,"cadence"));
        zombie.setVitesse(getConfigZombie(id,"vitesse"));
        terrain.getLigne(randomLigne).addZombie(zombie);
    }
    else
    {
        int compt = 0;
        for(int i=0; i<getTerrain().getNbLignes();i++)
        {
            if(getTerrain().getLigne(i).getSizeZombies() == 0)
            {
                compt++;
            }
        }
        if(compt == getTerrain().getNbLignes())
        {
            niveauSuivant();
        }
    }
}


bool Jeu::plante_existe_ici(int x,int y)
{
    int numLigne = yEnNumLigne(y);
    for(list<Plante>::iterator it=getTerrain().getLigne(numLigne).beginPlante();it!=getTerrain().getLigne(numLigne).endPlante();it++)
    {
        if(((*it).getPosition().getVectX()<=x)&&(x<=(*it).getPosition().getVectX()+80)&&
           ((*it).getPosition().getVectY()<=y)&&(y<=(*it).getPosition().getVectY()+80))
            {
                return true;
            }
    }

    return false;

}


bool Jeu::soleil_existe_ici(int x,int y)
{
	int numLigne = yEnNumLigne(y);
    for(list<Soleil>::iterator it=getTerrain().getLigne(numLigne).beginSoleil();it!=getTerrain().getLigne(numLigne).endSoleil();it++)
    {
        if(((*it).getPosition().getVectX()<=x)&&(x<=(*it).getPosition().getVectX()+80)&&
           ((*it).getPosition().getVectY()<=y)&&(y<=(*it).getPosition().getVectY()+80))
            {
                return true;
            }
    }

    return false;
}


void Jeu::poserPlante(Plante plante, int numLigne, int numCase)
{
	int id = plante.getId();
	int posX = getTerrain().getLigne(numLigne).getCase(numCase).getPosition().getVectX();
	int posY = getTerrain().getLigne(numLigne).getCase(numCase).getPosition().getVectY();

	plante.setPosition(Vecteur2D(posX,posY-10));
    plante.setPv(getConfigPlante(id,"pv"));
    plante.setDegats(getConfigPlante(id,"degats"));
    plante.setPrix(getConfigPlante(id,"prix"));
    plante.setCadence(getConfigPlante(id,"cadence"));
    plante.setPortee(getConfigPlante(id,"portee"));

    terrain.getLigne(numLigne).addPlante(plante);
    setNbSoleils(getNbSoleils()-plante.getPrix());
}


void Jeu::ramasserSoleil(int x,int y)
{
    int numLigne = yEnNumLigne(y);
    bool fait = false;

    list<Soleil>::iterator it=getTerrain().getLigne(numLigne).beginSoleil();
    while(it!=getTerrain().getLigne(numLigne).endSoleil()&&!fait)
    {
        if((*it).curseurEstDessus(x,y))
        {
            setNbSoleils(getNbSoleils()+(*it).getEnergie());
            it=getTerrain().getLigne(numLigne).rmSoleil(it);
            fait = true;
        }
        else
        {
            it++;
        }
    }
}


void Jeu::setIdNiveau(int idN)
{
    delete niveau;
    Niveau * tmp = new Niveau(idN);
	niveau= tmp;
    initConfigJeu();
}


void Jeu::niveauSuivant()
{
	int idsuiv=niveau->getId() + 1;
	setIdNiveau(idsuiv);
}


bool Jeu::contactZombiePlante(list<Zombie>::iterator itZ,list<Plante>::iterator itP)
{
    return(((*itZ).getPosition().getVectX()<=(*itP).getPosition().getVectX()+40)&&((*itZ).getPosition().getVectX()>=(*itP).getPosition().getVectX()));
}


bool Jeu::contactProjectileZombie(list<Projectile>::iterator itP,list<Zombie>::iterator itZ)
{
    return(((*itZ).getPosition().getVectX()<=(*itP).getPosition().getVectX())&&((*itP).getPosition().getVectX()<=(*itZ).getPosition().getVectX()+80));
}


bool Jeu::zombiePeutAvancer(list<Zombie>::iterator it,int numLigne)
{
    if((*it).getPosition().getVectX()>getTerrain().getPosition().getVectX())
    {
        for(list<Plante>::iterator it2=getTerrain().getLigne(numLigne).beginPlante();it2!=getTerrain().getLigne(numLigne).endPlante();it2++)
        {
            if(contactZombiePlante(it,it2))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}


bool Jeu::projectilePeutAvancer(list<Projectile>::iterator it,int numLigne)
{
    if((*it).getPosition().getVectX()<=getTerrain().getPosition().getVectX()+getTerrain().getDimension().getVectX()+10)
    {
        for(list<Zombie>::iterator it2=getTerrain().getLigne(numLigne).beginZombie();it2!=getTerrain().getLigne(numLigne).endZombie();it2++)
        {
            if(contactProjectileZombie(it,it2))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}


bool Jeu::plantePeutTirer(list<Plante>::iterator it,int numLigne)
{
    for(list<Zombie>::iterator it2=getTerrain().getLigne(numLigne).beginZombie();it2!=getTerrain().getLigne(numLigne).endZombie();it2++)
    {
        if((*it).getPosition().getVectX()<=(*it2).getPosition().getVectX())
        {
            return true;
        }
    }
    return false;
}


void Jeu::actionsAuto()
{
    for(int i=0;i<getTerrain().getNbLignes();i++)
    {
        for(list<Plante>::iterator it=getTerrain().getLigne(i).beginPlante();it!=getTerrain().getLigne(i).endPlante();it++)
		{
			if((*it).getComptCadence()==(*it).getCadence())
            {
                actionPlante(it,i);
                (*it).setComptCadence(0);
            }
            else
            {
                (*it).setComptCadence((*it).getComptCadence()+1);
            }
		}
		for(list<Zombie>::iterator it=getTerrain().getLigne(i).beginZombie();it!=getTerrain().getLigne(i).endZombie();it++)
		{
		    if((*it).getComptCadence()==(*it).getCadence())
            {
                attaqueZombie(it,i);
                (*it).setComptCadence(0);
            }
            else
            {
                (*it).setComptCadence((*it).getComptCadence()+1);
            }

            if((*it).getComptVitesse()<0)
            {
                avanceZombie(it,i);
                (*it).setComptVitesse((*it).getComptVitesse()+1);
            }
            if(((*it).getComptVitesse()>=0)&&((*it).getComptVitesse()<(*it).getVitesse()))
            {
                (*it).setComptVitesse((*it).getComptVitesse()+1);
            }
			if((*it).getComptVitesse()==(*it).getVitesse())
            {
                (*it).setComptVitesse(-20);
            }

		}

		if(getTerrain().getLigne(i).getTondeuse()!=NULL)
		{
			if(getTerrain().getLigne(i).getTondeuse()->getComptVitesse()==getTerrain().getLigne(i).getTondeuse()->getVitesse())
            {
                getTerrain().getLigne(i).getTondeuse()->setComptVitesse(0);
                avanceTondeuse(i);
            }
            else
            {
                int tmp = getTerrain().getLigne(i).getTondeuse()->getComptVitesse()+1;
                getTerrain().getLigne(i).getTondeuse()->setComptVitesse(tmp);
            }
		}
		else
        {
            gestionTondeuse(i);
        }

		for(list<Projectile>::iterator it=getTerrain().getLigne(i).beginProjectile();it!=getTerrain().getLigne(i).endProjectile();it++)
		{
			if((*it).getComptVitesse()==(*it).getVitesse())
            {
                actionProjectile(it,i);
                (*it).setComptVitesse(0);
            }
            else
            {
                (*it).setComptVitesse((*it).getComptVitesse()+1);
            }
		}
		for(list<Soleil>::iterator it=getTerrain().getLigne(i).beginSoleil();it!=getTerrain().getLigne(i).endSoleil();it++)
		{
            //peut-être inutile
		}
    }

    if(getComptCadenceSpawnZombie()==getCadenceSpawnZombie())
    {
        apparitionZombie();
        setComptCadenceSpawnZombie(0);
    }
    else
    {
        setComptCadenceSpawnZombie(getComptCadenceSpawnZombie()+1);
    }

    if(getComptCadenceSpawnSoleil()==getCadenceSpawnSoleil())
    {
        apparitionSoleil();
        setComptCadenceSpawnSoleil(0);
    }
    else
    {
        setComptCadenceSpawnSoleil(getComptCadenceSpawnSoleil()+1);
    }
}


void Jeu::avanceZombie(list<Zombie>::iterator it1,int i)
{
    if(zombiePeutAvancer(it1,i))
    {
        (*it1).avance();
    }
}

void Jeu::attaqueZombie(list<Zombie>::iterator it1,int i)
{
    for(list<Plante>::iterator it2=getTerrain().getLigne(i).beginPlante();it2!=getTerrain().getLigne(i).endPlante();it2++)
    {
        if(contactZombiePlante(it1,it2))
        {
            if(((*it2).getPv()-(*it1).getDegats())<=0)
            {
                it2=getTerrain().getLigne(i).rmPlante(it2);
            }
            else
            {
                (*it2).setPv((*it2).getPv()-(*it1).getDegats());
            }
        }
    }

}


void Jeu::actionPlante(list<Plante>::iterator it0,int i)
{
    if((*it0).getId()==1)
    {
        if(plantePeutTirer(it0,i))
        {
            getTerrain().getLigne(i).planteTire(it0);
        }
    }
    if((*it0).getId()==2)
    {
        int posX=(*it0).getPosition().getVectX();
        int posY=(*it0).getPosition().getVectY();

        int ecartX = rand()%20 - 10;
        Soleil soleil=Soleil(Vecteur2D(posX+ecartX,posY));
        terrain.getLigne(i).addSoleil(soleil);
    }
}


void Jeu::actionProjectile(list<Projectile>::iterator it0,int i)
{
    if(getTerrain().getLigne(i).getSizeZombies()==0)
    {
        if(projectilePeutAvancer(it0,i))
        {
            (*it0).avance();
        }
        else
        {
            it0=getTerrain().getLigne(i).rmProjectile(it0);
        }
    }
    else
    {
        if(projectilePeutAvancer(it0,i))
        {
            (*it0).avance();
        }
        else
        {
            for(list<Zombie>::iterator it1=getTerrain().getLigne(i).beginZombie(); it1!=getTerrain().getLigne(i).endZombie(); it1++)
            {
                if(contactProjectileZombie(it0,it1))
                {
                    if(((*it1).getPV()-(*it0).getDegats())<=0)
                    {
                        it1=getTerrain().getLigne(i).rmZombie(it1);
                    }
                    else
                    {
                         (*it1).setPV((*it1).getPV()-(*it0).getDegats());
                         (*it1).setEtatTouche(true);
                    }
                    it0=getTerrain().getLigne(i).rmProjectile(it0);
                }
            }
        }
    }
}

void Jeu::avanceTondeuse(int i)
{
    if(getTerrain().getLigne(i).getTondeuse()!=NULL)
    {
        for(list<Zombie>::iterator it=getTerrain().getLigne(i).beginZombie();it!=getTerrain().getLigne(i).endZombie();it++)
        {
            if((*it).getPosition().getVectX()<=getTerrain().getLigne(i).getTondeuse()->getPosition().getVectX())
                it=getTerrain().getLigne(i).rmZombie(it);
        }
        getTerrain().getLigne(i).getTondeuse()->avance();
        if(getTerrain().getLigne(i).getTondeuse()->getPosition().getVectX()>getTerrain().getPosition().getVectX()+getTerrain().getDimension().getVectX()-40)
        {
            delete getTerrain().getLigne(i).getTondeuse();
            getTerrain().getLigne(i).setTondeuse(NULL);
        }
    }
}

void Jeu::planteTire()
{
    for(int i=0; i<getTerrain().getNbLignes(); i++)
    {
        for(list<Plante>::iterator it0=getTerrain().getLigne(i).beginPlante();it0!=getTerrain().getLigne(i).endPlante();it0++)
        {
            if(plantePeutTirer(it0,i))
            {
                getTerrain().getLigne(i).planteTire(it0);
            }
        }
    }
}

void Jeu::gestionTondeuse(int i)
{
    if(getTerrain().getLigne(i).getContientTondeuse())
    {
        for(list<Zombie>::iterator it=getTerrain().getLigne(i).beginZombie();it!=getTerrain().getLigne(i).endZombie();it++)
        {
            if((*it).getPosition().getVectX() <= getTerrain().getPosition().getVectX())
            {
                getTerrain().getLigne(i).setContientTondeuse(false);
                Tondeuse * tmp=new Tondeuse(getTerrain().getLigne(i).getPosition());
                getTerrain().getLigne(i).setTondeuse(tmp);
            }
        }
    }
    else
    {
        for(list<Zombie>::iterator it=getTerrain().getLigne(i).beginZombie();it!=getTerrain().getLigne(i).endZombie();it++)
        {
            if((*it).getPosition().getVectX() <= getTerrain().getPosition().getVectX())
            {
                setPartieTerminee(true);
            }
        }
    }
}

void Jeu::traitementChoix(int x,int y)
{
    for(int i=0; i<getTerrain().getNbLignes();i++)
    {
        for(int j=0; j<getTerrain().getLigne(i).getNbCases(); j++)
        {
            if(getTerrain().getLigne(i).getCase(j).curseurEstDessus(x,y))
            {
                for(int k=0; k<getHud().getTailleTabActions();k++)
                {
                    if(getHud().getChoix() == getHud().getAction(k))
                    {
                        if(!plante_existe_ici(x,y))
                        {
                            if(getNbSoleils()-getConfigPlante(k+1,"prix") >=0)
                            {
                                Plante plante;
                                plante.setId(k+1);
                                poserPlante(plante,i,j);
                                getHud().setChoix("");
                            }
                        }
                    }
                }
            }
        }
    }
}


int Jeu::getConfigPlante(int id,string nomAction)
{
    string linkFile = "data/configPlantes.txt";
    ifstream tmp(linkFile, ios::in);
    if(!tmp.is_open())
    {
        linkFile = "../data/configPlantes.txt";
    }
    tmp.close();

    ifstream fichier(linkFile, ios::in);


    string mot;
    int numId, nbPv, nbDegats, nbPrix, nbCadence, nbPortee;

    if(!fichier.is_open())
    {
        cout<<"erreur ouverture configPlantes.txt"<<endl;
    }
    else
    {
        fichier>>mot>>mot>>mot>>mot>>mot>>mot>>mot;
        do
        {
            fichier>>numId;
            fichier>>mot;
            fichier>>nbPv>>nbDegats>>nbPrix>>nbCadence>>nbPortee;
        }while(numId != id);

        fichier.close();

        if(nomAction=="pv")      return(nbPv);
        if(nomAction=="degats")  return(nbDegats);
        if(nomAction=="prix")    return(nbPrix);
        if(nomAction=="cadence") return(nbCadence);
        if(nomAction=="portee")  return(nbPortee);
    }
    return -1;
}


int Jeu::getConfigZombie(int id, string nomAction)
{
    string linkFile = "data/configZombies.txt";
    ifstream tmp(linkFile, ios::in);
    if(!tmp.is_open())
    {
        linkFile = "../data/configZombies.txt";
    }
    tmp.close();

    ifstream fichier(linkFile, ios::in);  // on ouvre le fichier en lecture


    string mot;
    int numId, nbPv, nbDegats, nbCadence, nbVitesse;

    if(!fichier.is_open())
    {
        cout<<"erreur ouverture configZombies.txt ../data/..."<<endl;
    }
    else
    {
        fichier>>mot>>mot>>mot>>mot>>mot>>mot;
        do
        {
            fichier>>numId;
            fichier>>mot;
            fichier>>nbPv>>nbDegats>>nbCadence>>nbVitesse;
        }while(numId != id);

        fichier.close();
        if(nomAction=="pv")     return(nbPv);
        if(nomAction=="degats") return(nbDegats);
        if(nomAction=="cadence") return(nbCadence);
        if(nomAction=="vitesse") return(nbVitesse);
    }
    return -1;
}

int Jeu::xEnNumCase(int x)
{
    int posX, dimX;
    for(int i=0; i<getTerrain().getLigne(1).getNbCases();i++)
    {
        posX = getTerrain().getLigne(1).getCase(i).getPosition().getVectX();
        dimX = getTerrain().getLigne(1).getCase(i).getDimension().getVectX();
        if((posX<=x)&&(x<=posX+dimX))
        {
            return(getTerrain().getLigne(1).getCase(i).getId());
        }
    }
    return -1;
}

int Jeu::yEnNumLigne(int y)
{
    int posY, dimY;
    for(int i=0; i<getTerrain().getNbLignes();i++)
    {
        posY = getTerrain().getLigne(i).getPosition().getVectY();
        dimY = getTerrain().getLigne(i).getDimension().getVectY();
        if((posY<=y)&&(y<=posY+dimY))
        {
            return(getTerrain().getLigne(i).getId());
        }
    }
    return -1;
}


void Jeu::initHud()
{
    hud.setPosition(Vecteur2D(160,20));
	hud.setDimension(Vecteur2D(280,100));
	hud.addAction("tireur");
	hud.addAction("tournesol");
	hud.addAction("noix");

	for(int i=0; i<hud.getTailleTabActions();i++)
    {
        int dimXBouton = 80;
        int dimYBouton = 80;
        int posXBouton = hud.getPosition().getVectX() + (i+1)*10 + i*dimXBouton;
        int posYBouton = hud.getPosition().getVectY() + 10;

        Bouton b(Vecteur2D(posXBouton,posYBouton) , Vecteur2D(dimXBouton,dimYBouton));
        getHud().addBouton(b);
    }
}

void Jeu::initConfigJeu()
{
    for(int i=0; i<getTerrain().getNbLignes();i++)
    {
        getTerrain().getLigne(i).rmAllPlantes();
        getTerrain().getLigne(i).rmAllProjectiles();
        getTerrain().getLigne(i).rmAllSoleils();
        getTerrain().getLigne(i).setTondeuse(NULL);
        getTerrain().getLigne(i).setContientTondeuse(true);
    }
    setPartieTerminee(false);
    setComptCadenceSpawnSoleil(0);
    setComptCadenceSpawnZombie(-200);

    if(getNiveau()->getModeJeu()=="Tutoriel")
    {
        setNbSoleils(100);
        setCadenceSpawnSoleil(200);
        setCadenceSpawnZombie(50);
    }
    if(getNiveau()->getModeJeu()=="Normal")
    {
        setNbSoleils(100);
        setCadenceSpawnSoleil(400);
        setCadenceSpawnZombie(500);
    }
    if(getNiveau()->getModeJeu()=="Difficile")
    {
        setNbSoleils(100);
        setCadenceSpawnSoleil(400);
        setCadenceSpawnZombie(300);
    }
    if(getNiveau()->getModeJeu()=="Cauchemar")
    {
        setNbSoleils(1000);
        setCadenceSpawnSoleil(-1);
        setCadenceSpawnZombie(100);
    }
}
