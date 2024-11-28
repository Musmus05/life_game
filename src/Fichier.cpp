#include "Fichier.h"

Fichier::Fichier() {}

void Fichier::lecture_fichier()
{
    ifstream nom_fichier("data.txt");

    if (!nom_fichier.is_open())
    {
        cout << "Erreur d'ouverture de fichier !" << endl;
        return;
    }

    // Lire la première ligne (dimensions)
    getline(nom_fichier, premiere_ligne);

    // Extraire les dimensions de la première ligne
    stringstream pl(premiere_ligne);
    int ligne, colonne;
    pl >> ligne >> colonne;

    // Redimensionner la matrice en fonction des dimensions lues
    matrice.resize(ligne, vector<int>(colonne));

    // Lire le reste du fichier pour remplir la matrice
    string reste_ligne;
    for (int i = 0; i < ligne; i++)
    {
        getline(nom_fichier, reste_ligne);
        stringstream reste_ligne_stringstream(reste_ligne);
        for (int j = 0; j < colonne; j++)
        {
            reste_ligne_stringstream >> matrice[i][j];
        }
    }

    nom_fichier.close();
}


int Fichier::get_ligne(){
    return matrice.size();
}

int Fichier::get_colonne(){
    return matrice[0].size();
}

vector<vector<int>> Fichier::get_matrice(){
    return matrice;
}