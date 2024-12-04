#ifndef jeux_vie_h
#define jeux_vie_h

#include <iostream>
#include <vector>
#include "Fichier.h"
#include "Cellule.h"
#include "Grille.h"
#include "Affichage_terminal.h"
#include "Affichage_graphique.h"
#include "Grille_update.h"
#include "Grille_update_default.h"
#include "Grille_update_torique.h"


class Jeux_vie
{
private:
    Grille *grille;
    int nombre_generation;
    int generation;
    int choix;
    Fichier sortie;
    std::vector<std::string> fichiers_recents;//gestion des dernier fichiers creer
    int nombre_dernier_fichier; //on stocke combien de dernier fichier ?
    long int temps_entre_generation ;
    Grille_update* grille_update;

public:
    Jeux_vie();
    void menu();
    void run();  
    void verif_generation_successive();
    int get_generation();
    ~Jeux_vie();
};

#endif