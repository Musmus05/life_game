#ifndef Grille_h
#define Grille_h

#include <iostream>
#include <vector>
#include "Fichier.h"
#include "Cellule.h"

class Cellule;

class Grille
{
protected:
    int ligne;
    int colonne;
    std::vector<std::vector<Cellule>> matrice;
    int compteur;
    int compteur_cellule_morte;
    int compteur_cellule_vivante;

public:
    Grille();
    void Grille_init();
    virtual ~Grille();
    int get_ligne();
    int get_colonne();
    void set_matrice(const std::vector<std::vector<Cellule>> &nouvelle_matrice)
    {
        if (nouvelle_matrice.size() == ligne && nouvelle_matrice[0].size() == colonne)
        {
            matrice = nouvelle_matrice;
        }
    }
    std::vector<std::vector<Cellule>> get_matrice();
};

#endif
