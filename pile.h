#ifndef EXPRESSION_ARITHM_TIQUE_CPP_PILE_H
#define EXPRESSION_ARITHM_TIQUE_CPP_PILE_H
#include "operande.h"
//premier entré premier sorti

class pile {
    operande *head;
    int nb_operandes;
public:
    pile();
    void empiler(int operande);
    int depiler();
    bool vide();
    void afficher();
};

#endif
