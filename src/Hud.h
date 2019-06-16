#ifndef _HUD
#define _HUD

#include "Vecteur2D.h"
#include "Bouton.h"
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
* @class Hud Hud.h "src/Hud.h"
*
* @brief La classe Hud représente l'hud
* 
* la classe gère lhud ou le joeur va choisir les plantes qu'ils placent sur le terrain
*les soleils disponibles
*/
class Hud
{
    private:
        vector<std::string> tabActions; 			/** tableau dynamique de string gérant les actions */
        vector<Bouton> tabBoutons;					/** tableau dynamique de Bouton gérant les boutons */
        string choix;								/** string choix de l'action */
        Vecteur2D position;							/** position du coin  haut gauche de l'hud */
        Vecteur2D dimension;						/** position du coin bas droit de l'hud */

    public:
		/**
		* @brief Constructeur par défaut
		*
		* Constructeur par defaut de la classe Hud
		*/
        Hud();
		
		/**
		* @brief Constructeur
		*
		*Constructeur de la classe Hud
		* @param Vecteur2D : la position de l'Hud
		* @param Vecteur2D : la dimension de l'Hud
		*/
        Hud(const Vecteur2D &, const Vecteur2D &);

		
		/**
		* @brief accesseur
		*
		* accesseur à la position de l'Hud
		* @return renvoie un vecteur2D \b position de l'Hud
		*/
        Vecteur2D getPosition()const;
		
		/**
		* @brief mutateur
		*
		* mutateur de la position de l'Hud
		* @param Vecteur2D : nouvelle position de l'Hud
		*/
        void setPosition(const Vecteur2D &);
		
		/**
		* @brief accesseur
		*
		* accesseur à la dimension de l'Hud
		* @return renvoie un vecteur2D \b dimension de l'Hud
		*/
        Vecteur2D getDimension()const;
		
		/**
		* @brief mutateur
		*
		* mutateur de la dimension de l'Hud
		* @param Vecteur2D : nouvelle dimension de l'Hud
		*/
        void setDimension(const Vecteur2D &);
		
		/**
		* @brief accesseur
		*
		*accesseur au choix
		* @return renvoie un string \b choix 
		*/
        string getChoix()const;
		
		/**
		* @brief mutateur
		*
		*mutateur du choix
		* @param string : nouveau choix
		*/
        void setChoix(string );
		
		/**
		* @brief accesseur
		*
		*accesseur a l'action dans tabActions
		* @param int : indice de l'action dans tabActions
		* @return renvoie un string \b actions voulu
		*/
        std::string getAction(int )const;
		
		/**
		* @brief mutateur
		*
		* mutateur  d'une action correspondant à un indice dans TabActions
		* @param int : indice de l'action dans tabActions
		* @param string : nouvelle action
		*/
        void setAction(int ,std::string );
		
		/**
		* @brief accesseur
		*
		*accesseur à la taille de TabActions
		* @return renvoie un int \b taille du tableau
		*/
        int getTailleTabActions()const;
		
		/**
		* @brief accesseur
		*
		*accesseur a l'indice de l'action dans TabActions
		* @param string : action dont l'on veut l'indice
		* @return renvoie un int \b indice de l'action voulue
		*/
        int getIndiceAction(std::string )const;
		
		/**
		* @brief ajoute une action
		*
		* ajoute une action au TabActions
		* @param string : action à ajouter
		*/
        void addAction(std::string );
			
		/**
		* @brief renvoie le bouton d'indice voulu
		* 
		* @param int : indice du bouton dans TabBouton
		* @return Bouton : Bouton d'indice voulu
		*/
        Bouton& getBouton(int );
		
		/**
		* @brief accesseur
		*
		*accesseur à la taille de TabBouton
		* @return renvoie un int \b taille du tableau
		*/
        int getTailleTabBoutons()const;
		
		/**
		* @brief ajoute un bouton
		*
		* ajoute une bouton au TabBouton
		* @param Bouton : Bouton à ajouter
		*/
        void addBouton(const Bouton &);

		/**
		* @brief vérifie quelle plante est choisi
		*
		* vérifie quel bouton sont actifs de l'Hud et en déduit le choix d'action
		*/
        void choixPlante(); 

		/**
		* @brief affiche tabActions
		*/
        void afficheTabActions()const;
		
		/**
		* @brief affiche choix
		*/
        void afficheChoix()const;
		
		/**
		* @brief affiche position
		*/
        void affichePosition()const;
		
		/**
		* @brief affiche dimension
		*/
        void afficheDimension()const;
		
		/**
		* @brief curseurEstDessus
		*
		* Renvoie vrai si la position du curseur donnée en paramètre est sur l' Hud
		*
		* @param int : coordonnee x du curseur
		* @param int : coordonnee y du curseur
		* @return renvoie un bool
		*/
        bool curseurEstDessus(int ,int );
		
		/**
		* @brief affiche les stats
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

    private:
		
		/**
		* @brief vérifie que l'action est dans le tabActions
		*
		* @param string : action à chercher
		* @return renvoie un bool
		*/
        bool estDansTabActions(std::string )const;
};
#endif // _HUD
