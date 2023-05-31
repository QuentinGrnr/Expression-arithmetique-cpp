#include "arbre.h"
#include <iostream>
using namespace std;

int main(){
cout  << "=========================================Question 4========================================="<<endl;
    cout << "entrez une expression infixe" << endl;
    string expinf;
    cin >> expinf;
    arbre *A = new arbre (expinf);
    cout << endl;
    A->afficher();
    cout << endl << "expression infixe de votre arbre : ";
    A->afficherInfixe();
    cout << endl;
    A->deriver();
    cout << endl;
    delete A;
}