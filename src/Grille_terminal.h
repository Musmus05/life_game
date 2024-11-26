#ifndef grille_terminal_h
#define grille_terminal_h

#include <iostream>
#include <vector>
#include "Grille.h"


class Grille_terminal : public Grille {
    public:
        Grille_terminal();
        ~Grille_terminal();
        int get_ligne();
        void set_ligne(int x);
        int get_colonne();
        void set_colonne(int y);
        void afficher_grille();
};

#endif