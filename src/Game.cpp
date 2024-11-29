#include "Game.h"

using namespace std;

Game::Game() {}

void Game::Start_Terminal_Interface(string filename)
{
    int nbr_generation;
    cout << "Nombre de génération : ";
    cin >> nbr_generation;

    Fichier matrice;
    matrice.lecture_fichier(filename); // lecture du fichier
    int abscisse = matrice.abscisse(); // recuperation du nombre de ligne
    int ordonnee = matrice.ordonnee(); // recuperation du nombre de colonne
    // matrice.afficher_matrice(); //affichage des dimensions et du contenu de la matrice

    // creation de la grille
    Grille grille;
    for (int i = 0; i < abscisse; i++)
    {
        for (int j = 0; j < ordonnee; j++)
        {
            Cellule nouvelleCellule(i, j, matrice.get_status(i, j));
            grille.ajouterCellule(nouvelleCellule);
        }
    }

    for (int i = 0; i < nbr_generation; i++)
    {
        grille.afficherGrille(abscisse, ordonnee);
        grille.actualiserGrille(abscisse, ordonnee);

        // gestion de la sauvegarde
        string nom_fichier = "Sauvegarde/Test_" + to_string(i + 1) + ".txt";
        grille.sauvegarde(nom_fichier, abscisse, ordonnee);
    }
}

void Game::Start_Graphique_Interface(string filename)
{
    int nbr_generation;
    cout << "Nombre de génération : ";
    cin >> nbr_generation;

    Fichier matrice;
    matrice.lecture_fichier(filename); // lecture du fichier
    int abscisse = matrice.abscisse(); // recuperation du nombre de ligne
    int ordonnee = matrice.ordonnee(); // recuperation du nombre de colonne
    // matrice.afficher_matrice(); //affichage des dimensions et du contenu de la matrice

    // creation de la grille
    Grille grille;
    for (int i = 0; i < abscisse; i++)
    {
        for (int j = 0; j < ordonnee; j++)
        {
            Cellule nouvelleCellule(i, j, matrice.get_status(i, j));
            grille.ajouterCellule(nouvelleCellule);
        }
    }
}

Game::~Game() {}