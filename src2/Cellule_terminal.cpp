#include "Cellule_terminal.h"

int Cellule_terminal::compteur = 0;

Cellule_terminal::Cellule_terminal() : x(0), y(0), status_cellule(0)
{
    compteur++;
}
Cellule_terminal::Cellule_terminal(int x, int y, int status_cellule)
{
    this->x = x;
    this->y = y;
    this->status_cellule = status_cellule;
    compteur++;
}

int Cellule_terminal::get_status()
{
    return status_cellule;
}

int Cellule_terminal::get_x()
{
    return x;
}

int Cellule_terminal::get_y()
{
    return y;
}

int Cellule_terminal::get_compteur()
{
    return compteur;
}

void Cellule_terminal::set_status(int nouveau_status)
{
    this->status_cellule = nouveau_status;
}

Cellule_terminal::~Cellule_terminal()
{
    compteur--;
}