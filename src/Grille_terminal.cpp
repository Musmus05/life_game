#include "Grille_terminal.h"

Grille_terminal::Grille_terminal():Grille(){}

Grille_terminal::~Grille_terminal(){}

int Grille_terminal::get_ligne(){
    return ligne;
}

void Grille_terminal::set_ligne(int x){
    this->ligne = x;
}

int Grille_terminal::get_colonne(){
    return colonne;
}

void Grille_terminal::set_colonne(int y){
    this->colonne = y;
}


void Grille_terminal::afficher_grille(){
        for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            cout << matrice[i][j].get_status() << " ";
        }
        cout << endl; // Saut de ligne après chaque ligne de la matrice
    }

}

