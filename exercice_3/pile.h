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
    void empiler(char operateur);
    void empiler(float operande);
    char depiler(char type);
    bool vide();
    noeud *getHead();
    void afficher();
    void evaluer(string expression);
};

#endif
