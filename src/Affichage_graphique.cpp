#include "Affichage_graphique.h"
using namespace std;
using namespace sf;

Affichage_graphique::Affichage_graphique() : Grille() {}

Affichage_graphique::~Affichage_graphique() {}

Affichage_graphique::Affichage_graphique(long int temps_entre_generation) : Grille(), temps_entre_generation(temps_entre_generation)
{
    cout << "torique ou non torique ? (1/0) : ";
    int torique;
    cin >> torique;
    if (torique == 1)
    {
        grille_update = new Grille_update_Torique();
    }
    else if (torique == 0)
    {
        grille_update = new Grille_update_default();
    }
}

void Affichage_graphique::afficher_grille()
{

    RenderWindow window(VideoMode(window_colonne, window_ligne ), "Jeu de la vie");
    this->window = &window;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        afficher_cellule();
        afficher_compteurs();
        window.display();
        grille_update->update(*this);
        sleep(milliseconds(temps_entre_generation));
    }
}

void Affichage_graphique::afficher_cellule()
{
    for (int i = 0; i < get_ligne(); i++)
    {
        for (int j = 0; j < get_colonne(); j++)
        {
            sf::RectangleShape rectangle(sf::Vector2f(cellule_taille, cellule_taille));
            rectangle.setPosition(j * cellule_taille, i * cellule_taille);
            if (get_matrice()[i][j].get_status() == 1)
            {
                rectangle.setFillColor(sf::Color::Black);
            }
            else if (get_matrice()[i][j].get_status() == 0)
            {
                rectangle.setFillColor(sf::Color::White);
            }
            else if (get_matrice()[i][j].get_status() == 2)
            {
                rectangle.setFillColor(sf::Color::Red);
            }
            window->draw(rectangle);
        }
    }
}

void Affichage_graphique::afficher_compteurs()
{

    int total = compteur.calcule_compteur_cellule(*this);
    int vivantes = compteur.calcule_compteur_cellule_vivante(*this);
    int mortes = compteur.calcule_compteur_cellule_morte(*this);

    cout << "Nombre de cellules : " << total << endl;
    cout << "Nombre de cellules vivantes : " << vivantes << endl;
    cout << "Nombre de cellules mortes : " << mortes << endl;

}