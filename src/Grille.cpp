#include "Grille.h"
#include "Fichier.h"
using namespace std;

Grille::Grille() {
    string filename; // nom du fichier
    cout << "Nom du fichier : "; // on demande le nom du fichier
    cin >> filename;
    Fichier fichier(filename); // on crée un objet fichier
    fichier.lecture_fichier(filename); // on lit le fichier
    ligne = fichier.get_ligne(); // on récupère le nombre de lignes
    colonne = fichier.get_colonne(); // on récupère le nombre de colonnes
    matrice.resize(ligne, vector<Cellule>(colonne)); // on redimensionne la matrice avec les dimensions de la matrice du fichier
    for (int i = 0; i < ligne; i++) { // on parcours la matrice
        for (int j = 0; j < colonne; j++) { 
            matrice[i][j] = Cellule(i, j, fichier.get_matrice()[i][j]); // on crée une cellule avec les coordonnées et le statut de la matrice du fichier
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