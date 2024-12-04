#pragma once
#include "Grille.h"
#include <string>

class Afficher_grille_terminal {
protected:
    std::vector<std::vector<Cellule>> matrice;

public:
    Afficher_grille_terminal(std::vector<std::vector<Cellule>> matrice);
    void afficher_grille();
    ~Afficher_grille_terminal();
};
