#include "Jeux_vie.h"
#include "test.h"

using namespace std;

int main()
{
    int oui = 0;
    cout << "Voulez vous faire des tests unitaires 0 = non, 1 = oui ? " << endl;
    cin >> oui;
    if (oui == 0)
    {
        Jeux_vie jeux_vie;
        jeux_vie.run();
    }

    else if (oui == 1)
    {
        test_creer_dossier();
        test_lecture_fichier();
        test_ecriture_fichier();
        test_supprimer_dossier();
        test_get_nom();
        test_grille_creation();
        test_set_ligne();
        test_set_colonne();
        test_set_matrice();
        test_get_matrice();
        test_cellule_creation_par_defaut();
        test_cellule_creation_par_parametres();
        test_getters();
        test_status_update();
        test_affichage_terminal_et_compteurs();
        test_affichage_graphique_et_compteurs();
        test_grille_update_default();
        test_grille_update_torique();
    }

    return 0;
}