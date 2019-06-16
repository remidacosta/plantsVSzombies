#ifndef TERRAIN_H
#define TERRAIN_H
#include "Vecteur2D.h"
#include "Ligne.h"
using namespace std;

/**
* @class Terrain Terrain.h "src/Terrain.h"
* @brief La classe Terrain represente le terrain sur le quel est joue la partie
* 
* la classe gere le terrain tout au long du jeu.
*/
class Terrain
{
	private:

        int nbLignes;			/** nombres de ligne */
        Ligne tabLignes [5];    /** tableau de ligne qui compose le terrain */
        Vecteur2D position;     /** position 2D du terrain */
        Vecteur2D dimension;    /** dimension 2D du terrain */


	public:

        /**
        * @brief Constructeur par defaut
	*
        * Cree un Terrain
        */
        Terrain();

        /**
        * @brief Constructeur
	*
        * @param Vecteur2D : position du terrain
	* @param Vecteur2D : dimension du terrain
        */
        Terrain(const Vecteur2D &,const Vecteur2D &);

        /**
        * @brief Accesseur
	*
        * Renvoie un entier correspondant au nombre de lignes du terrain
	*@return un entier
        */
        int getNbLignes()const;

        /**
        * @brief Mutateur
	*
        * Modifie le nombre de lignes du terrain
        * @param int : nouveau nombre de ligne
        */
        void setNbLignes(int );

        /**
        * @brief Accesseur
	*
        * Renvoie une ligne du terrain
        * @param int :id de la ligne a renvoyer
	* @return une ligne
        */
        Ligne &getLigne(int);

        /**
        * @brief Accesseur
	*
        * Renvoie un Vecteur2D correspondant a la position du terrain*
	* @return un Vecteur2D
        */
        Vecteur2D getPosition() const;

        /**
        * @brief Mutateur
	*
        * Modifie la position du terrain
        * @param Vecteur2D : nouvelle position
        */
        void setPosition(const Vecteur2D &);

        /**
        * @brief Accesseur
	*
        * Renvoie un Vecteur2D correspondant a la dimension du terrain
	* @return un Vecteur2D
	*/
        Vecteur2D getDimension() const;

        /**
        * @brief Mutateur
	*
        * Modifie la dimension du terrain
        * @param Vecteur2D : nouvelle dimension du terrain
        */
        void setDimension(const Vecteur2D &);

        /**
        * @brief Affiche la position des cases du terrain dans la console
        */
        void affichePositionCases();

        /**
        * @brief Affiche l'id des cases du terrain dans la console
        */
        void afficheIdCases();

        /**
        * @brief Test de regression
	*
        * Teste l'ensemble des fonctions de la classe Terrain
        */
        void testRegression();
};

#endif
