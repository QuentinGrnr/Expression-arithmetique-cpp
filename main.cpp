#include "pile.h"
#include <iostream>
using namespace std;

int main(){
    pile p;
    p.empiler(1);
    p.empiler(2);
    p.empiler(3);
    p.empiler(4);
    p.empiler(5);
    p.empiler(6);
    p.empiler(7);
    cout << "Affichage de la pile" << endl;
    p.afficher();
    p.depiler();
    p.empiler(8);
    cout << "Affichage de la pile" << endl;
    p.afficher();
}