#include "outputChain.h"
#include <iostream>
#include <string>
#include "pile.h"
#include "noeud.h"
using namespace std;

outputChain::outputChain() { //constructeur sans argument
    this->tail = nullptr;
    this->head = nullptr;
    this->nb_noeuds = 0;
}

void outputChain::add(noeud *newN) { //ajouter un noeud a la chaine
    if (this->nb_noeuds == 0) { //si la chaine est vide
            this->tail = newN;
            this->head = newN;
            this->nb_noeuds++;
    } else { //si la chaine n'est pas vide
            this->tail->Osuivant = newN;
            this->nb_noeuds++;
            this->tail = this->tail->Osuivant;
    }
}

void outputChain::afficher() { //afficher la chaine
     cout << "Votre expression suffixe : ";
    noeud *n = this->head; //pointeur vers le premier noeud de la chaine
    for (int i = 0; i < this->nb_noeuds; i++) { //parcourir la chaine
        if (n->type == 'o') {
            cout << n->ope;
        } else {
            cout << n->val;
        }
        cout << " ";
        n = n->Osuivant;
    }
    cout << endl;
}

int getopPriority (char op) { //retourner la priorité d'un opérateur donné (0 pour parenthèse ouvrante, 1 pour + et -, 2 pour * et /, 3 pour ^, 4 pour parenthèse fermante, -1 pour opérande ou vide)
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
    string op = ""; //chaine de caractére qui va contenir les opérandes et qui va nous permettre de les concaténer pour former un nombre
    for (int i = 0; i < expression.length()+1; i++) { //parcourir l'expression infixe
        if (expression[i] == '\0') { //si on arrive à la fin de l'expression
            while (!p.vide()) { // tant que la pile n'est pas vide
                this->add(p.depiler()); // on ajoute les opérateurs de la pile à la chaine de sortie jusqu'à ce que la pile soit vide
            }
            continue; //on passe à l'itération suivante (soit normalement la fin de la boucle)
        }
        noeud *n = new noeud(expression[i]); //créer un nouveau noeud avec le caractére courant de l'expression
        if (n->type == 'f') {
            op = expression[i];
            while (getopPriority(expression[i + 1]) == -1 && expression[i + 1] !='\0') { // tant que le caractére Osuivant est un opérande différant de vide = c'est un chiffre
                op += expression[i + 1]; // on concaténe les chiffres pour former le nombre final
                i++;// on incrémente i pour passer au caractére Osuivant
            }
            n->val = stof(
                    op); // on convertit la chaine de caractére en float pour passer la nouvelle valeur à la variable val du noeud
                    this->add(
                    n); //on ajoute directement le chiffre/nombre à la chaine de sortie suivit d'un espace pour séparer les opérandes
        } else if (!p.vide()) {
            if (getopPriority(expression[i]) ==
                3) { // si expression[i] (que l'on passe en string) est un ^ soit le seul oprérateur (utilisé ici) avec une associativité à droite en cpp
                while (!p.vide() &&  getopPriority(expression[i]) < getopPriority(
                        p.getHead()->ope)) { // tant que l'opérateur au sommet de la pile est strictement plus prioritaire que celui de l'expression
                    this->add(p.depiler()); // on ajoute l'opérateur de la pile à la chaine de sortie
                }
                p.empiler(n); // on empile l'opérateur de l'expression
            } else if (getopPriority(expression[i]) ==
                       0) { // si expression[i] (que l'on passe en string) est une parenthèse ouvrante
                p.empiler(n); // on empile la parenthèse ouvrante directement
            } else if (getopPriority(expression[i])  == 4) { // si expression[i] (que l'on passe en string) est une parenthèse fermante
                while (p.getHead()->ope !=
                       '(') { // tant que l'opérateur au sommet de la pile n'est pas une parenthèse ouvrante
                    this->add(p.depiler()); // on ajoute l'opérateur de la pile à la chaine de sortie
                }
                p.depiler(); // on dépile ensuite la parenthèse ouvrante
            } else { // pour tout les autres opérateurs qui on une associativité de gauche a droite
                while (!p.vide() && getopPriority(expression[i])  <= getopPriority(p.getHead()->ope)) {// tant que l'opérateur au sommet de la pile est strictement plus prioritaire que celui de l'expression
                    this->add(p.depiler()); // on ajoute l'opérateur de la pile à la chaine de sortie
                }
                p.empiler(n); // on empile l'opérateur de l'expression
            }
        } else { // si la pile est vide et que c'est un operateur
            p.empiler(n); // on empile l'opérateur de l'expression
        }
    }
}

noeud *outputChain::getHead() { //retourne le premier noeud de la chaine
    return head;
}

int outputChain::getcount() { //retourne le nombre de noeuds de la chaine
    return this->nb_noeuds;
}