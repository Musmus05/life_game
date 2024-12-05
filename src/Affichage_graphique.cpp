#include "Affichage_graphique.h"
using namespace std;
using namespace sf;

Affichage_graphique::Affichage_graphique(Grille *grille, long int temps_entre_generation) : Affichage(grille), temps_entre_generation(temps_entre_generation)
{
    cout << "Torique ou non torique ? (1/0) : ";
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
    window_colonne = grille->get_colonne() * cellule_taille;
    window_ligne = grille->get_ligne() * cellule_taille;
}

Affichage_graphique::~Affichage_graphique() {}

void Affichage_graphique::afficher_grille()
{
    RenderWindow window(VideoMode(window_colonne, window_ligne), "Jeu de la vie"); // fenetre pour le jeu
    this->window = &window;

    RenderWindow windowCompteurs(VideoMode(400, 200), "Compteurs"); // fenetre pour les compteurs
    windowCompteurs.setPosition(sf::Vector2i(0, 0));
    this->windowCompteurs = &windowCompteurs;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        { // fenetre principale
            if (event.type == Event::Closed)
            { // verification si fermé ou non
                window.close();
            }
        }

        while (windowCompteurs.pollEvent(event))
        { // verification si fermé ou non
            if (event.type == Event::Closed)
            {
                windowCompteurs.close();
            }
        }

        window.clear();
        afficher_cellule(); // acutaliser la premiere fenetre
        window.display();

        windowCompteurs.clear();
        afficher_compteurs(); // actualiser la deuxieme fenetre
        windowCompteurs.display();

        // Mise à jour de la grille
        grille_update->update(*grille);
        sleep(milliseconds(temps_entre_generation)); // temps entre generation
    }
}

void Affichage_graphique::afficher_cellule()
{
    for (int i = 0; i < grille->get_ligne(); i++)
    {
        for (int j = 0; j < grille->get_colonne(); j++)
        {
            sf::RectangleShape rectangle(sf::Vector2f(cellule_taille, cellule_taille));
            rectangle.setPosition(j * cellule_taille, i * cellule_taille);
            if (grille->get_matrice()[i][j].get_status() == 1)
            {
                rectangle.setFillColor(sf::Color::Black);
            }
            else if (grille->get_matrice()[i][j].get_status() == 0)
            {
                rectangle.setFillColor(sf::Color::White);
            }
            else if (grille->get_matrice()[i][j].get_status() == 2)
            {
                rectangle.setFillColor(sf::Color::Red);
            }
            window->draw(rectangle);
        }
    }
}

void Affichage_graphique::afficher_compteurs()
{
    int total = compteur.calcule_compteur_cellule(*grille);
    int vivantes = compteur.calcule_compteur_cellule_vivante(*grille); // on met les compteurs dans des var
    int mortes = compteur.calcule_compteur_cellule_morte(*grille);

    // Chargement de la police
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"))
    {
        cout << "Erreur : impossible de charger la police DejaVu Sans." << endl;
        return;
    }

    sf::Text textTotal, textVivantes, textMortes, textgeneration; // defini les polices d'écriture
    textTotal.setFont(font);
    textVivantes.setFont(font);
    textMortes.setFont(font);
    textgeneration.setFont(font);

    textTotal.setString("Nombre de cellules : " + to_string(total)); // on set le text pour chque compteur
    textVivantes.setString("Nombre de cellules vivantes : " + to_string(vivantes));
    textMortes.setString("Nombre de cellules mortes : " + to_string(mortes));
    textgeneration.setString("Generations : " + to_string(generation++));

    textTotal.setCharacterSize(20); // on set la taille de police
    textVivantes.setCharacterSize(20);
    textMortes.setCharacterSize(20);
    textgeneration.setCharacterSize(20);

    textTotal.setFillColor(sf::Color::White); // on set la couleur
    textVivantes.setFillColor(sf::Color::White);
    textMortes.setFillColor(sf::Color::White);
    textgeneration.setFillColor(sf::Color::White);

    textTotal.setPosition(10, 10); // on set la position
    textVivantes.setPosition(10, 40);
    textMortes.setPosition(10, 70);
    textgeneration.setPosition(10, 100);

    windowCompteurs->draw(textTotal); // on affiche sur la deuxieme fenetre
    windowCompteurs->draw(textVivantes);
    windowCompteurs->draw(textMortes);
    windowCompteurs->draw(textgeneration);
}