#ifndef AFFICHAGE_TERMINAL_H
#define AFFICHAGE_TERMINAL_H

#include <iostream>
#include "Affichage.h"
#include "compteurs.h"

class Affichage_terminal : public Affichage {
private:
    Compteurs compteur;
public:
    Affichage_terminal(Grille* grille);
    ~Affichage_terminal();
    void afficher_grille() override;
};

#endif