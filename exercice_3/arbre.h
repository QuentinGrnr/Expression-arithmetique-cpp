#ifndef TD2S2_POO_ARBRE_H
#define TD2S2_POO_ARBRE_H
#include <string>
#include "noeud.h"
using namespace std;

class arbre {
    noeud *racine;
public:
    arbre();
    arbre(string expressioninf);
    noeud* createnode(char caractere);
};


#endif