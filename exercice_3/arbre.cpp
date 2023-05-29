#include "arbre.h"
#include <string>
#include "outputChain.h"
#include <iostream>
#include "pile.h"
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
            current->fg = pi.depiler();
            current->fd = pi.depiler();
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

arbre::~arbre() {
    delete racine;
    cout << "Destruction de l'arbre terminee" << endl;
}


