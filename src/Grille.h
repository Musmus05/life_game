#pragma once

#include "Cellule.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class Grille
{
protected:
    std::vector<Cellule> grille;

public:
    Grille();

    void ajouterCellule(const Cellule &cellule);

    // Afficher toutes les cellules de la grille
    void afficherGrille() const;

    void sauvegarde(std::string file, int ordonnee, int taille_x, int taille_y);

    ~Grille();
};
