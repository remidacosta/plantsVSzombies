#ifndef JEU_H
#define JEU_H
#include "Hud.h"
#include "Terrain.h"
#include "Niveau.h"
#include "Soleil.h"
#include "Zombie.h"
#include "Projectile.h"
#include "Plante.h"

/** 
*\class Jeu Jeu.h "src/Jeu.h"
* \brief la classe Jeu represente un jeu PlantsVSZombies
*
* La classe gere le jeu PlantsVSZombies independamment d'une bibliotheque graphique
*/
class Jeu
{
	private:
        Hud hud;                        /** hud du jeu, permet le choix d'une plante a poser**/
        Niveau * niveau;                /** pointeur sur un niveau de jeu **/
        Terrain terrain;                /** terrain du jeu **/
        int nbSoleils;                  /** nombre de soleils disponibles **/
        bool partie_terminee;           /** booleen de letat de la partie, TRUE si partie terminee, FALSE sinon **/
        float cadenceSpawnSoleil[2];    /** tableau de cadence de l'apparition des soleils sur le terrain **/
        float cadenceSpawnZombie[2];    /** tableau de cadence de l'apparition des zombies sur le terrain **/

	public:
	/**
        * \brief constructeur par defaut
        *
        * Constructeur par defaut de la classe Jeu
        */
        Jeu();

        /**
        * \brief destructeur par defaut
        *
        * destructeur par defaut de la classe Jeu
        */
        ~Jeu();

        /**
        * \brief accesseur
        *
        * Accesseur de l'Hud
        * \return renvoie un Hud \b Hud
        */
        Hud& getHud();

        /**
        * \brief mutateur
        *
        * mutateur de l'Hud
        * \param Hud
        */
        void setHud(const Hud &);

        /**
        * \brief accesseur
        *
        * Accesseur du terrain
        * \return renvoie un terrain \b Terrain
        */
        Terrain& getTerrain();

        /**
        * \brief mutateur
        *
        * mutateur du terrain
        * \param Terrain
        */
        void setTerrain(const Terrain &);

        /**
        * \brief accesseur
        *
        * Accesseur du Niveau
        * \return renvoie un niveau \b Niveau
        */
        Niveau * getNiveau() const;

        /**
        * \brief mutateur
        *
        * mutateur du Niveau
        * \param Niveau
        */
        void setNiveau(Niveau *);

        /**
        * \brief mutateur
        *
        * mutateur de l'ID du Niveau
        * \param entier
        */
        void setIdNiveau(int );

        /**
        * \brief accesseur
        *
        * Accesseur du nombre de soleils
        * \return renvoie un entier \b int
        */
        int getNbSoleils() const;

        /**
        * \brief mutateur
        *
        * mutateur du nombre de soleils
        * \param entier
        */
        void setNbSoleils(int);

        /**
        * \brief accesseur
        *
        * Accesseur de letat de la partie
        * \return renvoie un booleen \b bool
        */
        bool getPartieTerminee() const;

        /**
        * \brief mutateur
        *
        * mutateur de letat de la partie
        * \param booleen : bool
        */
        void setPartieTerminee(bool);

        /**
        * \brief accesseur
        *
        * Accesseur du compteur de la cadence d'apparition des soleils sur le terrain
        * \return renvoie un reel \b float
        */
        float getComptCadenceSpawnSoleil()const;

        /**
        * \brief mutateur
        *
        * mutateur du compteur de la cadence d'apparition des soleils sur le terrain
        * \param reel : float
        */
        void setComptCadenceSpawnSoleil(float);

        /**
        * \brief accesseur
        *
        * Accesseur de la cadence d'apparition des soleils sur le terrain
        * \return renvoie un reel \b float
        */
        float getCadenceSpawnSoleil()const;

        /**
        * \brief mutateur
        *
        * mutateur de la cadence d'apparition des soleils sur le terrain
        * \param reel : float
        */
        void setCadenceSpawnSoleil(float);

        /**
        * \brief accesseur
        *
        * Accesseur du compteur de la cadence d'apparition des zombies sur le terrain
        * \return renvoie un reel \b float
        */
        float getComptCadenceSpawnZombie()const;

        /**
        * \brief mutateur
        *
        * mutateur du compteur de la cadence d'apparition des zombies sur le terrain
        * \param reel : float
        */
        void setComptCadenceSpawnZombie(float);

        /**
        * \brief accesseur
        *
        * Accesseur de la cadence d'apparition des zombies sur le terrain
        * \return renvoie un reel \b float
        */
        float getCadenceSpawnZombie()const;

        /**
        * \brief mutateur
        *
        * mutateur de la cadence d'apparition des zombies sur le terrain
        * \param reel : float
        */
        void setCadenceSpawnZombie(float);

        /**
        * \brief apparitionSoleil
        *
        * gere l'apparition d'un soleil de maniere aleatoire sur le terrain
        */
        void apparitionSoleil();

        /**
        * \brief apparitionZombie
        *
        * gere l'apparition d'un zombie sur une ligne aleatoire
        */
        void apparitionZombie();

        /**
        * \brief plante_existe_ici
        *
        * verifie si une plante appartient a une case sur une certaine ligne
        * \param int : indice ligne
        * \param int : indice case
        * \return booleen \b bool
        */
        bool plante_existe_ici(int ,int );

        /**
        * \brief soleil_existe_ici
        *
        * verifie si un soleil appartient a une case sur une certaine ligne
        * \param int : indice ligne
        * \param int : indice case
        * \return booleen \b bool
        */
        bool soleil_existe_ici(int ,int );

