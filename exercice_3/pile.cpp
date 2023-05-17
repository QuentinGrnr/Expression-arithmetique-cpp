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
        noeud *n = new noeud(op);
        cout << "La valeur empilee est " << op << endl;
        this->head = n;
    } else {
        noeud *n = new noeud(op, this->head);
        this->head = n;
        cout << "La valeur empilee est " << op << endl;
    }
    this->nb_caractere++;
}

void pile::empiler(float val) {
    if (this->vide()) {
        noeud *n = new noeud(val);
        cout << "La valeur empilee est " << val << endl;
        this->head = n;
    } else {
        noeud *n = new noeud(val, this->head);
        this->head = n;
        cout << "La valeur empilee est " << val << endl;
    }
    this->nb_caractere++;
}

char pile::depiler(char type) {
    if (type == 'o'){
       return
    } else {

    }
}

float pile::depiler(float operande) {
    return 0;
}

char pile::depiler() {
    if (this->vide()) {
        cout << "La pile est vide, la valeur renvoyee est une valeur par defaut (-1)" << endl;
        return 'e';
    } else {
        if (this->head->type == 'o'){
            char val = this->head->ope;
            noeud *n = this->head;
            this->head = this->head->suivant;
            delete n;
            this->nb_caractere--;
            cout << "La valeur depilee est " << val << endl;
            return val;
        } else {
            float val = this->head->val;
            noeud *n = this->head;
            this->head = this->head->suivant;
            delete n;
            this->nb_caractere--;
            cout << "La valeur depilee est " << val << endl;
            return val;
        }

    }
}

bool pile::vide() {
    if (this->head == nullptr) {
        return true;
    } else {
        return false;
    }
}

void pile::afficher() {
    if (this->vide()) {
        cout << "La pile est vide" << endl;
    } else {
        caractere *o = this->head;
        while (o != nullptr) {
            cout << o->valeur << endl;
            o = o->suivant;
        }
    }
}

void pile::evaluer(string expression) {
    string op = "";
    for (int i = 0; i < expression.length(); i++) {
        cout << expression[i] << endl;
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            int b = stoi(this->depiler());
            cout << "b = " << b << endl;
            int a = stoi(this->depiler());
            cout << "a = " << a << endl;
            if (expression[i] == '+') {
                this->empiler(to_string(a + b));
            } else if (expression[i] == '-') {
                this->empiler(to_string(a - b));
            } else if (expression[i] == '*') {
                this->empiler(to_string(a * b));
            } else if (expression[i] == '/') {
                this->empiler(to_string(a / b));
            }
        } else {
            op = expression[i];
            while (expression[i+1] != ' ') { // tant que l'opérande n'est pas fini
                 op += expression[i+1]; // on ajoute le caractère suivant à l'opérande
                 i++; // on incrémente i pour passer au caractère suivant
            }
            i++; // on incrémente i pour passer au caractére suivant sans considérer l'espace
            this->empiler(op); //string(1, expression[i]) permet de convertir un char en string
        }
    }
    cout << "Le resultat est " << this->depiler() << endl;
}

caractere *pile::getHead() {
    if (this->head != nullptr) {
        cout << "La valeur au sommet de la pile est " << this->head->valeur << endl;
        return this->head;
    } else {
        cout << "La pile est vide" << endl;
        return nullptr;
    }
}



