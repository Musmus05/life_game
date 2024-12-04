#include "Grille_update_torique.h"

void Grille_update_Torique::update(Grille &grille) {
    auto matrice = grille.get_matrice();
    int ligne = grille.get_ligne();
    int colonne = grille.get_colonne();
    std::vector<std::vector<Cellule>> nouvelle_matrice = matrice;

    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < colonne; j++) {
            if (matrice[i][j].get_status() == 2) {
                continue;
            }

            int somme = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    int voisin_i = (i + x + ligne) % ligne;
                    int voisin_j = (j + y + colonne) % colonne;
                    if (matrice[voisin_i][voisin_j].get_status() == 1) {
                        somme++;
                    }
                }
            }

            if (matrice[i][j].get_status() == 1) {
                if (somme < 2 || somme > 3) {
                    nouvelle_matrice[i][j].status_update(0);
                }
            } else if (matrice[i][j].get_status() == 0) {
                if (somme == 3) {
                    nouvelle_matrice[i][j].status_update(1);
                }
            }
        }
    }

    grille.set_matrice(nouvelle_matrice);
}
