#include "compteurs.h"


int Compteurs::calcule_compteur_cellule(Grille &grille) 
{
     return  grille.get_ligne() * grille.get_colonne(); // Retourne le nombre de cellules
}


int Compteurs::calcule_compteur_cellule_vivante(Grille &grille)
{
    int compteur = 0; // Initialisation du compteur
    for (int i = 0; i < grille.get_ligne(); i++)  //parcours de la grille
    {
        for (int j = 0; j < grille.get_colonne(); j++) 
        {
            if (grille.get_matrice()[i][j].get_status() == 1) //si la cellule est vivante
            {
                compteur++; //on incrémente le compteur
            }
        }
    }
    return compteur; //on retourne le compteur
} 

int Compteurs::calcule_compteur_cellule_morte(Grille &grille)
{
    int compteur = 0;
    for (int i = 0; i < grille.get_ligne(); i++) //parcours de la grille
    {
        for (int j = 0; j < grille.get_colonne(); j++)
        {
            if (grille.get_matrice()[i][j].get_status() == 0) //si la cellule est morte
            {
                compteur++;
            }
        }
    }
    return compteur; //on retourne le compteur
}