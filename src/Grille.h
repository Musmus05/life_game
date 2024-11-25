#ifndef Grille
#define Grille

class grille {
    private:
        int x,y;
    public:
        grille();
        grille(int x, int y);
        int get_x();
        void set_x();
        int get_y();
        void set_y();
        void grille_creation();

};



#endif