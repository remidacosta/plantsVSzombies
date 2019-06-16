#ifndef _VECTEUR2D
#define _VECTEUR2D


/** \class Vecteur2D Vecteur2D.h "src/Vecteur2D.h"
* \brief classe Vecteur2D en dimension 2
*
*La classe Vecteur2D que l'on utilise pour definir la dimension et la position
*/
class Vecteur2D
{

    private:
        int tx; /** coordonnee x du vecteur */
        int ty; /** coordonnee y du vecteur */

    public:


    	/**
    	* \brief constructeur par defaut
    	*
    	* Constructeur par defaut d'un vecteur 2D
    	*/
        Vecteur2D();

        /**
        * \brief constructeur
        *
        * Constructeur de la classe vecteur 2D
        * \param int : coordonnee x du vecteur
        * \param int : coordonnee y du vecteur
        */
        Vecteur2D(int,int);

        /**
        * \brief accesseur
        *
        * accesseur à la coordonnee x du vecteur
        * \return renvoie un entier \b coordoonnee du vecteur
        */
        int getVectX()const;

        /**
        * \brief mutateur
        *
        * mutateur de la coordonnee x du vecteur
        * \param int : nouvelle coordonne x du vecteur
        */
        void setVectX(int);

        /**
        * \brief accesseur
        *
        * accesseur à la coordonnee y du vecteur
        * \return renvoie un entier \b coordoonnee du vecteur
        */
        int getVectY()const;

        /**
        * \brief mutateur
        *
        * mutateur de la coordonnee y du vecteur
        * \param int : nouvelle coordonne y du vecteur
        */
        void setVectY(int);


        /**
        *\brief testRegression
        *
        * test toutes les fonctions du module
        */
        void testRegression();
};
#endif // _VECTEUR2D

/**
* \brief surchage operateur
*
* surchage l'operateur "==" pour la classe vecteur2D
* \param Vecteur2D v1 : pour la comparaison
* \param Vecteur2D v2 : pour la comparaison
* \return renvoie un bool résultat de la comparaison
*/
bool operator==(Vecteur2D const& v1,Vecteur2D const& v2);
