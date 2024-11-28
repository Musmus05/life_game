#include "Grille.h"

class Cellule
{
private:
   int x,y; // stocke les coordonnees de la cellule
   bool statut_cellule; // stocke le statut de la cellule vivante ou morte

public:
    Cellule(int x, int y, bool statut);
    /*---GETTERS---*/
    bool get_status(); // recupere le statut de la cellule (vivante/morte)
    int get_x(); // recupere l'abscisse de la cellule
    int get_y(); // recupere l'ordonnee de la cellule

    /*---SETTERS---*/
    void update_status(); // definir le statut de la cellule vivante ou morte
    void set_x(); // definir la coordonnee en abscisse
    void set_y();// definir la coordonnee en ordonne

    virtual void set_taille_cellule(); // définir la taille de la cellule pour la représentation graphique

    ~Cellule();
};