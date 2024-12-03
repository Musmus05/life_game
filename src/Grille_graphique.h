#ifndef grille_graphique_h
#define grille_graphique_h

#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Grille.h"


class Grille_graphique : public Grille {
    private:
        int cellule_taille = 10;
        int window_colonne = this->colonne * cellule_taille;
        int window_ligne = this->ligne * cellule_taille;
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
        std::vector<std::vector<Cellule>> get_matrice();
   
};

#endif