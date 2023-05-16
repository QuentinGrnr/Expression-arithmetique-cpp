#include "pile.h"
#include <iostream>
#include <string>
using namespace std;

pile::pile() {
    this->head = nullptr;
    this->nb_caractere = 0;
}

void pile::empiler(string val) {
    if (this->vide()) {
        caractere *o = new caractere(val);
        cout << "La valeur empilee est " << val << endl;
        this->head = o;
    } else {
        caractere *o = new caractere(val, this->head);
        this->head = o;
        cout << "La valeur empilee est " << val << endl;
    }
    this->nb_caractere++;
}

string pile::depiler() {
    if (this->vide()) {
        cout << "La pile est vide, la valeur renvoyee est une valeur par defaut (-1)" << endl;
        return "error";
    } else {
        string val = this->head->valeur;
        caractere *o = this->head;
        this->head = this->head->suivant;
        delete o;
        this->nb_caractere--;
        cout << "La valeur depilee est " << val << endl;
        return val;
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
            this->empiler(string(1, expression[i])); //string(1, expression[i]) permet de convertir un char en string
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


