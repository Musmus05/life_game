#include "Jeux_vie.h"

Jeux_vie::Jeux_vie()
{
    menu();
    cin >> choix;
    switch (choix)
    {
    case 1:
        grille = new Grille_terminal();
        cout << "Nombre de generation : ";
        cin >> this->nombre_generation;
        generation = 0;
        break;
    case 2:
        grille = new Grille_graphique();
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
    sortie.supprimer_dossier();
    if (choix == 2)
    {
        grille->afficher_grille();
    }
    else{
    for (int i = 0; i < nombre_generation; i++)
    {
        grille->afficher_grille();
        cout << "Generation : " << this->generation << endl;
        cout << "Nombre de cellule : " << grille->calcule_compteur_cellule() << endl;
        cout << "Nombre de cellule vivante : " << grille->calcule_compteur_cellule_vivante() << endl;
        cout << "Nombre de cellule morte : " << grille->calcule_compteur_cellule_morte() << endl;
        cout << "====================" << endl;
        grille->Grille_update();
        generation++;
        sortie.ecriture_fichier(grille->get_matrice(), generation);

    }
    }
}

int Jeux_vie::get_generation()
{
    return generation;
}

Jeux_vie::~Jeux_vie()
{
    delete grille;
}

