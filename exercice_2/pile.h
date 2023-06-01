#ifndef EXPRESSION_ARITHM_TIQUE_CPP_PILE_H
#define EXPRESSION_ARITHM_TIQUE_CPP_PILE_H
#include "caractere.h"
#include <string>
using namespace std;
//premier entré premier sorti

class pile {
    caractere *head; //pointeur vers le premier caractere de la pile
    int nb_caractere; //nombre de caractere dans la pile
public:
    pile(); //constructeur par defaut
    void empiler(string operande); //ajoute un caractere à la pile
    string depiler(); //supprime un caractere de la pile
    bool vide();    //verifie si la pile est vide
    caractere *getHead(); //retourne le premier caractere de la pile
    void afficher(); //affiche la pile
    void evaluer(string expression); //évalue une expression arithmétique suffixée
};

#endif
