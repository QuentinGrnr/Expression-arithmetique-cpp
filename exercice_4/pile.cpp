#include "pile.h"
#include <iostream>
#include <string>
using namespace std;

pile::pile() { //constructeur sans argument
    this->head = nullptr;
    this->nb_caractere = 0;
}

void pile::empiler(noeud *n) { //ajouter un noeud au sommet de la pile
    if (this->vide()) {
        this->head = n;
    } else {
        n->Psuivant = this->head; //le noeud suivant du noeud a empiler est le noeud au sommet de la pile
        this->head = n; //le noeud a empiler devient le noeud au sommet de la pile
    }
    this->nb_caractere++;
}

noeud* pile::depiler(){ //retirer le noeud au sommet de la pile et le retourner
    if (this->vide()) {
        cout << "La pile est vide, la valeur renvoyee est nullptr" << endl;
        return nullptr;
    } else {
        noeud *n = this->head;
        this->head = this->head->Psuivant;
        this->nb_caractere--;
        return n;
    }
}


bool pile::vide() {
    if (this->nb_caractere==0 ) {
        return true;
    } else {
        return false;
    }
}

void pile::afficher() {
    if (this->vide()) {
        cout << "La pile est vide" << endl;
    } else {
        noeud *n = this->head;
        while (n != nullptr) {
            if (n->type == 'o') {
                cout << n->ope << endl;
            } else {
                cout << n->val << endl;
            }
            n = n->Psuivant;
        }
    }
}

noeud *pile::getHead() {
    if (!this->vide()) {
        return this->head;
    } else {
        cout << "La pile est vide" << endl;
        return nullptr;
    }
}




