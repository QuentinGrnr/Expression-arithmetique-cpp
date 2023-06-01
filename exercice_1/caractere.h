#ifndef EXPRESSION_ARITHM_TIQUE_CPP_OPERANDE_H
#define EXPRESSION_ARITHM_TIQUE_CPP_OPERANDE_H
#include <string>
using namespace std;

class caractere {
    string valeur; //valeur du caractere
    caractere *suivant; //pointeur vers le caractere suivant
public:
    caractere(); //constructeur par defaut
    caractere(string valeur); //constructeur avec parametre (valeur)
    caractere(string valeur, caractere *suivant); //constructeur avec parametres (valeur et suivant)
    ~caractere(); //delete
    friend class pile; //pile est une classe amie de caractere
    friend class outputChain; //outputChain est une classe amie de caractere
};


#endif
