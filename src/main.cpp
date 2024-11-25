#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Fichier
{
private:
    string first_lign;          // Première ligne contenant les dimensions
    vector<vector<int>> matrix; // Matrice 2D pour stocker les données

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
        getline(nom_fichier, first_lign);

        // Extraire les dimensions de la première ligne
        stringstream fl(first_lign);
        int rows, cols;
        fl >> rows >> cols;

        // Redimensionner la matrice en fonction des dimensions lues
        matrix.resize(rows, vector<int>(cols));

        // Lire le reste du fichier pour remplir la matrice
        string line;
        for (int i = 0; i < rows; i++)
        {
            getline(nom_fichier, line);
            stringstream line_ss(line);
            for (int j = 0; j < cols; j++)
            {
                line_ss >> matrix[i][j];
            }
        }

        nom_fichier.close();
    }

    // Afficher la taille de la matrice et son contenu
    void afficher_matrice()
    {
        int rows = matrix.size();    // Nombre de lignes
        int cols = matrix[0].size(); // Nombre de colonnes

        // Afficher les dimensions de la matrice
        cout << "Dimensions de la matrice : " << rows << " lignes x " << cols << " colonnes." << endl;

        // Afficher le contenu de la matrice
        cout << "Contenu de la matrice : " << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << matrix[i][j] << " ";
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
