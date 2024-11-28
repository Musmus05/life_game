#ifndef grille_terminal_h
#define grille_terminal_h

#include <iostream>
#include <vector>
#include "Grille.h"

class Grille_terminal : public Grille
{
public:
    Grille_terminal();
    ~Grille_terminal();
    int get_ligne();
    void set_ligne(int x);
    int get_colonne();
    void set_colonne(int y);
    void afficher_grille();
    int ajouter(Cellule *cellule);
    int suprimmer(Cellule *cellule);
    void notify();
    int calcule_compteur_cellule();
    int calcule_compteur_cellule_morte();
    int calcule_compteur_cellule_vivante();

};

#endif