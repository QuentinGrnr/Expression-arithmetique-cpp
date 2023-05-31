#include "noeud.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

noeud::noeud() { //constructeur par défaut
    fg = nullptr;
    fd = nullptr;
}

noeud::noeud(char caractere) { //constructeur avec paramètre
    if (caractere == '+' || caractere == '-' || caractere == '*' || caractere == '/' || caractere == '%' || caractere == '^' || caractere == '(' || caractere == ')'){ //si le caractère est un operateur
        this->type = 'o';
        this->ope = caractere; //on stocke l'opérateur dans la variable ope
        fg = nullptr;
        fd = nullptr;
    } else if (caractere == 'X' || caractere == 'Y' || caractere == 'Z'){ //si le caractère est une variable
        this->type = 'v';
        this->var = caractere; //on stocke la variable dans la variable var
        fg = nullptr;
        fd = nullptr;
    }else { //si le caractère est un operande
        this->type = 'r';
        this->val = atof(string(1, caractere).c_str()); //conversion du caractère en string puis en float
        fg = nullptr;
        fd = nullptr;
    }
}

void noeud::afficher() { //afficher le noeud
    if (this->type == 'o') {
        cout << this->ope;
    } else if (this->type == 'v'){
        cout << this->var;
    } else if (this->type == 'r'){
        cout << this->val;
    }
}

noeud::~noeud() { //destructeur de noeud
        delete this->fg;
        delete this->fd;
}