        /**
        * \brief ramasserSoleil
        *
        * gere le ramassage d'un soleil sur une certaine case d'une certaine ligne
        * \param int : indice ligne
        * \param int : indice case
        */
        void ramasserSoleil(int ,int );

        /**
        * \brief poserPlante
        *
        * pose une plante donnee en parametre sur une case
        * \param Plante : plante a poser
        * \param int : indice ligne
        * \param int : indice case
        */
        void poserPlante(Plante ,int ,int );

        /**
        * \brief niveauSuivant
        *
        * passe au niveau suivant
        */
        void niveauSuivant();

        /**
        * \brief contactZombiePlante
        *
        * verifie si il y a contact entre un zombie et une plante donnes en parametre
        * \param iterateur de Zombie
        * \param iterateur de Plante
        */
        bool contactZombiePlante(list<Zombie>::iterator ,list<Plante>::iterator );

        /**
        * \brief contactProjectileZombie
        *
        * verifie si il y a contact entre un projectile et un zombie donnes en parametre
        * \param iterateur de Projectile
        * \param iterateur de Zombie
        */
        bool contactProjectileZombie(list<Projectile>::iterator ,list<Zombie>::iterator);

        /**
        * \brief zombiePeutAvancer
        *
        * verifie si un zombie donne en parametre peut avancer
        * \param iterateur de Zombie
        * \param int : indice de la ligne
        */
        bool zombiePeutAvancer(list<Zombie>::iterator ,int );

        /**
        * \brief projectilePeutAvancer
        *
        * verifie si un projectile donne en parametre peut avancer
        * \param iterateur de Projectile
        * \param int : indice de la ligne
        */
        bool projectilePeutAvancer(list<Projectile>::iterator ,int );

        /**
        * \brief plantePeutTirer
        *
        * verifie si une plante donnee en parametre peut tirer
        * \param iterateur de Plante
        * \param int : indice de la ligne
        */
        bool plantePeutTirer(list<Plante>::iterator ,int );

        /**
        * \brief actionsAuto
        *
        * gere toutes les actions automatiques du jeu, comme les deplacements des zombies, des projectiles, le tire des plantes, l'apparition des soleils et des zombies
        */
        void actionsAuto();

        /**
        * \brief actionPlante
        *
        * gere les actions d'une plante donnee en parametre
        * \param iterateur de Plante
        * \param int : indice de la ligne
        */
        void actionPlante(list<Plante>::iterator,int);

        /**
        * \brief actionProjectile
        *
        * gere les actions d'un projectile donne en parametre
        * \param iterateur de Projectile
        * \param int : indice de la ligne
        */
        void actionProjectile(list<Projectile>::iterator,int);

        /**
        * \brief avanceZombie
        *
        * gere les actions d'un zombie donne en parametre
        * \param iterateur de Zombie
        * \param int : indice de la ligne
        */
        void avanceZombie(list<Zombie>::iterator ,int );

        /**
        * \brief attaqueZombie
        *
        * gere les actions d'un zombie donne en parametre
        * \param iterateur de Zombie
        * \param int : indice de la ligne
        */
        void attaqueZombie(list<Zombie>::iterator ,int );

        /**
        * \brief avanceTondeuse
        *
        * gere le deplacement de la tondeuse d'une ligne dont l'indice est donne en parametre
        * \param int : indice de la ligne
        */
        void avanceTondeuse(int );

        /**
        * \brief planteTire
        *
        * fait tirer les plantes
        */
        void planteTire();

        /**
        * \brief gestionTondeuse
        *
        * gere letat des tondeuses et si oui ou non elles se deplacent
        * \param indice de la ligne
        */
        void gestionTondeuse(int );

        /**
        * \brief traitementChoix
        *
        * en fonction de la plante choisie dans l'Hud, verifie si l'utilisateur clique sur une case vide pour poser sa plante
        * \param int : coordonnee x du clic de la souris
        * \param int : coordonnee y du clic de la souris
        */
        void traitementChoix(int,int);

        /**
        * \brief getConfigPlante
        *
        * charge la donnee souhaitee(cadence,PV,degats,...) a la creation de la plante, depuis un fichier texte dans le dossier data, avec en parametre l'ID de la Plante et la donnee concernee
        * \param int : ID de la plante
        * \param string : donnee souhaitee
        */
        int getConfigPlante(int,string );

        /**
        * \brief getConfigPlante
        *
        * charge la donnee souhaitee(cadence,PV,degats,...) a la creation du zombie,  depuis un fichier texte dans le dossier data, avec en parametre l'ID du Zombie et la donnee concernee
        * \param int : ID de la plante
        * \param string : donnee souhaitee
        */
        int getConfigZombie(int,string );

        /**
        * \brief afficher
        *
        * affiche le jeu sur la version texte
        */
        void afficher();

    private:
        /**
        * \brief initHud
        *
        * initialise toutes les variables de l'Hud et configure l'ensemble des actions disponibles a partir de l'Hud
        */
        void initHud();

        /**
        * \brief initConfigJeu
        *
        * initialise toutes les variables du jeu
        */
        void initConfigJeu();

        /**
        * \brief xEnNumCase
        *
        * transforme une coordonnee x de clic de souris en un id de case
        * \param int : coordonnee x du clic de la souris
        * \return int : id Case
        */
        int xEnNumCase(int );

        /**
        * \brief yEnNumLigne
        *
        * transforme une coordonnee y de clic de souris en un id de ligne
        * \param int : coordonnee y du clic de la souris
        * \return int : id Ligne
        */
        int yEnNumLigne(int );
};

#endif //_JEU
