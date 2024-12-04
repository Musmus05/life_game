#include "Fichier.h"

using namespace std;
Fichier::Fichier() {}

Fichier::Fichier(string filename) {this->filename = filename;}

vector<vector<int>> Fichier::lecture_fichier(string filename)
{
    ifstream nom_fichier(filename);

    if (!nom_fichier.is_open())
    {
        cout << "Erreur d'ouverture de fichier !" << endl;
        return matrice;
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
    return matrice;
    nom_fichier.close();
}


int Fichier::get_ligne(){
    return matrice.size();
}

int Fichier::get_colonne(){
    return matrice[0].size();
}

vector<vector<int>> Fichier::get_matrice(){
    return matrice;
}

string Fichier::ecriture_fichier(vector<vector<Cellule>> matrice, int revision) //modif du type pour renvoyer le nom du fichier
{
    string filename = "Sortie_sauvegarde/data_out_" + to_string(revision) + ".txt";
    ofstream nom_fichier(filename);

    if (!nom_fichier.is_open())
    {
        cout << "Erreur d'ouverture de fichier !" << endl;
        return ""; //modif pour quand meme arrete le pro
    }

    //ecriture de la taille de la grille
    nom_fichier << matrice.size() << " " << matrice[0].size() << endl;

    //ecriture du contenu de la grille
    for (int i = 0; i < matrice.size(); i++)
    {
        for (int j = 0; j < matrice[0].size(); j++)
        {
            nom_fichier << matrice[i][j].get_status() << " ";
        }
        nom_fichier << endl;
    }
    nom_fichier.close();
    return filename;//on retourn le nom du fichier
}

void Fichier::supprimer_dossier()
{
    system("rm -rf Sortie_sauvegarde/*");

}

void Fichier::creer_dossier()
{
    system("mkdir Sortie_sauvegarde");
}

string Fichier::get_nom() const {
    return filename;
}