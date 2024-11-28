#include "Cellule.h"
int Cellule::compteur = 0;

Cellule::Cellule() : x(0), y(0), statut_cellule(false) {
}
Cellule::Cellule(int x, int y, bool status):x(x),y(y),statut_cellule(status){
    compteur++;
}
Cellule::~Cellule(){
}
bool Cellule::get_status(){
    return statut_cellule;
}

int Cellule::get_x(){
    return x;
}

int Cellule::get_y(){
    return y;
}

void Cellule::set_status(){
    statut_cellule = !statut_cellule;
}

int Cellule::get_compteur(){
    return compteur;
}

