#pragma once

class Cellule_terminal
{
protected:
    int x, y;
    int status_cellule;
    static int compteur;

public:
    Cellule_terminal();
    Cellule_terminal(int x, int y, int status_cellule);
    /*---GETTERS---*/
    int get_status();
    int get_x();
    int get_y();
    int get_compteur();
    /*---SETTERS---*/
    void set_status(int nouveau_status);
    virtual ~Cellule_terminal();
};