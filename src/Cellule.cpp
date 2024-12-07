#include "Cellule.h"


Cellule::Cellule() : x(0), y(0), status_cellule(0) {
}
Cellule::Cellule(int x, int y, int status):x(x),y(y),status_cellule(status){}
Cellule::~Cellule(){
}
int Cellule::get_status(){
    return status_cellule;
}

int Cellule::get_x(){
    return x;
}

int Cellule::get_y(){
    return y;
}

void Cellule::status_update(int nouveau_status)
{
    this->status_cellule = nouveau_status;
}

