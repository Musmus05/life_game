#pragma once

#include "Cellule_terminal.h"

class Cellule_graphique : public Cellule_terminal
{
private:
    int taille_cellule;

public:
    Cellule_graphique(int x, int y, int status_cellule, int taille_cellule);
    ~Cellule_graphique();

    int get_taille() const;
    void set_taille(int nouvelle_taille);
};
