#ifndef TONDEUSE_H
#define TONDEUSE_H
#include <iostream>
#include <string.h>
#include <cassert>
#include "Vecteur2D.h"
using namespace std;

/**
* @class Tondeuse Tondeuse.h "src/Tondeuse.h"
* @brief La classe Tondeuse represente les tondeuses au cours de la partie
* 
* la classe gère les Tondeuses tout au long du jeu.
*/
class Tondeuse
{
	private:
	Vecteur2D position;    /** position du coin haut gauche de la tondeuse */
	float vitesse[2];		/** tableau de deux floats un compteur et une borne max pour la vitesse de la tondeuse*/

	public:
	/**
	* @brief Constructeur par défaut
	*
	* Crée une tondeuse
	*/
        Tondeuse();

        /**
        * @brief Constructeur
	*
        * Crée une tondeuse
        * @param Vecteur2D : position tondeuse
        */
        Tondeuse(const Vecteur2D &);

        /**
        * @brief Accesseur
	*
        * Renvoie un Vecteur2D correspondant à la position de la tondeuse
	* @return un Vecteur2D
        */
        Vecteur2D getPosition() const;

        /**
        * @brief Mutateur
	*
        * Modifie la valeur de la position de la tondeuse
        * @param Vecteur2D : nouvelle position tondeuse
        */
        void setPosition(const Vecteur2D &);

        /**
        * @brief Accesseur
	*
	* Renvoie  un réel correspondant au compteur de la tondeuse
	*@return un float
        */
        float getComptVitesse()const;

        /**
        * @brief Mutateur
	*
        * Modifie la valeur du compteur de la tondeuse
        * @param float : nouvelle valeur du compteur
        */
        void setComptVitesse(float);

        /**
        * @brief Accesseur
	*
        * Renvoie un réel correspondant à la vitesse de la tondeuse
	* @return un float
        */
        float getVitesse()const;

        /**
        * @brief Mutateur
	*
	* Modifie la valeur de la vitesse de la tondeuse
        * @param float : nouvelle vitesse
        */
        void setVitesse(float);

        /**
        * @brief Fait avancer la tondeuse
	*
        * Augmente l'abscisse de la position de la tondeuse
        */
        void avance();
};

/**
* @brief surchage operateur ==
*
* surchage l'operateur "==" pour la classe tondeuse
* @param Tondeuse t1 : pour la comparaison
* @param Tondeuse t2 : pour la comparaison
* @return renvoie un bool résultat de la comparaison
*/
bool operator==(const Tondeuse & t1,const Tondeuse & t2);

#endif
