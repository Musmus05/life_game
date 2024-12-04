#pragma once
#include "Grille.h"
#include <SFML/Graphics.hpp>

class Afficher_grille_graphique
{
private:
    int ligne, colonne;
    int cellule_taille = 10;
    int window_colonne;
    int window_ligne;
    long int temps_entre_generation;
    std::vector<std::vector<Cellule>> matrice;
    

public:
    Afficher_grille_graphique(std::vector<std::vector<Cellule>> matrice);
    void afficher_grille();
    ~Afficher_grille_graphique();
};
