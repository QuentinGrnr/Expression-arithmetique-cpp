#ifndef TD2S2_POO_NOEUD_H
#define TD2S2_POO_NOEUD_H


class noeud {
    char type; // 'o' pour operateur, 'r' pour valeur et 'v' pour variable
    char var;
    char ope;
    float val;
    noeud *fg,*fd;
    noeud *Osuivant; // Suivant dans la file d'outputchain (pour la transformation d'infixe en sufixe)
    noeud *Psuivant; // Suivant dans la pile
public:
    noeud(); //constructeur par défaut
    noeud(char caractere); //constructeur avec paramètre
    void afficher(); //afficher le noeud

    ~noeud(); //destructeur de noeud

    friend class arbre;
    friend class outputChain;
    friend class pile;
};


#endif //TD2S2_POO_NOEUD_H
