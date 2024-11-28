#include "Grille.h"

Grille::Grille(){
    Grille_init();
};


Grille::~Grille() {

}

void Grille::Grille_init(){
    Fichier lecture;
    lecture.lecture_fichier();
    this->ligne = lecture.get_ligne();
    this->colonne = lecture.get_colonne();
    this->matrice = lecture.get_matrice();
}