#pragma once

#include <iostream>

class Cellule
{
protected:
    int x, y;            // coordonnee de la cellule
    int status_cellule; // status de la cellule morte/vivante
    static int cpt;

public:
    Cellule();
    Cellule(int x, int y, int status_cellule);

    int get_cpt();
    int get_status() const;
    void set_status(int nouveau_status);
    int get_x() const;
    int get_y() const;

    void afficher() const;

    ~Cellule();
};
