#include "outputChain.h"
#include <iostream>
#include <string>
#include "pile.h"
#include "noeud.h"
using namespace std;

outputChain::outputChain() {
    this->head = nullptr;
    this->tail = nullptr;
    this->nb_caracteres = 0;
}

void outputChain::add(noeud *n) {
    if (this->head == nullptr) {
        if (n->type== 'o') {
            noeud *n = new noeud(n->ope);
            this->head = n;
            this->tail = n;
            this->nb_caracteres++;
        } else {
            noeud *n = new noeud(n->val);
            this->head = n;
            this->tail = n;
            this->nb_caracteres++;
        }
    } else {
        if (n->type == 'o') {
            this->head->suivant = new noeud(n->ope);
            this->nb_caracteres++;
            this->head = this->head->suivant;
        } else {
            this->head->suivant = new noeud(n->val);
            this->nb_caracteres++;
            this->head = this->head->suivant;
        }
    }
}

void outputChain::afficher() {
    noeud *n = this->tail;
    while (n != nullptr) {
        if (n->type == 'o') {
            cout << n->ope;
        } else {
            cout << n->val;
        }
        n = n->suivant;
    }
    cout << endl;
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
        return -1; //l'op donné est un operande ou un vide
    }
}


void outputChain::InfToSuf(string expression) {

}
