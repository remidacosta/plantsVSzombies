#ifndef _ETAPETUTORIEL
#define _ETAPETUTORIEL

#include "ZoneDeTexte.h"
#include <iostream>
#include <fstream>
/** \class EtapeTutoriel EtapeTutoriel.h "src/EtapeTutoriel.h"
* \brief la classe EtapeTutoriel represente les étapes du tutoriel 
*
* La classe gere une etape du tutoriel, en fonction de son numero detape
*/
class EtapeTutoriel
{
    private:
        int numEtape;           /** numero de letape */
        ZoneDeTexte Zonetxt;    /** zone de texte correspondant au paragraphe a afficher */

    public:
        /**
        * \brief constructeur
        *
        * Constructeur de la classe EtapeTutoriel
        * \param int : numero de letape
        */
        EtapeTutoriel(int );

        /**
        * \brief accesseur
        *
        * Accesseur du numero de letape
        * \return renvoie un entier \b numero de letape
        */
        int getNumEtape()const;

        /**
        * \brief mutateur
        *
        * mutateur du numero de letape
        * \param int : numero de letape
        */
        void setNumEtape(int );

        /**
        * \brief accesseur
        *
        * Accesseur de la zone de texte
        * \return renvoie un type ZoneDeTexte \b zone de texte
        */
        ZoneDeTexte& getZonetxt();

    private:
        /**
        * \brief initZonetxt
        *
        * charge le texte dans la zone de texte en fontion du numero detape
        */
        void initZonetxt();

};

#endif // _ETAPETUTORIEL
