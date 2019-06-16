#ifndef _NIVEAU
#define _NIVEAU

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


/**
* @class Niveau Niveau.h "src/Niveau.h"
* @brief La classe Niveau qui gere les niveaux au cour  d'une partie
* 
* la classe niveau va gerer le nombre de zombie, leur type, le nombre de soleil de depart etc.. 
*/
class Niveau
{

    private:
        queue<int> fileIdZombies;       /** file contenant les id des zombies qui vont apparaitre dans l'ordre de defilement */
        vector<int> tabDiffType;     	/** tableau dynamique contenant les types de zombies */
        string lienData;				/** lien vers le data */
        string fichierNiveauActuel;		/** nom du fichier pour obtenir le niveau actuel */
        string fichierConfigNiveau;		/** nom du fichier pour obtenir la config des niveaux */
        int nbTotZombies;				/** nombre de zombie */
        int avancement;					/** avancement du jeu */
        string modeJeu;					/** mode de jeu soit tutoriel soit nightmare soit normal soit difficile */
        int id;							/** id du niveau different pour chaque niveau */

    public:
	
		/**
		* @brief Constructeur par defaut
		*
		* Constructeur par defaut de la classe Niveau
		*/
        Niveau();

		/**
		* @brief Constructeur 
		*
		* Constructeur avec le niveau en parametre
		* @param int : niveau
		*/
        Niveau(int i);                  
		
		
		
		/**
		* @brief Accesseeur 
		*
		* retourne la valeur du premier element de la file
		* @return un entier
		*/
        int getIdZombieFront()const;
		/**
		* @brief Accesseeur 
		*
		* retourne la taille de la file
		* @return un entier
		*/
        int getTailleFileIdZombies()const;
		
		/**
		* @brief ajoute un zombie 
		*
		* ajoute un ID de zombie a la file 
		* @param int : Id a ajouter
		*/
        void addIdZombie(int);
		
		/**
		* @brief enleve un zombie 
		*
		* enleve l'Id d'un zombie a la file 
		*/
        void rmIdZombie();
		
		/**
		* @brief test si la file est vide 
		*
		* retourne un booleen qui est TRUE si la file est Vide
		* @return un bool
		*/
        bool fileEstVide()const;

		/**
		* @brief Accesseeur 
		*
		* retourne le type du zombie d'indice donne en parametre
		* @param int : indice du zombie
		* @return un entier
		*/
        int getTypeZombie(int )const; 

		/**
		* @brief Accesseeur 
		*
		* retourne la taille du table de different type
		* @return un entier
		*/
        int getNbDiffTypeZombies()const;
		
		/**
		* @brief Mutateur 
		*
		* remplace l'id d'un zombie selon son indice
		* @param int : indice du zombie
		* @param int : id du zombie 
		*/
        void setTypeZombie(int, int);    
		
		/**
		* @brief ajoute un id de zombie a la fin du tableau
		*
		* 
		* @param int : id du zombie 
		*/
        void addTypeZombie(int );

		/**
		* @brief enleve un id de zombie en fonction de son indice dans le tableau
		*
		* 
		* @param int : indice du zombie
		*/
        void rmTypeZombie(int );  

		/**
		* @brief verifie que lelement est bien de le tableau des differents types de zombies
		*
		* renvoie un booleen TRUE si lelement est dans le tableau FALSE sinon
		* @param int : element a verifier
		* @return un bool
		*/
        bool estDansTabDiffTypeZombies(int )const;
		
		
		/**
		* @brief Accesseeur
		*
		* renvoie le string du lien vers le data
		* @return string
		*/
        string getLienData()const;
		
		/**
		* @brief Mutateur
		*
		* modifie le chemin vers le data
		* @param string : chemin vers le data
		*/
        void setLienData(string );
		
		/**
		* @brief Accesseeur
		*
		* retourne le nom du fichier contenant le niveau actuel
		* @return string
		*/
        string getFichierNiveauActuel()const;
		
		/**
		* @brief Mutateur
		*
		* modifie le nom du fichier contenant le niveau actuel
		* @param string : chemin vers le data
		*/
        void setFichierNiveauActuel(string );
		
