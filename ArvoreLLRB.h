#ifndef ARVORELLRB_H
#define ARVORELLRB_H


struct NO {
    int info;
    struct NO *esq;
    struct NO *dir;
    int cor;
};

int cor(struct NO* H);
void trocaCor(struct NO* H);
void imprimeArvore(struct NO* H);
struct NO* rotacionaEsquerda(struct NO* A);
struct NO* rotacionaDireita(struct NO* A);
struct NO* insereNO(struct NO* H, int valor, int *resp);
int busca(struct NO* H, int valor);

#endif
