#include "Cellule.h"

Cellule::Cellule(int x, int y, bool statut){
    this->x = x;
    this->y = y;
    this->statut_cellule = statut;
}

bool Cellule::get_status()
{
    return this->statut_cellule;
}

void Cellule::update_status()
{
    this->statut_cellule;
}