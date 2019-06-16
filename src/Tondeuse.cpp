#include "Tondeuse.h"

Tondeuse::Tondeuse()
{
	setPosition(Vecteur2D(0,0));
	setComptVitesse(0);
	setVitesse(1);
}

Tondeuse::Tondeuse(const Vecteur2D & position)
{
	setPosition(position);
	setComptVitesse(0);
	setVitesse(1);
}

Vecteur2D Tondeuse::getPosition() const
{
	return position;
}

void Tondeuse::setPosition(const Vecteur2D & pos)
{
	assert(pos.getVectX() >= 0);
	assert(pos.getVectY() >= 0);

	position.setVectX(pos.getVectX());
	position.setVectY(pos.getVectY());
}

float Tondeuse::getComptVitesse()const
{
    return vitesse[0];
}

void Tondeuse::setComptVitesse(float c)
{
    assert(c>=0);

    vitesse[0] = c;
}

float Tondeuse::getVitesse()const
{
    return vitesse[1];
}

void Tondeuse::setVitesse(float c)
{
    assert(c>=0);

    vitesse[1] = c;
}


void Tondeuse::avance()
{
	setPosition(Vecteur2D(getPosition().getVectX()+5, getPosition().getVectY()));
}

bool operator==(const Tondeuse & t1,const Tondeuse & t2)
{
    return((t1.getPosition().getVectX()==t2.getPosition().getVectX())&&(t1.getPosition().getVectY()==t2.getPosition().getVectY()));
}




