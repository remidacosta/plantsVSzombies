#include "ZoneDeTexte.h"

ZoneDeTexte::ZoneDeTexte()
{
    setTexte("");
    setPoliceCar("../data/big_noodle_titling.ttf");
    setAlignementX("gauche");
    setAlignementY("centre");
    setTchar(20);
    setDimension(Vecteur2D(400,200));
    setPosition(Vecteur2D(10,10));

    fond.setOutlineColor(sf::Color::White);
    fond.setOutlineThickness(1);
    fond.setFillColor(sf::Color::Black);
}

ZoneDeTexte::ZoneDeTexte(const Vecteur2D & pos, const Vecteur2D & dim, string text, int tailleCar)
{
    setTexte(text);
    setPoliceCar("../data/big_noodle_titling.ttf");
    setAlignementX("gauche");
    setAlignementY("centre");
    setTchar(tailleCar);
    setDimension(dim);
    setPosition(pos);
}

Vecteur2D& ZoneDeTexte::getPosition()
{
    return position;
}

void ZoneDeTexte::setPosition(const Vecteur2D & pos)
{
    position = pos;
    getFond().setPosition(sf::Vector2f(pos.getVectX(),pos.getVectY()));

    updateZone();
}


Vecteur2D& ZoneDeTexte::getDimension()
{
    return dimension;
}

void ZoneDeTexte::setDimension(const Vecteur2D & dim)
{
    dimension = dim;
    getFond().setSize(sf::Vector2f(dim.getVectX(),dim.getVectY()));

    updateZone();
}


int ZoneDeTexte::getTchar()const
{
    return tchar;
}

void ZoneDeTexte::setTchar(int t)
{
    tchar = t;

    updateZone();
}


string ZoneDeTexte::getTexte()const
{
    return texte;
}

void ZoneDeTexte::setTexte(string text)
{
    texte = text;

    updateZone();
}


string ZoneDeTexte::getMot(int numMot)const
{
    return tabMots[numMot];
}

void ZoneDeTexte::addMot(string mot)
{
    tabMots.push_back(mot);
}

void ZoneDeTexte::rmAllMots()
{
    tabMots.clear();
}

int ZoneDeTexte::getTailleTabMots()const
{
    return tabMots.size();
}


sf::Text& ZoneDeTexte::getLigne(int numLigne)
{
    return tabLignes[numLigne];
}

void ZoneDeTexte::addLigne(const sf::Text & ligne)
{
    tabLignes.push_back(ligne);
}

void ZoneDeTexte::rmAllLignes()
{
    tabLignes.clear();
}

int ZoneDeTexte::getTailleTabLignes()const
{
    return tabLignes.size();
}


void ZoneDeTexte::setPoliceCar(string file)
{
    policeCar.loadFromFile(file);

    updateZone();
}


sf::RectangleShape& ZoneDeTexte::getFond()
{
    return fond;
}

void ZoneDeTexte::setFond(const sf::RectangleShape & rect)
{
    fond.setFillColor(rect.getFillColor());
    fond.setOutlineColor(rect.getOutlineColor());
    fond.setOutlineThickness(rect.getOutlineThickness());
}


string ZoneDeTexte::getAlignementX()const
{
    return alignementX;
}

void ZoneDeTexte::setAlignementX(string mode)
{
    alignementX = mode;

    updateZone();
}

string ZoneDeTexte::getAlignementY()const
{
    return alignementY;
}

void ZoneDeTexte::setAlignementY(string mode)
{
    alignementY = mode;

    updateZone();
}


void ZoneDeTexte::testRegression()
{

}



void ZoneDeTexte::updateZone()
{
    rmAllLignes();
    rmAllMots();
    decoupageTexte();
    remplissageTabLignes();
    gestionAlignementTexte();
}


void ZoneDeTexte::decoupageTexte()
{
    stringstream ss(texte);
    string sousChaine;
    while (getline(ss, sousChaine, ' '))
    {
        tabMots.push_back(sousChaine);
    }

}

