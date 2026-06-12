//
// Created by Eric on 11/06/2026.
//

#include "resposta.h"
#include <stdlib.h>

int* inver_vet(int* vet, int tam) {
    if (!vet) return NULL;
    int temp;
    for (int i = 0; i < tam/2; i++) {
        temp = vet[i];
        vet[i] = vet[tam - i - 1];
        vet[tam - i - 1] = temp;
    }
    return vet;
}

TNoB** inver_ps(TNoB** a, int tam) {
    if (!a) return NULL;

    TNoB* aux = NULL;
    for (int i = 0; i < tam; i++) {
        aux = a[i];
        a[i] = a[tam - i];
        a[tam - i] = aux;
    }
    return a;
}

TNoB* inverte(TNoB *a) {
    if (!a) return NULL;

    a->s = inver_vet(a->s, a->m);
    a->p = inver_ps(a->p, a->m);

    for (int i = 0; i < a->m; i++) a->p[i] = inverte(a->p[i]);

    return a;
}