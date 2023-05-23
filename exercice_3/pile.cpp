#include "pile.h"
#include <iostream>
#include <string>
using namespace std;

pile::pile() {
    this->head = nullptr;
    this->nb_caractere = 0;
}

void pile::empiler(noeud *n) {
    if (this->vide()) {
        cout << "La valeur empilee est ";
        if (n->type == 'o') {
            cout << n->ope << endl;
        } else {
            cout << n->val << endl;
        }
        this->head = n;
    } else {
        n->Psuivant = this->head;
        this->head = n;
        cout << "La valeur empilee est ";
        if (n->type == 'o') {
            cout << n->ope << endl;
        } else {
            cout << n->val << endl;
        }
    }
    this->nb_caractere++;
}

noeud* pile::depiler(){
    if (this->vide()) {
        cout << "La pile est vide, la valeur renvoyee est nullptr" << endl;
        return nullptr;
    } else {
        noeud *n = this->head;
        this->head = this->head->Psuivant;
        this->nb_caractere--;
        cout << "La valeur depilee est ";
        if (n->type == 'o') {
            cout << n->ope << endl;
        } else {
            cout << n->val << endl;
        }
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
        if (this->head->type == 'o') {
            cout << "La valeur au sommet de la pile est " << this->head->ope << endl;
        } else {
            cout << "La valeur au sommet de la pile est " << this->head->val << endl;
        }
        return this->head;
    } else {
        cout << "La pile est vide" << endl;
        return nullptr;
    }
}




