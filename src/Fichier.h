#ifndef fichier_h
#define fichier_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
#include "Cellule.h"
#include "Grille.h"

class Fichier
{
private:
    string premiere_ligne;       // Première ligne contenant les dimensions
    vector<vector<int>> matrice; // Matrice 2D pour stocker les données
    std::string filename;        // nom du fichier
public:
    Fichier();
    Fichier(std::string filename);
    vector<vector<int>> lecture_fichier(std::string filename);
    int get_ligne();
    std::string get_nom() const;
    int get_colonne();
    std::string ecriture_fichier(vector<vector<Cellule>> matrice, int revision); // modif pour renvoyer le nom du fichier
    void supprimer_dossier();
    void creer_dossier();
    vector<vector<int>> get_matrice();
};

#endif