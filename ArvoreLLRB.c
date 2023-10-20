#include <stdio.h>
#include <stdlib.h>
#include "ArvoreLLRB.h"

#define RED 1
#define BLACK 0

int cor(struct NO* H) {
    if (H == NULL)
        return BLACK;
    else
        return H->cor;
}
void trocaCor(struct NO* H) {
    H->cor = !H->cor;
    if (H->esq != NULL)
        H->esq->cor = !H->esq->cor;
    if (H->dir != NULL)
        H->dir->cor = !H->dir->cor;
}

struct NO* rotacionaEsquerda(struct NO* A) {
    struct NO* B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct NO* rotacionaDireita(struct NO* A) {
    struct NO* B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

// Função para inserir um nó com um valor específico na árvore de busca rubro-negra
struct NO* insereNO(struct NO* H, int valor, int *resp) {
    if (H == NULL) {
        // Se o nó for nulo, cria um novo nó.
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if (novo == NULL) {
            *resp = 0; // A alocação de memória falhou, indicando que a inserção não foi bem-sucedida.
            return NULL;
        }
        novo->info = valor; 
        novo->cor = RED; 
        novo->dir = NULL;
        novo->esq = NULL;
        *resp = 1; 
        return novo; 
    }

    if (valor == H->info) {
        *resp = 0; 
    } else if (valor < H->info) {
        H->esq = insereNO(H->esq, valor, resp); // Insere o valor na subárvore esquerda.
    } else {
        H->dir = insereNO(H->dir, valor, resp); // Insere o valor na subárvore direita.
    }

    // Verifica as propriedades da árvore e realiza rotações ou troca de cores conforme necessário.
    if (cor(H->dir) == RED && cor(H->esq) == BLACK) {
        H = rotacionaEsquerda(H);
    }
    if (cor(H->esq) == RED && cor(H->esq->esq) == RED) {
        H = rotacionaDireita(H);
    }
    if (cor(H->esq) == RED && cor(H->dir) == RED) {
        trocaCor(H);
    }

    return H; 
  }