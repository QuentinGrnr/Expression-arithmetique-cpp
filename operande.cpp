#include "operande.h"

operande::operande() {
    this->valeur = 0;
    this->suivant = nullptr;
}

operande::operande(int valeur) {
    this->valeur = valeur;
    this->suivant = nullptr;
}

operande::operande(int valeur, operande *suivant) {
    this->valeur = valeur;
    this->suivant = suivant;
}

operande::~operande() {
    this->suivant = nullptr;
}
