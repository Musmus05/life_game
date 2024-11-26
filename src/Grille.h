#ifndef Grille_h
#define Grille_h

#include <iostream>
#include <vector>
#include "Fichier.h"

class Grille {
    protected:
        int ligne;
        int colonne;
        vector<vector<int>> matrice; // Matrice 2D pour stocker les données
    public:
        Grille();
        virtual ~Grille();
        virtual int get_ligne() = 0;
        virtual void set_ligne(int ligne) =0;
        virtual int get_colonne() = 0;
        virtual void set_colonne(int colonne)  = 0; 
        virtual void afficher_grille() = 0;


};



#endif