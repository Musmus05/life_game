#include "compteurs.h"


int Compteurs::calcule_compteur_cellule(Grille &grille)
{
     return  grille.get_ligne() * grille.get_colonne();
}


int Compteurs::calcule_compteur_cellule_vivante(Grille &grille)
{
    int compteur = 0;
    for (int i = 0; i < grille.get_ligne(); i++)
    {
        for (int j = 0; j < grille.get_colonne(); j++)
        {
            if (grille.get_matrice()[i][j].get_status() == 1)
            {
                compteur++;
            }
        }
    }
    return compteur;
}

int Compteurs::calcule_compteur_cellule_morte(Grille &grille)
{
    int compteur = 0;
    for (int i = 0; i < grille.get_ligne(); i++)
    {
        for (int j = 0; j < grille.get_colonne(); j++)
        {
            if (grille.get_matrice()[i][j].get_status() == 0)
            {
                compteur++;
            }
        }
    }
    return compteur;
}