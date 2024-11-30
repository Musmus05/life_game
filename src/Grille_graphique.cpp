#include "Grille_graphique.h"

Grille_graphique::Grille_graphique() : Grille(){}

Grille_graphique::~Grille_graphique(){}

int Grille_graphique::get_ligne(){
    return this->ligne;
}

void Grille_graphique::set_ligne(int x){
    this->ligne = x;
}

int Grille_graphique::get_colonne(){
    return this->colonne;
}

void Grille_graphique::set_colonne(int y){
    this->colonne = y;
}
