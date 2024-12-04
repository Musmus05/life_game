#ifndef AFFICHAGE_GRAPHIQUE_H
#define AFFICHAGE_GRAPHIQUE_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Grille.h"
#include "Grille_update.h"
#include "Grille_update_torique.h"
#include "Grille_update_default.h"

class Affichage_graphique : public Grille {
private:
    int cellule_taille = 10;
    long int temps_entre_generation;
    Grille_update* grille_update;
public:
    Affichage_graphique();
    Affichage_graphique(long int temps_entre_generation);
    ~Affichage_graphique();
    void afficher_grille();
};

#endif