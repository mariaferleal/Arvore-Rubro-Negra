#include <stdio.h>
#include <stdlib.h>
#include "ArvoreLLRB.h"

#define RED 1
#define BLACK 0

void imprimeArvore(struct NO* H) {
    if (H != NULL) {
        imprimeArvore(H->esq);
        printf("%d ", H->info);
        if (H->cor == RED) {
            printf("(RED) ");
        } else {
            printf("(BLACK) ");
        }
        imprimeArvore(H->dir);
    }
}

int main() {
    struct NO* raiz = NULL;
    int resp, valor;

    raiz = insereNO(raiz, 25, &resp);
    raiz = insereNO(raiz, 20, &resp);
    raiz = insereNO(raiz, 10, &resp);
    raiz = insereNO(raiz, 5, &resp);

    imprimeArvore(raiz);
    printf("\n");

    return 0;
}