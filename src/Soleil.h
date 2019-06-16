#ifndef SOLEIL_H
#define SOLEIL_H
#include <iostream>
#include <string.h>
#include "Vecteur2D.h"
using namespace std;

/**
* @class Soleil Soleil.h "src/Soleil.h"
* @brief La classe Soleil représente un soleil, la ressource du jeu
*
*la classe gère les soleils tout au long du jeu
*/
class Soleil
{
	private :
        Vecteur2D position;		/** position du coin haut du sprite du soleil */
        Vecteur2D dimension;	/** dimension du sprite, correspond au coin bas droit du sprite */
        float vitesse[2];		/** vitesse d'apparition du soleil */
        int energie;            /** valeur du soleil  */

	public :

	/**
	* @brief Constructeur par défaut
	*
	* Constructeur par defaut de la classe soleil
	*/
        Soleil();

        /**
        * @brief Constructeur
	*
        * Crée un soleil à une position donnée
        * @param Vecteur2D : position du soleil
        */
        Soleil(const Vecteur2D &);

        /**
        * @brief Accesseur
	*
        * Renvoie un Vecteur2D correspondant à la position du soleil
        */
        Vecteur2D getPosition() const;

        /**
        * @brief Mutateur
	*
        * Modifie la valeur de la position du soleil
        * @param Vecteur2D : position du soleil
        */
        void setPosition(const Vecteur2D &);

        /**
        * @brief Accesseur
	*
        * Renvoie un Vecteur2D correspondant à la dimension du soleil
        */
        Vecteur2D getDimension()const;

        /**
        * @brief Mutateur
	*
        * Modifie la valeur de la dimension du soleil
        * @param Vecteur2D : dimension du soleil
        */
        void setDimension(const Vecteur2D &);

        /**
        * @brief Accesseur
	*
        * Renvoie un entier correspondant à  l'énergie qu'apporte un soleil
        */
        int getEnergie() const;

        /**
        * @brief Mutateur
	*
        * Modifie la valeur de l'énergie qu'apporte un soleil
        * @param int : energie
        */
        void setEnergie(int);

        /**
        * @brief Accesseur
	*
        * Renvoie un réel correspondant au compteur du soleil
        */
        float getComptVitesse()const;

        /**
        * @brief Mutateur
	*
        * Modifie la valeur du compteur du soleil
        * @param float : compteur apparition soleil
        */
        void setComptVitesse(float);

        /**
        * @brief Accesseur
	*
        * Renvoie un réel correspondant à la vitesse d'apparition du soleil
        */
        float getVitesse()const;

        /**
        * @brief Mutateur
	*
	* Modifie la valeur de la vitesse d'apparition du soleil
        * @param float : vitesse d'apparition
        */
        void setVitesse(float);

        /**
        * @brief Vérifie si le curseur de la souris est sur un soleil ou non
	*
        * @param int : coordonnée x du curseur
	* @param int : coordonnée y du curseur
        */
        bool curseurEstDessus(int ,int )const;

        /**
        * @brief Affiche l'ensemble des caractéristiques du soleil dans la console
	*
        */
        void afficheStats()const;

        /**
        * @brief Test de régression
	*
        * Teste l'ensemble des fonctions de la classe Soleil
        */
        void testRegression();

};

/**
* @brief Surcharge de l'opérateur ==
*
* Permet de comparer 2 soleils (si leurs caractéristiques sont identiques)
* @param Soleil s1 : pour la comparaison
* @param Soleil s2 : pour la comparaison
* @return renvoie un bool résultat de la comparaison
*/
bool operator==(const Soleil & s1,const Soleil & s2);

/**
* @brief Surcharge de l'opérateur !=
*
* Permet de comparer 2 soleils (si leurs caractéristiques sont différentes)
* @param Soleil s1 : pour la comparaison
* @param Soleil s2 : pour la comparaison
* @return renvoie un bool resultat de la comparaison
*/
bool operator!=(const Soleil & s1,const Soleil & s2);

#endif //_SOLEIL
