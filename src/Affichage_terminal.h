#ifndef AFFICHAGE_TERMINAL_H
#define AFFICHAGE_TERMINAL_H

#include <iostream>
#include "Grille.h"
#include "Grille_update.h"

class Affichage_terminal : public Grille {
public:
    Affichage_terminal();
    ~Affichage_terminal();
    void afficher_grille();
};

#endif