#include "Grille.h"

Grille::Grille(){
    Fichier lecture;
    lecture.lecture_fichier();
    this->ligne = lecture.get_ligne();
    this->colonne = lecture.get_colonne();
    this->matrice = lecture.get_matrice();
};


Grille::~Grille() {

}