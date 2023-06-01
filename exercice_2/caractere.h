#ifndef EXPRESSION_ARITHM_TIQUE_CPP_OPERANDE_H
#define EXPRESSION_ARITHM_TIQUE_CPP_OPERANDE_H
#include <string>
using namespace std;

class caractere {
    string valeur; //valeur du caractere
    caractere *suivant;
public:
    caractere();
    caractere(string valeur);
    caractere(string valeur, caractere *suivant);
    ~caractere();
    friend class pile;
    friend class outputChain;
};


#endif
