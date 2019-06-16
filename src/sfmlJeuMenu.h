#ifndef SFMLJEUMENU_H
#define SFMLJEUMENU_H

#include "Jeu.h"
#include "sfmlJeu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window.hpp>

/**
* @class sfmlJeuMenu smflJeuMenu.h "src/sfmlJeuMenu.h"
*
* @brief La classe sfmlJeuMenu gere le menu du jeu
*
* la classe gere l'affichage du menu et les fonctionnalites des boutons du menu
*/
class sfmlJeuMenu
{
      private:
        Jeu jeu; 					/** jeu a lancer lors de la pression de certain bouton */
        Bouton tutoriel;			/** bouton responsable du lancement du tuto */
        Bouton jouer;				/** bouton responsable du lancement du jeu */
        Bouton quitter;				/** bouton responsable de la fermeture de la fenetre */
        Bouton continuer;			/** bouton responsable de la continuation de la partie en cours */
        sf::RenderWindow *window;	/** fenetre du menu */
        sf::Texture texture;		/** texture du fond du menu */
        sf::Font font;				/** olice des boutons du menu */

      public:

        /**
	* @brief Constructeur par defaut
	*
	* creer une page menu avec different bouton
	*/
        sfmlJeuMenu();

        /**
	* @brief Destructeur du menu
	*
	*/
        ~sfmlJeuMenu();

        /**
        * @brief Accesseur
	*
        * Renvoie un Jeu
	* @return renvoie un jeu 
        */
        Jeu& getJeu();

        /**
        * @brief Affiche la page menu
	*
        * dessine tous les boutons et l'image de fond du menu
        */
        void sfmlAffMenu();

         /**
        * @brief charge une texture pour le fond du menu
	*
        * Ouvre le .png ou est stocke l'image du fond
        */
        void sfmlMenuInit();

        /**
        * @brief Gere la boucle d'evenements du jeu
	*
        * gere les actions de chaque bouton du menu
        */
        void sfmlBoucleMenu();

	/**
        * @brief Gere l'ensemble des actions possibles sur le relachement du clic
	*
        * @param Event : evenement de la bibliotheque SFML
	* @param int : coordonnee x du curseur
	* @param int : coordonnee y du curseur
        */
        void gestionsActionsClique(sf::Event &,int ,int );

        /**
        * @brief Gere l'ensemble des actions possibles sur le relachement du clic
	*
	* @param Event : evenement de la bibliotheque SFML
	* @param int : coordonnee x du curseur
	* @param int : coordonnee y du curseur
        */
        void gestionsActionsRelacheClique(sf::Event &,int ,int );


        /**
        * @brief Gere l'ensemble des actions possibles sur un mouvement du curseur de la souris
	*
	* @param Event : evenement de la bibliotheque SFML
	* @param int : coordonnee x du curseur
	* @param int : coordonnee y du curseur
        */
        void gestionsActionsBougeCurseur(sf::Event &,int ,int);

        /**
        * @brief Accesseur
	*
        * Retourne le bouton tutoriel du jeu
	* @return renvoie un bouton
        */
        Bouton& getBoutonTutoriel();

        /**
        * @brief Accesseur
	*
        * Retourne le bouton jouer du jeu
	* @return renvoie un bouton
        */
        Bouton& getBoutonJouer();

        /**
        * @brief Accesseur
	*
        * Retourne le bouton quitter du jeu
	* @return renvoie un bouton
        */
        Bouton& getBoutonQuitter();

        /**
        * @brief Accesseur
	*
        * Retourne le bouton continuer
	* @return renvoie un bouton
        */
        Bouton& getBoutonContinuer();

};

#endif // SFMLJEUMENU_H
