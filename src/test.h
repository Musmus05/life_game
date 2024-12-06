#include "Fichier.h"
#include "Grille.h"
#include "Grille_update_torique.h"
#include "Grille_update_default.h"
#include "Affichage_terminal.h"
#include "Affichage_graphique.h"
#include "compteurs.h"
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

//methode lecture_fichier
void test_lecture_fichier()
{
    cout << "==============================" << endl;
    cout << "Test de lecture de fichier" << endl;
    cout << "==============================" << endl;
    Fichier fichier("test.txt");

    //créer un fichier temporaire
    ofstream test_file("test.txt");
    test_file << "3 3\n1 2 3\n4 5 6\n7 8 9\n";
    test_file.close();

    //test de lecture du fichier
    vector<vector<int>> matrice = fichier.lecture_fichier("test.txt");

    //verif des dimensions
    assert(fichier.get_ligne() == 3);
    assert(fichier.get_colonne() == 3);

    //verif des valeurs
    assert(matrice[0][0] == 1);
    assert(matrice[1][1] == 5);
    assert(matrice[2][2] == 9);

    cout << "test_lecture_fichier passé avec succès !" << endl;
}

//methode ecriture_fichier
void test_ecriture_fichier()
{
    cout << "==============================" << endl;
    cout << "Test d'écriture de fichier" << endl;
    cout << "==============================" << endl;
    Fichier fichier;

    //creer une matrice de test
    vector<vector<Cellule>> matrice(3, vector<Cellule>(3, Cellule(1, 1, 0)));

    //ecriture dans un fichier
    string filename = fichier.ecriture_fichier(matrice, 1);
    //verif que le fichier a bien ete cree
    ifstream file(filename);
    assert(file.is_open());

    //verif de la dimension du fichier ecrit
    int ligne, colonne;
    file >> ligne >> colonne;
    assert(ligne == 3);
    assert(colonne == 3);

    //verif du contenu de la grille
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            int status;
            file >> status;
            assert(status == 0); //normalement les cellules doivent etre a 0
        }
    }
    file.close();

    cout << "test_ecriture_fichier passé avec succès !" << endl;
}

//methode creer_dossier
void test_creer_dossier()
{
    cout << "==============================" << endl;
    cout << "Test de creer un dossier" << endl;
    cout << "==============================" << endl;
    Fichier fichier;

    //sup le dossier s'il existe avant de le refaire
    fichier.supprimer_dossier();

    //methode creer_dossier
    fichier.creer_dossier();

    //verif si le dossier a bien ete fait
    int result = system("test -d Sortie_sauvegarde");

    if (result == 0)
    {
        cout << "test_creer_dossier passé avec succès !" << endl;
    }
    else
    {
        cout << "Test échoué : Le dossier n'a pas été créé !" << endl;
    }
}

//methode supprimer_dossier
void test_supprimer_dossier()
{
    cout << "==============================" << endl;
    cout << "Test de supprimer un dossier" << endl;
    cout << "==============================" << endl;
    Fichier fichier;

    //supprimer_dossier
    fichier.supprimer_dossier();

    //verif si le dossier a existe plus
    if (system("test -d Sortie_sauvegarde"))
    {
        cout << "Test échoué : Le dossier n'a pas été supprimé !" << endl;
    }
    else
    {
        cout << "test_supprimer_dossier passé avec succès !" << endl;
    }
}

//methode get_nom
void test_get_nom()
{
    cout << "==============================" << endl;
    cout << "Test de récupérer le nom d'un dossier" << endl;
    cout << "==============================" << endl;
    Fichier fichier("fichier_test.txt");

    //verif du nom du fichier
    assert(fichier.get_nom() == "fichier_test.txt");

    cout << "test_get_nom passé avec succès !" << endl;
}

void test_grille_creation()
{
    cout << "==============================" << endl;
    cout << "Test de création de grille" << endl;
    cout << "==============================" << endl;
    //creation d'un fichier de test temporaire
    ofstream test_file("test.txt");
    test_file << "3 3\n1 2 3\n4 5 6\n7 8 9\n"; //contenu de la grille
    test_file.close();

    //creation d'une instance de Grille
    Grille grille;

    //verif les dimensions
    assert(grille.get_ligne() == 3);
    assert(grille.get_colonne() == 3);

    //verif les valeurs de la matrice
    vector<vector<Cellule>> matrice = grille.get_matrice();
    assert(matrice[0][0].get_status() == 1);
    assert(matrice[1][1].get_status() == 5);
    assert(matrice[2][2].get_status() == 9);

    cout << "test_grille_creation passé avec succès !" << endl;
}

