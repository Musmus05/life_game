#include "Grille_graphique.h"
using namespace std;
Grille_graphique::Grille_graphique() : Grille(){}

Grille_graphique::~Grille_graphique(){}

Grille_graphique::Grille_graphique(long int temps_entre_generation):Grille(),temps_entre_generation(temps_entre_generation){}
int Grille_graphique::get_ligne(){
    return this->ligne;
}

void Grille_graphique::set_ligne(int x){
    this->ligne = x;
}

int Grille_graphique::get_colonne(){
    return this->colonne;
}

void Grille_graphique::set_colonne(int y){
    this->colonne = y;
}


void Grille_graphique::afficher_grille() {
    // Créer une fenêtre SFML pour afficher la grille
    sf::RenderWindow window(sf::VideoMode(window_colonne, window_ligne), "Jeu de la vie");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::White); 
            for (int i = 0; i < this->ligne; i++) {
                for (int j = 0; j < this->colonne; j++) {
                    sf::RectangleShape rectangle(sf::Vector2f(cellule_taille, cellule_taille));
                    rectangle.setPosition(j * cellule_taille, i * cellule_taille);
                    if (this->matrice[i][j].get_status() == 1) {
                        rectangle.setFillColor(sf::Color::Black);
                    } else if (this->matrice[i][j].get_status() == 0){
                        rectangle.setFillColor(sf::Color::White);
                    }
                    else if (this->matrice[i][j].get_status() == 2){
                        rectangle.setFillColor(sf::Color::Red);
                    }
                    window.draw(rectangle);
                }
            }

        window.display(); // Afficher le contenu de la fenêtre

        Grille_update(); // Mettre à jour la grille
        // Attendre un court instant avant la prochaine mise à jour
        sf::sleep(sf::milliseconds(this->temps_entre_generation));
    }
}



void Grille_graphique::Grille_update()
{
    // copie de la matrice de depart
    vector<vector<Cellule>> nouvelle_matrice = matrice;

    for (int i = 0; i < ligne; i++)
    { // parcour de chaque cellule de la matrice
        for (int j = 0; j < colonne; j++)
        {
            // Si la cellule a le statut 2, elle reste inchangee
            if (matrice[i][j].get_status() == 2)
            {
                continue;
            }

            int somme = 0;

            // veirf en grille torique
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (x == 0 && y == 0)
                        continue;                               // Ignorer la cellule elle-même
                    int voisin_i = (i + x + ligne) % ligne;     // Gestion torique pour les lignes
                    int voisin_j = (j + y + colonne) % colonne; // Gestion torique pour les colonnes
                    if (matrice[voisin_i][voisin_j].get_status() == 1)
                    {
                        somme++;
                    }
                }
            }

            // regle du jeu de la vie
            if (matrice[i][j].get_status() == 1)
            { // Cellule vivante
                if (somme < 2 || somme > 3)
                {                                            // peu ou trop de voisins
                    nouvelle_matrice[i][j].status_update(0); // Cellule meurt
                }
            }
            else if (matrice[i][j].get_status() == 0)
            { // Cellule morte
                if (somme == 3)
                {                                            // Une nouvelle cellule nait
                    nouvelle_matrice[i][j].status_update(1); // Cellule devient vivante
                }
            }
        }
    }

    // Mettre à jour la matrice avec les nouveaux états
    matrice = nouvelle_matrice;
}

int Grille_graphique::calcule_compteur_cellule(){
    return this->compteur = this->ligne * this->colonne;
}

int Grille_graphique::calcule_compteur_cellule_morte(){
    this->compteur_cellule_morte = 0;
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            if (matrice[i][j].get_status() == 0)
            {
                this->compteur_cellule_morte++;
            }
        }
    }
    return this->compteur_cellule_morte;
}

int Grille_graphique::calcule_compteur_cellule_vivante(){
    this->compteur_cellule_vivante = 0;
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            if (matrice[i][j].get_status() == 1)
            {
                this->compteur_cellule_vivante++;
            }
        }
    }
    return this->compteur_cellule_vivante;
}

vector<vector<Cellule>> Grille_graphique::get_matrice(){
    return this->matrice;
}