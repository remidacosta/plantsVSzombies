#include "Ligne.h"
#include <list>

Ligne::Ligne()
{
    setNbCases(9);
	setPosition(Vecteur2D(0,0));
	setDimension(Vecteur2D(720,80));
	setId(0);
	setContientTondeuse(true);
	setTondeuse(NULL);

	for(int i=0;i<getNbCases();i++)
	{
		getCase(i).setId(i);
		getCase(i).setPosition(Vecteur2D(i*80,getId()*80));
	}
}

Ligne::Ligne(const Vecteur2D & position,const Vecteur2D & dimension,int id)
{
    setNbCases(10);
	setPosition(position);
	setDimension(dimension);
	setId(id);
	setContientTondeuse(true);
	setTondeuse(NULL);

	for(int i=0;i<getNbCases();i++)
	{
		getCase(i).setId(i);
		getCase(i).setPosition(Vecteur2D(i*80,getId()*80));
	}
}

Ligne::~Ligne()
{
	delete tondeuse;
	tondeuse=NULL;
}

bool Ligne::getContientTondeuse() const
{
	return contientTondeuse;
}

void Ligne::setContientTondeuse(bool contientTondeuse)
{
	this->contientTondeuse=contientTondeuse;
}

Tondeuse * Ligne::getTondeuse() const
{
	return tondeuse;
}

void Ligne::setTondeuse(Tondeuse * tondeuse)
{
	this->tondeuse=tondeuse;
}

Vecteur2D Ligne::getPosition() const
{
	return position;
}

void Ligne::setPosition(const Vecteur2D & pos)
{
	assert(pos.getVectX() >= 0);
	assert(pos.getVectY() >= 0);

	position.setVectX(pos.getVectX());
	position.setVectY(pos.getVectY());
}


Vecteur2D Ligne::getDimension() const
{
	return dimension;
}

void Ligne::setDimension(const Vecteur2D & dim)
{
	assert(dim.getVectX() >= 0);
	assert(dim.getVectY() >= 0);

	dimension.setVectX(dim.getVectX());
	dimension.setVectY(dim.getVectY());
}


int Ligne::getNbCases()const
{
    return nbCases;
}

void Ligne::setNbCases(int nCases)
{
    assert(nCases > 0);

    nbCases = nCases;
}


Case& Ligne::getCase(int id)
{
	return tabCases[id];
}


int Ligne::getId() const
{
	return id;
}

void Ligne::setId(int id)
{
	assert(id>=0);

	this->id=id;
}


void Ligne::addSoleil(const Soleil & soleil)
{
	soleils.push_back(soleil);
}

void Ligne::rmAllSoleils()
{
    soleils.clear();
}

list<Soleil>::iterator Ligne::rmSoleil(list<Soleil>::iterator soleil)
{
	list<Soleil>::iterator it=soleils.begin();
	bool rmFait = false;
	while(it!=soleils.end()&&!rmFait)
	{
		if((*it)==(*soleil))
        {
            it=soleils.erase(it);
            rmFait = true;
        }
        else
        {
            it++;
        }
	}
	return it;
}

list<Soleil>::iterator Ligne::beginSoleil()
{
    return soleils.begin();
}

list<Soleil>::iterator Ligne::endSoleil()
{
    return soleils.end();
}

int Ligne::getSizeSoleils()const
{
    return soleils.size();
}


void Ligne::addZombie(const Zombie & zombie)
{
	zombies.push_back(zombie);
}

void Ligne::rmAllZombies()
{
    zombies.clear();
}

list<Zombie>::iterator Ligne::rmZombie(list<Zombie>::iterator zombie)
{
	list<Zombie>::iterator it=zombies.begin();
	bool rmFait = false;
	while(it!=zombies.end()&&!rmFait)
	{
		if((*it)==(*zombie))
        {
            it=zombies.erase(it);
            rmFait = true;
        }
        else
        {
            it++;
        }
	}
	return it;
}

list<Zombie>::iterator Ligne::beginZombie()
{
    return zombies.begin();
}

list<Zombie>::iterator Ligne::endZombie()
{
    return zombies.end();
}

int Ligne::getSizeZombies()const
{
    return zombies.size();
}


void Ligne::addPlante(const Plante & plante)
{
	plantes.push_back(plante);
}

void Ligne::rmAllPlantes()
{
    plantes.clear();
}

list<Plante>::iterator Ligne::rmPlante(list<Plante>::iterator plante)
{
	list<Plante>::iterator it=plantes.begin();
	while(it!=plantes.end())
	{
		if((*it)==(*plante))
        {
            it=plantes.erase(it);
        }
        else
        {
            it++;
        }
	}
	return it;
}

list<Plante>::iterator Ligne::beginPlante()
{
    return plantes.begin();
}

list<Plante>::iterator Ligne::endPlante()
{
    return plantes.end();
}

int Ligne::getSizePlantes()const
{
    return plantes.size();
}


void Ligne::addProjectile(const Projectile & projectile)
{
    projectiles.push_back(projectile);
}

void Ligne::rmAllProjectiles()
{
    projectiles.clear();
}

list<Projectile>::iterator Ligne::rmProjectile(list<Projectile>::iterator projectile)
{
	list<Projectile>::iterator it=projectiles.begin();
	while(it!=projectiles.end())
	{
		if((*it)==(*projectile))
        {
            it=projectiles.erase(it);
        }
        else
        {
            it++;
        }
	}
	return it;
}

list<Projectile>::iterator Ligne::beginProjectile()
{
    return projectiles.begin();
}

list<Projectile>::iterator Ligne::endProjectile()
{
    return projectiles.end();
}

int Ligne::getSizeProjectiles()const
{
    return projectiles.size();
}


void Ligne::planteTire(list<Plante>::iterator itP)
{
    for(list<Plante>::iterator it0=beginPlante();it0!=endPlante();it0++)
    {
        if((*itP).getId()==(*it0).getId()&&(*itP).getPosition().getVectX()==(*it0).getPosition().getVectX())
        {
            Projectile proj;
            proj.setPosition(Vecteur2D((*itP).getPosition().getVectX()+40,(*itP).getPosition().getVectY()-20));
            proj.setDegats((*itP).getDegats());
            addProjectile(proj);
        }
    }
}


void Ligne::testRegression()
{
    cout<<"Position ("<<getPosition().getVectX()<<","<<getPosition().getVectY()<<")"<<endl;
    cout<<"contient tondeuse : "<<getContientTondeuse()<<endl;
}
