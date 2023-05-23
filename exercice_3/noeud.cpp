#include "noeud.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

noeud::noeud() {
    fg = nullptr;
    fd = nullptr;
}

int getCharPriority (char op) { //cette 2nd version de getpriority permet d'obtenir la priorité d'un operateur avant que ce dernier soit dans un noeud
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

noeud::noeud(char caractere) {
    if (getCharPriority(caractere)==-1){
        this->type = 'f';
        this->val = atof(string(1, caractere).c_str());
        fg = nullptr;
        fd = nullptr;
    } else {
        this->type = 'o';
        this->ope = caractere;
        fg = nullptr;
        fd = nullptr;
    }

}

noeud::~noeud() {
    if (fg != nullptr && fd != nullptr) {
        delete fg;
        delete fd;
        delete Psuivant;
    }
}
