#ifndef TD2S2_POO_OUTPUTCHAIN_H
#define TD2S2_POO_OUTPUTCHAIN_H
#include "caractere.h"
#include <iostream>
using namespace std;

class outputChain {
    caractere *head;
    caractere *tail;
    int nb_caracteres;
    public:
        outputChain();
        void add (string op);
        void afficher();
        void InfToSuf(string expression);
};

#endif
