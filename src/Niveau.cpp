#include "Niveau.h"

using namespace std;

Niveau::Niveau()
{
    srand(time(NULL)); // initialisation de rand

    setLienData("./data/");
    setFichierConfigNiveau("configNiveaux.txt");
    setFichierNiveauActuel("NiveauActuel.txt");
    if(!verifCheminAccesFichier(lienData+fichierNiveauActuel) || !verifCheminAccesFichier(lienData+fichierConfigNiveau))
    {
        setLienData("../data/");
    }

    setAvancement(0);
    setId(recupIdNiveauJeu());
    recupConfigNiveau();
}

Niveau::Niveau(int i)
{
    assert(i>=0);

    srand(time(NULL)); // initialisation de rand

    setLienData("./data/");
    setFichierConfigNiveau("configNiveaux.txt");
    setFichierNiveauActuel("NiveauActuel.txt");
    if(!verifCheminAccesFichier(lienData+fichierNiveauActuel) || !verifCheminAccesFichier(lienData+fichierConfigNiveau))
    {
        setLienData("../data/");
    }

    setAvancement(0);
    saveNiveauJeu(i);
    setId(i);
    recupConfigNiveau();
}


int Niveau::getIdZombieFront()const
{
    return fileIdZombies.front();
}

int Niveau::getTailleFileIdZombies()const
{
    return fileIdZombies.size();
}

void Niveau::addIdZombie(int idZ)
{
    assert(idZ > 0);

    fileIdZombies.push(idZ);
}

void Niveau::rmIdZombie()
{
    if(!fileEstVide())
    {
        fileIdZombies.pop();
    }
    else
    {
        cout<<"erreur suppresion element fileIdZombie : file vide"<<endl;
    }
}

bool Niveau::fileEstVide()const
{
    return fileIdZombies.empty();
}


int Niveau::getTypeZombie(int indice)const
{
    assert(indice>=0);
    assert(indice<=(int)tabDiffType.size());

    return tabDiffType[indice];
}

int Niveau::getNbDiffTypeZombies()const
{
    return tabDiffType.size();
}

void Niveau::setTypeZombie(int indice, int i)
{
    assert(indice>=0);

    tabDiffType[indice] = i;
}

void Niveau::addTypeZombie(int i)
{
    tabDiffType.push_back(i);
}

void Niveau::rmTypeZombie(int indice)
{
    assert(indice>=0);
    tabDiffType.erase(tabDiffType.begin() + indice);
}

bool Niveau::estDansTabDiffTypeZombies(int element)const
{
    for(unsigned int i =0; i < tabDiffType.size(); i++)
    {
        if(tabDiffType[i] == element)
        {
            return true;
        }
    }
    return false;
}


string Niveau::getLienData()const
{
    return lienData;
}

void Niveau::setLienData(string link)
{
    assert(link != "");

    lienData = link;
}

string Niveau::getFichierNiveauActuel()const
{
    return fichierNiveauActuel;
}

void Niveau::setFichierNiveauActuel(string nom)
{
    assert(nom != "");

    fichierNiveauActuel = nom;
}

string Niveau::getFichierConfigNiveau()const
{
    return fichierConfigNiveau;
}

void Niveau::setFichierConfigNiveau(string nom)
{
    assert(nom != "");

    fichierConfigNiveau = nom;
}


int Niveau::getNbTotZombies()const
{
    return nbTotZombies;
}

void Niveau::setNbTotZombies(int nb)
{
    assert(nb>0);
    nbTotZombies = nb;
}


int Niveau::getAvancement()const
{
    return avancement;
}

void Niveau::setAvancement(int a)
{
    assert(a>= 0);
    assert(a<=100);

    avancement = a;
}

bool Niveau::estFini()const
{
    return (avancement >= 100);
}


string Niveau::getModeJeu()const
{
    return modeJeu;
}

void Niveau::setModeJeu(string texte)
{
    modeJeu = texte;
}


int Niveau::getId()const
{
    return id;
}

void Niveau::setId(int i)
{
    assert(i>=0);
    id = i;
}


void Niveau::afficheCheminAccesFichier()const
{
    cout<<"chemin vers "<<getFichierNiveauActuel()<<" : "<<getLienData()+getFichierNiveauActuel()<<endl;
    cout<<"chemin vers "<<getFichierConfigNiveau()<<" : "<<getLienData()+getFichierConfigNiveau()<<endl;
}


