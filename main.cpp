#include "pile.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    pile p;
    string expression;
    cout << "Entrez une expression arithmetique postfixee" << endl;
    cin >> expression;
    p.evaluer(&expression);
}