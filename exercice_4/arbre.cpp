#include "arbre.h"
#include <string>
#include "outputChain.h"
#include <iostream>
#include "pile.h"
#include <cmath>
using namespace std;

arbre::arbre() {
    racine = nullptr; //initialisation de la racine
}

arbre::arbre(noeud *racine) {
    this->racine = racine; //initialisation de la racine
}

arbre::arbre(string expinf){
    outputChain o; //création d'une nouvelle outputChain qui va nous permettre de transformer l'expression infixe en expression suffixée
    o.InfToSuf(expinf); //appel de la methode InfToSuf qui transforme une expression infixe en expression suffixée
    o.afficher(); //affichage de l'expression suffixée
    pile pi; //création d'une nouvelle pile qui va nous permettre de créer l'arbre
    noeud* current = o.getHead(); //on récupère le premier noeud de l'outputChain pour commencer à créer l'arbre en la lisant
    for (int i = 0; i < o.getcount();i++){
        if (current->type == 'r' || current->type == 'v') { //si c'est un nombre ou une variable
            pi.empiler(current);//on l'empile
        } else { //si ce n'est pas un nombre ou une var, c'est un opérateur
            current->fd = pi.depiler();//on dépile le dernier nombre/var empilé et on le met à droite de l'opérateur
            current->fg = pi.depiler(); //on dépile le dernier nombre/var empilé et on le met à gauche de l'opérateur
            pi.empiler(current); //on empile l'opérateur
        }
        current = current->Osuivant; //on passe au noeud suivant
    }
    this->racine = pi.depiler(); //on dépile le dernier noeud empilé qui est la racine de l'arbre
}

void arbre::afficher() { //méthode d'affichage de l'arbre recursive
    if (racine != nullptr) {
        cout << "L'arbre de votre expression  : " << endl;
        afficherRecursive(racine, "", true);
    }
}

void arbre::afficherRecursive(noeud *noeudActuel, string miseEnPage, bool estDernier) {
    cout << miseEnPage; //mise en page de l'affichage qui est agrémenté de | et de -- pour représenter l'arbre
    cout << "|-- ";
    //cout << noeudActuel->type << " : ";
    if (noeudActuel->type == 'o') {
        cout << "Operateur: " << noeudActuel->ope << endl;
    } else if (noeudActuel->type == 'r') {
        cout << "Valeur: " << noeudActuel->val << endl;
    } else if (noeudActuel->type == 'v') {
        cout << "Variable: " << noeudActuel->var << endl;
    }
    string nouveauPrefixe = miseEnPage + (estDernier ? "    " : "|   ");//concaténation de la nouvelle mise en page de l'affichage avec l'ancienne
    if (noeudActuel->fg != nullptr) {//si le noeud a un fils gauche, on affiche le fils gauche
        afficherRecursive(noeudActuel->fg, nouveauPrefixe, false);
    }
    if (noeudActuel->fd != nullptr) {//si le noeud a un fils droit, on affiche le fils droit
        afficherRecursive(noeudActuel->fd, nouveauPrefixe, true);
    }
}
// fonction evaluer ne peut etre effectuée que dans le dossier exercice_3 car dans l'exerice l'ajout des variable rend impossible l'evaluation de l'arbre

void arbre::afficherInfixe() {
    if (racine != nullptr) { //méthode d'affichage infixe de l'arbre recursive
        afficherInfixe(racine); //appel de la méthode recursive
        cout << endl;
    }
}

void arbre::afficherInfixe(noeud* noeudActuel) {
    if (noeudActuel != nullptr) {
        if (noeudActuel->type == 'r') {
            cout << noeudActuel->val;
        } else if (noeudActuel->type == 'v') {
            cout << noeudActuel->var;
        } else if (noeudActuel->type == 'o' && (noeudActuel->fd->type == 'r' || noeudActuel->fd->type == 'v') && (noeudActuel->fg->type == 'r' || noeudActuel->fg->type == 'v')) { //si le noeud est un opérateur et que ses fils sont des nombres/var, on affiche l'opérateur et ses fils
            afficherInfixe(noeudActuel->fg);
            cout << " " << noeudActuel->ope << " ";
            afficherInfixe(noeudActuel->fd);
        } else { //sinon on affiche l'opérateur et ses fils entre parenthèses
            cout << "(";
            afficherInfixe(noeudActuel->fg);
            cout << " " << noeudActuel->ope << " ";
            afficherInfixe(noeudActuel->fd);
            cout << ")";
        }
    }
}

void arbre::deriver(){
    if (racine != nullptr) { //méthode de dérivation de l'arbre recursive
        cout << "L'arbre representant votre derivee : ";
        noeud* deriveRacine = deriverRecursive(this->racine); //appel de la méthode recursive
        arbre *deriveA = new arbre (deriveRacine);
        deriveA->afficher();
        cout << endl;
        cout << "L'expression infixe de votre derivee : ";
        deriveA->afficherInfixe();
    }
}

noeud* arbre::deriverRecursive(noeud *current) {

    if (current->type == 'r') {
        noeud* deriv = new noeud('0');
        return deriv;
    }
    else if (current->type == 'v') {
        noeud* deriv = new noeud('1');
        return deriv;
    }
    else {
        if (current->ope == '+' || current->ope == '-') {
            noeud* deriv = new noeud(current->ope);
            deriv->fg = deriverRecursive(current->fg);
            deriv->fd = deriverRecursive(current->fd);
            return deriv;
        }else if (current->ope == '*') {
            noeud* deriv = new noeud('+');
            deriv->fg = new noeud('*');
            deriv->fg->fg = deriverRecursive(current->fg);
            deriv->fg->fd = current->fd;

            deriv->fd = new noeud('*');
            deriv->fd->fg = current->fg;
            deriv->fd->fd = deriverRecursive(current->fd);

            return deriv;
        }else if (current->ope == '/') {
            noeud* deriv = new noeud('/');
            deriv->fg = new noeud('-');
            deriv->fg->fg = new noeud('*');
            deriv->fg->fg->fg = deriverRecursive(current->fg);
            deriv->fg->fg->fd = current->fd;

            deriv->fg->fd = new noeud('*');
            deriv->fg->fd->fg = current->fg;
            deriv->fg->fd->fd = deriverRecursive(current->fd);

            deriv->fd = new noeud('*');
            deriv->fd->fg = current->fd;
            deriv->fd->fd = current->fd;

            return deriv;
        }
        else if (current->ope == '^') {
            float exposant = current->fd->val;

            if (exposant == 0) {
                noeud* deriv = new noeud('1');
                return deriv;
            }
            else {
                noeud* deriv = new noeud('*');
                deriv->fg = new noeud('*');
                deriv->fg->fg = new noeud('0');//on met 0 pour le moment car on ne peut pas mettre un float en caractére
                deriv->fg->fg->val = exposant; //on met l'exposant
                deriv->fg->fd = new noeud('^');
                deriv->fg->fd->fg = current->fg;
                deriv->fg->fd->fd = new noeud('0'); //on met 0 pour le moment car on ne peut pas mettre un float en caractére
                deriv->fg->fd->fd->val = exposant - 1;
                deriv->fd = deriverRecursive(current->fg); //on dérive la fonction A qui est le fils gauche
                return deriv;
            }
        }
    }
    return nullptr;
}

arbre::~arbre() {
    delete racine;
    cout << "Destruction de l'arbre" << endl;
}

//8*X/9*X
