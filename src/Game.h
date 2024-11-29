#include "Fichier.h"
#include "Grille.h"
#include "Cellule.h"

class Game
{
private:
public:
    Game();
    void Start_Terminal_Interface(std::string filename); // demarre le jeu en mode console
    void Start_Graphique_Interface(std::string filename);                    // demarre le jeu en mode graphique
    ~Game();
};
