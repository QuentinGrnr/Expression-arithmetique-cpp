#ifndef TD2S2_POO_OUTPUTCHAIN_H
#define TD2S2_POO_OUTPUTCHAIN_H
#include <iostream>
#include "noeud.h"
using namespace std;

class outputChain {
    noeud *tail; //pointeur vers le dernier noeud de la chaine
    noeud *head; //pointeur vers le premier noeud de la chaine
    int nb_noeuds; //nombre de noeuds dans la chaine
    public:
        outputChain(); //constructeur sans argument
        void add (noeud *n); //ajouter un noeud a la chaine
        void afficher(); //afficher la chaine
        void InfToSuf(string expression); //convertir une expression infixe en expression suffixe
        noeud *getHead(); //retourner le pointeur vers le premier noeud de la chaine
        int getcount(); //retourner le nombre de noeuds dans la chaine
};

#endif
