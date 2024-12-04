#include "Afficher_grille_terminal.h"
#include <iostream>
using namespace std;

Afficher_grille_terminal::Afficher_grille_terminal(std::vector<std::vector<Cellule>> matrice) {
    this->matrice = matrice;
}

void Afficher_grille_terminal::afficher_grille() {
    for (int i = 0; i < matrice.size(); i++) {
        for (int j = 0; j < matrice[i].size(); j++) {
            cout << matrice[i][j].get_status() << " ";
        }
        cout << endl;
    }
    cout << endl;
}

Afficher_grille_terminal::~Afficher_grille_terminal() {}
