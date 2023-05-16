#include "outputChain.h"
#include <iostream>
#include <string>
#include "../exercice_1/pile.h"
using namespace std;

outputChain::outputChain() {
    this->head = nullptr;
    this->tail = nullptr;
    this->nb_caracteres = 0;
}

void outputChain::add(string op) {
    if (this->head == nullptr) {
        caractere *o = new caractere(op);
        this->head = o;
        this->tail = o;
        this->nb_caracteres++;
    } else {
        this->head->suivant = new caractere(op);
        this->nb_caracteres++;
        this->head = this->head->suivant;
    }
}

void outputChain::afficher() {
    caractere *o = this->tail;
    while (o != nullptr) {
        cout << o->valeur;
        o = o->suivant;
    }
    cout << endl;
}

int getpriority (string op) {
    if (op == "("){
        return 0; //parenthèse ouvrante
    }else if (op == "+" || op == "-"){
        return 1; //addition, soustraction
    } else if (op == "*" || op == "/" || op == "%"){
        return 2; //multiplication, division, modulo
    } else if (op == "^"){
        return 3; //puissance (associativité à droite)
    }else if (op == ")") {
        return 4; //parenthèse fermante
    } else {
        return -1; //l'op donné est un operande
    }
}

void outputChain::InfToSuf(string expression) {
    pile p;
    for (int i = 0; i < expression.length()+1;i++) {
        if (expression[i] == '\0') { // si l'entrée est vide
            cout << "L'expression est vide" << endl;
        }
        if (getpriority(string(1, expression[i])) == -1) { //si expression[i] (que l'on passe en string) est un opérande ou est vide
            if (expression[i] == '\0') { // si l'entrée est vide
                cout << "1 : " << expression[i]<< endl;
                while (!p.vide()) { // tant que la pile n'est pas vide
                    this->add(p.depiler()); // on ajoute les opérateurs de la pile à la chaine de sortie jusqu'à ce que la pile soit vide
                }
            } else { //si l'entrée n'est pas vide c'est un opérande
                    cout << "2 : " << expression[i] << endl;
                    this->add(string(1, expression[i])); // donc on l'ajoute directement à la chaine de sortie
                }
        } else if (!p.vide()){ //si la pile n'est pas vide et que c'est un opérateur
            if (getpriority(string(1, expression[i])) == 3) { // si expression[i] (que l'on passe en string) est un ^ soit le seul oprérateur (utilisé ici) avec une associativité à droite en cpp
                cout << "3 : " << expression[i] << endl;
                while (getpriority(string(1, expression[i])) < getpriority(
                        p.getHead()->valeur)) { // tant que l'opérateur au sommet de la pile est strictement plus prioritaire que celui de l'expression
                    this->add(p.depiler()); // on ajoute l'opérateur de la pile à la chaine de sortie
                }
            }
            else if (getpriority(string(1, expression[i])) == 0) { // si expression[i] (que l'on passe en string) est une parenthèse ouvrante
                cout << "4 : " << expression[i] << endl;
                p.empiler(string(1, expression[i])); // on empile la parenthèse ouvrante directement
            } else if (getpriority(string(1, expression[i])) == 4) { // si expression[i] (que l'on passe en string) est une parenthèse fermante
                cout << "5 : " << expression[i] << endl;
                while (p.getHead()->valeur != "(") { // tant que l'opérateur au sommet de la pile n'est pas une parenthèse ouvrante
                    this->add(p.depiler()); // on ajoute l'opérateur de la pile à la chaine de sortie
                }
                p.depiler(); // on dépile ensuite la parenthèse ouvrante
            } else { // pour tout les autres opérateurs qui on une associativité de gauche a droite
                cout << "6 : " << expression[i] << endl;
                while (!p.vide() && getpriority(string(1, expression[i])) <= getpriority(p.getHead()->valeur)) {// tant que l'opérateur au sommet de la pile est strictement plus prioritaire que celui de l'expression
                        cout << "vide : " << p.vide() << endl;
                        cout << "val1 : " << getpriority(string(1, expression[i])) << endl;
                        cout << "val2 : " << getpriority(p.getHead()->valeur) << endl;
                        this->add(p.depiler()); // on ajoute l'opérateur de la pile à la chaine de sortie
                }
                p.empiler(string(1, expression[i])); // on empile l'opérateur de l'expression
            }
        } else { // si la pile est vide et que c'est un operateur
            cout << "7 : " << expression[i] << endl;
            p.empiler(string(1, expression[i])); // on empile l'opérateur de l'expression
        }
    }
    this->afficher();
}
