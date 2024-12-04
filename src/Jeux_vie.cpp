#include "Jeux_vie.h"
using namespace std;
Jeux_vie::Jeux_vie()
{
    menu();
    cin >> choix;
    switch (choix)
    {
    case 1:
        grille = new Grille_terminal();
        cout << "Nombre de génération : ";
        cin >> this->nombre_generation;
        cout << "Combien de fichiers voulez-vous examiner pour vérifier la répétition des dernières générations : ";
        cin >> nombre_dernier_fichier;
        // redimensionnement du vecteur
        fichiers_recents.resize(nombre_dernier_fichier);
        break;
    case 2:
        cout << "Combien de temps entre chaque génération voulez-vous (en miliseconde) : ";
        cin >> this->temps_entre_generation;
        grille = new Grille_graphique(temps_entre_generation);

        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "Choix invalide !" << endl;
        exit(0);
        break;
    }
}

void Jeux_vie::menu()
{
    cout << "=== Menu ===" << endl;
    cout << "1. Grille terminal" << endl;
    cout << "2. Grille graphique" << endl;
    cout << "3. Quitter" << endl;
    cout << "Votre choix : ";
}

void Jeux_vie::run()
{
    string nom_fichier_sortie;
    sortie.supprimer_dossier(); // sup les anciens fichiers
    if (choix == 2)
    {
        grille->afficher_grille();
    }
    else
    {
        for (int i = 0; i < nombre_generation+1 ; i++)
        {
            verif_generation_successive(); // methode pour verif si les generation successice sont les memes
            grille->afficher_grille();

            // informations sur la grille
            cout << "Generation : " << this->generation << endl;
            cout << "Nombre de cellule : " << grille->calcule_compteur_cellule() << endl;
            cout << "Nombre de cellule vivante : " << grille->calcule_compteur_cellule_vivante() << endl;
            cout << "Nombre de cellule morte : " << grille->calcule_compteur_cellule_morte() << endl;
            cout << "====================" << endl;

            // recup du nom du fichier genere
            nom_fichier_sortie = sortie.ecriture_fichier(grille->get_matrice(), generation); // on recup le nom du fichier

            // Déplacement des fichiers dans la liste récents
            for (int j = nombre_dernier_fichier - 1; j > 0; j--)
            {
                fichiers_recents[j] = fichiers_recents[j - 1];
            }
            // Ajout du nouveau fichier à la première position
            fichiers_recents[0] = nom_fichier_sortie; // ajout dun nouveau fichier vide
            grille->Grille_update();
            generation++;
        }
    }
}

int Jeux_vie::get_generation()
{
    return generation;
}

Jeux_vie::~Jeux_vie()
{
    delete grille; // libere la memoire
}

void Jeux_vie::verif_generation_successive()
{
    int compteur = 0;
    if (generation > fichiers_recents.size())
    {
        for (int i = 0; i < fichiers_recents.size() - 1; i++)
        {
            Fichier file1;
            Fichier file2;

            if (file1.lecture_fichier(fichiers_recents[i]) == file2.lecture_fichier(fichiers_recents[i + 1]))
            {
                compteur++;
            }
            else
            {
                compteur = 0;
            }
        }
    }
    if (compteur == fichiers_recents.size() - 1)
    {
        cout << "Il y a " << compteur + 1 << " generation identique. Arrêt du programme." << endl;
        exit(0);
    }
}