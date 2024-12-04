#include "Affichage_terminal.h"
using namespace std;

Affichage_terminal::Affichage_terminal() : Grille() {}

Affichage_terminal::~Affichage_terminal() {}

void Affichage_terminal::afficher_grille() {
    for (int i = 0; i < get_ligne(); i++) {
        for (int j = 0; j < get_colonne(); j++) {
            cout << get_matrice()[i][j].get_status() << " ";
        }
        cout << endl;
    }
    cout << endl;

    // informations sur la grille
    cout << "Nombre de cellules : " << compteur.calcule_compteur_cellule(*this) << endl;
    cout << "Nombre de cellules vivantes : " << compteur.calcule_compteur_cellule_vivante(*this) << endl;
    cout << "Nombre de cellules mortes : " << compteur.calcule_compteur_cellule_morte(*this) << endl;
}

