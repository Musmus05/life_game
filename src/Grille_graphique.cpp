#include "Grille_graphique.h"

Grille_graphique::Grille_graphique() : Grille(){}

Grille_graphique::~Grille_graphique(){}

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
                    } else {
                        rectangle.setFillColor(sf::Color::White);
                    }
                    window.draw(rectangle);
                }
            }

        window.display(); // Afficher le contenu de la fenêtre

        Grille_update(); // Mettre à jour la grille
        // Attendre un court instant avant la prochaine mise à jour
        sf::sleep(sf::milliseconds(500));
    }
}



void Grille_graphique::Grille_update() { 
    // Créer une copie de la matrice pour stocker les nouveaux états
    vector<vector<Cellule>> nouvelle_matrice = matrice;

    for (int i = 0; i < ligne; i++) { // Parcourir chaque cellule de la matrice
        for (int j = 0; j < colonne; j++) { 
            int somme = 0;

            // Vérifier les 8 voisins dans une grille torique
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue; // Ignorer la cellule elle-même on passe à la porchaine boucle
                    int voisin_i = (i + x + ligne) % ligne; // Gestion torique pour les lignes
                    int voisin_j = (j + y + colonne) % colonne; // Gestion torique pour les colonnes
                    if (matrice[voisin_i][voisin_j].get_status() == 1) {
                        somme++;
                    }
                }
            }

            // Appliquer les règles du jeu de la vie
            if (matrice[i][j].get_status() == 1) { // Cellule vivante
                if (somme < 2 || somme > 3) {  // que les cellules vivantes avec 2 ou 3 voisins vivants survivent
                    nouvelle_matrice[i][j].status_update(); 
                }
            } else {
                if (somme == 3) { // Règle 4
                    nouvelle_matrice[i][j].status_update(); 
                }
            }
        }
    }
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