#include "Zombie.h"

#include <cassert>
#include <string.h>
#include <random>
#include <time.h>


Zombie::Zombie()
{
    srand(time(NULL));
	setPosition(Vecteur2D(0,0));
	setPV(100);
	setDegats(1);
	setId(0);
	setComptCadence(0);
	setComptVitesse(-20);
	setCadence(1);
	setVitesse(3);
	setEtatAttaque(false);
	setEtatTouche(false);
}

Zombie::Zombie(const Vecteur2D & pos,int pv,int id)
{
	assert(pos.getVectX() >= 0);
  	assert(pos.getVectY() >= 0);

  	srand(time(NULL));
	setPosition(pos);
	setPV(pv);
	setDegats(1);
	setId(id);
    setComptCadence(0);
	setComptVitesse(-20);
	setCadence(1);
	setVitesse(3);
	setEtatAttaque(false);
	setEtatTouche(false);
}

Vecteur2D Zombie::getPosition() const
{
    return position;
}

void Zombie::setPosition(const Vecteur2D & pos)
{
	assert(pos.getVectX() >= 0);
	assert(pos.getVectY() >= 0);

	position.setVectX(pos.getVectX());
	position.setVectY(pos.getVectY());
}

int Zombie::getPV() const
{
    return pv;
}

void Zombie::setPV(int ptdv)
{
    pv=ptdv;
}


int Zombie::getDegats() const
{
	return degats;
}

void Zombie::setDegats(int deg)
{
    degats=deg;
}


int Zombie::getId () const
{
    return id;
}

void Zombie::setId(int ID)
{
    id=ID;
}


float Zombie::getComptCadence() const
{
	return cadence[0];
}

void Zombie::setComptCadence(float c)
{
    assert(c>=0);

	cadence[0] = c;
}

float Zombie::getCadence() const
{
	return cadence[1];
}

void Zombie::setCadence(float c)
{
    assert(c>=0);

	cadence[1] = c;
}


float Zombie::getComptVitesse() const
{
	return vitesse[0];
}

void Zombie::setComptVitesse(float c)
{

	vitesse[0] = c;
}

float Zombie::getVitesse() const
{
	return vitesse[1];
}

void Zombie::setVitesse(float c)
{
    assert(c>=0);

	vitesse[1] = c;
}

bool Zombie::getEtatAttaque()const
{
    return etat[0];
}

void Zombie::setEtatAttaque(bool e)
{
    etat[0] = e;
}


bool Zombie::getEtatTouche()const
{
    return etat[1];
}

void Zombie::setEtatTouche(bool e)
{
    etat[1] = e;
}


void Zombie::avance()
{
    setPosition(Vecteur2D(position.getVectX()-1,position.getVectY()));
}


bool Zombie::curseurEstDessus(int x,int y) const
{
    bool condSurX = ((getPosition().getVectX()<=x)&&(x<=getPosition().getVectX()+80));
    bool condSurY = ((getPosition().getVectY()<=y)&&(y<=getPosition().getVectY()+80));
    return(condSurX&&condSurY);
}


void Zombie::afficheStats()
{
    cout<<"ZOMBIE"<<endl;
    cout<<"Position : ("<<getPosition().getVectX()<<","<<getPosition().getVectY()<<")"<<endl;
    cout<<"PV : "<<getPV()<<endl;
    cout<<"Degats : "<<getDegats()<<endl;
    cout<<"CadenceFrappe : "<<getComptCadence()<<"/"<<getCadence()<<endl;
    cout<<"CadenceAvance : "<<getComptVitesse()<<"/"<<getVitesse()<<endl;
    cout<<"Id : "<<getId()<<endl;
    cout<<endl;
}


void Zombie::testRegression()
{
    cout<<"Position ("<<getPosition().getVectX()<<","<<getPosition().getVectY()<<")"<<endl;
    cout<<"PV : "<<getPV()<<"  Degats : "<<getDegats()<<"  Id : "<<getId();
    setPV(200); setDegats(5); setId(2); avance();
    cout<<endl;
    cout<<"Position ("<<getPosition().getVectX()<<","<<getPosition().getVectY()<<")"<<endl;
    cout<<"PV : "<<getPV()<<"  Degats : "<<getDegats()<<"  Id : "<<getId();
}


bool operator==(const Zombie & z1,const Zombie & z2)
{
    return((z1.getPosition().getVectX()==z2.getPosition().getVectX())&&(z1.getPosition().getVectY()==z2.getPosition().getVectY()));
}
