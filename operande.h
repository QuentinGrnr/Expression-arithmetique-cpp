#ifndef EXPRESSION_ARITHM_TIQUE_CPP_OPERANDE_H
#define EXPRESSION_ARITHM_TIQUE_CPP_OPERANDE_H


class operande {
    int valeur;
    operande *suivant;
public:
    operande();
    operande(int valeur);
    operande(int valeur, operande *suivant);
    ~operande();
    friend class pile;
};


#endif
