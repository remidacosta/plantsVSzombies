#ifndef PLANTE_H
#define PLANTE_H
#include <string>
#include <cassert>
#include "Vecteur2D.h"
#include "Projectile.h"
using namespace std;




/**
* @class Plante Plante.h "src/Plante.h"
* @brief La classe Plante represente les plantes 
*
*l'outil principale du joueur pour combattre les zombies
*/
class Plante
{
	private:
        Vecteur2D position; 			/** position du coin  haut gauche du sprite de la plante */
        int pv;							/** pv de la plante */
        int degats;						/** degats de la plante */
        int prix;						/** pris en soleil de la plante */
        float cadence[2];				/** cadence de tir de la plante */
        int portee;						/** portee de tir de la plante */
        int id;							/** id de la plante */

	public:
	/**
	* @brief Constructeur par defaut de la classe 
	*
	* Cree une plante
	*/
	Plante();

	/**
        * @brief Constructeur
	*
        * Cree une plante a une position donnee
        * @param Vecteur2D : position de la plante
        * @param des entier pour les stats de la plante
        */
        Plante(const Vecteur2D &, int, int, int, int, int, int);


        /**
        * @brief Accesseur
	*
        * Renvoie un Vecteur2D correspondant a la position de la plante
	* @return renvoie un vecteur2D \b position de la plante
        */
        Vecteur2D getPosition() const;

        /**
        * @brief Mutateur
	*
        * Modifie la position de la plante
        * @param Vecteur2D : position
        */
        void setPosition(const Vecteur2D &);


        /**
        * @brief Accesseur
	*
        * Renvoie un entier correspondant au point de vie de la plante
	* @return renvoie un entier \b pv de la plante
        */
        int getPv() const;

	/**
        * @brief Mutateur
	*
        * Modifie la valeur des points de vie de la plante
        * @param int : pv
        */
        void setPv(int);


        /**
        * @brief Accesseur
	*
        * Renvoie un entier correspondant au degats de la plante
	*@return renvoie un entier \b degats de la plante
        */
        int getDegats() const;

	/**
        * @brief Mutateur
	*
        * Modifie la valeur des degats de la plante
        * @param int : degat
        */
        void setDegats(int);


        /**
        * @brief Accesseur
	*
        * Renvoie un entier correspondant au prix de la plante
	* @return renvoie un entier \b prix de la plante
        */
        int getPrix() const;

	/**
        * @brief Mutateur
	*
        * Modifie la valeur du prix d'une plante
        * @param int : prix
        */
        void setPrix(int);


        /**
        * @brief Accesseur
	*
        * Renvoie un entier correspondant au compteur de la cadence de tir de la plante
	* @return renvoie un float \b compteur cadence de la plante
        */
        float getComptCadence()const;

	/**
        * @brief Mutateur
	*
        * Modifie la valeur du compteur de la plante
        * @param float : compteur cadence
        */
        void setComptCadence(float);


        /**
        * @brief Accesseur
	*
        * Renvoie un entier correspondant a  la cadence de tir de la plante
	* @return renvoie un float \b cadence de la plante
        */
        float getCadence() const;

         /**
        * @brief Mutateur
	*
        * Modifie la valeur de la cadence a laquelle tire une plante
        * @param float : cadence 
        */
        void setCadence(float);


        /**
        * @brief Accesseur
	*
        * Renvoie un entier correspondant a  la portee de la plante
	* @return renvoie un entier \b portee de la plante
        */
        int getPortee() const;

         /**
        * @brief Mutateur
	*
        * Modifie la valeur de la portee d'une plante
        * @param int : portee 
        */
        void setPortee(int);

        /**
        * @brief Accesseur
	*
	* Renvoie un entier correspondant a l'id d'une plante
	* @return renvoie un entier \b Id de la plante
        */
        int getId() const;

	/**
        * @brief Mutateur
	*
        * Modifie la valeur de l'id d'une plante
        * @param int : Id de la plante
        */
        void setId(int);


        /**
        * @brief Verifie si le curseur de la souris est sur une plante ou non
	*
        * @param int : coordonnee x du curseur
	* @param int : coordonnee y du curseur 
	* @return renvoie un bool 
        */
        bool curseurEstDessus(int ,int )const;

        /**
        * @brief Affiche l'ensemble des caracteristiques de la plante dans la console
        */
        void afficheStats();

        /**
        * @brief Test de regression
	*
        * Teste l'ensemble des fonctions de la classe Plante
        */
        void testRegression();
};

/**
* @brief Surcharge de l'operateur ==
*
* Permet de comparer 2 plantes (si leurs caracteristiques sont identiques)
* @param Plante p1 : pour la comparaison
* @param Plante p2 : pour la comparaison
* @return renvoie un bool resultat de la comparaison 
*/
bool operator==(const Plante & p1,const Plante & p2);

#endif
