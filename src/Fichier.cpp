#include "Fichier.h"

using namespace std;

Fichier::Fichier() {}

void Fichier::lecture_fichier()
{
    ifstream nom_fichier("data.txt");

    if (!nom_fichier.is_open())
    {
        cout << "Erreur d'ouverture de fichier !" << endl;
        return;
    }

    // Lire la première ligne (dimensions)
    getline(nom_fichier, premiere_ligne);

    // Extraire les dimensions de la première ligne
    stringstream fl(premiere_ligne);
    int abscisse, ordonnee;
    fl >> abscisse >> ordonnee;

    // Redimensionner la matrice en fonction des dimensions lues
    matrice.resize(abscisse, vector<bool>(ordonnee));

    // Lire le reste du fichier pour remplir la matrice
    string ligne;
    for (int i = 0; i < abscisse; i++)
    {
        getline(nom_fichier, ligne);
        stringstream ligne_stringstream(ligne);
        for (int j = 0; j < ordonnee; j++)
        {
            int valeur_temporaire;
            ligne_stringstream >> valeur_temporaire;
            matrice[i][j] = (valeur_temporaire != 0); // Convertir en bool
        }
    }
    nom_fichier.close();
}

int Fichier::abscisse()
{
    return matrice.size(); // Nombre de lignes
}

int Fichier::ordonnee()
{
    return matrice[0].size();
    ; // Nombre de lignes
}
bool Fichier::get_status(int i, int j) const
{
    return matrice[i][j];
}

// Afficher la taille de la matrice et son contenu
void Fichier::afficher_matrice()
{
    int abscisse = matrice.size();    // Nombre de lignes
    int ordonnee = matrice[0].size(); // Nombre de colonnes

    // Afficher les dimensions de la matrice
    cout << "Dimensions de la matrice : " << abscisse << " lignes x " << ordonnee << " colonnes." << endl;

    // Afficher le contenu de la matrice
    cout << "Contenu de la matrice : " << endl;
    for (int i = 0; i < abscisse; i++)
    {
        for (int j = 0; j < ordonnee; j++)
        {
            cout << matrice[i][j] << " ";
        }
        cout << endl; // Saut de ligne après chaque ligne de la matrice
    }
}