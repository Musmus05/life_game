#include "Fichier.h"
#include "Grille.h"
#include "Grille_terminal.h"




int main()
{
    Grille *grille;
    grille = new Grille_terminal(); 
    grille->afficher_grille();
    return 0;
}
