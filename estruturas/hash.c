#include "hash.h"

#include <stdio.h>
#include <stdlib.h>

int hash(int chave, int tam) {
    return chave % tam;
}

Hash* hash_inicializa(int m) {
    Hash *tab = malloc(sizeof(TH*)*m);
    int i;
    for (i = 0; i < m; i++) {
        tab[i] = NULL;
    }
    return tab;
}

TH* hash_busca(Hash *tab, int m, int mat) {
    int h = hash(mat, m);
    TH *p = tab[h];
    while ((p != NULL) && (p->chave != mat)) {
        p = p->prox;
    }
    return p;
}

TH* hash_aloca(int chave) {
    TH *novo = (TH *) malloc(sizeof(TH));
    novo->chave = chave;
    novo->prox = NULL;
    return novo;
}

void hash_insere(Hash *tab, int m, int chave) {
    int h = hash(chave, m);
    TH *p = tab[h];
    TH *ant = NULL;
    while ((p != NULL) && (p->chave != chave)) {
        ant = p;
        p = p->prox;
    }

    if (p == NULL) {
        TH *novo = hash_aloca(chave);
        if (!ant) {
            tab[h] = novo;
        } else {
            ant->prox = novo;
        }
    }
}

Hash* hash_libera(Hash *tab, int m) {
    int i;
    for (i = 0; i < m; i++) {
        if (tab[i]) {
            TH *p = tab[i];
            TH *q;
            while (p) {
                q = p;
                p = p->prox;
                free(q);
            }
        }
    }
    free(tab);
    return NULL;
}

void hash_exclui(Hash *tab, int m, int chave) {
    int h = hash(chave, m);
    if (tab[h] == NULL) return;
    TH *p = tab[h];
    TH *ant = NULL;
    int valor = -1;
    while ((p != NULL) && (p->chave != chave)) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) return;

    if (ant == NULL) {
        tab[h] = p->prox;
    } else {
        ant->prox = p->prox;
    }
    free(p);
}

void hash_imprime(Hash *tab, int m) {
    for (int i = 0; i < m; i++) {
        printf("%d: ", i);
        if (tab[i]) {
            TH *p = tab[i];
            printf("\n");
            while (p) {
                printf("\t%d\t%p\n", p->chave, p->prox);
                p = p->prox;
            }
        } else printf("NULL\n");
    }
}