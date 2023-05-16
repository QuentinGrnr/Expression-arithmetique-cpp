#ifndef EXPRESSION_ARITHM_TIQUE_CPP_PILE_H
#define EXPRESSION_ARITHM_TIQUE_CPP_PILE_H
#include "caractere.h"
#include <string>
using namespace std;
//premier entré premier sorti

class pile {
    caractere *head;
    int nb_caractere;
public:
    pile();
    void empiler(string operande);
    string depiler();
    bool vide();
    caractere *getHead();
    void afficher();
    void evaluer(string expression);
};

#endif
