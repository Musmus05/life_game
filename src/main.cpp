#include "Fichier.h"
#include "Grille.h"
#include "Cellule.h"

using namespace std;

int main()
{
    Fichier bool_matrice;
    bool_matrice.lecture_fichier();  //lecture du fichier
    int abscisse = bool_matrice.abscisse(); //recuperation du nombre de ligne
    int ordonnee = bool_matrice.ordonnee(); //recuperation du nombre de colonne
    //bool_matrice.afficher_matrice(); //affichage des dimensions et du contenu de la matrice


    //creation de la grille
    Grille grille;
    for(int i = 0; i < abscisse; i++)
    {
        for(int j = 0; j < ordonnee; j++)
        {
            Cellule nouvelleCellule(i, j, bool_matrice.get_status(i,j));
            grille.ajouterCellule(nouvelleCellule);
        }
    }

    grille.afficherGrille(abscisse, ordonnee);
    grille.actualiserGrille(abscisse, ordonnee);
    grille.afficherGrille(abscisse, ordonnee);

    //gestion de la sauvegarde
    string nom_fichier = "Test.txt";
    grille.sauvegarde(nom_fichier, abscisse, ordonnee);

    return 0;
}
