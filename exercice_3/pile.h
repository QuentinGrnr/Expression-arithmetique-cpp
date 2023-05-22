#ifndef EXPRESSION_ARITHM_TIQUE_CPP_PILE_H
#define EXPRESSION_ARITHM_TIQUE_CPP_PILE_H
#include "noeud.h"
#include <string>
using namespace std;
//premier entré premier sorti

class pile {
    noeud *head;
    int nb_caractere;
public:
    pile();
    void empiler(noeud *n);
    noeud* depiler();
    bool vide();
    noeud *getHead();
    void afficher();
    void evaluer(string expression);
};

#endif
