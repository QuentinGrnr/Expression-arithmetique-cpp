#ifndef TD2S2_POO_OUTPUTCHAIN_H
#define TD2S2_POO_OUTPUTCHAIN_H
#include <iostream>
#include "noeud.h"
using namespace std;

class outputChain {
    noeud *head;
    noeud *tail;
    int nb_caracteres;
    public:
        outputChain();
        void add (noeud *n);
        void afficher();
        void InfToSuf(string expression);
        friend class outputChain;
};

#endif
