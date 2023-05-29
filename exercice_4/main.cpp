#include "arbre.h"
#include <iostream>
using namespace std;

int main(){
cout  << "=========================================Question 3========================================="<<endl;
    arbre *A = new arbre ("956*8+9-856-(8^5)/9");
    A->afficher();
    cout << A->evaluer() << endl;
    A->afficherInfixe();
    delete A;
}
     //9568*9+8565^8--