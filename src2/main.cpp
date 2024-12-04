// #include "Jeux_vie.h"
#include "Fichier.h"
#include "Cellule.h"
#include "Grille.h"
#include "Afficher_grille_terminal.h"
#include "Afficher_grille_graphique.h"

#include <string>
using namespace std;

int main()
{
    // Jeux_vie jeux_vie;
    // jeux_vie.run();
    // return 0;
    int choix;

    cout << "=== Menu ===" << endl;
    cout << "1. Grille terminal" << endl;
    cout << "2. Grille graphique" << endl;
    cout << "3. Quitter" << endl;
    cout << "Votre choix : ";

    cin >> choix;

    switch (choix)
    {
    case 1:
        Grille *grille;
        cout << "Affichage dans le terminal" << endl;
        grille = new Grille();
        Afficher_grille_terminal *afft;
        afft = new Afficher_grille_terminal(grille->get_matrice());
        afft->afficher_grille();

        // cout << "Nombre de génération : ";
        // cin >> this->nombre_generation;
        // cout << "Combien de fichiers voulez-vous examiner pour vérifier la répétition des dernières générations : ";
        // cin >> nombre_dernier_fichier;
        // // redimensionnement du vecteur
        // fichiers_recents.resize(nombre_dernier_fichier);
        break;
    case 2:
        Grille *grille2;
        cout << "graphique" << endl;
        Afficher_grille_graphique* affg;
        grille2 = new Grille();
        affg = new Afficher_grille_graphique(grille2->get_matrice());
        affg->afficher_grille();
        // cout << "Combien de temps entre chaque génération voulez-vous (en miliseconde) : ";
        // cin >> this->temps_entre_generation;
        // grille = new Grille();

        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "Choix invalide !" << endl;
        exit(0);
        break;
    }
}