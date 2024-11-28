#include "Grille.h"

using namespace std;

Grille::Grille() {}

void Grille::ajouterCellule(const Cellule &cellule)
{
    grille.push_back(cellule);
}

void Grille::afficherGrille() const
{
    cout << "Contenu de la grille :" << endl;
    for (const auto &cellule : grille)
    {
        cellule.afficher();
    }
}

void Grille::sauvegarde(std::string file, int ordonnee, int taille_x, int taille_y)
{
    ofstream nom_fichier(file);

    if (!nom_fichier.is_open())
    {
        cout << "Erreur d'ouverture de fichier !" << endl;
        return;
    }
    nom_fichier << taille_x << " " << taille_y;
    for (int i = 0; i < grille.size(); i++)
    {

        if (i % ordonnee == 0)
        {
            nom_fichier << endl;
        }
        nom_fichier << grille[i].get_status() << " ";
    }
}

Grille::~Grille() {}