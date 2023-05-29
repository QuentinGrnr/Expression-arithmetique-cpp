#include "outputChain.h"
#include <iostream>
#include <string>
#include "pile.h"
#include "noeud.h"
using namespace std;

outputChain::outputChain() {
    this->head = nullptr;
    this->tail = nullptr;
    this->nb_noeuds = 0;
}

void outputChain::add(noeud *newN) {
    if (this->nb_noeuds == 0) {
        if (newN->type== 'o') {
            this->head = newN;
            this->tail = newN;
            this->nb_noeuds++;
            cout << this->head->ope << " a ete ajoute" <<endl;
        } else {
            this->head = newN;
            this->tail = newN;
            this->nb_noeuds++;
            cout << this->head->val << " a ete ajoute" <<endl;
        }
    } else {
        if (newN->type == 'o') {
            this->head->Osuivant = newN;
            this->nb_noeuds++;
            this->head = this->head->Osuivant;
            cout << this->head->ope << " a ete ajoute" <<endl;
        } else {
            this->head->Osuivant = newN;
            this->nb_noeuds++;
            this->head = this->head->Osuivant;
            cout << this->head->val << " a ete ajoute" <<endl;
        }
    }
}

void outputChain::afficher() {
    noeud *n = this->tail;
    for (int i = 0; i < this->nb_noeuds; i++) {
        if (n->type == 'o') {
            cout << n->ope;
        } else {
            cout << n->val;
        }
        n = n->Osuivant;
    }
    cout << endl;
}

int getopPriority (char op) {
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
    pile p;
    string op = "";
    for (int i = 0; i < expression.length()+1; i++) {
        if (expression[i] == '\0') {
            cout << "1 : "<< expression[i] << endl;
            while (!p.vide()) { // tant que la pile n'est pas vide
                cout << "in" << endl;
                this->add(p.depiler()); // on ajoute les opérateurs de la pile à la chaine de sortie jusqu'à ce que la pile soit vide
            }
            continue;
        }
        noeud *n = new noeud(expression[i]);
        if (n->type == 'f') {
            cout << "2-1 : "<< n->val << endl;
            op = expression[i];
            while (getopPriority(expression[i + 1]) == -1 && expression[i + 1] !='\0') { // tant que le caractére Osuivant est un opérande différant de vide = c'est un chiffre
                op += expression[i + 1]; // on concaténe les chiffres pour former le nombre final
                i++;// on incrémente i pour passer au caractére Osuivant
            }
            n->val = stof(
                    op); // on convertit la chaine de caractére en float pour passer la nouvelle valeur à la variable val du noeud
            cout << "2-2 : "<< n->val << endl;
                    this->add(
                    n); //on ajoute directement le chiffre/nombre à la chaine de sortie suivit d'un espace pour séparer les opérandes
        } else if (!p.vide()) {
            if (getopPriority(expression[i]) ==
                3) { // si expression[i] (que l'on passe en string) est un ^ soit le seul oprérateur (utilisé ici) avec une associativité à droite en cpp
                cout << "3 : "<< n->ope << endl;
                while (!p.vide() &&  getopPriority(expression[i]) < getopPriority(
                        p.getHead()->ope)) { // tant que l'opérateur au sommet de la pile est strictement plus prioritaire que celui de l'expression
                    this->add(p.depiler()); // on ajoute l'opérateur de la pile à la chaine de sortie
                }
                p.empiler(n); // on empile l'opérateur de l'expression
            } else if (getopPriority(expression[i]) ==
                       0) { // si expression[i] (que l'on passe en string) est une parenthèse ouvrante
                cout << "4 : "<< n->ope << endl;
                p.empiler(n); // on empile la parenthèse ouvrante directement
            } else if (getopPriority(expression[i])  == 4) { // si expression[i] (que l'on passe en string) est une parenthèse fermante
                cout << "5 : "<< n->ope << endl;
                while (p.getHead()->ope !=
                       '(') { // tant que l'opérateur au sommet de la pile n'est pas une parenthèse ouvrante
                    this->add(p.depiler()); // on ajoute l'opérateur de la pile à la chaine de sortie
                }
                p.depiler(); // on dépile ensuite la parenthèse ouvrante
            } else { // pour tout les autres opérateurs qui on une associativité de gauche a droite
                cout << "6 : "<< n->ope << endl;
                while (!p.vide() && getopPriority(expression[i])  <= getopPriority(p.getHead()->ope)) {// tant que l'opérateur au sommet de la pile est strictement plus prioritaire que celui de l'expression
                    cout << "vide : " << p.vide() << endl;
                    cout << "val1 : " << getopPriority(expression[i])  << endl;
                    cout << "val2 : " << getopPriority(p.getHead()->ope) << endl;
                    this->add(p.depiler()); // on ajoute l'opérateur de la pile à la chaine de sortie
                }
                p.empiler(n); // on empile l'opérateur de l'expression
            }
        } else { // si la pile est vide et que c'est un operateur
            cout << "7 : "<< n->ope << endl;
            p.empiler(n); // on empile l'opérateur de l'expression
        }
    }
}

noeud *outputChain::gettail() {
    return tail;
}

int outputChain::getcount() {
    return this->nb_noeuds;
}