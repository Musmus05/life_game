#include "Cellule.h"


Cellule::Cellule() : x(0), y(0), status_cellule(false) {
}
Cellule::Cellule(int x, int y, bool status):x(x),y(y),status_cellule(status){

}
Cellule::~Cellule(){
}
bool Cellule::get_status(){
    return status_cellule;
}

int Cellule::get_x(){
    return x;
}

int Cellule::get_y(){
    return y;
}

void Cellule::status_update(){
    status_cellule = !status_cellule;
}


