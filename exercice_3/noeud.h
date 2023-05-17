#ifndef TD2S2_POO_NOEUD_H
#define TD2S2_POO_NOEUD_H


class noeud {
    char type; // 'o' pour operateur, 'f' pour valeur
    char ope;
    float val;
    noeud *fg,*fd;

public:
    noeud();
    noeud(char ope);
    friend class arbre;
};


#endif //TD2S2_POO_NOEUD_H
