#include "pile.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
//=========================================Question 1=========================================
    pile p; //creation d'une pile
    string expression; //creation d'une chaine de caractere
    cout << "Entrez une expression arithmetique suffixée" << endl;
    cin >> expression;
    p.evaluer(expression); //appel de la methode évaluer qui évalue une expression suffixée
}