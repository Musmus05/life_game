#pragma once

#include "Cellule.h"
#include <vector>
#include <iostream>

class Grille
{
protected:
    std::vector<Cellule> grille;

public:
    Grille() {}

    void ajouterCellule(const Cellule &cellule)
    {
        grille.push_back(cellule);
    }

    // Afficher toutes les cellules de la grille
    void afficherGrille() const
    {
        std::cout << "Contenu de la grille :" << std::endl;
        for (const auto &cellule : grille)
        {
            cellule.afficher();
        }
    }
    ~Grille() {}
};
