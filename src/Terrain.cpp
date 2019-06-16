#include "Terrain.h"

Terrain::Terrain()
{
    setNbLignes(5);
	setPosition(Vecteur2D(160,160));
	setDimension(Vecteur2D(720,400));
	for(int i=0;i<getNbLignes();i++)
	{
		getLigne(i).setPosition(Vecteur2D(0+getPosition().getVectX(),i*80+getPosition().getVectY()));
		getLigne(i).setDimension(Vecteur2D(720,80));
		getLigne(i).setId(i);
		for(int j=0; j<getLigne(i).getNbCases();j++)
        	{
            		getLigne(i).getCase(j).setPosition(Vecteur2D(j*80+getPosition().getVectX(),i*80+getPosition().getVectY()));
        	}
	}
}

Terrain::Terrain(const Vecteur2D & position,const Vecteur2D & dimension)
{
    setNbLignes(5);
	setPosition(position);
	setDimension(dimension);
	for(int i=0;i<getNbLignes();i++)
	{
		getLigne(i).setPosition(Vecteur2D(0,i*80));
		getLigne(i).setDimension(Vecteur2D(720,80));
		getLigne(i).setId(i);
		for(int j=0; j<getLigne(i).getNbCases();j++)
        	{
            		getLigne(i).getCase(j).setPosition(Vecteur2D(j*80,i*80));
        	}
	}
}


int Terrain::getNbLignes()const
{
    return nbLignes;
}

void Terrain::setNbLignes(int nLignes)
{
    assert(nLignes > 0);

    nbLignes = nLignes;
}


Ligne& Terrain::getLigne(int id)
{
	return tabLignes[id];
}


Vecteur2D Terrain::getPosition() const
{
	return position;
}

void Terrain::setPosition(const Vecteur2D & pos)
{
	assert(pos.getVectX() >= 0);
	assert(pos.getVectY() >= 0);

	position.setVectX(pos.getVectX());
	position.setVectY(pos.getVectY());
}


Vecteur2D Terrain::getDimension() const
{
	return dimension;
}

void Terrain::setDimension(const Vecteur2D & dim)
{
	assert(dim.getVectX() >= 0);
	assert(dim.getVectY() >= 0);

	dimension.setVectX(dim.getVectX());
	dimension.setVectY(dim.getVectY());
}

void Terrain::affichePositionCases()
{
    for(int i=0; i< getDimension().getVectY(); i++)
    {
        for(int j=0; j<getDimension().getVectX(); j++)
        {
            Vecteur2D pos = getLigne(i).getCase(j).getPosition();
            cout<<"("<<pos.getVectX()<<","<<pos.getVectY()<<")";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Terrain::afficheIdCases()
{
    for(int i = 0; i< getDimension().getVectY(); i++)
    {
        int idL = getLigne(i).getId();
        cout<<idL<<"  ";
        for(int j=0; j<getDimension().getVectX(); j++)
        {
            int idC = getLigne(i).getCase(j).getId();
            cout<<idC;
        }
        cout<<endl;
    }
    cout<<endl;
}

void Terrain::testRegression()
{
	setPosition(Vecteur2D(3,3));
	cout<<getPosition().getVectX()<<" "<<getPosition().getVectY()<<endl;
	setDimension(Vecteur2D(4,4));
	cout<<getDimension().getVectX()<<" "<<getDimension().getVectY()<<endl;
	affichePositionCases();
	afficheIdCases();
}
