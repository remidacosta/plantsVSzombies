#include "Case.h"
#include <cassert>
#include <iostream>

Case::Case()
{
	setPosition(Vecteur2D(0,0));
	setDimension(Vecteur2D(80,80));
	setId(0);
}

Case::Case(const Vecteur2D & position,const Vecteur2D & dimension,int id)
{
	setPosition(position);
	setDimension(dimension);
	setId(id);
}

Vecteur2D Case::getPosition() const
{
	return position;
}

void Case::setPosition(const Vecteur2D & pos)
{
	assert(pos.getVectX() >= 0);
	assert(pos.getVectY() >= 0);

	position.setVectX(pos.getVectX());
	position.setVectY(pos.getVectY());
}


Vecteur2D Case::getDimension() const
{
	return dimension;
}

void Case::setDimension(const Vecteur2D & dim)
{
	assert(dim.getVectX() >= 0);
	assert(dim.getVectY() >= 0);

	dimension.setVectX(dim.getVectX());
	dimension.setVectY(dim.getVectY());
}


int Case::getId() const
{
	return id;
}

void Case::setId(int id)
{
	assert(id>=0);

	this->id=id;
}

bool Case::curseurEstDessus(int x,int y)const
{
    bool condSurX = ((getPosition().getVectX()<=x)&&(x<=getPosition().getVectX()+getDimension().getVectX()));
    bool condSurY = ((getPosition().getVectY()<=y)&&(y<=getPosition().getVectY()+getDimension().getVectY()));
    return(condSurX&&condSurY);
}


void Case::afficheStats()
{
    cout<<"CASE"<<endl;
    cout<<"Position : ("<<getPosition().getVectX()<<","<<getPosition().getVectY()<<")"<<endl;
    cout<<"Dimension : ("<<getDimension().getVectX()<<","<<getDimension().getVectY()<<")"<<endl;
    cout<<"Id : "<<getId()<<endl;
    cout<<endl;
}


void Case::testRegression()
{
	setPosition(Vecteur2D(2,2));
	cout<<getPosition().getVectX()<<" "<<getPosition().getVectY()<<endl;
	setDimension(Vecteur2D(5,5));
	cout<<getDimension().getVectX()<<" "<<getDimension().getVectY()<<endl;
	setId(3);
	cout<<getId()<<endl;
}
