#ifndef CELLULE_H
#define CELLULE_H

class Cellule
{
protected:
   int x, y; // stocke les coordonnees de la cellule
   bool statut_cellule; // stocke le statut de la cellule vivante ou morte

public:
    Cellule(); 
    Cellule(int x, int y, bool status);
    /*---GETTERS---*/
    bool get_status(); // recupere le statut de la cellule (vivante/morte)
    int get_x(); // recupere l'abscisse de la cellule
    int get_y(); // recupere l'ordonnee de la cellule
        /*---SETTERS---*/
    void status_update(); // definir le statut de la cellule vivante ou morte
    virtual ~Cellule(); // Make destructor virtual
};

#endif