#include "caractere.h"

caractere::caractere() {
    this->valeur = "";
    this->suivant = nullptr;
}

caractere::caractere(string valeur) {
    this->valeur = valeur;
    this->suivant = nullptr;
}

caractere::caractere(string valeur, caractere *suivant) {
    this->valeur = valeur;
    this->suivant = suivant;
}

caractere::~caractere() {
    this->suivant = nullptr;
}
