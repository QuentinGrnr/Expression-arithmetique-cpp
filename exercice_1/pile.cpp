#include "pile.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

pile::pile() {
    this->head = nullptr;
    this->nb_caractere = 0;
}

void pile::empiler(string val) {
    if (this->vide()) { //si la pile est vide
        caractere *o = new caractere(val);//on crée un nouveau caractere
        this->head = o;//on affecte le nouveau caractere à la tete de la pile
    } else {
        caractere *o = new caractere(val, this->head); //on crée un nouveau caractere avec le caractere suivant qui est la tete de la pile
        this->head = o; //on affecte le nouveau caractere
    }
    this->nb_caractere++; //on incrémente le nombre de caractere
}

string pile::depiler() {
    if (this->vide()) { //si la pile est vide
        cout << "La pile est vide, la valeur renvoyee est une valeur par defaut (-1)" << endl;
        return "error";
    } else { //si la pile n'est pas vide
        string val = this->head->valeur; //on récupère la valeur du caractere à la tete de la pile
        caractere *o = this->head; //on crée un pointeur vers le caractere à la tete de la pile
        this->head = this->head->suivant; //on affecte le caractere suivant à la tete de la pile
        delete o; //on supprime le caractere à la tete de la pile
        this->nb_caractere--; //on décrémente le nombre de caractere
        return val; //on retourne la valeur du caractere à la tete de la pile
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
        return ;
    } else {
        caractere *o = this->head;
        while (o != nullptr) {
            cout << o->valeur << endl;
            o = o->suivant;
        }
    }
}

void pile::evaluer(string expression) {
    string op = ""; //opérande qui permet de stocker les nombres
    for (int i = 0; i < expression.length(); i++) { //on parcourt la chaine de caractere
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^' ) { //si le caractere est un opérateur
            int b = stoi(this->depiler()); //on dépile le premier nombre
            int a = stoi(this->depiler()); //on dépile le deuxième nombre
            cout << a << " " << expression[i] << " " << b << endl;
            if (expression[i] == '+') { //on effectue l'opération en fonction de l'opérateur et on empile le resultat
                this->empiler(to_string(a + b));
            } else if (expression[i] == '-') {
                this->empiler(to_string(a - b));
            } else if (expression[i] == '*') {
                this->empiler(to_string(a * b));
            } else if (expression[i] == '/') {
                this->empiler(to_string(a / b));
            } else if (expression[i] == '^') {
                this->empiler(to_string(pow(a, b)));
            }
        } else { //si le caractere est un nombre
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
        return this->head;
    } else {
        return nullptr;
    }
}


