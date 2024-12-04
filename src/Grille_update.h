#ifndef GRILLE_UPDATE_H
#define GRILLE_UPDATE_H

#include "Grille.h"

class Grille_update {
    public:
        virtual void update(Grille &grille) = 0;
};

#endif