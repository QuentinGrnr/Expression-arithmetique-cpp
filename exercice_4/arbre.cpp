#include "arbre.h"
#include <string>
#include "outputChain.h"
#include <iostream>
#include "pile.h"
#include <cmath>
using namespace std;

arbre::arbre() {
    racine = nullptr;
}

arbre::arbre(string expinf){
    outputChain o;
    o.InfToSuf(expinf); //appel de la methode InfToSuf qui transforme une expression infixe en expression suffixée 88 9 555 9 +5 -*8 *+
    o.afficher();
    pile pi;
    noeud* current = o.gettail();
    for (int i = 0; i < o.getcount();i++){
        cout << "current->type = " << current->type << endl;
        if (current->type == 'f'){
            cout << "current->val = " << current->val << endl;
            pi.empiler(current);
        } else { //si ce n'est pas un nombre, c'est un opérateur
            cout << "current->ope = " << current->ope << endl;
            current->fd = pi.depiler();
            current->fg = pi.depiler();
            pi.empiler(current);
        }
        current = current->Osuivant;
    }
    this->racine = pi.depiler();
}

void arbre::afficher() {
    if (racine != nullptr) {
        afficherRecursive(racine, "", true);
    }
}

void arbre::afficherRecursive(noeud *noeudActuel, string miseEnPage, bool estDernier) {
    cout << miseEnPage;
    cout << "|-- ";
    if (noeudActuel->type == 'o') {
        cout << "Operateur: " << noeudActuel->ope << endl;
    } else if (noeudActuel->type == 'f') {
        cout << "Valeur: " << noeudActuel->val << endl;
    }
    string nouveauPrefixe = miseEnPage + (estDernier ? "    " : "|   ");
    if (noeudActuel->fg != nullptr) {
        afficherRecursive(noeudActuel->fg, nouveauPrefixe, false);
    }
    if (noeudActuel->fd != nullptr) {
        afficherRecursive(noeudActuel->fd, nouveauPrefixe, true);
    }
}

float arbre::evaluer() {
    if (racine != nullptr) {
        return evaluer(racine);
    }
    else {
        return 0;
    }
}

float arbre::evaluer(noeud* noeudActuel) {
    if (noeudActuel->type == 'f') {
        return noeudActuel->val; // Si le nœud est une valeur, retourner la valeur
    }
    else if (noeudActuel->type == 'o') {
        float resultatGauche = evaluer(noeudActuel->fg); // Évaluer le sous-arbre gauche
        float resultatDroit = evaluer(noeudActuel->fd); // Évaluer le sous-arbre droit

        // Appliquer l'opération de l'opérateur sur les résultats des sous-arbres
        switch (noeudActuel->ope) {
            case '+':
                cout << "resultatGauche + resultatDroit = " << resultatGauche + resultatDroit << endl;
                return resultatGauche + resultatDroit;
            case '-':
                cout << "resultatGauche - resultatDroit = " << resultatGauche << " " << resultatDroit << " " <<resultatGauche - resultatDroit << endl;
                return resultatGauche - resultatDroit;
            case '*':
                cout << "resultatGauche * resultatDroit = " << resultatGauche * resultatDroit << endl;
                return resultatGauche * resultatDroit;
            case '/':
                cout << "resultatGauche / resultatDroit = " << resultatGauche / resultatDroit << endl;
                return resultatGauche / resultatDroit;
            case '^':
                cout << "resultatGauche ^ resultatDroit = " << pow(resultatGauche, resultatDroit) << endl; //pow = puissance
                return pow(resultatGauche, resultatDroit);
            case '%':
                cout << "resultatGauche % resultatDroit = " << fmod(resultatGauche, resultatDroit) << endl;//fmod = modulo float
                return fmod(resultatGauche, resultatDroit);
            default:
                return 0.0; // Opérateur invalide, retourner 0.0
        }
    }
    else {
        return 0.0; // Type de nœud invalide, retourner 0.0
    }
}

void arbre::afficherInfixe() {
    if (racine != nullptr) {
        afficherInfixe(racine);
    }
}

void arbre::afficherInfixe(noeud* noeudActuel) {
    if (noeudActuel != nullptr) {
        if (noeudActuel->type == 'f') {
            cout << noeudActuel->val;
        } else if (noeudActuel->type == 'o' && noeudActuel->fd->type == 'f' && noeudActuel->fg->type == 'f') {
            afficherInfixe(noeudActuel->fg);
            cout << " " << noeudActuel->ope << " ";
            afficherInfixe(noeudActuel->fd);
        } else {
            cout << "(";
            afficherInfixe(noeudActuel->fg);
            cout << " " << noeudActuel->ope << " ";
            afficherInfixe(noeudActuel->fd);
            cout << ")";
        }
    }
}

arbre::~arbre() {
    delete racine;
    cout << "Destruction de l'arbre terminee" << endl;
}


