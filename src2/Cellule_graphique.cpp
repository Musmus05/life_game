#include "Cellule_graphique.h"

Cellule_graphique::Cellule_graphique(int x, int y, int status_cellule, int taille_cellule)
    : Cellule_terminal(x, y, status_cellule), taille_cellule(taille_cellule) {}


Cellule_graphique::~Cellule_graphique()
{}

int Cellule_graphique::get_taille() const
{
    return taille_cellule;
}

void Cellule_graphique::set_taille(int nouvelle_taille)
{
    taille_cellule = nouvelle_taille;
}

Cellule_graphique::~Cellule_graphique()
{
    compteur--;
}