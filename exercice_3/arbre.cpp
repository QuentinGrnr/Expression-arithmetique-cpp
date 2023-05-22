#include "arbre.h"
#include <string>
#include "outputChain.h"
#include <iostream>
using namespace std;

arbre::arbre() {
    racine = nullptr;
}

int getpriority (char op) {
    if (op == '('){
        return 0; //parenthèse ouvrante
    }else if (op == '+' || op == '-'){
        return 1; //addition, soustraction
    } else if (op == '*' || op == '/' || op == '%'){
        return 2; //multiplication, division, modulo
    } else if (op == '^'){
        return 3; //puissance (associativité à droite)
    }else if (op == ')') {
        return 4; //parenthèse fermante
    } else {
        return -1; //l'op donné est un operande
    }
}

noeud* arbre::createnode(char caractere) {
        if (getpriority(caractere) == -1) {
            noeud *n = new noeud(stof(string(1,caractere)));// string(1,expression[i]) permet de convertir un char en string et stof permet de convertir un string en float
            return n;
        } else {
            noeud *n = new noeud(caractere);
            return n;
    }
}

arbre::arbre(string expressioninf) {

}
