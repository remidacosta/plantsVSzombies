#ifndef _ZONEDETEXTE
#define _ZONEDETEXTE

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <SFML/Graphics.hpp>
#include "Vecteur2D.h"

using namespace std;

/** \class ZoneDeTexte ZoneDeTexte.h "src/ZoneDeTexte.h"
* \brief la classe ZoneDeTexte represente une zone de texte sous SFML
*
* La classe gere la zone de texte, sa position, l'alignement du texte
*/
class ZoneDeTexte
{
    private:
        Vecteur2D position;             /** position 2D du coin haut gauche de la zone de texte */
        Vecteur2D dimension;            /** dimension 2D de la zone de texte  */
        int tchar;                      /** taille de caractere  */
        string texte;                   /** texte a afficher dans la zone de texte */
        vector <string> tabMots;        /** tableau contenant tous les mots du texte */
        vector <sf::Text> tabLignes;    /** tableau conteannt les lignes a afficher sous SFML */
        sf::Font policeCar;             /** police de caractere */
        sf::RectangleShape fond;        /** fond de la zone de texte */
        string alignementX;             /** choix de l'alignement du texte sur L'axe horizontal */
        string alignementY;             /** choix de l'alignement du texte sur l'axe vertical */

    public:
        /**
        * \brief constructeur par defaut
        *
        * Constructeur par defaut de la classe ZoneDeTexte
        */
        ZoneDeTexte();

        /**
        * \brief Constructeur
        *
        * Constructeur de la classe ZoneDeTexte
        * \param Vecteur2D : la position de la zone de texte
        * \param Vecteur2D : la dimension de la zone de texte
        * \param string : texte a afficher
        * \param int : taille de caractere
        */
        ZoneDeTexte(const Vecteur2D &, const Vecteur2D &, string, int);

        /**
        * \brief accesseur
        *
        * accesseur de la position de la zone de texte
        * \return renvoie un vecteur2D \b position de la zone de texte
        */
        Vecteur2D& getPosition();

        /**
        * \brief mutateur
        *
        * mutateur de la position de la zone de texte
        * \param Vecteur2D : position de la zone de texte
        */
        void setPosition(const Vecteur2D &);

        /**
        * \brief accesseur
        *
        * accesseur de la dimension de la zone de texte
        * \return renvoie un vecteur2D \b dimension de la zone de texte
        */
        Vecteur2D& getDimension();

        /**
        * \brief mutateur
        *
        * mutateur de la dimension de la zone de texte
        * \param Vecteur2D : dimension de la zone de texte
        */
        void setDimension(const Vecteur2D &);

        /**
        * \brief accesseur
        *
        * Accesseur de la taille de caractere
        * \return renvoie un entier \b taille de caractere
        */
        int getTchar()const;

        /**
        * \brief mutateur
        *
        * mutateur de letat de la taille de caractere
        * \param int : taille de caractere
        */
        void setTchar(int );

        /**
        * \brief accesseur
        *
        * Accesseur du texte
        * \return renvoie un string \b texte a afficher
        */
        string getTexte()const;

        /**
        * \brief mutateur
        *
        * mutateur du texte
        * \param string : texte a afficher
        */
        void setTexte(string );

        /**
        * \brief accesseur
        *
        * Accesseur d'un mot dans le tableau de mots
        * \return renvoie un string \b mot
        * \param int : indice du mot dans le tableau
        */
        string getMot(int )const;

        /**
        * \brief addMot
        *
        * ajoute un mot au tableau de mots
        * \param string : mot a ajouter
        */
        void addMot(string );

        /**
        * \brief rmAllMot
        *
        * supprime tous les mots du tableau de mots
        */
        void rmAllMots();

        /**
        * \brief getTailleTabMots
        *
        * Renvoie un entier correspondant a la taille du tableau de mots
        * \return renvoie un entier \b int
        */
        int getTailleTabMots()const;

        /**
        * \brief accesseur
        *
        * Accesseur d'une ligne dans le tableau de lignes
        * \return renvoie un sf::Text \b une ligne de texte
        * \param int : indice de la ligne dans le tableau
        */
        sf::Text& getLigne(int );

        /**
        * \brief addLigne
        *
        * ajoute une ligne au tableau de lignes
        * \param sf::Text : ligne de texte a ajouter
        */
        void addLigne(const sf::Text &);

        /**
        * \brief rmAllLignes
        *
        * supprime toutes les lignes du tableau de lignes
        */
        void rmAllLignes();

