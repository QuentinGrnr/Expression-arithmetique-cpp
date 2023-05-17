#include "exercice_1/pile.h"
#include <iostream>
using namespace std;

int main() {
    cout << "=========================================Question 1=========================================" << endl;
    pile p; //creation d'une pile
    string expression; //creation d'une chaine de caractere
    cout << "Entrez une expression arithmetique suffixee" << endl;
    getline(cin, expression); //lecture de la chaine de caractere en entier (toute la ligne)
    p.evaluer(expression); //appel de la methode évaluer qui évalue une expression suffixée
}