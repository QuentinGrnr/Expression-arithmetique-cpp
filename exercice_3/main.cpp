#include "pile.h"
#include "outputChain.h"
#include "arbre.h"
#include <iostream>
using namespace std;

int main(){
cout  << "=========================================Question 3========================================="<<endl;
    outputChain o; //creation d'une chaine de sortie
    o.InfToSuf("88+9*(555+9-5)*8"); //appel de la methode InfToSuf qui transforme une expression infixe en expression suffixée
    o.afficher();
}
     //88 9 555 9 +5 -*8 *+