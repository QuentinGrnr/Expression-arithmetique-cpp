#ifndef TD2S2_POO_OUTPUTCHAIN_H
#define TD2S2_POO_OUTPUTCHAIN_H
#include "caractere.h"
#include <iostream>
using namespace std;

class outputChain {
    caractere *head; //pointeur vers le premier caractere de la pile
    caractere *tail; //pointeur vers le dernier caractere de la pile
    int nb_caracteres; //nombre de caractere dans la pile
public:
    outputChain(); //constructeur par defaut
    void add (string op); //ajoute un caractere à la pile
    void afficher(); //affiche la pile
    void InfToSuf(string expression); //convertit une expression arithmétique infixe en suffixée
};

#endif
