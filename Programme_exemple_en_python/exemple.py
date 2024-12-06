import random

rows, cols = 50, 50

# Générer la grille aléatoire
grid = [[random.randint(0, 1) for _ in range(cols)] for _ in range(rows)]

# Afficher la grille dans le terminal
for row in grid:
    print(" ".join(map(str, row)))