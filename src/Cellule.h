#ifndef CELLULE_H
#define CELLULE_H

class Cellule
{
protected:
    int x, y;            // stocke les coordonnees de la cellule
    int status_cellule; // stocke le statut de la cellule vivante ou morte

public:
    Cellule();
    Cellule(int x, int y, int status);
    /*---GETTERS---*/
    int get_status(); // recupere le statut de la cellule (vivante/morte)
    int get_x();       // recupere l'abscisse de la cellule
    int get_y();       // recupere l'ordonnee de la cellule
    /*---SETTERS---*/
    void status_update(int nouveau_status); // definir le statut de la cellule vivante ou morte
    ~Cellule();
};

#endif