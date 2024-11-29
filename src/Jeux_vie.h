#ifndef jeux_vie_h
#define jeux_vie_h

#include <iostream>
#include <vector>
#include "Fichier.h"
#include "Cellule.h"
#include "Grille.h"
#include "Grille_terminal.h"
#include "Grille_graphique.h"

class Jeux_vie
{
private:
    Grille *grille;
    int nombre_generation;
    int generation;
    int choix;
public:
    Jeux_vie();
    Jeux_vie(int choix,int nombre_generation);
    void menu();
    void run();
    int get_generation();
    ~Jeux_vie();
};

#endif