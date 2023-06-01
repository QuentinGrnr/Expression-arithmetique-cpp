#include "pile.h"
#include "outputChain.h"
#include <iostream>
using namespace std;

int main(){
cout  << "=========================================Question 2========================================="<<endl;
    cout << "entrez une expression arithmetique infixe : ";
    outputChain o; //creation d'une chaine de sortie
    string expression;
    getline(cin, expression); //recuperation de l'expression arithmetique
    o.InfToSuf(expression); //appel de la methode InfToSuf qui transforme une expression infixe en expression suffixée
}
