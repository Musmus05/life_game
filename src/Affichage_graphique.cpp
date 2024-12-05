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

    RenderWindow windowCompteurs(VideoMode(400, 250), "Compteurs"); // fenetre pour les compteurs
    windowCompteurs.setPosition(sf::Vector2i(0, 0));
    this->windowCompteurs = &windowCompteurs;

    bool isPaused = false; // pause ou play

    // charger police
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"))
    {
        std::cout << "Impossible de charger la police!" << std::endl;
        return;
    }

    // init du texte de pause
    sf::Text pause;
    pause.setFont(font);
    pause.setString("Pause");
    pause.setFillColor(sf::Color::Red);
    pause.setCharacterSize(20);
    pause.setPosition(window.getSize().x / 2 - pause.getLocalBounds().width / 2, window.getSize().y / 4); // centrer

    while (window.isOpen())
    {
        sf::Event event;

        // gestion event fenetre principale
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        // gestion event fenetre compteur
        while (windowCompteurs.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                windowCompteurs.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) // verif le clic de la soures
            {
                if (event.mouseButton.button == sf::Mouse::Left) // verif si c'est un clic gauche
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(windowCompteurs); // recup la position de la souris

                    // si le bouton 3 est clique
                    if (button3.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                        isPaused = true; // mettre en pause
                    }

                    // si le bouton 4 est clique
                    if (button4.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                        isPaused = false; // relancer le jeu
                    }

                    // bouton 1 et 2
                    if (button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) // Bouton 1
                    {
                        temps_entre_generation = temps_entre_generation + 100; // Augmente le temps entre les gen
                    }

                    if (button2.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) // Bouton 2
                    {
                        temps_entre_generation = temps_entre_generation - 100; // Diminue le temps entre les gen
                    }
                }
            }
        }

        // verif si le jeu est en pause
        if (!isPaused)
        {
            // maj de la fenetre principale
            window.clear();
            afficher_cellule();
            window.display();

            // maj fenetre compteur
            windowCompteurs.clear();
            afficher_compteurs();
            windowCompteurs.display();

            // Mise à jour de la grille
            grille_update->update(*grille);
            sleep(milliseconds(temps_entre_generation)); // temps entre generation
        }
        else
        {
            //si jeu en pause affiche pause
            window.clear();
            afficher_cellule();
            window.display();
        }
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
    // Calcul des compteurs
    int total = compteur.calcule_compteur_cellule(*grille);
    int vivantes = compteur.calcule_compteur_cellule_vivante(*grille);
    int mortes = compteur.calcule_compteur_cellule_morte(*grille);

    // Chargement de la police
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"))
    {
        std::cout << "Erreur : impossible de charger la police DejaVu Sans." << std::endl;
        return;
    }

    // Définition des textes pour les compteurs
    sf::Text textTotal, textVivantes, textMortes, textGeneration;
    textTotal.setFont(font);
    textVivantes.setFont(font);
    textMortes.setFont(font);
    textGeneration.setFont(font);

    textTotal.setString("Nombre de cellules : " + std::to_string(total));
    textVivantes.setString("Nombre de cellules vivantes : " + std::to_string(vivantes));
    textMortes.setString("Nombre de cellules mortes : " + std::to_string(mortes));
    textGeneration.setString("Generations : " + std::to_string(generation++));

    textTotal.setCharacterSize(20);
    textVivantes.setCharacterSize(20);
    textMortes.setCharacterSize(20);
    textGeneration.setCharacterSize(20);

    textTotal.setFillColor(sf::Color::White);
    textVivantes.setFillColor(sf::Color::White);
    textMortes.setFillColor(sf::Color::White);
    textGeneration.setFillColor(sf::Color::White);

    textTotal.setPosition(10, 10);
    textVivantes.setPosition(10, 40);
    textMortes.setPosition(10, 70);
    textGeneration.setPosition(10, 100);

    // création du bouton avec un rectangle et du texte dedans
    button.setSize(sf::Vector2f(150, 40));
    button.setFillColor(sf::Color::Blue);
    button.setPosition(10, 150);

    sf::Text buttonText;
    buttonText.setFont(font);
    buttonText.setString("Ralentir"); // On donne les caractéristique du bouton
    buttonText.setCharacterSize(20);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(button.getPosition().x + 10, button.getPosition().y + 5); // pos du bouton
    // création du bouton avec un rectangle et du texte dedans
    button2.setSize(sf::Vector2f(150, 40));
    button2.setFillColor(sf::Color::Blue);
    button2.setPosition(170, 150);

    sf::Text buttonText2;
    buttonText2.setFont(font);
    buttonText2.setString("Accelerer");
    buttonText2.setCharacterSize(20); // On donne les caractéristique du bouton
    buttonText2.setFillColor(sf::Color::White);
    buttonText2.setPosition(button2.getPosition().x + 10, button2.getPosition().y + 5);

    // création du bouton avec un rectangle et du texte dedans
    button3.setSize(sf::Vector2f(150, 40));
    button3.setFillColor(sf::Color::Blue);
    button3.setPosition(10, 200);

    sf::Text buttonText3;
    buttonText3.setFont(font);
    buttonText3.setString("⏸");
    buttonText3.setCharacterSize(20); // On donne les caractéristique du bouton
    buttonText3.setFillColor(sf::Color::White);
    buttonText3.setPosition(button3.getPosition().x + 10, button3.getPosition().y + 5);

    button4.setSize(sf::Vector2f(150, 40));
    button4.setFillColor(sf::Color::Blue);
    button4.setPosition(170, 200);

    sf::Text buttonText4;
    buttonText4.setFont(font);
    buttonText4.setString("||>");
    buttonText4.setCharacterSize(20); // On donne les caractéristique du bouton
    buttonText4.setFillColor(sf::Color::White);
    buttonText4.setPosition(button4.getPosition().x + 10, button4.getPosition().y + 5);

    // Dessin des éléments sur la fenêtre des compteurs
    windowCompteurs->draw(textTotal);
    windowCompteurs->draw(textVivantes);
    windowCompteurs->draw(textMortes);
    windowCompteurs->draw(textGeneration);
    windowCompteurs->draw(button);      // on dessine le bouton
    windowCompteurs->draw(button2);     // on dessine le bouton
    windowCompteurs->draw(button3);     // on dessine le bouton
    windowCompteurs->draw(button4);     // on dessine le bouton
    windowCompteurs->draw(buttonText);  // on dessine le text sur le bouton
    windowCompteurs->draw(buttonText2); // on dessine le text sur le bouton
    windowCompteurs->draw(buttonText3); // on dessine le text sur le bouton
    windowCompteurs->draw(buttonText4); // on dessine le text sur le bouton
}