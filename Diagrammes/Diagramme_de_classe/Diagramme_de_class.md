classDiagram
    class Cellule {
        - int x
        - int y
        - bool statut_cellule
        + Cellule()
        + Cellule(int x, int y, bool status)
        + ~Cellule()
        + bool get_status()
        + int get_x()
        + int get_y()
        + void set_status()
        + void set_taille_cellule()
        + void update()
    }

    class Fichier {
        - string premiere_ligne
        - matrice : Vector: Vector : int
        - string filename
        + Fichier()
        + Fichier(string filename)
        + void lecture_fichier(string filename)
        + int get_ligne()
        + int get_colonne()
        + MatrixInt get_matrice()
    }

    class Grille {
        # int ligne
        # int colonne
        # matrice: Vector : Vector:       Cellule
        # int compteur
        # int compteur_cellule_morte
        # int compteur_cellule_vivante
        + Grille()
        + ~Grille()
        + void Grille_init()
        + int get_ligne()
        + void set_ligne(int ligne)
        + int get_colonne()
        + void set_colonne(int colonne)
        + void afficher_grille()
        + void Grille_update()
        + int calcule_compteur_cellule()
        + int calcule_compteur_cellule_morte()
        + int calcule_compteur_cellule_vivante()
        + MatrixCellule get_matrice()
    }

    class Grille_terminal {
        + Grille_terminal()
        + ~Grille_terminal()
        + int get_ligne()
        + void set_ligne(int x)
        + int get_colonne()
        + void set_colonne(int y)
        + void afficher_grille()
        + void Grille_update()
        + int calcule_compteur_cellule()
        + int calcule_compteur_cellule_morte()
        + int calcule_compteur_cellule_vivante()
    }

    class Grille_graphique {
        + Grille_graphique()
        + ~Grille_graphique()
        + int get_ligne()
        + void set_ligne(int x)
        + int get_colonne()
        + void set_colonne(int y)
        + void afficher_grille()
        + void Grille_update()
        + int calcule_compteur_cellule()
        + int calcule_compteur_cellule_morte()
        + int calcule_compteur_cellule_vivante()
        + MatrixCellule get_matrice()
    }

    class Jeux_vie {
        - int choix
        - int nombre_generation
        - int generation
        - Grille* grille
        - Fichier sortie
        + Jeux_vie()
        + ~Jeux_vie()
        + void menu()
        + void run()
        + int get_generation()
    }

    Grille <|-- Grille_terminal : hérite
    Grille <|-- Grille_graphique : hérite
    Grille "1" *-- "n" Cellule : contient
    Jeux_vie "1" ..> "1" Grille : utilise
    
    Fichier "1" *-- "1" Grille : contient
    Jeux_vie ..> Fichier : utilise