void test_set_ligne()
{
    cout << "==============================" << endl;
    cout << "Test de modification du nombre de ligne de la grille" << endl;
    cout << "==============================" << endl;
    Grille grille;
    grille.set_ligne(5);

    //verif que la ligne est modifiee
    assert(grille.get_ligne() == 5);

    cout << "test_set_ligne passé avec succès !" << endl;
}

void test_set_colonne()
{
    cout << "==============================" << endl;
    cout << "Test de modification du nombre de colonne de la grille" << endl;
    cout << "==============================" << endl;
    Grille grille;
    grille.set_colonne(4);

    //verif que la colonne est modifiee
    assert(grille.get_colonne() == 4);

    cout << "test_set_colonne passé avec succès !" << endl;
}

void test_set_matrice()
{
    cout << "==============================" << endl;
    cout << "Test de modification de la grille" << endl;
    cout << "==============================" << endl;
    Grille grille;

    //creer une nouvelle matrice 3x3 avec des valeurs specifique
    vector<vector<Cellule>> nouvelle_matrice(3, vector<Cellule>(3, Cellule(0, 0, 1)));

    //modif la matrice de la grille
    grille.set_matrice(nouvelle_matrice);

    //verif que la matrice a ete modifiee
    vector<vector<Cellule>> matrice = grille.get_matrice();
    assert(matrice[0][0].get_status() == 1);
    assert(matrice[1][1].get_status() == 1);
    assert(matrice[2][2].get_status() == 1);

    cout << "test_set_matrice passé avec succès !" << endl;
}

void test_get_matrice()
{
    cout << "==============================" << endl;
    cout << "Test de récupération de la matrice" << endl;
    cout << "==============================" << endl;
    //creer un fichier de test temporaire
    ofstream test_file("test.txt");
    test_file << "3 3\n1 2 3\n4 5 6\n7 8 9\n"; //contenu de la grille
    test_file.close();

    Grille grille;

    //verif que la methode get_matrice retourne la bonne matrice
    vector<vector<Cellule>> matrice = grille.get_matrice();
    assert(matrice[0][0].get_status() == 1);
    assert(matrice[1][1].get_status() == 5);
    assert(matrice[2][2].get_status() == 9);

    cout << "test_get_matrice passé avec succès !" << endl;
}

void test_cellule_creation_par_defaut()
{
    cout << "==============================" << endl;
    cout << "Test de création de cellule par défaut" << endl;
    cout << "==============================" << endl;
    Cellule cellule;

    //verif les valeurs initiales
    assert(cellule.get_x() == 0);
    assert(cellule.get_y() == 0);
    assert(cellule.get_status() == 0);

    cout << "test_cellule_creation_par_defaut passé avec succès !" << endl;
}

void test_cellule_creation_par_parametres()
{
    cout << "==============================" << endl;
    cout << "Test de création de cellule avec paramètres" << endl;
    cout << "==============================" << endl;
    Cellule cellule(5, 10, 1);

    //verif les valeurs initialisee par les arguments
    assert(cellule.get_x() == 5);
    assert(cellule.get_y() == 10);
    assert(cellule.get_status() == 1);

    cout << "test_cellule_creation_par_parametres passé avec succès !" << endl;
}

void test_getters()
{
    cout << "==============================" << endl;
    cout << "Test de récupération des informations de cellule" << endl;
    cout << "==============================" << endl;
    Cellule cellule(2, 3, 1);

    //verif les getters
    assert(cellule.get_x() == 2);
    assert(cellule.get_y() == 3);
    assert(cellule.get_status() == 1);

    cout << "test_getters passé avec succès !" << endl;
}

void test_status_update()
{
    cout << "==============================" << endl;
    cout << "Test de modification du statut de cellule" << endl;
    cout << "==============================" << endl;
    Cellule cellule(1, 1, 0);

    //MAJ le statut de la cellule
    cellule.status_update(1);
    assert(cellule.get_status() == 1); //verif que le statut a ete mis ajour

    cellule.status_update(0);
    assert(cellule.get_status() == 0); //verif que le statut a ete mis à jour à 0

    cout << "test_status_update passé avec succès !" << endl;
}

