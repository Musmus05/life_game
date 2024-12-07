#ifndef GRILLE_UPDATE_DEFAULT_H
#define GRILLE_UPDATE_DEFAULT_H

#include "Grille_update.h"

class Grille_update_default : public Grille_update
{
public:
    void update(Grille &grille) override;
};

#endif