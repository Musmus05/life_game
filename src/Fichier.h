#ifndef fichier_h
#define fichier_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class Fichier
{
    private:
        std::string premiere_ligne;          // Première ligne contenant les dimensions
        std::vector<std::vector<int>> matrice; // Matrice 2D pour stocker les données
    public:
        Fichier();
        void lecture_fichier();
        void afficher_matrice();


};

#endif