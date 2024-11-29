#include "Cellule.h"
using namespace std;

int Cellule::cpt = 0; // init le static int à 0

// construteur
Cellule::Cellule(int x, int y, int status_cellule)
{
    this->x = x;
    this->y = y;
    this->status_cellule = status_cellule;
    cpt++;
}

// constructeur par défaut
Cellule::Cellule()
{
    this->x = 0;
    this->y = 0;
    this->status_cellule = 0;
    cpt++;
}

// on affiche le status de la cellule
void Cellule::afficher() const
{
    cout << status_cellule << endl;
}

// on recup le nombre de cellule
int Cellule::get_cpt()
{
    return cpt;
}

// on recup le status
int Cellule::get_status() const
{
    return this->status_cellule;
}

// on defini le status
void Cellule::set_status(int nouveau_status)
{
    this->status_cellule = nouveau_status;
}

// on recupere x
int Cellule::get_x() const
{
    return this->x;
}

// on recupere y
int Cellule::get_y() const
{
    return this->y;
}

// destructeur et decrementation du compteur de cellule
Cellule::~Cellule() { cpt--; }