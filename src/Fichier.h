#ifndef fichier_h
#define fichier_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#include "Grille.h"

class Fichier
{
    private:
        string premiere_ligne;          // Première ligne contenant les dimensions
        vector<vector<int>> matrice; // Matrice 2D pour stocker les données
    public:
        Fichier();
        void lecture_fichier();
        int get_ligne();
        int get_colonne();
        vector<vector<int>> get_matrice();



};

#endif