//
// Created by luizao on 11/06/2026.
//

#include "../estruturas/TLista.h"
#include <stdlib.h>

TLista* insere_fim(TLista *l, int valor) {
    TLista *novo = (TLista*) malloc(sizeof(TLista));
    if (novo == NULL) exit(1);

    novo->valor = valor;
    novo->prox = NULL;

    if (l == NULL) return novo;

    TLista *aux = l;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novo;

    return l;
}