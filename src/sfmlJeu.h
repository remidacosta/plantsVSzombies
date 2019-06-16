#ifndef IHM_H
#define IHM_H

#include "Jeu.h"
#include "EtapeTutoriel.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window.hpp>

/**
* @class sfmlJeu sfmlJeu.h "src/sfmlJeu.h"
*
* @brief La classe sfmlJeu gere l'affichage du jeu avec la bibliotheque graphique SFML
*/
class sfmlJeu {

    private:

        Jeu jeu; 						/** le jeu en lien avec les graphismes */
        Bouton pause;					/** bouton qui pause le jeu */
        Bouton menu;					/** bouton qui retourne au menu */
        sf::RenderWindow * window;		/** pointeur sur la fenetre */ 
        sf::Texture texture;			/** ensemble des sprites du jeu */
        sf::Sprite tabSprite2D[5][4];	/** tableau 2D de sprite contenant chaque sprite utilise dans le jeu */
        sf::Font font;					/** police de caractere utilise */
        EtapeTutoriel * etapeTuto;		/** pointeur sur Etape tutriel */

    public :

        /**
        * @brief Constructeur par defaut
        */
        sfmlJeu();

        /**
        * @brief Destructeur
        */
        ~sfmlJeu();

        /**
        * @brief Accesseur
	*
        * Renvoie un Jeu
	* @return Jeu
        */
        Jeu& getJeu();

        /**
        * @brief Cree le tableau des sprites
	*
        * Ouvre le .png ou sont stockes les sprites et place les sprites dans un tableau 2D
        */
        void sfmlInit();
		
		
	/** 
	* @brief accesseur
	*
	* renvoie un pointeur  d'une etape du tuto
	* @return pointeur sur EtapeTutoriel
	*/
        EtapeTutoriel * getEtapeTuto()const;
		
	/** 
	* @brief mutateur
	*
	* modifie le pointeur sur EtapeTutoriel
	* @param pointeur sur EtapeTutoriel
	*/
        void setEtapeTuto(EtapeTutoriel *);

        /**
        * @brief Gere la boucle devenements du jeu
	*
        * S'occupe egalement de la clock du jeu
        */
        void sfmlBoucle();

        /**
        * @brief Gere l'affichage du jeu dans son integralite
        */
        void sfmlAff();

        /**
        * @brief Affiche l'HUD du jeu
        */
        void afficheHud();

        /**
        * @brief Gere l'affichage de la plante selectionnee sous le curseur (hover)
	*
        * @param int : coordonnee x du curseur
	* @param int : coordonnee y du curseur
        */
        void afficheCurseur(int, int);

        /**
        * @brief Affiche de la barre d'avancement
        */
        void afficheAvancement();

        /**
        * @brief Affiche le nombre de Soleil disponible
        */
        void afficheNbrSoleil();

        /**
        * @brief Affiche le niveau actuel du jeu
        */
        void afficherNiveau();

        /**
        * @brief Gere l'ensemble des actions possibles sur un clic du joueur sur la souris
	*
        * @param Event : un evenement (issu de la bibliotheque SFML)
	* @param int : coordonnee x du curseur
	* @param int : coordonnee y du curseur
        */
        void gestionsActionsClique(sf::Event &,int ,int );

        /**
        * @brief Gere l'ensemble des actions possibles sur le relachement du clic
	*
        * @param Event : un evenement (issu de la bibliotheque SFML)
	* @param int : coordonnee x du curseur
	* @param int : coordonnee y du curseur
        */
        void gestionsActionsRelacheClique(sf::Event &,int ,int );

        /**
        * @brief Gere l'ensemble des actions possibles sur un mouvement du curseur de la souris
	*
	*
        * @param Event : un evenement (issu de la bibliotheque SFML)
	* @param int : coordonnee x du curseur
	* @param int : coordonnee y du curseur
        */
        void gestionsActionsBougeCurseur(sf::Event &,int ,int);
		
		
	/**
	* @brief affiche le tutoriel
	*/
        void gestionAffichageTutoriel();

        /**
        * @brief Accesseur
	*
        * Retourne le bouton pause du jeu
	* @return renvoie un bouton
        */
        Bouton& getBoutonPause();

        /**
        * @brief Accesseur
	*
        * Retourne le bouton menu du jeu
	* @return renvoie un bouton
        */
        Bouton& getBoutonMenu();


        /**
        * @brief Retourne letat du bouton pause
        */
        bool enPause();

        /**
        * @brief Affiche toutes les caracteristiques de l'objet sur lequel le curseur de la souris pointe
        */
        void afficheStats(int ,int);
};

#endif
