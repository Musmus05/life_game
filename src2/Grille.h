#pragma once

#include "Cellule_terminal.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class Grille
{
protected:
    std::vector<Cellule_terminal> grille;

public:
    Grille();

    void ajouterCellule(const Cellule_terminal &cellule);

    virtual void afficherGrille(int taille_x, int taille_y) const;

    virtual void sauvegarde(std::string file, int taille_x, int taille_y);

    virtual void actualiserGrille(int taille_x, int taille_y) = 0;

    virtual ~Grille();
};
