#include "noeud.h"

noeud::noeud() {
    fg = nullptr;
    fd = nullptr;
}

noeud::noeud(char ope) {
    this->type = 'o';
    if (type == 'o') {
        this->ope = ope;
    }
    if (type == 'f') this->val = val;
    fg = nullptr;
    fd = nullptr;
}