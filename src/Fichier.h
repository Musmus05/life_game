#ifndef fichier_h
#define fichier_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Grille.h"


class Fichier
{
private:
    std::string premiere_ligne;       // Première ligne contenant les dimensions
    std::vector<std::vector<int>> matrice; // Matrice 2D pour stocker les données
    std::string filename;        // nom du fichier
public:
    Fichier();
    Fichier(std::string filename);
    std::vector<std::vector<int>> lecture_fichier(std::string filename);
    int get_ligne();
    std::string get_nom() const;
    int get_colonne();
    std::string ecriture_fichier(std::vector<std::vector<Cellule>> matrice, int revision); // modif pour renvoyer le nom du fichier
    void supprimer_dossier();
    void creer_dossier();
    std::vector<std::vector<int>> get_matrice();
};

#endif