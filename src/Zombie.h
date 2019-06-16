#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <string.h>
#include <iostream>
#include "Vecteur2D.h"

using namespace std;

/**
* @class Zombie Zombie.h "src/Zombie.h"
* @brief La classe Zombie représente les zombies au cours de la partie 
* 
* la classe gère le zombie tout au long du jeu.
*/
class Zombie
{
	private :
	Vecteur2D position; 		/** position du coin  haut gauche du sprite du zombie */
	int pv;						/** point de vie du zombie */
	int degats;					/** degats du zombie */
	int id;						/** id du zombie */
	float cadence[2];			/** tableau de deux floats un compteur et une borne max pour la cadence */
	float vitesse[2];			/** tableau de deux floats un compteur et une borne max pour la vitesse de déplacement */
	bool etat[2];				/** tableau de deux bool avec les etats possible */

	public :
	/**
	* @brief Constructeur par défaut
	*
	* Constructeur par defaut de la classe zombie
	*/
	Zombie();


	/**
	* @brief Constructeur
	*
	*Constructeur de la classe Zombie
	* @param Vecteur2D : la position du zombie
	* @param Vecteur2D : la dimension du zombie
	* @param int : pv du zombie
	* @param int : id du zombie
	*/
	Zombie(const Vecteur2D &,int,int);

	/**
	* @brief accesseur
	*
	* accesseur à la position du zombie
	* @return renvoie un vecteur2D \b position du zombie
	*/
	Vecteur2D getPosition() const;

	/**
	* @brief mutateur
	*
	* mutateur de la position du zombie
	* @param Vecteur2D : position du zombie
	*/
	void setPosition(const Vecteur2D &);

	/**
	* @brief accesseur
	*
	*accesseur au points de vie du zombie
	* @return renvoie un entier \b pv du zombie
	*/
	int getPV() const;

	/**
	* @brief mutateur
	*
	* mutateur des PVs du zombie
	* @param int : pv du zombie
	*/
	void setPV(int);

	/**
	* @brief accesseur
	*
	*accesseur au degats du zombie
	* @return renvoie un entier \b degats du zombie
	*/
	int getDegats() const;

	/**
	* @brief mutateur
	*
	* mutateur des degats du zombie
	* @param int : degats du zombie
	*/
	void setDegats(int);

	/**
	* @brief accesseur
	*
	*accesseur a l'id  du zombie
	* @return renvoie un entier \b id du zombie
	*/
	int getId() const;

	/**
	* @brief mutateur
	*
	* mutateur de l'id du zombie
	* @param int : id du zombie
	*/
	void setId(int);

	/**
	* @brief accesseur
	*
	*accesseur au compteur de la cadence du zombie
	*@return renvoie un float
	*/
	float getComptCadence()const;

	/**
	* @brief mutateur
	*
	* mutateur du compteur de  la cadence du zombie
	*@param float : compteur cadence du zombie
	*/
	void setComptCadence(float);

	/**
	*@brief accesseur
	*
	*accesseur à la cadence du zombie
	*@return renvoie un float
	*/
	float getCadence() const;

	/**
	*@brief mutateur
	*
	*mutateur de la cadence du zombie
	*
	*@param float : cadence du zombie
	*/
	void setCadence(float);

	/**
	*@brief accesseur
	*
	*accesseur au compteur de la vitesse du zombie
	*@return renvoie un float
	*/
	float getComptVitesse()const;

	/**
	* @brief mutateur
	*
	* mutateur du compteur de  la vtesse du zombie
	*@param float : compteur vitesse du zombie
	*/
	void setComptVitesse(float);

	/**
	*@brief accesseur
	*
	*accesseur à la vitesse du zombie
	*@return renvoie un float
	*/
	float getVitesse() const;

	/**
	*@brief mutateur
	*
	*mutateur de la vitesse du zombie
	*
	*@param float : vitesse du zombie
	*/
	void setVitesse(float);

	/**
	*@brief accesseur
	*
	*accesseur à l'état du zombie qui permet de savoir s'il attaque
	*@return renvoie un booléen
	*/
	bool getEtatAttaque()const;

	/**
	*@brief mutateur
	*
	*mutateur de l'état du zombie qui permet de savoir s'il attaque
	*
	*@param bool : EtatAttaque
	*/
	void setEtatAttaque(bool );

	/**
	*@brief accesseur
	*
	*accesseur à l'état du zombie qui permet de savoir s'il est touché
	*@return renvoie un booléen
	*/
	bool getEtatTouche()const;

	/**
	*@brief mutateur
	*
	*mutateur de l'état du zombie qui permet de savoir s'il est touché
	*
	*@param bool : EtatTouche
	*/
	void setEtatTouche(bool );

	/**
	* @brief avance
	*
	* Fait avancer le zombie
	*/
	void avance();

	/**
	* @brief curseurEstDessus
	*
	* Renvoie vrai si la position du curseur donnée en paramètre est sur ce zombie
	*
	* @param int : coordonnee x du curseur
	* @param int : coordonnee y du curseur
	* @return renvoie un bool
	*/
	bool curseurEstDessus(int ,int )const;

	/**
	* @brief afficheStats
	*
	* affiche dans la console les valeurs des variables membres
	*/
	void afficheStats();

	/**
	*@brief testRegression
	*
	* test toutes les fonctions du module
	*/
	void testRegression();
};

/**
* @brief surchage operateur ==
*
* surchage l'operateur "==" pour la classe zombie
* @param Zombie z1 : pour la comparaison
* @param Zombie z2 : pour la comparaison
* @return renvoie un bool résultat de la comparaison
*/
bool operator==(const Zombie & z1,const Zombie & z2);

#endif //_ZOMBIE


