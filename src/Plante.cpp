#include "Plante.h"

Plante::Plante()
{
    setPosition(Vecteur2D(0,0));
	setPv(1);
	setDegats(1);
	setPrix(100);
	setComptCadence(0);
	setCadence(1);
	setPortee(1);
	setId(1);
}
Plante::Plante(const Vecteur2D & pos, int pv, int degats, int prix, int cadence, int portee, int id)
{
    assert(pos.getVectX() >= 0);
  	assert(pos.getVectY() >= 0);
  	assert(pv>0);
  	assert(degats>=0);
  	assert(prix>=0);
  	assert(cadence>=0);
  	assert(portee>=0);
  	assert(id>=0);

	setPosition(pos);
	setPv(pv);
	setDegats(degats);
	setPrix(prix);
	setComptCadence(0);
	setCadence(cadence);
	setPortee(portee);
	setId(id);
}

Vecteur2D Plante::getPosition() const
{
	return position;
}

void Plante::setPosition(const Vecteur2D & pos)
{
	assert(pos.getVectX() >= 0);
	assert(pos.getVectY() >= 0);

	position.setVectX(pos.getVectX());
	position.setVectY(pos.getVectY());
}

int Plante::getPv() const
{
	return pv;
}

void Plante::setPv(int pv)
{
	this->pv=pv;
}


int Plante::getDegats() const
{
	return degats;
}

void Plante::setDegats(int degats)
{
    assert(degats>=0);

	this->degats=degats;
}


int Plante::getPrix() const
{
	return prix;
}

void Plante::setPrix(int prix)
{
    assert(prix>=0);

	this->prix=prix;
}

float Plante::getComptCadence() const
{
	return cadence[0];
}

void Plante::setComptCadence(float c)
{
    assert(c>=0);

	cadence[0] = c;
}

float Plante::getCadence() const
{
	return cadence[1];
}

void Plante::setCadence(float c)
{
    assert(c>=0);

	cadence[1] = c;
}


int Plante::getPortee() const
{
	return portee;
}

void Plante::setPortee(int portee)
{
    assert(portee>=0);

	this->portee=portee;
}


int Plante::getId() const
{
	return id;
}

void Plante::setId(int id)
{
	assert(id>=0);

	this->id=id;
}

bool operator==(const Plante & p1,const Plante & p2)
{
    return((p1.getPosition().getVectX()==p2.getPosition().getVectX())&&(p1.getPosition().getVectY()==p2.getPosition().getVectY()));
}

bool Plante::curseurEstDessus(int x,int y) const
{
    bool condSurX = ((getPosition().getVectX()<=x)&&(x<=getPosition().getVectX()+80));
    bool condSurY = ((getPosition().getVectY()<=y)&&(y<=getPosition().getVectY()+80));
    return(condSurX&&condSurY);
}


void Plante::afficheStats()
{
    cout<<"PLANTE"<<endl;
    cout<<"Position : ("<<getPosition().getVectX()<<","<<getPosition().getVectY()<<")"<<endl;
    cout<<"PV : "<<getPv()<<endl;
    cout<<"Degats : "<<getDegats()<<endl;
    cout<<"Prix : "<<getPrix()<<endl;
    cout<<"Cadence : "<<getComptCadence()<<"/"<<getCadence()<<endl;
    cout<<"Portee : "<<getPortee()<<endl;
    cout<<"Id : "<<getId()<<endl;
    cout<<endl;
}


void Plante::testRegression()
{
	setPosition(Vecteur2D(2,2));
	Vecteur2D positionPlante=getPosition();
	cout<<positionPlante.getVectX()<<" "<<positionPlante.getVectY()<<endl;
	setPv(2);
	cout<<getPv()<<endl;
	setDegats(3);
	cout<<getDegats()<<endl;
	setPrix(50);
	cout<<getPrix()<<endl;
	setCadence(3);
	cout<<getCadence()<<endl;
	setPortee(8);
	cout<<getPortee()<<endl;
	setId(2);
	cout<<getId()<<endl;
}
