#include "Fichier.h"

Fichier::Fichier() {}

void Fichier::lecture_fichier()
{
    std::ifstream nom_fichier("data.txt");

    if (!nom_fichier.is_open())
    {
        std::cout << "Erreur d'ouverture de fichier !" << std::endl;
        return;
    }

    // Lire la première ligne (dimensions)
    getline(nom_fichier, premiere_ligne);

    // Extraire les dimensions de la première ligne
    std::stringstream pl(premiere_ligne);
    int ligne, colonne;
    pl >> ligne >> colonne;

    // Redimensionner la matrice en fonction des dimensions lues
    matrice.resize(ligne, std::vector<int>(colonne));

    // Lire le reste du fichier pour remplir la matrice
    std::string reste_ligne;
    for (int i = 0; i < ligne; i++)
    {
        getline(nom_fichier, reste_ligne);
        std::stringstream reste_ligne_stringstream(reste_ligne);
        for (int j = 0; j < colonne; j++)
        {
            reste_ligne_stringstream >> matrice[i][j];
        }
    }

    nom_fichier.close();
}

// Afficher la taille de la matrice et son contenu
void Fichier::afficher_matrice(){
    int ligne = matrice.size();    // Nombre de lignes
    int colonne = matrice[0].size(); // Nombre de colonnes

    // Afficher les dimensions de la matrice
    std::cout << "Dimensions de la matrice : " << ligne << " lignes x " << colonne << " colonnes." << std::endl;

    // Afficher le contenu de la matrice
    std::cout << "Contenu de la matrice : " << std::endl;
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            std::cout << matrice[i][j] << " ";
        }
        std::cout << std::endl; // Saut de ligne après chaque ligne de la matrice
    }
}
