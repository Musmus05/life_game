#ifndef grille_graphique_h
#define grille_graphique_h

#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Grille.h"


class Grille_graphique : public Grille {
    public:
        Grille_graphique();
        ~Grille_graphique();
        int get_ligne();
        void set_ligne(int x);
        int get_colonne();
        void set_colonne(int y);
        void afficher_grille();
};

#endif