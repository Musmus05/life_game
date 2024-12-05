#include "Affichage_terminal.h"
using namespace std;

Affichage_terminal::Affichage_terminal(Grille* grille) : Affichage(grille) {}

Affichage_terminal::~Affichage_terminal() {}

void Affichage_terminal::afficher_grille() {
    for (int i = 0; i < grille->get_ligne(); i++) {
        for (int j = 0; j < grille->get_colonne(); j++) {
            cout << grille->get_matrice()[i][j].get_status() << " ";
        }
        cout << endl;
    }
    cout << endl;

    // informations sur la grille
    cout << "Nombre de cellules : " << compteur.calcule_compteur_cellule(*grille) << endl;
    cout << "Nombre de cellules vivantes : " << compteur.calcule_compteur_cellule_vivante(*grille) << endl;
    cout << "Nombre de cellules mortes : " << compteur.calcule_compteur_cellule_morte(*grille) << endl;
}