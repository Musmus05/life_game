#include "Fichier.h"

using namespace std;

Fichier::Fichier() {}

void Fichier::lecture_fichier(string filename)
{
    ifstream nom_fichier(filename);

    if (!nom_fichier.is_open())
    {
        cout << "Erreur d'ouverture de fichier !" << endl;
        return;
    }

    // lecture de la premiere ligne pour recuperer les dimensions pour la creation de la matrice
    getline(nom_fichier, premiere_ligne);

    // extraction des dimensions de la premiere ligne
    stringstream fl(premiere_ligne);
    int abscisse, ordonnee;
    fl >> abscisse >> ordonnee;

    // redimensionner la matrice en fonction des dimensions lues et stockee dans premiere_ligne
    matrice.resize(abscisse, vector<int>(ordonnee));

    // lire le reste du fichier pour remplir la matrice
    string ligne;
    for (int i = 0; i < abscisse; i++)
    {
        getline(nom_fichier, ligne);
        stringstream ligne_stringstream(ligne);
        for (int j = 0; j < ordonnee; j++)
        {
            int valeur_temporaire;
            ligne_stringstream >> valeur_temporaire;
            matrice[i][j] = valeur_temporaire; // Assigner directement l'entier
        }
    }
    nom_fichier.close(); // fermeture du fichier
}

int Fichier::abscisse()
{
    return matrice.size(); // nombre de lignes de la matrice
}

int Fichier::ordonnee()
{
    return matrice[0].size(); // nombre de colonnes de la matrice
}
int Fichier::get_status(int i, int j) const
{
    return matrice[i][j]; // recuperation du status aux coordonnes (x,y)
}

// affichage de la taille de la matrice et de son contenu dans la console
void Fichier::afficher_matrice()
{
    int abscisse = matrice.size();    // nombre de lignes
    int ordonnee = matrice[0].size(); // nombre de colonnes

    // dimensions de la matrice
    cout << "Dimensions de la matrice : " << abscisse << " lignes x " << ordonnee << " colonnes." << endl;

    // contenu de la matrice
    cout << "Contenu de la matrice : " << endl;
    for (int i = 0; i < abscisse; i++)
    {
        for (int j = 0; j < ordonnee; j++)
        {
            cout << matrice[i][j] << " ";
        }
        cout << endl; // saut de ligne apres chaque ligne de la matrice
    }
}