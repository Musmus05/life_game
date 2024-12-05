#include "Jeux_vie.h"
using namespace std;

Jeux_vie::Jeux_vie()
{
    menu();
    cin >> choix;
    switch (choix)
    {
    case 1:
        grille = new Grille();
        affichage = new Affichage_terminal(grille);
        cout << "Nombre de génération : ";
        cin >> this->nombre_generation;
        cout << "Combien de fichiers voulez-vous examiner pour vérifier la répétition des dernières générations : ";
        cin >> nombre_dernier_fichier;
        // redimensionnement du vecteur
        fichiers_recents.resize(nombre_dernier_fichier);

        cout << "torique ou non torique ? (1/0) : ";
        int torique;
        cin >> torique;
        if (torique == 1)
        {
            grille_update = new Grille_update_Torique();
        }
        else
        {
            grille_update = new Grille_update_default();
        }
        break;
    case 2:
        grille = new Grille();
        cout << "Combien de temps entre chaque génération voulez-vous (en miliseconde) : ";
        cin >> this->temps_entre_generation;
        affichage = new Affichage_graphique(grille, this->temps_entre_generation);
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

void Jeux_vie::run()
{
    string nom_fichier_sortie;
    sortie.supprimer_dossier(); // sup les anciens fichiers
    if (choix == 2)
    {
        affichage->afficher_grille();
    }
    else
    {
        for (int i = 0; i < nombre_generation + 1; i++)
        {
            verif_generation_successive(); // methode pour verif si les generation successice sont les memes
            cout << "Generation : " << generation << endl;
            affichage->afficher_grille();
            cout << "===================================" << endl;
            nom_fichier_sortie = sortie.ecriture_fichier(grille->get_matrice(), generation); // on recup le nom du fichier

            // Déplacement des fichiers dans la liste récents
            for (int j = nombre_dernier_fichier - 1; j > 0; j--)
            {
                fichiers_recents[j] = fichiers_recents[j - 1];
            }

            // Ajout du nouveau fichier à la première position
            fichiers_recents[0] = nom_fichier_sortie; // ajout dun nouveau fichier vide

            // mise a jour de la grille
            grille_update->update(*grille);
            generation++;
        }
    }
}

Jeux_vie::~Jeux_vie()
{
    delete grille; // libere la memoire
    delete affichage;
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

int Jeux_vie::get_generation()
{
    return generation;
}

void Jeux_vie::menu()
{
    cout << "1. Affichage terminal" << endl;
    cout << "2. Affichage graphique" << endl;
    cout << "3. Quitter" << endl;
    cout << "Choisissez une option : ";
}