void Niveau::afficheFileIdZombies()const
{
    queue<int> q = fileIdZombies;
    while(!q.empty())
    {
        cout << q.front();
        q.pop();
        if(!q.empty())
        cout << " ";
    }
}

void Niveau::afficheTabDiffTypeZombies()const
{
    for(unsigned int i=0; i<tabDiffType.size();i++)
    {
        cout<<getTypeZombie(i)<<" ";
    }
    cout<<endl;
}

void Niveau::afficheNbTotZombies()const
{
    cout<<getNbTotZombies()<<endl;
}

void Niveau::afficheAvancement()const
{
    cout<<getAvancement()<<endl;
}

void Niveau::afficheIdNiveau()const
{
    cout<<getId()<<endl;
}

void Niveau::saveNiveauJeu(int niv)const
{
    ofstream fichier(lienData+fichierNiveauActuel, ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier

    if(fichier.is_open())
    {
        fichier << niv;
        fichier.close();
    }
    else cout<< "Erreur a l'ouverture du fichier niveauAtuel (ecriture) !" << endl;
}

void Niveau::testRegression()
{
    afficheCheminAccesFichier();
    afficheAvancement();
    afficheIdNiveau();
    afficheNbTotZombies();
    afficheTabDiffTypeZombies();
    afficheFileIdZombies();
}



int Niveau::recupIdNiveauJeu()
{
    int niveau;
    ifstream fichier(lienData+fichierNiveauActuel, ios::in);  // on ouvre le fichier en lecture

    if(fichier.is_open())  // si l'ouverture a réussi
    {
        fichier>>niveau;

        fichier.close();  // on ferme le fichier
        return niveau;
    }
    else  // sinon
        {cout << "Impossible d'ouvrir le fichier NiveauActuel (lecture)!" << endl;
        return -1; }


}

void Niveau::recupConfigNiveau()
{
    ifstream fichier(lienData+fichierConfigNiveau, ios::in);  // on ouvre le fichier en lecture
    string mot, mode;
    vector<int> tabNbType;
    int numNiveau, nbZombies, typeZ, nbType;

    if(!fichier.is_open())
    {
        cout<<"erreur ouverture configniveaux"<<endl;
    }
    else
    {
        fichier >> mot;
        while(!fichier.eof() && fichier.is_open())
        {
            viderTab(tabDiffType);
            viderTab(tabNbType);
            fichier >> numNiveau >> mode;
            fichier >> mot >> nbZombies;

            fichier>>mot;
            do
            {
                fichier >> typeZ;
                if(!estDansTabDiffTypeZombies(typeZ))
                {
                    addTypeZombie(typeZ);
                }
                else
                {
                    cout<<"incoherence configNiveau : type redondant"<<endl;
                }

                fichier >> nbType;
                tabNbType.push_back(nbType);
                fichier>>mot;

            }while(!fichier.eof() && mot != "Niveau");

            if(numNiveau == getId())
            {
                fichier.close();
                int somme = calculSommeElementsTab(tabNbType);

                if(nbZombies != somme)
                {
                    cout<<"erreur nbZombies != somme des types de zombies"<<endl;
                    cout<<"somme = "<<somme<<" alors que nbZombie = "<<nbZombies<<endl;
                }
                else
                {
                    setNbTotZombies(nbZombies);
                    setModeJeu(mode);
                    unsigned int nbAleat = 0;
                    while(calculSommeElementsTab(tabNbType) != 0)
                    {
                        nbAleat = rand()%(tabNbType.size())+1;

                        for(unsigned int i =1; i<= tabNbType.size(); i++ )
                        {
                            if(nbAleat == i)
                            {
                                if(tabNbType[i-1] != 0)
                                {
                                    addIdZombie(nbAleat);
                                    tabNbType[i-1]--;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                if(fichier.eof())
                {
                    fichier.close();
                    setId(1);
                    recupConfigNiveau();
                }
            }

        }
    }


}

int Niveau::calculSommeElementsTab(const vector<int> & tab)const
{
    int somme = 0;
    for(unsigned int i=0; i<tab.size();i++)
    {
        somme = somme + tab[i];
    }

    return somme;
}

void Niveau::viderTab(vector<int> & tab)
{
    tab.clear();
}

bool Niveau::verifCheminAccesFichier(string link)const
{
        ifstream fichier(link, ios::in);  // on ouvre le fichier en lecture
        if(!fichier.is_open())
        {
            return false;
        }
        fichier.close();
	return true;
}

