#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <iostream>
#include "Grille.h"
#include "compteurs.h"

class Affichage {
protected:
    Grille grille;
    Compteurs compteur;

public:
    Affichage();
    Affichage(Grille grille);
    virtual ~Affichage();
    virtual void afficher_grille() = 0;
};

#endif