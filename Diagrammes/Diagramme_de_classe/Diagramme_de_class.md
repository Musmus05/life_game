classDiagram
    class Jeux_vie {
        -Grille *grille
        -int nombre_generation
        -int generation
        -int choix
        -Fichier sortie
        -vector~string~ fichiers_recents
        -int nombre_dernier_fichier
        -long int temps_entre_generation
        +Jeux_vie()
        +menu()
        +run()
        +verif_generation_successive()
        +get_generation()
    }

    class Grille {
        #int ligne
        #int colonne
        #vector~vector~Cellule~~ matrice
        +Grille()
        +virtual ~Grille()
        +get_ligne()
        +set_ligne()
        +get_colonne()
        +set_colonne()
        +get_matrice()
        +set_matrice()
        +virtual afficher_grille() = 0
    }



    class Affichage_graphique {
        +Affichage_graphique();
        +Affichage_graphique(long int temps_entre_generation);
        +~Affichage_graphique();
        -int cellule_taille
        -long int temps_entre_generation
        -Grille_update* grille_update
        -sf::RenderWindow* window
        -Compteurs compteur;
        +afficher_grille()
    }

        class Affichage_terminal {
        +Affichage_terminal();
        +~Affichage_terminal();
        -Compteurs compteur
        -Grille_update* grille_update
        +afficher_grille()
    }

    class Grille_update {
        +virtual update(Grille &grille) = 0
    }

    class Grille_update_Torique {
        +update(Grille &grille)
    }

    class Grille_update_default {
        +update(Grille &grille)
    }

    class Cellule {
        -int x
        -int y
        -int status_cellule
        +Cellule()
        +Cellule(int x, int y, int status)
        +~Cellule()
        +get_status()
        +get_x()
        +get_y()
        +status_update()
    }

    class Fichier {
        -string premiere_ligne
        -vector~vector~int~~ matrice
        -string filename
        +Fichier()
        +Fichier(string filename)
        +lecture_fichier()
        +ecriture_fichier()
        +get_ligne()
        +get_colonne()
        +supprimer_dossier()
    }

    class Compteurs {
        +calcule_compteur_cellule()
        +calcule_compteur_cellule_vivante()
        +calcule_compteur_cellule_morte()
    }

    Jeux_vie "1" *-- "1" Grille : contains
    Grille <|-- Affichage_terminal
    Grille <|-- Affichage_graphique
    Grille_update <|-- Grille_update_Torique
    Grille_update <|-- Grille_update_default
    Grille "1" *-- "many" Cellule : contains
    Affichage_terminal "1" ..> "1" Grille_update : uses
    Affichage_graphique "1" ..> "1" Grille_update : uses
    Affichage_terminal "1" ..> "1" Compteurs : uses
    Affichage_graphique "1" ..> "1" Compteurs : uses
    Grille o-- Fichier
    Jeux_vie ..> Fichier
