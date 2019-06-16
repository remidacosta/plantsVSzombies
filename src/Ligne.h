#ifndef LIGNE_H
#define LIGNE_H
#include <string.h>
#include "Vecteur2D.h"
#include "Case.h"
#include "Soleil.h"
#include "Zombie.h"
#include "Plante.h"
#include "Tondeuse.h"
#include "Projectile.h"
#include <list>
using namespace std;

/**
* @class Ligne Ligne.h "src/Ligne.h"
* @brief La classe Ligne represente les lignes du terrain
* 
* la classe gere les lignes tout au long du jeu.
*/
class Ligne
{
	private:

        bool contientTondeuse;			/** booleen permettant de savoir si une tondeuse est sur la ligne */
        Tondeuse * tondeuse;			/** pointeur sur tondeuse */
        Vecteur2D position;        	 		/** position du coin haut gauche de la ligne*/
        Vecteur2D dimension;			/** dimension du coin bas droit de la ligne */
        int nbCases;					/** nombres de case par ligne */
        Case tabCases [10];				/** tableau de 10 Cases */
        list<Soleil> soleils; 				/** liste chainee de soleil */
        list<Zombie> zombies;			/** liste chainee de zombies */
    	list<Plante> plantes;			/** liste chainee de plantes */
        list<Projectile> projectiles;		/** liste chainee de projectile */
        int id;						/** id de la ligne differents pour chauque ligne */

	public:

	/**
        * @brief Constructeur par defaut
	*
        * Cree une ligne
        */
        Ligne();

        /**
        * @brief Constructeur
	*
        * Cree une ligne
        * @param Vecteur2D : position de la ligne
	* @param Vecteur2D : dimension de la ligne
	* @param int : id de la ligne
        */
        Ligne(const Vecteur2D &,const Vecteur2D &,int);

        /**
        * @brief Destructeur
	*
        */
        ~Ligne();

        /**
        * @brief Accesseur
	*
        * Renvoie vrai s'il y a une tondeuse en bout de ligne, faux sinon
	* @return renvoie un bool
        */
        bool getContientTondeuse() const;

        /**
        * @brief Mutateur
	*
        * Modifie la valeur de ContientTondeuse
        * @param bool
        */
        void setContientTondeuse(bool);

        /**
        * @brief Accesseur
	*
        * Renvoie un pointeur sur une Tondeuse
	* @return renvoie un pointeur 
        */
        Tondeuse * getTondeuse() const;

        /**
        * @brief Mutateur
	*
        * Modifie la valeur de Tondeuse (ajoute une tondeuse sur la ligne)
        * @param tondeuse : pointeur sur Tondeuse
        */
        void setTondeuse(Tondeuse * tondeuse);

        /**
        * @brief Accesseur
	*
        * Renvoie la valeur de la position de la ligne
	* @return Vecteur2D : position de la ligne 
        */
        Vecteur2D getPosition() const;

        /**
        * @brief Mutateur
	*
        * Modifie la valeur de la position de la ligne
        * @param Vecteur2D : nouvelle position
        */
        void setPosition(const Vecteur2D &);

        /**
        * @brief Accesseur
	*
        * Renvoie la valeur de la dimension de la ligne
	* @return un Vecteur2D
        */
        Vecteur2D getDimension() const;

        /**
        * @brief Mutateur
	*
        * Modifie la valeur de la dimension de la ligne
        * @param Vecteur2D : nouvelle dimension
        */
        void setDimension(const Vecteur2D &);

        /**
        * @brief Accesseur
	*
        * Renvoie la valeur du nombre de cases de la ligne
	* @return un entier 
        */
        int getNbCases()const;

        /**
        * @brief Mutateur
	*
        * Modifie la valeur du nombre de cases de la ligne
        * @param int : nouveau nombre de cases 
        */
        void setNbCases(int );

        /**
        * @brief Accesseur
	*
        * Renvoie une case du tableau de Case tabCases
	* @param int : indice dans TabCases de la case
	* @return un case
        */
        Case& getCase(int);

        /**
        * @brief ajoute un Soleil a la liste chainee de Soleil
	*
        * @param Soleil : soleil a ajouter
        */
        void addSoleil(const Soleil &);

        /**
        * @brief Vide la liste chainee de Soleil
        */
        void rmAllSoleils();

