#ifndef FICHIER_H
#define FICHIER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class Fichier
{
private:
    std::string premiere_ligne;
    std::vector<std::vector<bool>> matrice;

public:
    Fichier() {}

    // Fonction pour lire le fichier et extraire les dimensions + les données de la matrice
    void lecture_fichier()
    {
        std::ifstream nom_fichier("data.txt");

        if (!nom_fichier.is_open())
        {
            std::cout << "Erreur d'ouverture de fichier !" << std::endl;
            return;
        }

        // Lire la première ligne (dimensions)
        std::getline(nom_fichier, premiere_ligne);

        // Extraire les dimensions de la première ligne
        std::stringstream fl(premiere_ligne);
        int abscisse, ordonnee;
        fl >> abscisse >> ordonnee;

        // Redimensionner la matrice en fonction des dimensions lues
        matrice.resize(abscisse, std::vector<bool>(ordonnee));

        // Lire le reste du fichier pour remplir la matrice
        std::string ligne;
        for (int i = 0; i < abscisse; i++)
        {
            std::getline(nom_fichier, ligne);
            std::stringstream ligne_stringstream(ligne);
            for (int j = 0; j < ordonnee; j++)
            {
                int valeur_temporaire;
                ligne_stringstream >> valeur_temporaire;
                matrice[i][j] = (valeur_temporaire != 0); // Convertir en bool
            }
        }

        nom_fichier.close();
    }

    int abscisse()
    {
        return matrice.size(); // Nombre de lignes
    }

    int ordonnee()
    {
        return matrice[0].size();
        ; // Nombre de lignes
    }
    bool get_status(int i, int j) const
    {
        return matrice[i][j];
    }

    // Afficher la taille de la matrice et son contenu
    void afficher_matrice()
    {
        int abscisse = matrice.size();    // Nombre de lignes
        int ordonnee = matrice[0].size(); // Nombre de colonnes

        // Afficher les dimensions de la matrice
        std::cout << "Dimensions de la matrice : " << abscisse << " lignes x " << ordonnee << " colonnes." << std::endl;

        // Afficher le contenu de la matrice
        std::cout << "Contenu de la matrice : " << std::endl;
        for (int i = 0; i < abscisse; i++)
        {
            for (int j = 0; j < ordonnee; j++)
            {
                std::cout << matrice[i][j] << " ";
            }
            std::cout << std::endl; // Saut de ligne après chaque ligne de la matrice
        }
    }
};

#endif
