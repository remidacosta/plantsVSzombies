#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Plante.h"
#include "Vecteur2D.h"
#include "Zombie.h"

using namespace std;

/**
* @class Projectile Projectile.h "src/Projectile.h"
* @brief La classe Projectile represente les objets tires par les plantes
*
* La classe gere les projectiles tout au long du jeu
*/
class Projectile
{
	private :
        int degats; 			/** degats de chaque projectile */
        float vitesse[2];		/** vitesse de deplacement des projectiles */
        Vecteur2D position;		/** position du coin haut gauche du sprite projectile */

	public :
	/**
	* @brief Constructeur par defaut
	*
	* Cree un projectile
	*/
        Projectile();

        /**
        * @brief Constructeur
	*
        * Cree un projectile a une position donnee
        * @param Vecteur2D : position du projectile
        */
        Projectile(const Vecteur2D &, int);


        /**
        * @brief Accesseur
	*
        * Renvoie un entier correspondant au degats du projectile
        */
        int getDegats() const;

        /**
        * @brief Mutateur
	*
        * Modifie la valeur des degats du projectile
        * @param int : degats du projectile
        */
        void setDegats (int);

        /**
        * @brief Accesseur
	*
        * Renvoie un reel correspondant au compteur du projectile
        */
        float getComptVitesse()const;

        /**
        * @brief Mutateur
	*
        * Modifie la valeur du compteur du projectile
        * @param float : compteur vitesse 
        */
        void setComptVitesse(float);

        /**
        * @brief Accesseur
	*
        * Renvoie un reel correspondant a la vitesse du projectile
        */
        float getVitesse()const;

        /**
        * @brief Mutateur
	*
        * Modifie la vitesse du projectile
        * @param float : vitesse du projectile
        */
        void setVitesse(float);

        /**
        * @brief Accesseur
	*
        * Renvoie un Vecteur2D correspondant a la position du projectile
        */
        Vecteur2D getPosition() const;

        /**
        * @brief Mutateur
	*
        * Modifie la position du projectile
        * @param Vecteur2D : position du projectile
        */
        void  setPosition(const Vecteur2D &);


        /**
        *@brief fait avancer le projectile de trois pixel vers la droite
	*
        */
        void avance();

	/**
        * @brief Verifie si le curseur de la souris est sur un projectile ou non
	*
        * @param int : coordonnee x du curseur
	* @param int : coordonnee y du curseur
        */
        bool curseurEstDessus(int ,int )const;

        /**
        * @brief Affiche l'ensemble des caracteristiques du projectile dans la console
        */
        void afficheStats();


	/**
        * @brief Test de regression
	*
        * Teste l'ensemble des fonctions de la classe projectile
        */
        void testRegression();
};

/**
* @brief Surcharge de l'operateur ==
*
* Permet de comparer 2 projectiles (si leurs caracteristiques sont identiques)
* @param Projectile p1 : pour la comparaison
* @param Projectile p2 : pour la comparaison 
* @return renvoie un bool resultat de la comparaison.
*/
bool operator==(const Projectile & p1,const Projectile & p2);

#endif //_PROJECTILE
