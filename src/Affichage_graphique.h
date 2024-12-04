#ifndef AFFICHAGE_GRAPHIQUE_H
#define AFFICHAGE_GRAPHIQUE_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Grille.h"
#include "Grille_update.h"
#include "Grille_update_torique.h"

class Affichage_graphique : public Grille {
private:
    int cellule_taille = 10;
    long int temps_entre_generation;
    Grille_update_Torique grille_update;
public:
    Affichage_graphique();
    Affichage_graphique(long int temps_entre_generation);
    ~Affichage_graphique();
    void afficher_grille();
};

#endif