        /**
        * \brief getTailleTabLignes
        *
        * Renvoie un entier correspondant a la taille du tableau de lignes
        * \return renvoie un entier \b int
        */
        int getTailleTabLignes()const;

        /**
        * \brief mutateur
        *
        * mutateur de la police de caractere
        * \param string : lien vers le fichier contenant la police de caractere
        */
        void setPoliceCar(string );

        /**
        * \brief accesseur
        *
        * Accesseur du fond de la zone de texte
        * \return renvoie un sf::RectangleShape& \b un rectangle representant le fond de la zone de texte
        */
        sf::RectangleShape& getFond();

        /**
        * \brief mutateur
        *
        * mutateur du fond de la zone de texte
        * \param sf::RectangleShape : rectangle representant le fond de la zone de texte
        */
        void setFond(const sf::RectangleShape &);

        /**
        * \brief accesseur
        *
        * Accesseur du choix de l'alignement sur l'axe horizontal
        * \return renvoie un string \b alignement sur l'axe horizontal
        */
        string getAlignementX()const;

        /**
        * \brief mutateur
        *
        * mutateur du choix de l'alignement sur l'axe horizontal
        * \param string : choix de l'alignement sur l'axe horizontal
        */
        void setAlignementX(string );

        /**
        * \brief accesseur
        *
        * Accesseur du choix de l'alignement sur l'axe vertical
        * \return renvoie un string \b alignement sur l'axe vertical
        */
        string getAlignementY()const;

        /**
        * \brief mutateur
        *
        * mutateur du choix de l'alignement sur l'axe vertical
        * \param string : choix de l'alignement sur l'axe vertical
        */
        void setAlignementY(string );

        /**
        * \brief testRegression
        *
        * test l'ensemble des fonctions de la classe
        */
        void testRegression();


    private:
        /**
        * \brief updateZone
        *
        * actualise la zone de texte
        */
        void updateZone();

        /**
        * \brief decoupageTexte
        *
        * decoupe le texte en un ensemble de mots
        */
        void decoupageTexte();

        /**
        * \brief remplissageTabLignes
        *
        * a partir du tableau de mots, de la dimesnion du fond et de la taille de caracere, remplit le tableau de lignes avec des sf::Text
        */
        void remplissageTabLignes();

        /**
        * \brief gestionAlignementTexte
        *
        * en fonction de alignementX et alignementY, gere l'alignement sur tous les axes du texte dans la zone de texte
        */
        void gestionAlignementTexte();

        /**
        * \brief aligneLigneCentreX
        *
        * renvoie la position sur X de la ligne d'indice en parametre si l'alignementX = "centre"
        * \param int : indice de la ligne dans le tableau de lignes
        * \return renvoie un int \b position sur l'axe horizontal
        */
        int aligneLigneCentreX(int );

        /**
        * \brief aligneLigneGaucheX
        *
        * renvoie la position sur X de la ligne d'indice en parametre si l'alignementX = "gauche"
        * \param int : indice de la ligne dans le tableau de lignes
        * \return renvoie un int \b position sur l'axe horizontal
        */
        int aligneLigneGaucheX(int );

        /**
        * \brief aligneLigneDroiteX
        *
        * renvoie la position sur X de la ligne d'indice en parametre si l'alignementX = "droite"
        * \param int : indice de la ligne dans le tableau de lignes
        * \return renvoie un int \b position sur l'axe horizontal
        */
        int aligneLigneDroiteX(int );

        /**
        * \brief aligneLigneCentreY
        *
        * renvoie la position sur Y de la ligne d'indice en parametre si l'alignementY = "centre"
        * \param int : indice de la ligne dans le tableau de lignes
        * \return renvoie un int \b position sur l'axe vertical
        */
        int aligneLigneCentreY(int );

        /**
        * \brief aligneLigneHautY
        *
        * renvoie la position sur Y de la ligne d'indice en parametre si l'alignementY = "haut"
        * \param int : indice de la ligne dans le tableau de lignes
        * \return renvoie un int \b position sur l'axe vertical
        */
        int aligneLigneHautY(int );

        /**
        * \brief aligneLigneBasY
        *
        * renvoie la position sur Y de la ligne d'indice en parametre si l'alignementY = "bas"
        * \param int : indice de la ligne dans le tableau de lignes
        * \return renvoie un int \b position sur l'axe vertical
        */
        int aligneLigneBasY(int );

};

#endif // _ZONEDETEXTE
