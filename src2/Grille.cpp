#include "Grille.h"
using namespace std;

Grille::Grille()
{
    Grille_init();
};

Grille::~Grille() {}

void Grille::Grille_init()
{
    string filename;
    cout << "Nom du fichier : ";
    cin >> filename;
    Fichier fichier(filename);
    fichier.lecture_fichier(filename);
    ligne = fichier.get_ligne();
    colonne = fichier.get_colonne();
    matrice.resize(ligne, vector<Cellule>(colonne)); // Initialisation de la matrice
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            matrice[i][j] = Cellule(i, j, fichier.get_matrice()[i][j]); // Remplissage de la matrice
        }
    }
}

std::vector<std::vector<Cellule>> Grille::get_matrice()
{
    return matrice;
}

int Grille::get_ligne(){
    return matrice.size();
}

int Grille::get_colonne(){
    return matrice[0].size();
}