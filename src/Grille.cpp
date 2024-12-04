#include "Grille.h"
#include "Fichier.h"
using namespace std;

Grille::Grille() {
    string filename;
    cout << "Nom du fichier : ";
    cin >> filename;
    Fichier fichier(filename);
    fichier.lecture_fichier(filename);
    ligne = fichier.get_ligne();
    colonne = fichier.get_colonne();
    matrice.resize(ligne, vector<Cellule>(colonne));
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < colonne; j++) {
            matrice[i][j] = Cellule(i, j, fichier.get_matrice()[i][j]);
        }
    }
}

Grille::~Grille() {}

int Grille::get_ligne() const {
    return ligne;
}

void Grille::set_ligne(int ligne) {
    this->ligne = ligne;
}

int Grille::get_colonne() const {
    return colonne;
}

void Grille::set_colonne(int colonne) {
    this->colonne = colonne;
}

std::vector<std::vector<Cellule>> Grille::get_matrice() const {
    return matrice;
}

void Grille::set_matrice(const std::vector<std::vector<Cellule>>& matrice) {
    this->matrice = matrice;
}