sequenceDiagram
    participant User
    participant Jeux_vie
    participant Grille
    participant Affichage_terminal
    participant Affichage_graphique
    participant Fichier

    User->>Jeux_vie: main()
    activate Jeux_vie
    Jeux_vie->>Jeux_vie: menu()
    Jeux_vie->>User: Afficher le menu
    User->>Jeux_vie: Choisir le type d'affichage
    User->>Grille: Choisire le fichier source
    alt Choix 1: Affichage terminal
        Jeux_vie->>Grille: new Grille()
        Jeux_vie->>Affichage_terminal: new Affichage_terminal(grille)
    else Choix 2: Affichage graphique
        Jeux_vie->>User: Demander le temps entre générations
        User->>Jeux_vie: Entrer le temps
        Jeux_vie->>Grille: new Grille()
        Jeux_vie->>Affichage_graphique: new Affichage_graphique(grille, temps_entre_generation)
    end
    Jeux_vie->>Jeux_vie: run()
    activate Grille
    Jeux_vie->>Fichier: supprimer_dossier()
    loop pour chaque génération
        Jeux_vie->>Affichage: afficher_grille()
        Jeux_vie->>Grille_update: update(grille)
        Grille_update->>Grille: Mettre à jour la matrice
        Jeux_vie->>Fichier: ecriture_fichier(grille->get_matrice(), generation)
        Jeux_vie->>Jeux_vie: verif_generation_successive()
    end
    deactivate Grille
    deactivate Jeux_vie