void test_affichage_terminal_et_compteurs()
{
    cout << "==============================" << endl;
    cout << "Test d'affichage dans le terminal et test des compteurs" << endl;
    cout << "==============================" << endl;
    Grille *grille;
    Affichage *affichage;

    //creation de la grille
    grille = new Grille();

    //init de la matrice avec un motif specifique
    vector<vector<Cellule>> matrice(5, vector<Cellule>(5));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            //creer un motif simple
            if ((i == 1 && j == 2) || (i == 3 && j == 1) || (i == 3 && j == 3))
            {
                matrice[i][j] = Cellule(i, j, 1); //cellule vivante
            }
            else
            {
                matrice[i][j] = Cellule(i, j, 0); //cellule morte
            }
        }
    }

    //config de la grille
    grille->set_ligne(5);
    grille->set_colonne(5);
    grille->set_matrice(matrice);

    //creation de l'affichage
    affichage = new Affichage_terminal(grille);

    //verif des compteurs
    Compteurs compteur;
    int total_cells = grille->get_ligne() * grille->get_colonne();
    int alive_cells = 3; //selon le motif
    int dead_cells = total_cells - alive_cells;

    assert(compteur.calcule_compteur_cellule(*grille) == total_cells);
    assert(compteur.calcule_compteur_cellule_vivante(*grille) == alive_cells);
    assert(compteur.calcule_compteur_cellule_morte(*grille) == dead_cells);

    cout << "Tests des compteurs passés avec succès !" << endl;

    //verif des affichages
    cout << "Affichage de la grille et des statistiques :\n";
    affichage->afficher_grille();

    cout << "Test d'Affichage_terminal passé avec succès !" << endl;

    //tests pour Cellule
    Cellule cellule_test(2, 3, 1); //cellule vivante
    assert(cellule_test.get_status() == 1);
    assert(cellule_test.get_x() == 2);
    assert(cellule_test.get_y() == 3);

    cellule_test.status_update(0); //maj du statut
    assert(cellule_test.get_status() == 0);

    cout << "Test des méthodes Cellule passé avec succès !" << endl;
}

void test_affichage_graphique_et_compteurs()
{
    cout << "==============================" << endl;
    cout << "Test d'affichage graphique et test des compteurs" << endl;
    cout << "==============================" << endl;
    Grille *grille;
    Affichage_graphique *affichage;

    //creation de la grille
    grille = new Grille();

    //init de la matrice avec un motif special
    vector<vector<Cellule>> matrice(5, vector<Cellule>(10));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            //creer un motif simple
            if ((i == 1 && j == 2) || (i == 3 && j == 1) || (i == 3 && j == 3))
            {
                matrice[i][j] = Cellule(i, j, 1); //cellule vivante
            }
            else
            {
                matrice[i][j] = Cellule(i, j, 0); //cellule morte
            }
        }
    }

    //config de la grille
    grille->set_ligne(5);
    grille->set_colonne(10);
    grille->set_matrice(matrice);

    //creation de l'affichage graphique
    affichage = new Affichage_graphique(grille, 500);

    //verif des compteurs
    Compteurs compteur;
    int total_cells = grille->get_ligne() * grille->get_colonne();
    int alive_cells = 3; //selon le motif
    int dead_cells = total_cells - alive_cells;

    assert(compteur.calcule_compteur_cellule(*grille) == total_cells);
    assert(compteur.calcule_compteur_cellule_vivante(*grille) == alive_cells);
    assert(compteur.calcule_compteur_cellule_morte(*grille) == dead_cells);

    cout << "Tests des compteurs passés avec succès !" << endl;

    //verif de l'affichage graphique
    cout << "Lancement de l'affichage graphique. Fermez les fenêtres pour continuer..." << endl;
    affichage->afficher_grille();

    cout << "Test d'Affichage_graphique passé avec succès !" << endl;

    //liberation de la memoire
    delete affichage;
    delete grille;
}

void test_grille_update_default()
{
    cout << "==============================" << endl;
    cout << "Test de mise à jour de la grille avec une grille classique" << endl;
    cout << "==============================" << endl;
    //creation de la grille et initialisation
    Grille grille;
    grille.set_ligne(5);
    grille.set_colonne(5);

    //motif initial
    vector<vector<Cellule>> matrice(5, vector<Cellule>(10));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if ((i == 2 && j == 1) || (i == 2 && j == 2) || (i == 2 && j == 3))
            {
                matrice[i][j] = Cellule(i, j, 1); //cellule vivante
            }
            else
            {
                matrice[i][j] = Cellule(i, j, 0); //cellule morte
            }
        }
    }
    grille.set_matrice(matrice);

    //creation de l'objet Grille_update_default
    Grille_update_default update_default;

    //verif de l'etat initial
    cout << "Grille initiale :" << endl;
    for (int i = 0; i < grille.get_ligne(); ++i)
    {
        for (int j = 0; j < grille.get_colonne(); ++j)
        {
            cout << grille.get_matrice()[i][j].get_status() << " ";
        }
        cout << endl;
    }

    //application de la mise à jour
    update_default.update(grille);

    //affichage de l'etat apres une maj
    cout << "Grille après mise à jour :" << endl;
    for (int i = 0; i < grille.get_ligne(); ++i)
    {
        for (int j = 0; j < grille.get_colonne(); ++j)
        {
            cout << grille.get_matrice()[i][j].get_status() << " ";
        }
        cout << endl;
    }

    //verif des etats attendus apres la maj
    auto nouvelle_matrice = grille.get_matrice();
    assert(nouvelle_matrice[1][2].get_status() == 1);
    assert(nouvelle_matrice[2][2].get_status() == 1);
    assert(nouvelle_matrice[3][2].get_status() == 1);
    assert(nouvelle_matrice[2][1].get_status() == 0);
    assert(nouvelle_matrice[2][3].get_status() == 0);

    cout << "Test Grille_update_default passé avec succès !" << endl;
}


