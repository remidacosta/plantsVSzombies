#include "EtapeTutoriel.h"

EtapeTutoriel::EtapeTutoriel(int nEtape)
{
    setNumEtape(nEtape);
    initZonetxt();
}

int EtapeTutoriel::getNumEtape()const
{
    return numEtape;
}

void EtapeTutoriel::setNumEtape(int n)
{
    numEtape = n;

    initZonetxt();
}


ZoneDeTexte& EtapeTutoriel::getZonetxt()
{
    return Zonetxt;
}



void EtapeTutoriel::initZonetxt()
{
    string linkFile = "data/tutoriel.txt";
    ifstream tmp(linkFile, ios::in);
    if(!tmp.is_open())
    {
        linkFile = "../data/tutoriel.txt";
    }
    tmp.close();

    ifstream fichier(linkFile, ios::in);  // on ouvre le fichier en lecture

    string mot; int num; string chaine = "";

    if(!fichier.is_open())
    {
        cout<<"erreur ouverture tutoriel.txt ../data/..."<<endl;
    }
    else
    {
        fichier>>mot;
        do
        {
            chaine = "";
            fichier>>num;
            fichier>>mot;
            while(mot != "Etape"&&!fichier.eof())
            {
                chaine = chaine + mot + " ";
                fichier>>mot;
            }
        }while(num != getNumEtape());

        getZonetxt().setTexte(chaine);
    }


    switch(getNumEtape())
    {
        case 0:
            getZonetxt().setPosition(Vecteur2D(160,500)); getZonetxt().setTchar(30); getZonetxt().setDimension(Vecteur2D(800,200));break;
        case 1:
            getZonetxt().setPosition(Vecteur2D(160,600)); getZonetxt().setTchar(20); getZonetxt().setDimension(Vecteur2D(600,100));break;
        case 2:
            getZonetxt().setPosition(Vecteur2D(160,600)); getZonetxt().setTchar(20); getZonetxt().setDimension(Vecteur2D(600,100));break;
        case 3:
            getZonetxt().setPosition(Vecteur2D(160,550)); getZonetxt().setTchar(20); getZonetxt().setDimension(Vecteur2D(600,150));break;
        case 4:
            getZonetxt().setPosition(Vecteur2D(160,600)); getZonetxt().setTchar(20); getZonetxt().setDimension(Vecteur2D(600,100));break;
        case 5:
            getZonetxt().setPosition(Vecteur2D(160,550)); getZonetxt().setTchar(20); getZonetxt().setDimension(Vecteur2D(600,150));break;
        case 6:
            getZonetxt().setPosition(Vecteur2D(160,600)); getZonetxt().setTchar(20); getZonetxt().setDimension(Vecteur2D(600,100));break;
        case 7:
            getZonetxt().setPosition(Vecteur2D(160,600)); getZonetxt().setTchar(20); getZonetxt().setDimension(Vecteur2D(600,100));break;
        case 8:
            getZonetxt().setPosition(Vecteur2D(160,600)); getZonetxt().setTchar(20); getZonetxt().setDimension(Vecteur2D(600,100));break;
        case 9:
            getZonetxt().setPosition(Vecteur2D(120,320)); getZonetxt().setTchar(30); getZonetxt().setDimension(Vecteur2D(800,80));break;
    }
}
