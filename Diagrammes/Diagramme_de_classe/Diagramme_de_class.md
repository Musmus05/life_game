classDiagram
    class Jeux_vie {
        -Grille *grille
        -Affichage *affichage
        -int nombre_generation
        -int generation
        -int choix
        -Fichier sortie
        -vector~string~ fichiers_recents
        -int nombre_dernier_fichier
        -long int temps_entre_generation
        -Grille_update* grille_update
        +Jeux_vie()
        +menu()
        +run()
        +verif_generation_successive()
        +get_generation()
        +~Jeux_vie()
    }

    class Grille {
        -int ligne
        -int colonne
        -vector~vector~Cellule~~ matrice
        +Grille()
        +~Grille()
        +int get_ligne() const
        +void set_ligne(int ligne)
        +int get_colonne() const
        +void set_colonne(int colonne)
        +vector~vector~Cellule~~ get_matrice() const
        +void set_matrice(const vector~vector~Cellule~~& matrice)
    }

    class Cellule {
        -int x
        -int y
        -int status_cellule
        +Cellule()
        +Cellule(int x, int y, int status)
        +~Cellule()
        +int get_status()
        +int get_x()
        +int get_y()
        +void status_update(int nouveau_status)
    }

    class Fichier {
        -string premiere_ligne
        -vector~vector~int~~ matrice
        -string filename
        +Fichier()
        +Fichier(string filename)
        +vector~vector~int~~ lecture_fichier(string filename)
        +int get_ligne()
        +int get_colonne()
        +vector~vector~int~~ get_matrice()
        +string ecriture_fichier(vector~vector~Cellule~~ matrice, int revision)
        +void supprimer_dossier()
        +void creer_dossier()
        +string get_nom() const
    }

    class Compteurs {
        +int calcule_compteur_cellule(Grille& grille)
        +int calcule_compteur_cellule_vivante(Grille& grille)
        +int calcule_compteur_cellule_morte(Grille& grille)
    }

    class Grille_update {
        <<abstract>>
        +virtual void update(Grille &grille) = 0
        +virtual ~Grille_update() = default
    }

    class Grille_update_Torique {
        +void update(Grille &grille)
    }

    class Grille_update_default {
        +void update(Grille &grille)
    }

    class Affichage {
        <<abstract>>
        #Grille* grille
        +Affichage(Grille* grille)
        +virtual ~Affichage() = default
        +virtual void afficher_grille() = 0
    }

    class Affichage_terminal {
        -Compteurs compteur
        +Affichage_terminal(Grille* grille)
        +~Affichage_terminal()
        +void afficher_grille() override
    }

    class Affichage_graphique {
        -int cellule_taille
        -long int temps_entre_generation
        -Grille_update* grille_update
        -int window_colonne
        -int window_ligne
        -Compteurs compteur
        -sf::RenderWindow* window
        -sf::RenderWindow* windowCompteurs
        -int generation
        +Affichage_graphique(Grille* grille, long int temps_entre_generation)
        +~Affichage_graphique()
        +void afficher_grille() override
        +void afficher_cellule()
        +void afficher_compteurs()
    }

    Jeux_vie "1" *-- "1" Grille : contains
    Jeux_vie "1" *-- "1" Affichage : contains
    Jeux_vie "1" *-- "1" Grille_update : contains
    Jeux_vie "1" ..> "1" Fichier : uses
    Grille "1" o-- "many" Cellule : contains
    Grille_update <|-- Grille_update_Torique
    Grille_update <|-- Grille_update_default
    Affichage <|-- Affichage_terminal
    Affichage <|-- Affichage_graphique
    Affichage_graphique "1" ..> "1" Compteurs : uses
    Affichage_graphique "1" ..> "1" Grille_update : uses
    Grille o-- Fichier
    Jeux_vie *-- Compteurs