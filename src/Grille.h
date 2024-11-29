#ifndef Grille_h
#define Grille_h

#include <iostream>
#include <vector>
#include "Fichier.h"
#include "Cellule.h"

class Cellule;

class Grille {
    protected:
        int ligne;
        int colonne;
        vector<vector<Cellule>> matrice; // Matrice 2D pour stocker les données
        int compteur;
        int compteur_cellule_morte;
        int compteur_cellule_vivante;
    public:
        Grille();
        void Grille_init();
        virtual ~Grille();
        virtual int get_ligne() = 0;
        virtual void set_ligne(int ligne) = 0;
        virtual int get_colonne() = 0;
        virtual void set_colonne(int colonne)  = 0; 
        virtual void afficher_grille() = 0;
        virtual void Grille_update() = 0;
        virtual int calcule_compteur_cellule() = 0;
        virtual int calcule_compteur_cellule_morte() = 0;
        virtual int calcule_compteur_cellule_vivante() = 0;
};



#endif