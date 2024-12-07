#ifndef AFFICHAGE_H
#define AFFICHAGE_H


#include "Grille.h"

class Affichage {
protected:
    Grille* grille;
public:
    Affichage(Grille* grille) : grille(grille) {}
    virtual ~Affichage() {}
    virtual void afficher_grille() = 0;
};

#endif