#ifndef TD2S2_POO_NOEUD_H
#define TD2S2_POO_NOEUD_H


class noeud {
    char type; // 'o' pour operateur, 'f' pour valeur
    char ope;
    float val;
    noeud *fg,*fd;
    noeud *suivant; // facultatif mais permet une lecture plus facile de la pile

public:
    noeud();
    noeud(char ope);
    noeud(float val);
    noeud(char ope,noeud *suivant);
    noeud(float val,noeud *suivant);
    void setfgfd(noeud *fg,noeud *fd);

    ~noeud();

    friend class arbre;
    friend class pile;
};


#endif //TD2S2_POO_NOEUD_H
