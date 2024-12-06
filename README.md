# 🎲 Projet Jeu de la Vie CPIA2

## 👥 Fait par :
- Musmus05 : Madani Mustapha
- Cherubalex : Maumy Alexandre

## 📄 Pour plus d'information (Documentation)
Pour plus d'informations, consultez la [documentation technique et utilisateur](./Documentations_jeu_de_la_vie_Groupe6.pdf)



## 📚 Description
Ce projet implémente le célèbre "Jeu de la Vie" de John Conway en C++. Le jeu de la vie est un automate cellulaire où des cellules vivent, meurent ou se multiplient selon des règles simples.

## 🚀 Fonctionnalités
- Initialisation de la grille à partir du fichier data.txt
- Evolution de la grille selon les règles du jeu
- Affichage de la grille à chaque étape, L'utilisateur choisit entre un affichage terminal et graphique

## 🛠️ Langages et Technologies
- C++ (98.1%)
- Makefile (1.3%)
- Python (0,6%)

## 📦 Installation
Pour compiler et exécuter le projet, utilisez les commandes suivantes :

```sh
make
./main
```

## 📝 Règles du Jeu
1. Toute cellule vivante avec moins de deux voisins vivants meurt, comme par sous-population.
2. Toute cellule vivante avec deux ou trois voisins vivants survit à la génération suivante.
3. Toute cellule vivante avec plus de trois voisins vivants meurt, comme par surpopulation.
4. Toute cellule morte avec exactement trois voisins vivants devient vivante, comme par reproduction.


