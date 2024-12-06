#ifndef GRILLE_H
#define GRILLE_H

#include <iostream>
#include <vector>
#include "Cellule.h"

class Grille {
private:
    int ligne;
    int colonne;
    std::vector<std::vector<Cellule>> matrice;
public:
    Grille();
    virtual ~Grille();
    int get_ligne() const;
    void set_ligne(int ligne);
    int get_colonne() const;
    void set_colonne(int colonne);
    std::vector<std::vector<Cellule>> get_matrice() const;
    void set_matrice(const std::vector<std::vector<Cellule>>& matrice);
};

#endif