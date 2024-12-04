sequenceDiagram
    participant User
    participant Jeux_vie
    participant Grille
    participant Grille_terminal
    participant Grille_graphique
    participant Fichier

    User->>Jeux_vie: main()
    activate Jeux_vie
    Jeux_vie->>Jeux_vie: menu()
    Jeux_vie->>User: Afficher le menu
    User->>Jeux_vie: Choisir une option
    alt Choix 1: Grille terminal
        Jeux_vie->>Grille_terminal: new Grille_terminal()
    else Choix 2: Grille graphique
        Jeux_vie->>User: Demander le temps entre générations
        User->>Jeux_vie: Entrer le temps
        Jeux_vie->>Grille_graphique: new Grille_graphique(temps_entre_generation)
    end
    Jeux_vie->>Jeux_vie: run()
    activate Grille
    Jeux_vie->>Fichier: supprimer_dossier()
    loop pour chaque génération
        Jeux_vie->>Grille: afficher_grille()
        Jeux_vie->>Grille: Grille_update()
        Grille->>Grille: Mettre à jour la matrice
        Jeux_vie->>Fichier: ecriture_fichier(grille->get_matrice(), generation)
        Jeux_vie->>Jeux_vie: verif_generation_successive()
    end
    deactivate Grille
    deactivate Jeux_vie