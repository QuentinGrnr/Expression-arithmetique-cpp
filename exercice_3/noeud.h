#ifndef TD2S2_POO_NOEUD_H
#define TD2S2_POO_NOEUD_H


class noeud {
    char type; // 'o' pour operateur, 'f' pour valeur
    char ope;
    float val;
    noeud *fg,*fd;
    noeud *Osuivant; // Suivant dans la file d'outputchain
    noeud *Psuivant; // Suivant dans la pile
public:
    noeud();
    noeud(char caractere);
    void setfgfd(noeud *fg,noeud *fd);

    ~noeud();

    friend class arbre;
    friend class outputChain;
    friend class pile;
};


#endif //TD2S2_POO_NOEUD_H
