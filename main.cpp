#include "exercice_1/pile.h"
#include "exercice_2/outputChain.h"
#include <iostream>
using namespace std;

int main(){
cout  << "=========================================Question 1=========================================" <<endl;
    pile p; //creation d'une pile
    string expression; //creation d'une chaine de caractere
    cout << "Entrez une expression arithmetique suffixee" << endl;
    cin >> expression;
    p.evaluer(expression); //appel de la methode évaluer qui évalue une expression suffixée

cout  << "=========================================Question 2========================================="<<endl;
    outputChain o; //creation d'une chaine de sortie
    o.InfToSuf("8+9*(5+9-5)*8"); //appel de la methode InfToSuf qui transforme une expression infixe en expression suffixée
     }
     //89589+5-*8*7/+