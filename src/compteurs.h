#ifndef COMPTEURS_H
#define COMPTEURS_H

#include "Grille.h"

class Compteurs
{
public:
    int calcule_compteur_cellule(Grille& grille);
    int calcule_compteur_cellule_vivante(Grille& grille);
    int calcule_compteur_cellule_morte(Grille& grille);
};

#endif