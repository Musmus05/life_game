#include "Cellule.h"
using namespace std;

int Cellule::cpt = 0;

Cellule::Cellule(int x, int y, bool status_cellule)
{
    this->x = x;
    this->y = y;
    this->status_cellule = status_cellule;
    cpt++;
}

Cellule::Cellule()
{
    this->x = 0;
    this->y = 0;
    this->status_cellule = 0;
    cpt++;
}

void Cellule::afficher() const
{
    cout << "Abscisse : " << x << endl
         << "Ordonnée : " << y << endl
         << "Status : " << status_cellule << endl;
    ;
}

int Cellule::get_cpt()
{
    return cpt;
}

bool Cellule::get_status()
{
    return this->status_cellule;
}

Cellule::~Cellule() { cpt--; }