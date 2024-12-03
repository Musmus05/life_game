#include "Grille_terminal.h"
using namespace std;

Grille_terminal::Grille_terminal() : Grille() {}

Grille_terminal::~Grille_terminal() {}

int Grille_terminal::get_ligne()
{
    return ligne;
}

void Grille_terminal::set_ligne(int x)
{
    this->ligne = x;
}

int Grille_terminal::get_colonne()
{
    return colonne;
}

void Grille_terminal::set_colonne(int y)
{
    this->colonne = y;
}

void Grille_terminal::afficher_grille()
{
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            cout << matrice[i][j].get_status() << " ";
        }
        cout << endl; // Saut de ligne après chaque ligne de la matrice
    }
    cout << endl; // Saut de ligne après l'affichage de la matrice
}

void Grille_terminal::Grille_update()
{
    // copie de la matrice de depart
    vector<vector<Cellule>> nouvelle_matrice = matrice;

    for (int i = 0; i < ligne; i++)
    { // parcour de chaque cellule de la matrice
        for (int j = 0; j < colonne; j++)
        {
            // Si la cellule a le statut 2, elle reste inchangee
            if (matrice[i][j].get_status() == 2)
            {
                continue;
            }

            int somme = 0;

            // veirf en grille torique
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (x == 0 && y == 0)
                        continue;                               // Ignorer la cellule elle-même
                    int voisin_i = (i + x + ligne) % ligne;     // Gestion torique pour les lignes
                    int voisin_j = (j + y + colonne) % colonne; // Gestion torique pour les colonnes
                    if (matrice[voisin_i][voisin_j].get_status() == 1)
                    {
                        somme++;
                    }
                }
            }

            // regle du jeu de la vie
            if (matrice[i][j].get_status() == 1)
            { // Cellule vivante
                if (somme < 2 || somme > 3)
                {                                            // peu ou trop de voisins
                    nouvelle_matrice[i][j].status_update(0); // Cellule meurt
                }
            }
            else if (matrice[i][j].get_status() == 0)
            { // Cellule morte
                if (somme == 3)
                {                                            // Une nouvelle cellule nait
                    nouvelle_matrice[i][j].status_update(1); // Cellule devient vivante
                }
            }
        }
    }

    // Mettre à jour la matrice avec les nouveaux états
    matrice = nouvelle_matrice;
}

int Grille_terminal::calcule_compteur_cellule()
{
    return this->compteur = this->ligne * this->colonne;
}

int Grille_terminal::calcule_compteur_cellule_morte()
{
    this->compteur_cellule_morte = 0;
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            if (matrice[i][j].get_status() == 0)
            {
                this->compteur_cellule_morte++;
            }
        }
    }
    return this->compteur_cellule_morte;
}

int Grille_terminal::calcule_compteur_cellule_vivante()
{
    this->compteur_cellule_vivante = 0;
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            if (matrice[i][j].get_status() == 1)
            {
                this->compteur_cellule_vivante++;
            }
        }
    }
    return this->compteur_cellule_vivante;
}

vector<vector<Cellule>> Grille_terminal::get_matrice()
{
    return matrice;
}