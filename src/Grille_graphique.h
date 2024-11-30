#ifndef grille_graphique_h
#define grille_graphique_h

#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Grille.h"
#include "Cellule.h"


class Grille_graphique : public Grille {
    public:
        Grille_graphique();
        ~Grille_graphique();
        int get_ligne();
        void set_ligne(int x);
        int get_colonne();
        void set_colonne(int y);
        void afficher_grille();
        void Grille_update();
        int calcule_compteur_cellule();
        int calcule_compteur_cellule_morte();
        int calcule_compteur_cellule_vivante();
        // void afficher_compteur_cellule();
        // void afficher_compteur_cellule_morte();
        // void afficher_compteur_cellule_vivante();
        vector<vector<Cellule>> get_matrice();
   
};

#endif