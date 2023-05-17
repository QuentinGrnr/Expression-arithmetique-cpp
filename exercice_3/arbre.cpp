#include "arbre.h"
#include <string>
#include "outputChain.h"
#include <iostream>
using namespace std;

arbre::arbre() {
    racine = nullptr;
}

arbre::arbre(string expressioninf) {
     outputChain suffixee;
     suffixee.InfToSuf(expressioninf);
}
