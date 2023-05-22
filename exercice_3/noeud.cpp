#include "noeud.h"

noeud::noeud() {
    fg = nullptr;
    fd = nullptr;
}

noeud::noeud(char ope) {
    this->type = 'o';
    this->ope = ope;
    fg = nullptr;
    fd = nullptr;
}

noeud::noeud(float val) {
    this->type = 'f';
    this->val = val;
    fg = nullptr;
    fd = nullptr;
}

void noeud::setfgfd(noeud *fg, noeud *fd) {
    this->fg = fg;
    this->fd = fd;
}

noeud::~noeud() {
    if (fg != nullptr && fd != nullptr) {
        delete fg;
        delete fd;
        delete suivant;
    }
}

noeud::noeud(char ope, noeud *suivant) {
    this->type = 'o';
    this->ope = ope;
    this->suivant = suivant;
    fg = nullptr;
    fd = nullptr;
}

noeud::noeud(float val, noeud *suivant) {
    this->type = 'f';
    this->val = val;
    this->suivant = suivant;
    fg = nullptr;
    fd = nullptr;
}
