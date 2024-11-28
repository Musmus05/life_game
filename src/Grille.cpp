#include "Grille.h"

using namespace std;

//constructeur
Grille::Grille() {}

void Grille::ajouterCellule(const Cellule &cellule)
{
    //on push la cellule dans le vector
    grille.push_back(cellule);
}

void Grille::afficherGrille(int taille_x, int taille_y) const
{
    cout << "Contenu de la grille :" << endl;

    for (int i = 0; i < taille_x; ++i)
    {
        for (int j = 0; j < taille_y; ++j)
        {
            //calculer l'index lineaire dans le vecteur
            int index = i * taille_y + j;

            //on get le statut de la cellule
            cout << grille[index].get_status();

            //ajouter un espace après chaque cellule (sauf à la fin de la ligne)
            if (j < taille_y - 1)
            {
                cout << " ";
            }
        }
        //on met un saut de ligne
        cout << endl;
    }
}

void Grille::sauvegarde(string file, int taille_x, int taille_y)
{
    ofstream nom_fichier(file); //on ouvre le fichier en ecriture

    if (!nom_fichier.is_open()) //verif s'il est ouvert
    {
        cout << "Erreur d'ouverture de fichier !" << endl;
        return;
    }

    //on ecrit la taille en x et y
    nom_fichier << taille_x << " " << taille_y;
    //on parcourt le vector grille pour recuperer et ecrire le status de la cellule
    for (int i = 0; i < grille.size(); i++)
    {
        //verification pour les retours a la ligne
        if (i % taille_y == 0)
        {
            nom_fichier << endl;
        }
        //on ecrit le contenu
        nom_fichier << grille[i].get_status() << " ";
    }
}
void Grille::actualiserGrille(int taille_x, int taille_y)
{
    //creer une copie de l etat actuel de la grille
    vector<vector<bool>> etat_actuel(taille_x, vector<bool>(taille_y));
    //remplissage de la matrice etat_actuel
    for (const auto &cellule : grille) //auto pour detecter automatiquement le type ici Cellule
    {
        etat_actuel[cellule.get_x()][cellule.get_y()] = cellule.get_status(); //on recup les coordonnee et on met a jour le status
    }

    //on parcours toutes les cellules et appliquer les regles du jeu de la vie
    for (int i = 0; i < taille_x; i++)
    {
        for (int j = 0; j < taille_y; j++)
        {
            int voisines_vivantes = 0;
            /*
            O O O
            O X O
            O O O*/ 
            // les deux boucles imbriquees suivantes permettent de vérifier la disposition
            //des voisines ci dessus

            //on verif les 8 voisines de maniere torique
            for (int dx = -1; dx <= 1; dx++) //interval -1;1 pour prendre toute verif toutes les voisines
            {
                for (int dy = -1; dy <= 1; dy++)//interval -1;1 pour prendre toute verif toutes les voisines
                {
                    if (dx == 0 && dy == 0)
                        continue; //permet de pas compter la cellule elle meme

                    int voisin_x = (i + dx + taille_x) % taille_x; //indice torique pour x
                    int voisin_y = (j + dy + taille_y) % taille_y; //indice torique pour y

                    if (etat_actuel[voisin_x][voisin_y]) //compteur pour savoir combien de voisines sont vivantes
                        voisines_vivantes++;
                }
            }

            //applicationdes regles
            Cellule &cellule_courante = grille[i * taille_y + j];
            if (cellule_courante.get_status())
            {
                //cellule vivante
                if (voisines_vivantes < 2 || voisines_vivantes > 3)
                {
                    cellule_courante.set_status(false); //morte
                }
            }
            else
            {
                //cellule morte
                if (voisines_vivantes == 3)
                {
                    cellule_courante.set_status(true); //en vie
                }
            }
        }
    }
}

//destructeur
Grille::~Grille() {}