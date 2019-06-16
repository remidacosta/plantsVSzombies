#include "Projectile.h"

#include <cassert>
#include <string.h>
#include <time.h>


Projectile::Projectile()
{
	setDegats(1);
	setPosition(Vecteur2D(0,0));
	setComptVitesse(0);
	setVitesse(0);
}

Projectile::Projectile(const Vecteur2D & pos, int degats)
{
	assert(pos.getVectX() >= 0);
  	assert(pos.getVectY() >= 0);

	setDegats(degats);
	setPosition(pos);
	setComptVitesse(0);
	setVitesse(0);
}


int Projectile::getDegats() const
{
	return degats;
}

void Projectile::setDegats(int deg)
{
    degats=deg;
}

Vecteur2D Projectile::getPosition() const
{
    return position;
}

void Projectile::setPosition(const Vecteur2D & pos)
{
	assert(pos.getVectX() >= 0);
	assert(pos.getVectY() >= 0);

	position.setVectX(pos.getVectX());
	position.setVectY(pos.getVectY());
}

float Projectile::getComptVitesse()const
{
    return vitesse[0];
}

void Projectile::setComptVitesse(float c)
{
    assert(c>=0);

    vitesse[0] = c;
}

float Projectile::getVitesse()const
{
    return vitesse[1];
}

void Projectile::setVitesse(float c)
{
    assert(c>=0);

    vitesse[1] = c;
}

void Projectile::avance()
{
    setPosition(Vecteur2D(position.getVectX()+3, position.getVectY()));
}


bool Projectile::curseurEstDessus(int x,int y) const
{
    bool condSurX = ((getPosition().getVectX()<=x)&&(x<=getPosition().getVectX()+80));
    bool condSurY = ((getPosition().getVectY()<=y)&&(y<=getPosition().getVectY()+80));
    return(condSurX&&condSurY);
}


void Projectile::afficheStats()
{
    cout<<"PROJECTILE"<<endl;
    cout<<"Position : ("<<getPosition().getVectX()<<","<<getPosition().getVectY()<<")"<<endl;
    cout<<"Degats : "<<getDegats()<<endl;
    cout<<"Vitesse : "<<getComptVitesse()<<"/"<<getVitesse()<<endl;
    cout<<endl;
}


void Projectile::testRegression()
{
    cout<<"Position ("<<getPosition().getVectX()<<","<<getPosition().getVectY()<<")"<<endl;
    cout<<"  Degats : "<<getDegats()<<endl;
    setDegats(100); avance();
    cout<<"Position ("<<getPosition().getVectX()<<","<<getPosition().getVectY()<<")"<<endl;
    cout<<"  Degats : "<<getDegats()<<endl;
}


bool operator==(const Projectile & p1,const Projectile & p2)
{
    return((p1.getPosition().getVectX()==p2.getPosition().getVectX())&&(p1.getPosition().getVectY()==p2.getPosition().getVectY()));
}