void ZoneDeTexte::remplissageTabLignes()
{
    int indiceMot = 0;
    string chaine;
    int compt = getTailleTabMots();
    int compt2;

    while(indiceMot != getTailleTabMots())
    {
        chaine = ""; compt2 = 0;
        for(int i= indiceMot;i<compt;i++)
        {
            chaine = chaine+getMot(i)+"  ";
            compt2++;
        }
        sf::Text tmp(chaine,policeCar,getTchar());
        if(tmp.getLocalBounds().width<getDimension().getVectX()-(0.05*getDimension().getVectX()))
        {
            addLigne(tmp);
            indiceMot = indiceMot + compt2;
            compt = getTailleTabMots();
        }
        else
        {
            compt--;
        }
    }
}

void ZoneDeTexte::gestionAlignementTexte()
{
    int posX, posY;
    for(int i=0; i<getTailleTabLignes();i++)
    {
        if(alignementX == "centre")
        {
            posX = aligneLigneCentreX(i);
        }
        if(alignementX == "gauche")
        {
            posX = aligneLigneGaucheX(i);
        }
        if(alignementX == "droite")
        {
            posX = aligneLigneDroiteX(i);
        }
        if(alignementX == "" || alignementX == " ")
        {
            posX = aligneLigneCentreX(i);
        }

        if(alignementY == "centre")
        {
            posY = aligneLigneCentreY(i);
        }
        if(alignementY == "haut")
        {
            posY = aligneLigneHautY(i);
        }
        if(alignementY == "bas")
        {
            posY = aligneLigneBasY(i);
        }
        if(alignementY == "" || alignementY == " ")
        {
            posY = aligneLigneCentreY(i);
        }

        getLigne(i).setPosition(posX,posY);
    }
}

int ZoneDeTexte::aligneLigneCentreX(int numLigne)
{
    int posInitX = getPosition().getVectX();
    int dimFondX = getDimension().getVectX();

    int posX = posInitX + (dimFondX-getLigne(numLigne).getLocalBounds().width)/2;
    return(posX);
}

int ZoneDeTexte::aligneLigneGaucheX(int numLigne)
{
    int posInitX = getPosition().getVectX();
    int dimFondX = getDimension().getVectX();

    int posX = posInitX + (0.05*dimFondX);
    return(posX);
}

int ZoneDeTexte::aligneLigneDroiteX(int numLigne)
{
    int posInitX = getPosition().getVectX();
    int dimFondX = getDimension().getVectX();
    int dimLigneX = getLigne(numLigne).getLocalBounds().width;

    int posX = posInitX + (dimFondX-dimLigneX);
    return(posX);
}

int ZoneDeTexte::aligneLigneCentreY(int numLigne)
{
    int posInitY = getPosition().getVectY();
    int dimY = getDimension().getVectY();
    int dimLigneY = getLigne(numLigne).getLocalBounds().height;
    int dimParaph = getTailleTabLignes()*dimLigneY ;

    int posY = posInitY + (dimY-dimParaph)/(getTailleTabLignes()+1);

    return(posY + numLigne*dimLigneY + numLigne*10);
}

int ZoneDeTexte::aligneLigneHautY(int numLigne)
{
    int posInitY = getPosition().getVectY();
    int dimY = getDimension().getVectY();
    int dimLigneY = getLigne(numLigne).getLocalBounds().height;

    int posY = posInitY + (0.05*dimY) + numLigne*dimLigneY;
    return(posY + numLigne*10);
}

int ZoneDeTexte::aligneLigneBasY(int numLigne)
{
    int posInitY = getPosition().getVectY();
    int dimY = getDimension().getVectY();
    int dimLigneY = getLigne(numLigne).getLocalBounds().height;
    int dimParaph = (getTailleTabLignes()+1)*dimLigneY + (getTailleTabLignes()-1)*10;

    int posY = posInitY + (dimY - dimParaph) + numLigne*dimLigneY;
    return(posY + numLigne*10);
}


