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

    //ajout des cellules dans le vector
    void ajouterCellule(const Cellule &cellule);

    // on afficher toutes les cellules de la grille
    void afficherGrille(int taille_x, int taille_y) const;

    // on sauvegarde avec le nom du fichier avec en arg la taille en x et y
    void sauvegarde(std::string file, int taille_x, int taille_y);

    // verification pour le jeu de la vie (condiftoin : cf sujet)
    void actualiserGrille(int taille_x, int taille_y);

    ~Grille();
};
