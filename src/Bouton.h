#ifndef _BOUTON
#define _BOUTON

#include <SFML/Graphics.hpp>
#include "Vecteur2D.h"

/** 
* @class Bouton Bouton.h "src/Bouton.h"
* @brief la classe Bouton represente un objet bouton dans une fenetre SFML
*
* La classe gere le bouton, son apparence et son etat
*/
class Bouton
{

    private:
       bool etat;                       /** etat du bouton, TRUE si actif et FALSE sinon */
       bool visible;                    /** etat de visibilite du bouton, TRUE si visible et FALSE sinon */
       Vecteur2D position;              /** position 2D du coin haut gauche du bouton */
       Vecteur2D dimension;             /** dimension 2D du bouton */
       sf::RectangleShape rectBouton;   /** forme du bouton */
       sf::Color couleurBouton;         /** couleur de la forme du bouton */
       sf::Text texteBouton;            /** texte inscrit sur le bouton */
       sf::Font font;                   /** police de caractere du texte */


    public:
        /**
        * \brief constructeur par defaut
        *
        * Constructeur par defaut de la classe Bouton
        */
        Bouton();

        /**
        * \brief Constructeur
        *
        * Constructeur de la classe Bouton
        * \param Vecteur2D : la position du Bouton
        * \param Vecteur2D : la dimension du Bouton
        */
        Bouton(const Vecteur2D &, const Vecteur2D &);

        /**
        * \brief accesseur
        *
        * Accesseur de letat du bouton
        * \return renvoie un booleen \b etat du bouton
        */
        bool getEtat()const;

        /**
        * \brief mutateur
        *
        * mutateur de letat du bouton
        * \param booleen : etat du bouton
        */
        void setEtat(bool);

        /**
        * \brief accesseur
        *
        * Accesseur de la visibilite du bouton
        * \return renvoie un booleen \b visibilite du bouton
        */
        bool getVisible()const;

        /**
        * \brief mutateur
        *
        * mutateur de la visibilite du bouton
        * \param booleen : visibilite du bouton
        */
        void setVisible(bool);

        /**
        * \brief accesseur
        *
        * accesseur de la position du bouton
        * \return renvoie un vecteur2D \b position du bouton
        */
        Vecteur2D getPosition()const;

        /**
        * \brief mutateur
        *
        * mutateur de la position du bouton
        * \param Vecteur2D : position du bouton
        */
        void setPosition(const Vecteur2D &);

        /**
        * \brief accesseur
        *
        * accesseur de la dimension du bouton
        * \return renvoie un vecteur2D \b dimension du bouton
        */
        Vecteur2D getDimension()const;

        /**
        * \brief mutateur
        *
        * mutateur de la dimension du bouton
        * \param Vecteur2D : dimension du bouton
        */
        void setDimension(const Vecteur2D &);

        /**
        * \brief accesseur
        *
        * accesseur du rectangle de fond du bouton
        * \return renvoie un sf::RectangleShape \b rectangle de fond du bouton
        */
        sf::RectangleShape getRectBouton()const;

        /**
        * \brief mutateur
        *
        * mutateur du rectangle de fond du bouton
        * \param sf::RectangleShape : rectangle de fond du bouton
        */
        void setRectBouton(const sf::RectangleShape &);

        /**
        * \brief mutateur
        *
        * mutateur de la couleur du rectangle de fond du bouton
        * \param sf::Color : couleur
        */
        void setCouleurRectBouton(const sf::Color &);

        /**
        * \brief mutateur
        *
        * mutateur de la couleur du contour du rectangle du bouton
        * \param sf::Color : couleur
        */
        void setCoulContourBouton(const sf::Color &);

        /**
        * \brief accesseur
        *
        * accesseur de la couleur du rectangle de fond du bouton
        * \return renvoie un sf::Color \b couleur
        */
        sf::Color getCouleurBouton()const;

        /**
        * \brief mutateur
        *
        * mutateur de la couleur du bouton
        * \param sf::Color : couleur
        */
        void setCouleurBouton(const sf::Color &);

        /**
        * \brief accesseur
        *
        * accesseur du texte affiche dans le bouton
        * \return renvoie un sf::Texte \b texte
        */
        sf::Text getTexte()const;

        /**
        * \brief mutateur
        *
        * mutateur du texte du bouton
        * \param string : texte a afficher dans le bouton
        */
        void setTexteBouton(std::string);

        /**
        * \brief mutateur
        *
        * mutateur de la couleur du texte du bouton
        * \param sf::Color : couleur du texte du bouton
        */
        void setCouleurTexte(const sf::Color &);

        /**
        * \brief estAppuye
        *
        * change l'apparence du bouton quand celui-ci est appuye
        */
        void estAppuye();

        /**
        * \brief estRelache
        *
        * change l'apparence du bouton quand celui-ci est relache
        */
        void estRelache();

        /**
        * \brief changeEtat
        *
        * change l'etat du bouton
        */
        void changeEtat();

        /**
        * \brief curseurEstDessus
        *
        * Renvoie vrai si la position du curseur donnee en parametre est sur ce bouton
        * \return renvoie un booleen \b booleen
        */
        bool curseurEstDessus(int,int);

        /**
        * \brief estActif
        *
        * Renvoie vrai si letat du bouton est TRUE
        * \return renvoie un booleen \b booleen
        */
        bool estActif();

        /**
        * \brief estVisible
        *
        * Renvoie vrai si la visibilite du bouton est TRUE
        * \return renvoie un booleen \b booleen
        */
        bool estVisible();

    private:
        /**
        * \brief initTexte
        *
        * Initialise le texte et son placement dans le bouton
        */
        void initTexte();

        /**
        * \brief mutateur
        *
        * mutateur de la taille de caractere du texte du bouton
        */
        void setTailleCaractere();

        /**
        * \brief aligneTxtCentre
        *
        * aligne le texte au centre du bouton
        */
        void aligneTxtCentre();


        /**
        * \brief disparaitreBouton
        *
        * fait disparaitre le bouton
        */
        void disparaitreBouton();

};

#endif // _BOUTON
