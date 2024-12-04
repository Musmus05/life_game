#include "Afficher_grille_graphique.h"

Afficher_grille_graphique::Afficher_grille_graphique(std::vector<std::vector<Cellule>> matrice)
{
    this->matrice = matrice;
    this->ligne = matrice.size();
    this->colonne = matrice[0].size();
    window_colonne = this->colonne * cellule_taille;
    window_ligne = this->ligne * cellule_taille;
}

void Afficher_grille_graphique::afficher_grille()
{
    // Créer une fenêtre SFML pour afficher la grille
    sf::RenderWindow window(sf::VideoMode(window_colonne, window_ligne), "Jeu de la vie");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::White); 

        for (int i = 0; i < this->ligne; i++)
        {
            for (int j = 0; j < this->colonne; j++)
            {
                sf::RectangleShape rectangle(sf::Vector2f(cellule_taille, cellule_taille)); 
                rectangle.setPosition(j * cellule_taille, i * cellule_taille);

                if (this->matrice[i][j].get_status() == 1)
                {
                    rectangle.setFillColor(sf::Color::Black);
                }
                else if (this->matrice[i][j].get_status() == 0)
                {
                    rectangle.setFillColor(sf::Color::White);
                }
                else
                {
                    rectangle.setFillColor(sf::Color::Red);
                }

                window.draw(rectangle);
            }
        }

        window.display();

        sf::sleep(sf::milliseconds(this->temps_entre_generation));
    }
}

Afficher_grille_graphique::~Afficher_grille_graphique()
{
}
