#ifndef AFFICHAGE_GRAPHIQUE_H
#define AFFICHAGE_GRAPHIQUE_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Grille.h"
#include "Grille_update.h"
#include "Grille_update_torique.h"
#include "Grille_update_default.h"
#include "compteurs.h"
#include "Affichage.h"

class Affichage_graphique : public Affichage
{
private:
    int cellule_taille = 10;
    long int temps_entre_generation;
    Grille_update *grille_update;
    int window_colonne = grille.get_colonne() * cellule_taille;
    int window_ligne = grille.get_ligne() * cellule_taille;
    sf::RenderWindow *window; //premiere fenetre
    sf::RenderWindow *windowCompteurs; //deuxieme fenetre
    int generation = 0; //compteur genration

public:
    Affichage_graphique();
    Affichage_graphique(long int temps_entre_generation);
    ~Affichage_graphique();
    void afficher_grille();
    void afficher_cellule();
    void afficher_compteurs();
};

#endif