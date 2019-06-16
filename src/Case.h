#ifndef CASE_H
#define CASE_H
#include <string>
#include "Vecteur2D.h"
using namespace std;

/**
* @class Case Case.h "src/Case.h"
* @brief La classe Case  represente les cases du terrain
* 
* la classe gere les cases.
*/
class Case
{
	private:
	Vecteur2D position;     /** position 2D de la case */
	Vecteur2D dimension;    /** dimension 2D de la case */
	int id;                 /** id de la case, variable unique a chaque case de chaque ligne */

	public:

    /**
    * @brief Constructeur par defaut
	*
    * Cree une case
    */
	Case();

	/**
	* @brief Constructeur
	*
	* Cree une case
	* @param Vecteur2D : position
	* @param Vecteur2D : dimension
	* @param int : id
	*/
	Case(const Vecteur2D &,const Vecteur2D &,int);

	/**
	* @brief Accesseur
	*
	* Renvoie un Vecteur2D correspondant a la position de la case
	* @return renvoie un Vecteur2D
	*/
	Vecteur2D getPosition() const;

	/**
	* @brief Mutateur
	*
	* Modifie la valeur de la position de la case
	* @param Vecteur2D : nouvelle position
	*/
	void setPosition(const Vecteur2D &);

	/**
	* @brief Accesseur
	*
	* Renvoie un Vecteur2D correspondant a la dimension de la case
	* @return renvoie un Vecteur2D
	*/
	Vecteur2D getDimension() const;

	/**
	* @brief Mutateur
	*
	* Modifie la valeur de la dimension de la case
	* @param Vecteur2D : nouvelle dimension
	*/
	void setDimension(const Vecteur2D &);

	/**
	* @brief Accesseur
	
	* Renvoie un entier correspondant a l'id de la case
	* @return renvoie un entier
	*/
	int getId() const;

	/**
	* @brief Mutateur
	*
	* Modifie la valeur de l'id de la case
	
	* @param int : nouvelle id
	*/
	void setId(int);

	/**
	* @brief Verifie si le curseur de la souris est sur une case (renvoie true) ou non (renvoie false)
	*
    * @param int : coordonnee x du curseur
	* @param int : coordonnee y du curseur
	*/
	bool curseurEstDessus(int ,int )const;

	/**
    * @brief Affiche l'ensemble des caracteristiques de la case dans la console
    */
	void afficheStats();

    /**
    * @brief Test de regression
	*
    * Teste l'ensemble des fonctions de la classe Case
    */
	void testRegression();
};

#endif
