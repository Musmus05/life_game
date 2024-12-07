#include "Grille_update_torique.h"

void Grille_update_Torique::update(Grille &grille) {
    auto matrice = grille.get_matrice(); // Récupère la matrice de la grille
    int ligne = grille.get_ligne(); // Récupère le nombre de lignes de la grille
    int colonne = grille.get_colonne(); // Récupère le nombre de colonnes de la grille
    std::vector<std::vector<Cellule>> nouvelle_matrice = matrice; // Copie la matrice de la grille

    for (int i = 0; i < ligne; i++) { // Parcours la matrice
        for (int j = 0; j < colonne; j++) { 
            if (matrice[i][j].get_status() == 2) { // Si la cellule est un obstacle, on continue
                continue;
            }

            int somme = 0; // Compte le nombre de voisins vivants
            for (int x = -1; x <= 1; x++) { // Parcours les voisins
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue; // On ne compte pas la cellule elle-même
                    int voisin_i = (i + x + ligne) % ligne; // Coordonnées du voisin avec la grille torique
                    int voisin_j = (j + y + colonne) % colonne; // Coordonnées du voisin avec la grille torique
                    if (matrice[voisin_i][voisin_j].get_status() == 1) { // Si le voisin est vivant
                        somme++; // On incrémente le compteur
                    }
                }
            }

            if (matrice[i][j].get_status() == 1) { // Si la cellule est vivante
                if (somme < 2 || somme > 3) {       // Si le nombre de voisins est inférieur à 2 ou supérieur à 3
                    nouvelle_matrice[i][j].status_update(0); // La cellule meurt
                }
            } else if (matrice[i][j].get_status() == 0) { // Si la cellule est morte
                if (somme == 3) { // Si le nombre de voisins est égal à 3
                    nouvelle_matrice[i][j].status_update(1); // La cellule devient vivante
                }
            }
        }
    }

    grille.set_matrice(nouvelle_matrice); // Met à jour la matrice de la grille
}