        /**
        * @brief Enleve un Soleil de la liste chainee de Soleil
	*
        * @param un iterateur pointant sur le Soleil a supprimer
        */
        list<Soleil>::iterator rmSoleil(list<Soleil>::iterator);

        /**
        * @brief Renvoie un iterateur pointant sur le premier element de la liste chainee de Soleil
        */
        list<Soleil>::iterator beginSoleil();

        /**
        * @brief Renvoie un iterateur pointant sur le dernier element de la liste chainee de Soleil
        */
        list<Soleil>::iterator endSoleil();

        /**
        * @brief Renvoie un entier correspondant a la taille de la liste chainee de Soleil
	*
	* @return un entier
        */
        int getSizeSoleils()const;

        /**
        * @brief ajoute un Zombie a la liste chainee de Zombie
	*
        * @param Zombie : zombie a ajouter
        */
        void addZombie(const Zombie &);

        /**
        * @brief Vide la liste chainee de Zombie
        */
        void rmAllZombies();

        /**
        * @brief Enleve un Zombie de la liste chainee de Zombie
        * @param un iterateur pointant sur le Zombie a supprimer
        */
        list<Zombie>::iterator rmZombie(list<Zombie>::iterator);

        /**
        * @brief Renvoie un iterateur pointant sur le premier element de la liste chainee de Zombie
        */
        list<Zombie>::iterator beginZombie();

        /**
        * @brief Renvoie un iterateur pointant sur le dernier element de la liste chainee de Zombie
        */
        list<Zombie>::iterator endZombie();

        /**
        * @brief Renvoie un entier correspondant a la taille de la liste chainee de Zombie
	*
	* @return un entier
        */
        int getSizeZombies()const;

        /**
        * @brief ajoute une Plante a la liste chainee de Plante
	*
        * @param Plante : plante a ajouter
        */
        void addPlante(const Plante &);

        /**
        * @brief Vide la liste chainee de Plante
        */
        void rmAllPlantes();

        /**
        * @brief Enleve une Plante de la liste chainee de Plante
        * @param un iterateur pointant sur la Plante a supprimer
        */
        list<Plante>::iterator rmPlante(list<Plante>::iterator);

        /**
        * @brief Renvoie un iterateur pointant sur le premier element de la liste chainee de Plante
        */
        list<Plante>::iterator beginPlante();

        /**
        * @brief Renvoie un iterateur pointant sur le dernier element de la liste chainee de Plante
        */
        list<Plante>::iterator endPlante();

        /**
        * @brief Renvoie un entier correspondant a la taille de la liste chainee de Plante
	*
	*@return un entier
        */
        int getSizePlantes()const;

        /**
        * @brief ajoute un Projectile a la liste chainee de Projectile
        * @param un Projectile : a ajouter
        */
        void addProjectile(const Projectile &);

        /**
        * @brief Vide la liste chainee de Projectile
        */
        void rmAllProjectiles();

        /**
        * @brief Enleve un Projectile de la liste chainee de Projectile
        * @param un iterateur pointant sur le Projectile a supprimer
        */
        list<Projectile>::iterator rmProjectile(list<Projectile>::iterator);

        /**
        * @brief Renvoie un iterateur pointant sur le premier element de la liste chainee de Projectile
        */
        list<Projectile>::iterator beginProjectile();

        /**
        * @brief Renvoie un iterateur pointant sur le dernier element de la liste chainee de Projectile
        */
        list<Projectile>::iterator endProjectile();

        /**
        * @brief Renvoie un entier correspondant a la taille de la liste chainee de Projectile
	*
	* @return un entier
        */
        int getSizeProjectiles()const;

        /**
        * @brief Accesseur
	*
        * Renvoie la valeur de l'id de la ligne
	*
	* @return un entier
        */
        int getId() const;

        /**
        * @brief Mutateur
	*
        * Modifie la valeur de l'id de la ligne
        * @param int : nouvel id
        */
        void setId(int);

        /**
        * @brief Fais tirer la plante
	*	
        * Cree un projectile a la position de la plante
        * @param un iterateur sur la liste de Plante pointant sur la plante qui doit tirer
        */
        void planteTire(list<Plante>::iterator );

        /**
        * @brief Test de regression
	*
        * Teste l'ensemble des fonctions de la classe Ligne
        */
        void testRegression();
};

#endif
