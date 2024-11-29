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
    std::vector<std::vector<int>> matrice;

public:
    Fichier();

    // fonction pour lire le fichier et extraire les dimensions + les donnees de la matrice
    void lecture_fichier(std::string filename);

    /*---GETTERS---*/
    int abscisse();
    int ordonnee();
    int get_status(int i, int j) const;

    // afficher la taille de la matrice et son contenu
    void afficher_matrice();
};

#endif
