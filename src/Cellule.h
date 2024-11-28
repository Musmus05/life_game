#pragma once

#include <iostream>

class Cellule
{
protected:
    int x, y;            // coordonnee de la cellule
    bool status_cellule; // status de la cellule morte/vivante
    static int cpt;

public:
    Cellule();
    Cellule(int x, int y, bool status_cellule);

    int get_cpt();
    bool get_status();

    void afficher() const;

    ~Cellule();
};
