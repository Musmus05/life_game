#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Fichier
{
private:
    string premiere_ligne;          // Première ligne contenant les dimensions
    vector<vector<int>> matrice; // Matrice 2D pour stocker les données

public:
    Fichier() {}

    // Fonction pour lire le fichier et extraire les dimensions + les données de la matrice
    void lecture_fichier()
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
        stringstream pl(premiere_ligne);
        int ligne, colonne;
        pl >> ligne >> colonne;

        // Redimensionner la matrice en fonction des dimensions lues
        matrice.resize(ligne, vector<int>(colonne));

        // Lire le reste du fichier pour remplir la matrice
        string reste_ligne;
        for (int i = 0; i < ligne; i++)
        {
            getline(nom_fichier, reste_ligne);
            stringstream reste_ligne_stringstream(reste_ligne);
            for (int j = 0; j < colonne; j++)
            {
                reste_ligne_stringstream >> matrice[i][j];
            }
        }

        nom_fichier.close();
    }

    // Afficher la taille de la matrice et son contenu
    void afficher_matrice()
    {
        int ligne = matrice.size();    // Nombre de lignes
        int colonne = matrice[0].size(); // Nombre de colonnes

        // Afficher les dimensions de la matrice
        cout << "Dimensions de la matrice : " << ligne << " lignes x " << colonne << " colonnes." << endl;

        // Afficher le contenu de la matrice
        cout << "Contenu de la matrice : " << endl;
        for (int i = 0; i < ligne; i++)
        {
            for (int j = 0; j < colonne; j++)
            {
                cout << matrice[i][j] << " ";
            }
            cout << endl; // Saut de ligne après chaque ligne de la matrice
        }
    }
};

int main()
{
    Fichier test;
    test.lecture_fichier();  // Lecture du fichier
    test.afficher_matrice(); // Affichage des dimensions et du contenu de la matrice

    return 0;
}