void test_grille_update_torique()
{
    cout << "==============================" << endl;
    cout << "Test de mise à jour de la grille avec une grille torique" << endl;
    cout << "==============================" << endl;

    //ouvre le fichier contenant le motif de la grille
    ifstream fichier("test_torique.txt");
    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le fichier motif.txt." << endl;
        return;
    }

    //lire les dimensions de la grille
    int lignes, colonnes;
    fichier >> lignes >> colonnes;  //premiere ligen

    //init grille
    Grille grille;
    vector<vector<Cellule>> matrice(lignes, vector<Cellule>(colonnes));

    //lecture matrice a partir du fichier
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            int valeur;
            fichier >> valeur;  //lire statut de chaque cellule
            matrice[i][j] = Cellule(i, j, valeur);  //init la cellule avec la valeur lue
        }
    }

    //config la grille avec la matrice lue
    grille.set_matrice(matrice);

    //affiche la grille avant la maj
    cout << "Grille initiale :" << endl;
    for (int i = 0; i < grille.get_ligne(); i++) {
        for (int j = 0; j < grille.get_colonne(); j++) {
            cout << grille.get_matrice()[i][j].get_status() << " ";
        }
        cout << endl;
    }

    //applique la maj torique
    Grille_update_Torique update_torique;
    update_torique.update(grille);

    //affiche la grille apres la maj
    cout << "Grille après mise à jour torique :" << endl;
    for (int i = 0; i < grille.get_ligne(); i++) {
        for (int j = 0; j < grille.get_colonne(); j++) {
            cout << grille.get_matrice()[i][j].get_status() << " ";
        }
        cout << endl;
    }

    //verif des resultats attendus apres la maj
    bool test_passed = true;

        for (int i = 0; i < grille.get_ligne(); i++) {
        for (int j = 0; j < grille.get_colonne(); j++) {
            //nombre de voisin de chaque cellule
            int voisins_vivants = 0;

            //verif des voisins dans la grille torique
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;  //ignore la cellule elle-meme

                    //calcul l'indice des voisins en torique
                    int ni = (i + di + grille.get_ligne()) % grille.get_ligne();
                    int nj = (j + dj + grille.get_colonne()) % grille.get_colonne();

                    if (grille.get_matrice()[ni][nj].get_status() == 1) {
                        voisins_vivants++;
                    }
                }
            }

            //regle du jeu pour les verifs
            int etat_actuel = grille.get_matrice()[i][j].get_status();
            int etat_attendu = etat_actuel;

            //regle du jeu torique
            if (etat_actuel == 1) {
                if (voisins_vivants < 2 || voisins_vivants > 3) {
                    etat_attendu = 0;  //cellule meurt
                }
            } else {
                if (voisins_vivants == 3) {
                    etat_attendu = 1;  //cellule vie
                }
            }

            //verif si l'etat attendu est le bon
            if (etat_actuel != etat_attendu) {
                cout << "Echec du test : la cellule (" << i << ", " << j << ") devrait avoir l'état " 
                     << etat_attendu << " mais a l'état " << etat_actuel << "." << endl;
                test_passed = false;
            }
        }
    }

    //resultat du test
    if (test_passed) {
        cout << "Test effectué avec succès !" << endl;
    } else {
        cout << "Test échoué." << endl;
    }
}



void test (){
    // test_lecture_fichier();
    // test_ecriture_fichier();
    // test_creer_dossier();
    // test_supprimer_dossier();
    // test_get_nom();
    // test_grille_creation();
    // test_set_ligne();
    // test_set_colonne();
    // test_set_matrice();
    // test_get_matrice();
    // test_cellule_creation_par_defaut();
    // test_cellule_creation_par_parametres();
    // test_getters();
    // test_status_update();
    // test_affichage_terminal_et_compteurs();
    // test_affichage_graphique_et_compteurs();
    // test_grille_update_default();
    test_grille_update_torique();

}