#ifndef fichier_h
#define fichier_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;



#include "Grille.h"
template <typename T>
class Fichier
{
    private:
        string premiere_ligne;          // Première ligne contenant les dimensions
        vector<vector<T>> matrice; // Matrice 2D pour stocker les données
    public:
        Fichier();
        void lecture_fichier();
        int get_ligne();
        int get_colonne();
        vector<vector<T>> get_matrice();
};


template <typename T>
Fichier<T>::Fichier(){}

template <typename T>
void Fichier<T>::lecture_fichier()
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
    matrice.resize(ligne, vector<T>(colonne));

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


template <typename T>
int Fichier<T>::get_ligne(){
    return matrice.size();
}

template <typename T>
int Fichier<T>::get_colonne(){
    return matrice[0].size();
}

template <typename T>
vector<vector<T>> Fichier<T>::get_matrice(){
    return matrice;
}



#endif