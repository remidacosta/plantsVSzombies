#include "Vecteur2D.h"
#include <iostream>
using namespace std;

Vecteur2D::Vecteur2D()
{
    tx = 0;
    ty = 0;
}

Vecteur2D::Vecteur2D(int x, int y)
{
    tx = x;
    ty = y;
}

int Vecteur2D::getVectX()const
{
    return tx;
}

void Vecteur2D::setVectX(int x)
{
    tx = x;
}

int Vecteur2D::getVectY()const
{
    return ty;
}

void Vecteur2D::setVectY(int y)
{
    ty = y;
}

void Vecteur2D::testRegression()
{
	setVectX(2);
	cout<<getVectX()<<endl;
	setVectY(3);
	cout<<getVectY()<<endl;
}

bool operator==(Vecteur2D const& v1,Vecteur2D const& v2)
{
    return((v1.getVectX()==v2.getVectX())&&(v1.getVectY()==v2.getVectY()));
}
