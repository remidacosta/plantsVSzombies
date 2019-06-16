#include "Soleil.h"
#include <cassert>
#include <string.h>
#include <time.h>

using namespace std;

Soleil::Soleil()
{
	setPosition(Vecteur2D(0,0));
	setDimension(Vecteur2D(80,80));
	setEnergie(25);
	setComptVitesse(0);
	setVitesse(1);
}

Soleil::Soleil(const Vecteur2D & pos)
{
	assert(pos.getVectX() >= 0);
  	assert(pos.getVectY() >= 0);
	setPosition(pos);
	setDimension(Vecteur2D(80,80));
	setEnergie(25);
}

Vecteur2D Soleil::getPosition() const
{
	return position;
}

void Soleil::setPosition(const Vecteur2D & pos)
{
	assert(pos.getVectX() >= 0);
	assert(pos.getVectY() >= 0);

	position.setVectX(pos.getVectX());
	position.setVectY(pos.getVectY());

}

Vecteur2D Soleil::getDimension() const
{
	return dimension;
}

void Soleil::setDimension(const Vecteur2D & dim)
{
	assert(dim.getVectX() >= 0);
	assert(dim.getVectY() >= 0);

	dimension.setVectX(dim.getVectX());
	dimension.setVectY(dim.getVectY());

}

int Soleil::getEnergie() const
{
	return energie;
}

void Soleil::setEnergie(int ener)
{
	energie = ener;
}

float Soleil::getComptVitesse()const
{
    return vitesse[0];
}

void Soleil::setComptVitesse(float c)
{
    assert(c>=0);

    vitesse[0] = c;
}

float Soleil::getVitesse()const
{
    return vitesse[1];
}

void Soleil::setVitesse(float c)
{
    assert(c>=0);

    vitesse[1] = c;
}

bool Soleil::curseurEstDessus(int x,int y) const
{
    bool condSurX = ((getPosition().getVectX()<=x)&&(x<=getPosition().getVectX()+getDimension().getVectX()));
    bool condSurY = ((getPosition().getVectY()<=y)&&(y<=getPosition().getVectY()+getDimension().getVectY()));
    return(condSurX&&condSurY);
}

void Soleil::afficheStats()const
{
    cout<<"SOLEIL"<<endl;
    cout<<"Position : ("<<getPosition().getVectX()<<","<<getPosition().getVectY()<<")"<<endl;
    cout<<"Dimension : ("<<getDimension().getVectX()<<","<<getDimension().getVectY()<<")"<<endl;
    cout<<"Energie : "<<getEnergie()<<endl;
    cout<<endl;
}

void Soleil::testRegression()
{
    cout<<"Position ("<<getPosition().getVectX()<<","<<getPosition().getVectY()<<")"<<endl;
    cout<<"Energie : "<<getEnergie()<<endl;
    setEnergie(20);
    cout<<"Position ("<<getPosition().getVectX()<<","<<getPosition().getVectY()<<")"<<endl;
    cout<<"Energie : "<<getEnergie()<<endl;
}


bool operator==(const Soleil & s1,const Soleil & s2)
{
    return((s1.getPosition().getVectX()==s2.getPosition().getVectX())&&(s1.getPosition().getVectY()==s2.getPosition().getVectY()));
}

bool operator!=(const Soleil & s1,const Soleil & s2)
{
    return((s1.getPosition().getVectX()!=s2.getPosition().getVectX())||(s1.getPosition().getVectY()!=s2.getPosition().getVectY()));
}



