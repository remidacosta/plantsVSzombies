#include "Hud.h"

Hud::Hud()
{
    choix ="";
    setPosition(Vecteur2D(0,0));
    setDimension(Vecteur2D(1,1));
}

Hud::Hud(const Vecteur2D & pos, const Vecteur2D & dim)
{
    assert(pos.getVectX() >= 0);
    assert(pos.getVectY() >= 0);
    assert(dim.getVectX() > 0);
    assert(dim.getVectY() > 0);

    choix="";
    setPosition(pos);
    setDimension(dim);
}

Vecteur2D Hud::getPosition()const
{
    return position;
}

void Hud::setPosition(const Vecteur2D & pos)
{
    position.setVectX(pos.getVectX());
    position.setVectY(pos.getVectY());
}


Vecteur2D Hud::getDimension()const
{
    return dimension;
}

void Hud::setDimension(const Vecteur2D & dim)
{
    dimension.setVectX(dim.getVectX());
    dimension.setVectY(dim.getVectY());
}


string Hud::getChoix()const
{
    return choix;
}

void Hud::setChoix(string action)
{
    choix = action;
}


std::string Hud::getAction(int indice)const
{
    return tabActions[indice];
}

void Hud::setAction(int indice, std::string action)
{
    assert(indice >= 0);

    tabActions[indice] = action;
}

int Hud::getTailleTabActions()const
{
    return tabActions.size();
}

int Hud::getIndiceAction(std::string action)const
{
    for(unsigned int i=0; i<tabActions.size() ;i++)
    {
        if(tabActions[i] == action)
        {
            return i;
        }
    }

    return -1;
}

void Hud::addAction(std::string action)
{
    if(!estDansTabActions(action))
    {
        tabActions.push_back(action);
    }
}


Bouton& Hud::getBouton(int indice)
{
    assert(indice>=0);

    return tabBoutons[indice];
}

void Hud::addBouton(const Bouton & bouton)
{
    tabBoutons.push_back(bouton);
}

int Hud::getTailleTabBoutons()const
{
    return tabBoutons.size();
}



void Hud::choixPlante()
{
    int compt = 0;
    int indice;
    for(int i=0; i<getTailleTabBoutons();i++)
    {
        if(getBouton(i).estActif())
        {
            compt++;
            indice = i;
            getBouton(i).changeEtat();
        }
    }

    if(compt == 1)
    {
        setChoix(tabActions[indice]);
    }
    if(compt==0)
    {
        setChoix("");
    }
}

void Hud::afficheTabActions()const
{
    for(unsigned int i=0; i<tabActions.size(); i++)
    {
        cout<<getAction(i)<<" ";
    }
    cout<<endl;
}

void Hud::afficheChoix()const
{
    cout<<getChoix()<<endl;
}

void Hud::affichePosition()const
{
    cout<<"("<<position.getVectX()<<","<<position.getVectY()<<")"<<endl;
}

void Hud::afficheDimension()const
{
    cout<<"("<<dimension.getVectX()<<","<<dimension.getVectY()<<")"<<endl;
}

bool Hud::curseurEstDessus(int x,int y)
{
    bool condSurX = ((getPosition().getVectX()<=x)&&(x<=getPosition().getVectX()+getDimension().getVectX()));
    bool condSurY = ((getPosition().getVectY()<=y)&&(y<=getPosition().getVectY()+getDimension().getVectY()));
    return(condSurX&&condSurY);
}

void Hud::afficheStats()
{
    cout<<"HUD"<<endl;
    cout<<"Position : ("<<getPosition().getVectX()<<","<<getPosition().getVectY()<<")"<<endl;
    cout<<"Dimension : ("<<getDimension().getVectX()<<","<<getDimension().getVectY()<<")"<<endl;
    cout<<"TabActions : ";
    for(int i=0; i<getTailleTabActions();i++)
    {
        cout<<getAction(i)<<" ";
    }
    cout<<endl;
    cout<<"Choix : "<<getChoix()<<endl;
    cout<<"TabBoutons etats : ";
    for(int i=0; i<getTailleTabBoutons();i++)
    {
        cout<<getBouton(i).getEtat()<<" ";
    }
    cout<<endl;
    cout<<endl;
}


void Hud::testRegression()
{
    setPosition(Vecteur2D(150,50));
    setDimension(Vecteur2D(2,2));
    addAction("plter");
    addAction("deterrer");
    addAction("xxxx");
    addAction("yyyy");
    addAction("rien");
    afficheTabActions();
    cout<<"test indice de deterrer :"<<getIndiceAction("plter")<<endl;
    setAction(0,"planter");

    affichePosition();
    afficheDimension();
    afficheChoix();
    afficheTabActions();

}

bool Hud::estDansTabActions(std::string action)const
{
    for(unsigned int i = 0; i<tabActions.size();i++)
    {
        if(tabActions[i] == action)
        {
            return true;
        }
    }
    return false;
}
