#include "Grille.h"

Grille::Grille(){
    Grille_init();
};


Grille::~Grille() {

}

void Grille::Grille_init() {
    Fichier fichier;
    fichier.lecture_fichier();
    ligne = fichier.get_ligne();
    colonne = fichier.get_colonne();
    matrice.resize(ligne, vector<Cellule>(colonne));
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < colonne; j++) {
            matrice[i][j] = Cellule(i, j, fichier.get_matrice()[i][j]);
        }
    }
}