		/**
		* @brief Accesseeur
		*
		* retourne le nom du fichier contenant la config des niveaux
		* @return string
		*/
        string getFichierConfigNiveau()const;
		
		/**
		* @brief Mutateur
		*
		* modifie le nom du fichier contenant la config des niveaux 
		* @param string : chemin vers le data
		*/
        void setFichierConfigNiveau(string );
		
		
		/**
		* @brief Accesseeur
		*
		* recupere le nombre de zombie total pour le niveau
		* @return un entier
		*/
        int getNbTotZombies()const; 

		/**
		* @brief Mutateur
		*
		* modifie le nombre de zombie total pour le niveau
		* @param int : nombre de zombie total
		*/
        void setNbTotZombies(int );
		
		/**
		* @brief Accesseeur
		*
		*recupere letat du niveau (fini : true)
		* @return un entier
		*/
        int getAvancement()const;   
		
        /**
		* @brief Mutateur
		*
		*modifie letat du niveau
		* @param int : avancement actuel
		*/
        void setAvancement(int );

		/**
		* @brief renvoie un booleen si l'avancement est superieur a 100
		*
		* verifie que l'avancement est plus petit que 100 
		* @return un bool
		*/
        bool estFini()const;
		
		/**
		* @brief Accesseeur
		*
		*recupere le mode de jeu
		* @return string
		*/
        string getModeJeu()const;
		
		/**
		* @brief Mutateur
		*
		*change le mode de jeu
		* @param string : mode de jeu
		*/
        void setModeJeu(string );
		
		/**
		* @brief Accesseeur
		*
		*recupere l'id du niveau
		* @return un entier
		*/
        int getId()const;  

		/**
		* @brief Mutateur
		
		*modifie l'id du niveau
		* @param int : nouvel id
		*/
        void setId(int );
		
		/**
		* @brief affiche le chemin d'acces jusqu' au data
		*/
        void afficheCheminAccesFichier()const;
		
		/**
		* @brief affiche la file de zombie dans la console
		*/
        void afficheFileIdZombies()const;
		
		/**
		* @brief affiche les types de zombies du niveau
		*/
        void afficheTabDiffTypeZombies()const;
		
		/**
		* @brief affiche le nombre total de zombie du niveau
		*/
        void afficheNbTotZombies()const;
		
		/**
		* @brief affiche l'avancement du niveau 
		*/
        void afficheAvancement()const;
		
		/**
		* @brief affiche l'id du niveau
		*/
        void afficheIdNiveau()const;
		
		/**
		* @brief sauvegarde le niveau actuel
		*
		* enregistre l'id du niveau actuel dans le fichierNiveauActuel
		*/
        void saveNiveauJeu(int )const;
		
		/**
		*@brief testRegression
		*
		* test toutes les fonctions du module
		*/
        void testRegression();

    private:
	
		/**
		* @brief calcul la somme des elements d'un tableau dynamique
		*
		* @param vector<int> : tableau dynamique d'entier 	
		* @return un entier
		*/
        int calculSommeElementsTab(const vector<int> &)const;
		
		/**
		* @brief vide le tableau
		*
		* @param vector<int> : tableau dynamique d'entier 
		*/
        void viderTab(vector<int> &);
	
		/**
		* @brief recupere l'id du niveau
		*
		*recupere l'id du niveau dans le dossier ./data/Niveauactuel.txt
		* 	
		* @return un entier
		*/
        int recupIdNiveauJeu();
		
		/**
		* @brief recupere l'id du niveau
		*
		*recupere la config du niveau (nbZombies, types de zombies) dans le dossier ./data/configNiveaux.txt
		*/
        void recupConfigNiveau();  

		/**
		* @brief verifie le chemin d'acces au fichier
		*
		*renvoie un bool TRUE si le chemin d'acces aux fichiers et le bon et FALSE sinon
		* @param string : chemind d'acces
		* @return un bool
		*/
        bool verifCheminAccesFichier(string )const;
};

#endif // _NIVEAU
